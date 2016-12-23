#include "utils.h"


/**
 * Retourne :	0 si bien passé
 *				1 en cas d'erreur
 */
int mid(unsigned char *in, int taille, int debut, int fin, unsigned char *out)
{
	int i, ecart;

	ecart = fin-debut;
	if(taille<=0 || ecart>=taille || ecart<=0)
		return(1);
	
	for(i=0;i<=ecart;i++)
		out[i] = in[debut+i];
	out[ecart+1]='\0';	// on termine la chaine de caractères
	
	return 0;
}

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
