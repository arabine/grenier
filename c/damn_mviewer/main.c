#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

long filesize(FILE *stream);

int main(void)
{
	FILE *in;
	unsigned long int taille;
	char c;
	int rep, car;

	printf("Recherche de M-Viewer...\n");
	
	in = fopen("MViewer3.exe","r+");

	if(in==NULL)
	{
		printf("Impossible de trouver M-Viewer.\n");
		exit(0);
	}
	
	printf("Fichier trouve.\n");

	taille = filesize(in);

	printf("Test de la taille... %d octets\n",taille);
	
	if(taille!=5278720)
	{
		printf("Taille de fichier incorrecte.\n");
		exit(0);	
	}

	fseek(in, 0x2DFFB8,0);
	c = fgetc(in);
	if(c!=117)
	{
		printf("Impossible d'appliquer le patch.\n");
		exit(0);
	}

	printf("Application du patch...\n");

	fseek(in, 0x2DFFB8,0);

	car = 116;
	rep = putc(car,in);

	if(rep==EOF)
	{
		printf("Impossible d'appliquer le patch.\n");
		exit(0);
	}
	
	fseek(in, 0x2DFFB8,0);

	c = fgetc(in);
	if(c==116)
	{
		printf("Patch applique avec succes.\n");		
	}
	else
	{
		printf("Echec de l'application du patch.\n");
	}

	fclose(in);

	return 0;

}


long filesize(FILE *stream)
{
	/* Renvoie la position du dernier octets du flot stream */

	long curpos,length;

	curpos = ftell(stream); /* garder la position courante */
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek (stream, curpos, SEEK_SET); /* restituer la position */
	return length;
}
