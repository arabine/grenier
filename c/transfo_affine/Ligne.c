#include "Image.h"
#include "Ligne.h"
#include "droite.h"


/****************************************************************/

LN *AllouerDirLig(int w, int h)
{

	LN *DirLig;
	int l,c;

	DirLig = (LN *)malloc(w*h*sizeof(LN));
	if(!(DirLig))
		{printf("erreur d'allocation memoire Allouer DirLig");exit(0);}

	for (l=0;l<h;l++)
		for (c=0;c<w;c++)
		{
		
			DirLig[l*w+c].right = (DIR *)malloc(NBDIR*sizeof(DIR));
			if(!(DirLig[l*w+c].right))
			{printf("erreur d'allocation memoire Allouer Dr");exit(0);}
		}

		

	return DirLig;

}


/****************************************************************/

void FreeDirLig(LN *DirLig, int w, int h)
{
	int l,c;

	if (DirLig != NULL) 
	{
		for (l=0;l<h;l++)
			for (c=0;c<w;c++)
			{
				if (DirLig[l*w+c].right) free(DirLig[l*w+c].right);
				DirLig[l*w+c].right = NULL;
			}
		free(DirLig);
		DirLig = NULL;
	}
}


/****************************************************************/



void ClearDirLig(LN *DirLig, int w, int h)
{
	int l,c,i;
	
	for (l=0;l<h;l++)
		for (c=0;c<w;c++)
		{

			DirLig[l*w+c].nbDirections = 0;
			for (i=0;i<NBDIR;i++)
			{
				DirLig[l*w+c].right[i].x = l;
				DirLig[l*w+c].right[i].y = c;
				DirLig[l*w+c].right[i].pas = 0;
				DirLig[l*w+c].right[i].diffNiv = 0;
				DirLig[l*w+c].right[i].a = 0;
				DirLig[l*w+c].right[i].b = 0;
			}


			
		}

	return;
}


/****************************************************************/

int CalculerDirection(int dx, int dy, double angle, int nbDir)
{

	double dir,dir2;
	unsigned char d;

	if (dx==0)
	{
		if (dy>=0) dir = PI/2.;
		else dir = -PI/2.;
	}
	else
	{
		dir = atan((double)dy/(double)dx);
		if (dx<0)
		{
			if (dy>0) dir = dir + PI;
			else dir = dir - PI;
		}

		
	}

	dir2 = fabs(dir/angle);
	if (dir2!=0) d = (unsigned char)((int)(dir2+0.5));
	else d=0;

	if (dir < 0.) d= (unsigned char)(nbDir - (int)d);
	
	if (d==nbDir) d=0;
	
	return (d);



}

/****************************************************************/

