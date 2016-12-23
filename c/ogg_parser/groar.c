/**
 * Groar - groar.c
 * Main decode routine. Call lots of sub-routines
 *
 * Input :
 *			filename
 * Output :
 *			return 0 if everything's Ok
 *			else return error code
 * Note :
 *
 *
 *
 */

#include "groar.h"



int groar(unsigned char *ptr_data)
{
	unsigned char *p_stream = ptr_data;	/* pointer to raw data */
	unsigned int page_offset;			/* point on the first byte of the current page to decode */	
	int i;

	int ret = 0;
	page_offset = 0;	/* We start at the beginning of the file */

	/*** Init global data here ***/
	dec_stat.curr_pos = NOTHING;
	dec_stat.prec_pos = NOTHING;
	dec_stat.vorbis_headers = 0;

	/* loop until the last page or the end of file */
	do
	{
		ret = decodeOggPage(p_stream, &page_offset);
		if(ret)
			return ret;
		/* if page is corrupted, bad CRC for example, try to find next page by hand
			do this here
		*/
	}while(dec_stat.curr_pos != LAST_PAGE);


	/* Free dynamic allocation memory */
	free(comment_header.vendor_string);
	for(i=0;i<comment_header.user_comment_list_length;i++)
		free(comment_header.comment[i]);

	return ret;
}

int decodeOggPage(unsigned char *data, unsigned int *offset)
{


	unsigned char buff[256];
	unsigned int i;
	int ret;
	char val;			/* temporary char variable */
	unsigned int temp;			/* temporary int variable */

	unsigned char *stream = data + *offset; /* start of the new page */
	unsigned char header_type_flag;
	unsigned int page_number;
	unsigned long page_checksum;
	unsigned int page_serial_number;
	unsigned int page_segments;
	unsigned char lacingTable[256];	/* lacing table for the current page */
	unsigned long page_size;
	unsigned char *page_table;
	unsigned long calculated_checksum;
	unsigned long granule_position;

	/* read capture_pattern */
	strncpy(buff, stream, 4);
	buff[4]='\0';
	if(strcmp(buff, "OggS"))
		return PAGE_NOT_OGG;

	/* read stream_structure_version */
	if(stream[4]!=0x00)
		return PAGE_UNKNOWN_VERSION;

	/* read header_type_flag
	bitflags:
			0x01: unset = fresh packet
	              set = continued packet
			0x02: unset = not first page of logical bitstream
                  set = first page of logical bitstream (bos)
			0x04: unset = not last page of logical bitstream
                  set = last page of logical bitstream (eos
	
	*/
	
	header_type_flag = stream[5];
	if((header_type_flag & 0x01) == 0x01)
	{
	
	}
	if((header_type_flag & 0x02) == 0x02)
	{
		/* here we detect if there is a first page */
		if(dec_stat.curr_pos == NOTHING && dec_stat.prec_pos == NOTHING)
		{
			dec_stat.curr_pos = FIRST_PAGE;
		
		}
		else
			return PAGE_BAD_HEADER_TYPE;				
	
	}
	if((header_type_flag & 0x04) == 0x04)
	{
		dec_stat.curr_pos = LAST_PAGE;
	}


	/* Calculate absolute granule position (bit 6 to 13)
	   limitation here : we calculate with only 4 bytes to save memory
	   extend to 7 bytes if needed (can be stored in a 64 bit register), but no more !
	*/
	granule_position = stream[6]+stream[7]*256+stream[8]*65536+stream[9]*16777216;

	/* read serial number */
	page_serial_number = stream[14]+stream[15]*256+stream[16]*65536+stream[17]*16777216;

	/* read page number (begin at 0) */
	page_number = stream[18]+stream[19]*256+stream[20]*65536+stream[21]*16777216;

	/* read CRC Checksum */
	page_checksum = stream[22]+stream[23]*256+stream[24]*65536+stream[25]*16777216;
	
	/* read number of segments in this page (maxi=256) */
	page_segments = stream[26];
	if(page_segments>256)
		return 10;

	/* now, we read the lancing values */
	i = page_segments;
	temp = 0;
	if(i>0)
	{
		do
		{
			lacingTable[i-1] = stream[26+i];
			temp += stream[26+i]; /* add total sizes, preparation for calculation of page size (see below) */
		}
		while(--i);
	}

	/* Prepare a table with the whole page inside, but with 0000 instead of serial number */
	/* first, calculate the total page size */
	page_size = 27 + page_segments + temp;

	/* then, allocate memory and copy page contents */
	page_table = (unsigned char*)malloc(page_size*sizeof(unsigned char));
	if(page_table == NULL)
		return PAGE_MEM_ALLOC_ERROR;

	/* update offset */
	*offset = *offset + page_size;

	for(i=0;i<page_size;i++)
		page_table[i] = stream[i];

	/* next, fill the original checksum by zeros */
	page_table[22] = 0;
	page_table[23] = 0;
	page_table[24] = 0;
	page_table[25] = 0;

	/* finally, calculate the checksum */
	calculated_checksum = crc_normal(page_table, page_size);

	if(calculated_checksum != page_checksum)
		return PAGE_CHECKSUM_ERROR;

//	printf("page_serial_number = %d\npage_segments = %d\npage_size = %lu\n",page_serial_number,page_segments,page_size);
//	printf("checksum lu : %lu\nChecksum calcule : %lu\n", page_checksum, calculated_checksum);

	/* point to the packet data and decode it */
	ret = decodeOggPacket(stream + 27 + page_segments, lacingTable, page_segments);
	if(ret)
		return ret;

	return 0;
}

