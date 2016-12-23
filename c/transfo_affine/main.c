
#include "Image.h"
#include "Ligne.h"
#include "DirLigneAdaptatif.h"
#include "Tueur.h"






int main()
{
		
	clock_t start,end;
	int w,h,levels;
	unsigned char *im;
	char nom[80];	

	IMAGE *I;
	COULEUR *PAL;
	LN *DirLig;

	

	/* Acquisitions */
	/* ------------ */


	sprintf(nom,"%s%s%d%s",NOMREPIN,NOMFICHIN,NFICHDEB,EXTIN);
	im = PgmRead(nom,EXTIN,&w,&h,&levels);


	I = ImageAllocInit(w,h,levels,0);
	I->pixel = im;
	I->h = h;
	I->w = w;

	
	/* Construction palette de couleur */
	/* ------------------------------- */

	PAL = GenererPalette256(I->levels);

	
		

	/* Préparations et initialisations  */
	/* -------------------------------  */

	Kext(5,8,I,I);
	
	sprintf(nom,"%s%s%d%s%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".tueur",EXTIN);
	PgmWrite(I,I,PAL,nom,EXTOUT,0);
	

	/* Détection de lignes de niveaux */
	/* ------------------------------ */

	DirLig = AllouerDirLig(w,h);

	start = clock();
	CalculerDirLigAdaptatif(I,DirLig);
	end = clock(); 
	printf("- Temps suivi en millisec : %ld\n",(end - start) );
	
	SauverDirLig(I,PAL,NOMREPOUT,NOMFICHOUT,NFICHDEB,DirLig);	


	/* libération de la mémoire */
	/* ------------------------ */


	ImageFree(I);

	if (PAL!=NULL) free(PAL);
	FreeDirLig(DirLig,w,h);



	return 0;

}