#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
 * Types :
 *			1 : P1: PBM ASCII (noir et blanc)
 *			2 :	P2: PGM ASCII (niveaux de gris)
 *			3 :	P3: PPM ASCII (couleurs)
 *			4 :	P4: PBM binary
 *			5 :	P5: PGM binary
 *			6 :	P6: PPM binary
 *
 */

#ifndef CPNMFILE_H
#define CPNMFILE_H

class CpnmFile
{

private:

	// Propriétés de l'image
	int type;
	int w;
	int h;
	unsigned int levels;
	unsigned char *pixel;


public:
	// Constructeurs et destructeurs
	CpnmFile(int magicNumber, int width, int hight, unsigned int levelMax, unsigned char niveauInit);
	~CpnmFile();

	// Mutateurs
	void setSize(unsigned int size);
	void clearImage(unsigned char niveau);

/*
	void ImageFree(IMAGE * I);
	COULEUR *GenererPalette256(unsigned int levelMax);
	unsigned char *PgmRead(char * nom, char *ext, int *w, int *h, int *levels);
	void PgmWrite(IMAGE *I, IMAGE *RES, COULEUR * PAL, char * nom, char *ext, unsigned char overlay);
*/
};

#endif


