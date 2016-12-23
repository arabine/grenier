#include "Image.h"
#include "Ligne.h"
#include "DirLigneAdaptatif.h"



int rectiligne(int rb,int cb, int rf, int cf, char PTS[])
{

	int dr, dc, x, y;
	double a,b,g,L;
	double d, maxd;
	int i,n;
	int taille;
	char f;

	dr = rf - rb;
	dc = cf - cb;
	L = sqrt(dr*dr+dc*dc);
	a = dc / L;
	b = -dr / L;
	g = (rf*cb - rb*cf)/L;


	/* calcul de la distance max à la droite */
		maxd = 0.;
		taille=strlen(PTS);
//		printf("- %s -",PTS);
//		getchar();
	

		x = rb;
		y = cb;
		for (i=0;i<taille;i++)
		{
			f = PTS[i];
			n = atoi(&f); 
			x = x + (n==2)*(-1) + (n==4);
			y = y + (n==3)*(-1) + (n==1);
			
			d = fabs(a * x + b * y + g);
			if (d > maxd)
			{
				maxd = d;
			}

		}
		if (maxd > DISTMAX) return 0;
		else return 1;

	
	
}




/*******************************************************/


void SuiviAdaptatif(IMAGE *I,int l,int c, int x, int y, int porteeCourante, int a, int b, char PTS[],LN *DirLig, int niv)
{
	int d;
	unsigned char na,nb;
	int dx,dy;
	unsigned char passage;
	int w,h;
	char freeman[255];

passage = 0;
w = I->w;
h = I->h;



if (porteeCourante < PORTEEMAX) 

if ( (strlen(PTS)<=2) || (rectiligne(l,c,x,y,PTS)) ) 
{


if (testLimite(y+1,x-1,0,0,w,h))
{
	if (testInf(I->pixel[(x-1)*w+y],I->pixel[x*w+y]))
	{
		na = testMin(testMax(I->pixel[(x-1)*w+y],I->pixel[x*w+y]),a);
		nb = testMax(testMin(I->pixel[x*w+y],I->pixel[(x-1)*w+y]),b);
		
		if (testEniv(na,nb)) 
		{
			if testDistance(l,c,x,y,x,(y+1)) 
			{
				passage = 1;
				strcpy(freeman,PTS); strcat(freeman,"1");
 				SuiviAdaptatif(I,l,c,x,y+1,porteeCourante+1,na,nb,freeman,DirLig,niv+abs(I->pixel[(x-1)*w+y]-I->pixel[x*w+y]));
			}	
		}
	}
}


/* cas 2 */
/* ----- */

if (testLimite(y-1,x-1,0,0,w,h))
{
	if (testInf(I->pixel[(x-1)*w+y-1],I->pixel[(x-1)*w+y])) 
	{
		na = testMin(testMax(I->pixel[(x-1)*w+y-1],I->pixel[(x-1)*w+y]),a);
		nb = testMax(testMin(I->pixel[(x-1)*w+y],I->pixel[(x-1)*w+y-1]),b);

		if (testEniv(na,nb))  
		{
			if testDistance(l,c,x,y,x-1,y) 
			{
				passage = 2;
				strcpy(freeman,PTS); strcat(freeman,"2");
				SuiviAdaptatif(I,l,c,x-1,y,porteeCourante+1,na,nb,freeman,DirLig,niv+abs(I->pixel[(x-1)*w+(y-1)]-I->pixel[(x-1)*w+y]));
			}
		}

	}
}

/* cas 3 */
/* ----- */

if (testLimite(y-1,x-1,0,0,w,h))
{
	if (testInf(I->pixel[x*w+y-1],I->pixel[(x-1)*w+y-1]))
	{
		na = testMin(testMax(I->pixel[(x)*w+y-1],I->pixel[(x-1)*w+(y-1)]),a);
		nb = testMax(testMin(I->pixel[(x-1)*w+y-1],I->pixel[(x)*w+y-1]),b);


		if (testEniv(na,nb))  
		{
			if testDistance(l,c,x,y,x,y-1) 
			{
				passage = 3;
				strcpy(freeman,PTS); strcat(freeman,"3");
 				SuiviAdaptatif(I,l,c,x,y-1,porteeCourante+1,na,nb,freeman,DirLig,niv+abs(I->pixel[(x)*w+y-1]-I->pixel[(x-1)*w+y-1]));
			}
		}
			
	}
}

/* cas 4 */
/* ----- */

if (testLimite(y-1,x+1,0,0,w,h))
{
	if (testInf(I->pixel[x*w+y],I->pixel[x*w+y-1]))
	{
		na = testMin(testMax(I->pixel[x*w+y],I->pixel[x*w+(y-1)]),a);
		nb = testMax(testMin(I->pixel[x*w+y-1],I->pixel[x*w+y]),b);

		if (testEniv(na,nb))  
		{
			if testDistance(l,c,x,y,x+1,y) 
			{
				passage = 4;
				strcpy(freeman,PTS); strcat(freeman,"4");
				SuiviAdaptatif(I,l,c,x+1,y,porteeCourante+1,na,nb,freeman,DirLig,niv +abs(I->pixel[(x)*w+y]-I->pixel[x*w+y-1]));
			}
			
		}

	}
}



}


/* Fin de la trajectoire : calcul des directions */
/*  -------------------------------------------  */


if ((passage == 0)&&(porteeCourante!=0))
{

	if (porteeCourante > PORTEEMIN)
	{
		dx = x - l;
		dy = y - c;
	
	
		d = CalculerDirection(dx,dy,ANGLE,NBDIR);

		if (DirLig[l*w+c].right[d].pas == 0) DirLig[l*w+c].nbDirections +=1;
		DirLig[l*w+c].right[d].x = x;
		DirLig[l*w+c].right[d].y = y;
		DirLig[l*w+c].right[d].a = a;
		DirLig[l*w+c].right[d].b = b;
		DirLig[l*w+c].right[d].pas = porteeCourante; 
		DirLig[l*w+c].right[d].diffNiv = niv/porteeCourante;
	}



}


}


