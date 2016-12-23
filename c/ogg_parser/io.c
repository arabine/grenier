/**
 * Groar - io.c
 * General input/output functions
 *
 * Note :
 *
 *  You will probably need to reimplement several functions 
 *  to target exactly for your system
 */


/**
 * Open ogg file from memory
 * Input :
 * Output :
 *			return 0 if everything's Ok
 *			else return error code
 */

#include "groar.h"


unsigned char *openOggFile(char *fileName)
{
#ifdef MODEL

	FILE *fp;
	unsigned char *buff;
	int taille, ret;

	fp = fopen(fileName, "rb");
	taille = filesize(fp);
	buff = (unsigned char *)malloc(taille*sizeof(unsigned char));
	if(buff == NULL)
	{
		printf("!!! Error : Can't allocate memory.\n");
		fclose(fp);
		return buff;
	}

	ret = fread(buff, sizeof(unsigned char), taille, fp);
	if(ret != taille)
	{
		printf("!!! Error : Can't read file.\n");
		fclose(fp);
		return buff;
	}

	fclose(fp);
	return buff;

#else


#endif
}

void printError(char *errorMsg)
{

#ifdef MODEL
	fprintf(stderr, errorMsg);
	exit(1);
#else

#endif

}

#ifdef MODEL
/**
 * Retourne la taille du fichier en octets
 */
long int filesize(FILE *stream)
{
	long curpos,length;

	curpos = ftell(stream); /* garder la position courante */
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek (stream, curpos, SEEK_SET); /* restituer la position */
	
	return length;
}

#endif