int decodeOggPacket(unsigned char *data, unsigned char lacing_table[256], unsigned int segments)
{
	/*	now we are at the beginning of a packet
		we decode all segments
	*/
	unsigned int i, offset;
	int ret;

	for(i=0;i<segments;i++)
	{
		if(i==0)
			offset = 0;
		else
			offset = lacing_table[i-1];
		ret = decodeVorbisSegment(data+offset, lacing_table[i]);
		if(ret)
			return ret;
	}

	return 0;
}

int decodeVorbisSegment(unsigned char *header, int size)
{

	unsigned char buff[256];
	unsigned char *end_adr = header + size;
	unsigned int offset;
	int ret;

	do
	{
		if(dec_stat.vorbis_headers <3)
		{
			/* is there a 'vorbis' string ? */
			strncpy(buff, header+1, 6);
			buff[6]='\0';
			if(!strcmp(buff, "vorbis")) /* yes */
			{
				/* read packet_type */
				if(header[0] == 0x01) /* identification header */
				{
					if(dec_stat.vorbis_headers != 0)
						return VORBIS_HEADER_ERR; /* problem, this header already exists */

					dec_stat.vorbis_headers = 1;

					ret = decodeVorbisIdentHeader(header);
					return ret;
				}
				else if(header[0] == 0x03) /* comment header */
				{
					if(dec_stat.vorbis_headers != 1)
						return VORBIS_COMMENT_ERR; /* problem, this header already exists */

					dec_stat.vorbis_headers = 2;

					ret = decodeVorbisCommentHeader(header);
					if(ret)
						return ret;

				}
				else if(header[0] == 0x05) /* setup header */
				{
					if(dec_stat.vorbis_headers != 2)
						return VORBIS_SETUP_ERR; /* problem, this header already exists */

					dec_stat.vorbis_headers = 3;

					ret = decodeVorbisSetupHeader(header);
					if(ret)
						return ret;
				
				}
				else
					return VORBIS_HEADER_ERR; /* error, no right number found */
			}
		}
		/* normal segment here */
		header++; /* don't do nothing for the moment */

	}
	while(header!=end_adr); /* loop */


	return 0;
}


int decodeVorbisIdentHeader(unsigned char *header)
{
	ident_header.vorbis_version = header[7]+header[8]*256+header[9]*65536+header[10]*16777216;
	ident_header.audio_channels = header[11];
	ident_header.audio_sample_rate = header[12]+header[13]*256+header[14]*65536+header[15]*16777216;
	ident_header.bitrate_maximum = header[16]+header[17]*256+header[18]*65536+header[19]*16777216;
	ident_header.bitrate_nominal = header[20]+header[21]*256+header[22]*65536+header[23]*16777216;
	ident_header.bitrate_minimum = header[24]+header[25]*256+header[26]*65536+header[27]*16777216;
	ident_header.blocksize_0 = 1<<(header[28] >> 4);
	ident_header.blocksize_1 = 1<<(header[28] & 0x0F);
	ident_header.framing_flag = header[29];

	if(ident_header.framing_flag != 0x01)
		return VORBIS_IDENT_FRAM;	/* must be equal to 1 for the identification header */
	
	header = header + 30; /* update pointer */


	printf("Version : %d\nChannels : %d\nSample rate : %d"
			"\nBitrate max : %d\nBitrate nominal : %d\nBitrate min : %d\n"
			"blocksize_0 : %d\nblocksize_1 : %d\nFraming flag : %d\n",
			ident_header.vorbis_version, ident_header.audio_channels, ident_header.audio_sample_rate,
			ident_header.bitrate_maximum,ident_header.bitrate_nominal, ident_header.bitrate_minimum,
			ident_header.blocksize_0, ident_header.blocksize_1, ident_header.framing_flag);


	return 0;
}

int decodeVorbisCommentHeader(unsigned char *header)
{
	int i;
	unsigned int var;
	unsigned char temp;

	comment_header.vendor_length = header[7]+header[8]*256+header[9]*65536+header[10]*16777216;
	comment_header.vendor_string = (char *)malloc(comment_header.vendor_length*sizeof(char)+1);
	if(comment_header.vendor_string == NULL)
		return VORBIS_MEM_ALLOC_ERR;

	strncpy(comment_header.vendor_string, header+11, comment_header.vendor_length);
	comment_header.vendor_string[comment_header.vendor_length]='\0';
	
	header = header + 11 + comment_header.vendor_length; /* update pointer */

	comment_header.user_comment_list_length = header[0]+header[1]*256+header[2]*65536+header[3]*16777216;

	header = header + 4; /* update pointer */

	for(i=0;i<comment_header.user_comment_list_length;i++)
	{
		var = header[0]+header[1]*256+header[2]*65536+header[3]*16777216;
		comment_header.comment[i] = (char *)malloc(var*sizeof(char)+1);
		if(comment_header.comment[i] == NULL)
			return VORBIS_MEM_ALLOC_ERR;

		strncpy(comment_header.comment[i], header+4, var);
		comment_header.comment[i][var] = '\0';
		header = header + 4 + var; /* update pointer */
		
	}
	
	temp = header[0];
	if((temp & 0x01) != 0x01)
		return VORBIS_COMMENT_FRAME;

	printf("vendor_string = %s\n", comment_header.vendor_string);
	for(i=0;i<comment_header.user_comment_list_length;i++)
	{
		printf("%s\n",comment_header.comment[i]);
	}

	return 0;
}

int decodeVorbisSetupHeader(unsigned char *header)
{

	return 0;
}