#include "Image.h"
#include "Ligne.h"
#include "droite.h"


/*********************************************************************************************/


void TransfoAffineInversePoint(int xp,int yp, int *x, int *y,int dx, int dy, int angle, double scale)
{

	double xf,yf;
	double teta;
	

	teta = (double)angle * PI / 180.;

	yf = (cos(teta) * (double)(yp - dy)/scale) -
 		 (sin(teta) * (double)(xp - dx)/scale);

	*y = (int)yf;

	xf = ((double)xp - (double)dx + scale * sin(teta) * yf) / (scale * cos(teta));

	*x = (int)xf;

	
}

/*************************************************************/

void TransfoAffinePoint(int x,int y, int *xp, int *yp,int dx, int dy, int angle, double scale)
{

	double xf,yf;
	double teta;
	

	teta = (double)angle * PI / 180.;

	xf = (double)x;
	yf = (double)y;

	
	*xp = (int) (scale * cos(teta)*xf + scale * sin(teta) *yf + (double)dx);
	*yp = (int) (scale * cos(teta)*yf - scale * sin(teta) *xf + (double)dy);

	
}



/*************************************************************/
/* Appliquer une tranfo affine à une image : 
	
	  - Rotation
	  - Translation
	  - Echelle

************************************************************/



void TransfoAffineInverse(int zx,int zy,IMAGE *I0,IMAGE *I1, IMAGE *I2, int dx, int dy, int angle, double scale)
{

	int w,h,x,y,xp,yp;
	double xf,yf;
	double teta;

	w = I1->w;
	h = I1->h;



	teta = (double)angle * PI / 180.;

	for (xp=0;xp<h;xp++)
		for (yp=0;yp<w;yp++)
		{

			yf = (cos(teta) * (double)(yp - dy)/scale) -
 				 (sin(teta) * (double)(xp - dx)/scale);

			y = (int)yf;

			xf = ((double)xp - (double)dx + scale * sin(teta) * yf) / (scale * cos(teta));

			x = (int)xf;

			if ((x>=0)&&(x<h)&&(y>=0)&&(y<w))
				I2->pixel[xp*w+yp] = I1->pixel[x*w+y];

			else if (I0!=NULL)
			{
				if (((zx+x)>=0)&&((zx+x)<I0->h)&&((zy+y)>=0)&&((zy+y)<I0->w))
					I2->pixel[xp*w+yp] = I0->pixel[(x+zx)*(I0->w)+y+zy];	
			}
			else I2->pixel[xp*w+yp] = 0;
			
		}



	


}

/**********************************************************************/
/* Estimer une tranfo de similarité à partir d'un couple de correspondants  */
/**********************************************************************/


void EstimerTransfoAffine(int i1, int j1, int i2, int j2, int i1p, int j1p, int i2p, int j2p,int *dx, int *dy, int *angle, double *scale)
{

	double x1,y1,x2,y2,x1p,y1p,x2p,y2p;
	double teta;
	double U, V, Z, T;


	x1 = (double)i1;
	y1 = (double)j1;
	x2 = (double)i2;
	y2 = (double)j2;
	x1p = (double)i1p;
	y1p = (double)j1p;
	x2p = (double)i2p;
	y2p = (double)j2p;



	V = ((x2p - x1p)*(y2 - y1) - (y2p - y1p)*(x2 - x1)) / 
		(-(x2 - x1)*(x2 - x1) - (y2 - y1)*(y2 - y1));

	U = ((x2p - x1p) - V*(y1 - y2)) / (x2 - x1);

	Z = x2p - U*x2 + V*y2;

	T = y2p - V*x2 - U*y2;

	if (U!=0.) teta = atan2(V,U);
	else if (V>0.) teta = PI/2.;
	else teta = -PI/2.;

	*angle = (int) (teta * 180. / PI);
	
	if (sin(teta) != 0.) *scale = V/sin(teta);
	else if (cos(teta)!=0) *scale=U/cos(teta);

	*dx = (int)Z;
	*dy = (int)T;


    //printf("%d %d %d %lf",*dx,*dy,*angle,*scale);getchar();

}



/*************************************************************/

