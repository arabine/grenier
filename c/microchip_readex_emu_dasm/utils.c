/**
 *
 * Quelques fonctions à but géénral
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "utils.h"

/**
 * Retourne une partie d'une chaine délimitée par deux positions
 */
char *mid(char *chaine, int debut, int fin)
{
	int taille;
	char *buf;
	int i;
	
	taille = fin-debut+1;
	
	if(taille<=0 || taille>=strlen(chaine))
	{
		printf("\nAppel non valide.\n");
		return NULL;
	}
	
	buf = (char *)calloc(taille+1,sizeof(char));
	
	for(i=0;i<taille;i++)
		buf[i] = chaine[debut+i];
	buf[taille]='\0';	// on termine la chaine de caractères
	return buf;
}

/**
 * Convertit une chaine de caractères hexadécimaux en valeur entière
 */
unsigned long int HexToInt(char *string)
{
	int i,j;
	unsigned long int val=0;
	char a;
	
	j = strlen(string)-1;
	for(i=0;i<strlen(string);i++)
	{
		a = asciiToHex(string[i]);
		val = val + a*pow(16,j);
		j--;
	}
	return val;
}

/**
 * Convertit un caractère ASCII en valeur hexadécimale
 */
char asciiToHex(char c)
{
	if(c<58 && c >47)
		return c-48;
	else if(c<71 && c>64)
			return c-55;
		else if(c<103 && c>96)
				return c-87;
			else
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
