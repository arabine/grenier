/**
 * Groar - groar.h
 * All Groar functions are declared here
 */

#ifndef GROAR_H
#define GROAR_H

/**
 * Aliases
 */

#define MODEL
#define OGG_VERSION "Xiph.Org libVorbis I 20020717"
#define INIT 0		/* for checksum calculation */
#define XOROT 0		/* for checksum calculation */

/**
 * Includes
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>

#include "error.h"


/**
 * typedef
 */

enum Position {NOTHING, NEW_PAGE, FIRST_PAGE ,LAST_PAGE};
typedef enum pos Position;

/**
 * Structures
 */



struct struct_ident_header
{
	unsigned int	vorbis_version;
	unsigned int	audio_channels;
	unsigned int	audio_sample_rate;
	signed int		bitrate_maximum;
	signed int		bitrate_nominal;
	signed int		bitrate_minimum;
	unsigned int	blocksize_0;
	unsigned int	blocksize_1;
	unsigned char	framing_flag;

} ident_header;


struct struct_comment_header
{
	unsigned int	vendor_length;
	char			*vendor_string;
	unsigned int	user_comment_list_length;
	unsigned char	*comment[256];

} comment_header;

/**
 * This structure store general variables
 * to control decode flow and well formed ogg format
 */
struct decode_status
{
	Position curr_pos, prec_pos; /* to control Ogg pages */
	int vorbis_headers; /* count number of vorbis headers (= 3) */

} dec_stat;


/**
 * prototypes
 */

/* in utils.c */
unsigned long crc_normal(unsigned char *blk_adr, unsigned long blk_len);

/* in io.c */
void printError(char *errorMsg);
unsigned char *openOggFile(char *fileName);
#ifdef MODEL
long int filesize(FILE *stream);
#endif

/* in groar.c */
int groar(unsigned char *ptr_data);
int decodeOggPage(unsigned char *data, unsigned int *offset);
int decodeVorbisIdentHeader(unsigned char *header);
int decodeVorbisCommentHeader(unsigned char *header);
int decodeVorbisSetupHeader(unsigned char *header);
int decodeVorbisSegment(unsigned char *header, int size);


#endif /* GROAR_H */