void VerifierTransfo()
{

int x1,y1,x2,y2,x1p,y1p,x2p,y2p;
int dx, dy,angle;
double scale;



for (x1p= 0;x1p<128;x1p++)
 for (y1p=0;y1p<128;y1p++)
	 for (x2p=255;x2p>128;x2p--)
		 for (y2p=255;y2p>128;y2p--)
		 {

			dx = -2;
			dy = 70;
			angle =-30;
			scale = .3;

			 
			TransfoAffineInversePoint(x1p,y1p,&x1,&y1,dx,dy,angle,scale);
			TransfoAffineInversePoint(x2p,y2p,&x2,&y2,dx,dy,angle,scale);

			printf("%d %d %d %d\n",x1p,y1p,x2p,y2p);
			printf("%d %d %d %d\n",x1,y1,x2,y2);
			printf("avant : %d %d %d %lf\n",dx,dy,angle,scale);
			

			EstimerTransfoAffine(x1,y1,x2,y2,x1p,y1p,x2p,y2p,&dx,&dy,&angle,&scale);

			printf("apres : %d %d %d %lf\n",dx,dy,angle,scale);
			getchar();

		 }

}


/*************************************************************/


void Copie(IMAGE *R, int io, int jo, IMAGE *I)
{

	int x,y;
	int w,h;
	int wr = R->w;

	w = I->w;
	h = I->h;

	for (x=0;x<h;x++)
		for (y=0;y<w;y++)
		{
			/*R->pixel[(x+io)*wr+(y+jo)] = I->pixel[x*w+y];*/

			if (R->pixel[(x+io)*wr+(y+jo)]==0) R->pixel[(x+io)*wr+(y+jo)] = I->pixel[x*w+y];
			else R->pixel[(x+io)*wr+(y+jo)] = (R->pixel[(x+io)*wr+(y+jo)] + I->pixel[x*w+y])/2;
			
		}


}


/************************************************************************************/

int maxi (int a, int b, int c, int d, int e)
{
	int max = 0;

	if (a>max) max=a;
	if (b>max) max=b;
	if (c>max) max=c;
	if (d>max) max=d;
	if (e>max) max=e;

	return max;
}

/************************************************************************************/

int mini (int a, int b, int c, int d, int e)
{
	int min = 1000000;

	if (a<min) min=a;
	if (b<min) min=b;
	if (c<min) min=c;
	if (d<min) min=d;
	if (e<min) min=e;

	return min;
}

/************************************************************************************/


IMAGE *RaccordAffine(int dx, int dy,int angle, double scale, IMAGE *I, IMAGE *J, COULEUR *PAL, int cptImage)
{

	int w,h;
	IMAGE *R=NULL;
	int wr,hr;
	int x,y, xp, yp, dw, dh;
	int xo,yo,xf,yf,xof,yof,xfo,yfo;

	w = I->w;
	h = I->h;



	TransfoAffinePoint(0,0,&xo,&yo,dx,dy,angle,scale);
	TransfoAffinePoint(h-1,w-1,&xf,&yf,dx,dy,angle,scale);
	TransfoAffinePoint(0,w-1,&xof,&yof,dx,dy,angle,scale);
	TransfoAffinePoint(h-1,0,&xfo,&yfo,dx,dy,angle,scale);


	wr = abs(maxi(w,yo,yf,yof,yfo)) + abs(mini(0,yo,yf,yof,yfo));
	hr = abs(maxi(h,xo,xf,xof,xfo)) + abs(mini(0,xo,xf,xof,xfo));


	dw = mini(0,yo,yf,yof,yfo);
	dh = mini(0,xo,xf,xof,xfo);


	R=ImageAllocInit(wr,hr,255,0);


	/* on vient mettre I */

	for (x=0;x<hr;x++)
		for (y=0;y<wr;y++)
		{	
			TransfoAffineInversePoint(x+dh,y+dw,&xp,&yp,dx,dy,angle,scale);
			if ((xp>0)&&(xp<h)&&(yp>0)&&(yp<w))
				R->pixel[x*wr+y] = I->pixel[xp*w+yp];
		
		}

	/* on vient mettre J */

	for (x=abs(dh);x<(abs(dh)+h);x++)
		for (y=abs(dw);y<(abs(dw)+w);y++)
		{	
			xp = x - abs(dh);
			yp = y - abs(dw);

			if ((xp>0)&&(xp<h)&&(yp>0)&&(yp<w))
			
				R->pixel[x*wr+y] = J->pixel[xp*w+yp];
			
		}


	return R;


}