void SauverDirLig(IMAGE *I0, COULEUR * PAL, const char *rep,const char *base,int numFich, LN *DirLig)
{
	int l,c,i;
//	int nb;
	char nom[80];
	int w,h;
	IMAGE *R1=NULL,*R2=NULL;
	

	w = I0->w;
	h = I0->h;

	
	R1=ImageAllocInit(w,h,I0->levels,0);
	R2=ImageAllocInit(w,h,I0->levels,0);


/* les directions */

/*
	for (i=0;i<NBDIR;i++)
	{

		for (l=0;l<h;l++)
			for (c=0;c<w;c++)
				R1->pixel[l*w+c] = (unsigned char)DirLig[l*w+c].right[i].pas;

  		sprintf(nom,"%s%s%d%s%d%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".r",i,EXTIN);
		PgmWrite(I0,R1,PAL,nom,EXTIN,0);


	}
*/

/* diffniv */

/*
	for (i=0;i<NBDIR;i++)
	{

		for (l=0;l<h;l++)
			for (c=0;c<w;c++)
				R1->pixel[l*w+c] = (unsigned char)DirLig[l*w+c].right[i].diffNiv;

		sprintf(nom,"%s%s%d%s%d%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".r",diffNiv,EXTIN);
		PgmWrite(I0,R1,PAL,nom,EXTIN,0);


	}
*/



/* nbparticulier */

/*	ImageClear(R1,0);

	for (l=0;l<h;l++)
		for (c=0;c<w;c++)
			R1->pixel[l*w+c] = (unsigned char) DirLig[l*w+c].particulier;
	
	sprintf(nom,"%s%s%d%s%d%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".particulier",NBDIR,EXTIN);
	PgmWrite(I0,R1,PAL,nom,EXTIN,0);

*/


/* nbDirections */



	for (l=0;l<h;l++)
		for (c=0;c<w;c++)
			R2->pixel[l*w+c] = (unsigned char) (DirLig[l*w+c].nbDirections!=0)*255;
	
	sprintf(nom,"%s%s%d%s%d%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".nbDirections",NBDIR,EXTIN);
	PgmWrite(I0,R2,PAL,nom,EXTIN,0);




/* longueur */

	ImageClear(R1,0);

	for (l=0;l<h;l++)
		for (c=0;c<w;c++)
			for (i=0;i<NBDIR;i++)
			{
				if (DirLig[l*w+c].right[i].pas != 0)
					R1->pixel[l*w+c] = (unsigned char)DirLig[l*w+c].right[i].pas;
			}

	sprintf(nom,"%s%s%d%s%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".longueur",EXTIN);
	PgmWrite(I0,R1,PAL,nom,EXTIN,0);




/* contraste */

ImageClear(R1,0);

		for (l=0;l<h;l++)
			for (c=0;c<w;c++)
					for (i=0;i<NBDIR;i++)
					{
						if (DirLig[l*w+c].right[i].pas != 0)
							R1->pixel[l*w+c] = (unsigned char)DirLig[l*w+c].right[i].diffNiv;
	
					}


sprintf(nom,"%s%s%d%s%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".constraste",EXTIN);
PgmWrite(I0,R1,PAL,nom,EXTIN,0);


/* teta */

ImageClear(R2,0);

	for (l=0;l<h;l++)
		for (c=0;c<w;c++)
			for (i=0;i<NBDIR;i++)
			{
				if (DirLig[l*w+c].right[i].pas != 0)
			
				R2->pixel[l*w+c] = (unsigned char) i;
			}

	sprintf(nom,"%s%s%d%s%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".teta",EXTIN);
	PgmWrite(R2,R2,PAL,nom,EXTOUT,1);


/* reconstitution ligne */


ImageClear(R1,0);

	for (l=0;l<h;l++)
		for (c=0;c<w;c++)
			for (i=0;i<NBDIR;i++)
			{
				if (DirLig[l*w+c].right[i].pas != 0)
				{
					Bresenham(R1, l,c,DirLig[l*w+c].right[i].x,DirLig[l*w+c].right[i].y,(unsigned char)i,w,h);
					
				}
			}
	
		sprintf(nom,"%s%s%d%s%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".bresenham",EXTIN);
		PgmWrite(R1,R1,PAL,nom,EXTOUT,1);



/* affichage ligne par ligne */



/*

nb = 0;
	for (l=0;l<h;l++)
		for (c=0;c<w;c++)

			if (DirLig[l*w+c].nbDirections != 0)
			{
			for (i=0;i<NBDIR;i++)
			{

				if (DirLig[l*w+c].right[i].pas != 0)
				{
					nb++;
					ImageClear(R1,0);
					Bresenham(R1, l,c,DirLig[l*w+c].right[i].x,DirLig[l*w+c].right[i].y,(unsigned char)i,w,h);
					sprintf(nom,"%s%s%d%s%d%s",NOMREPOUT,NOMFICHOUT,NFICHDEB,".bresenham",nb,EXTIN);
					PgmWrite(R1,R1,PAL,nom,EXTOUT,1);
			
				}
			}
			}
		
*/





ImageFree(R1);
ImageFree(R2);

		



return;

}

