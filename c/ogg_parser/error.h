/** 
 *	Error codes are defined here 
 *	
 */

/* Error codes about bad header */

#ifndef ERROR_H
#define ERROR_H

#define PAGE_NOT_OGG			1	/* Can't find Ogg string */
#define PAGE_UNKNOWN_VERSION	2	/* Not a Ogg version 0 */
#define PAGE_BAD_HEADER_TYPE	3	/* Problem with page flow */

#define PAGE_MEM_ALLOC_ERROR	5	/* Memory allocation error */
#define PAGE_CHECKSUM_ERROR		6	/* Error in page checksum == bad Ogg file */

#define VORBIS_IDENT_ERR		10	/* problem of vorbis indent header */
#define VORBIS_COMMENT_ERR		11	/* problem of vorbis comment header */
#define VORBIS_SETUP_ERR		12	/* problem of vorbis comment header */
#define VORBIS_HEADER_ERR		13	/* unknown header number */
#define VORBIS_IDENT_FRAM		14	/* no right frame in identification header */
#define	VORBIS_MEM_ALLOC_ERR	15	/* Memory allocation error */
#define VORBIS_COMMENT_FRAME	16	/* no right frame in comment header */

#endif	// ERROR_H