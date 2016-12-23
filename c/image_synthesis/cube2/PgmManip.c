#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*********************************************************
Fonctions :	
	- Allocation mémoire pour le viewPort (image .pgm)
	- Ecriture d'un point dans le viewPort
	- Lecture d'un point dans le viewPort
	
*********************************************************/



void AllouerMemoire(){
	int i;

	I = (unsigned char *) malloc (MAXX * MAXY * sizeof(unsigned char));
	for (i=0;i<MAXX*MAXY;i++)
			I[i]=0;

	}

/******************************************************/

void PutPixel(int x,int y,unsigned char couleur){
	I[y*MAXX+x] = couleur;
}

/******************************************************/

unsigned char GetPixel(int x,int y){
	unsigned char couleur;

	couleur = I[y*MAXX+x];
	return couleur;
}

/******************************************************/

void SauvegarderMemoire(){
	FILE *fp;
	int i,j;
	fp = fopen("viewport.pgm","w");
	fprintf(fp,"P5\n#\n%d %d\n255\n",MAXX,MAXY);
	for (i=MAXX*MAXY-MAXX;i>=0;i-=MAXX)
		for (j=0;j<MAXX;j++)
			fputc(I[i+j],fp);
	fclose(fp);
}


/******************************************************/

