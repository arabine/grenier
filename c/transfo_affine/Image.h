#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>




/* informations concernant le stockage et la lecture des fichiers images */


#define NOMREPIN ""
#define NOMFICHIN "lena"
#define NOMFICHOUT "lena"

#define NOMREPOUT ""
#define EXTIN ".pgm"
#define EXTOUT ".pnm"

#define NFICHDEB 1
#define NFICHFIN 2


/* Structure utilisée pour la sauvegarde des images */

typedef struct
{
	int w;
	int h;
	unsigned int levels;
	unsigned char *pixel;

} IMAGE;




typedef struct 
{
	unsigned char rouge;
	unsigned char vert;
	unsigned char bleu;
} COULEUR;




void ImageClear(IMAGE * I,unsigned char niveau);
IMAGE *ImageAllocInit(int w, int h, unsigned int levelMax, unsigned char niveau);
void ImageFree(IMAGE * I);
COULEUR *GenererPalette256(unsigned int levelMax);
unsigned char *PgmRead(char * nom, char *ext, int *w, int *h, int *levels);
void PgmWrite(IMAGE *I, IMAGE *RES, COULEUR * PAL, char * nom, char *ext, unsigned char overlay);