/***********************************************************************/

void CalculerDirLigAdaptatif(IMAGE *I, LN *DirLig)
{

	int x,y;
	int w,h;
	int i,k,j;
	int d,res;

	LN *DirLigTmp;

	h = I->h;
	w = I->w;


	DirLigTmp = AllouerDirLig(w,h);
	ClearDirLig(DirLigTmp,w,h);

	ClearDirLig(DirLig,w,h);

	/* suivi droit */
	/* *********** */

	for (x=1;x<h-1;x++)
		for (y=1;y<w-1;y++)
		{
				if  (
					(testInf(I->pixel[(x-1)*w+y],I->pixel[x*w+y])) || 
					(testInf(I->pixel[x*w+y],I->pixel[x*w+(y-1)])) ||
					(testInf(I->pixel[x*w+(y-1)],I->pixel[(x-1)*w+(y-1)])) || 
					(testInf(I->pixel[(x-1)*w+(y-1)],I->pixel[(x-1)*w+y])) ) 
					{
						SuiviAdaptatif(I,x,y,x,y,0,255,0,"",DirLigTmp,0);
						
					}
		}


	

	/* Suppression des redondances */
	/* *************************** */

	for (x=1;x<h-1;x++)
		for (y=1;y<w-1;y++)
		{
			DirLig[x*w+y].nbDirections = DirLigTmp[x*w+y].nbDirections;

			for (i=0;i<NBDIR;i++)
			{
				d = DirLigTmp[x*w+y].right[i].pas;
					
				if (d!=0)
				{
					res = 1;
					for(k=-1;k<=1;k++)
						for (j=-1;j<=1;j++)
						{
							if (((k!=0)||(j!=0)) && (DirLigTmp[(x+k)*w+(y+j)].right[i].pas != 0))
								res = res * ((d+1) != DirLigTmp[(x+k)*w+(y+j)].right[i].pas);
						}
					
					if (res!=0)
						DirLig[x*w+y].right[i] = DirLigTmp[x*w+y].right[i];
						
					else DirLig[x*w+y].nbDirections = DirLig[x*w+y].nbDirections - 1;
					
				}
			}
		}


	FreeDirLig(DirLigTmp,w,h);


}








