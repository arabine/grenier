#include <stdio.h>
#include <math.h>

#define MAXX 255
#define MAXY 255
#define MINX 0
#define MINY 0


unsigned char *I;     

#include "PgmManip.c"
#include "Bresenham.c"


typedef struct
{
	int x;
	int y;
	int z;

} Point;

typedef struct
{
	Point p;

} Vecteur;

typedef struct
{
	Point p1;
	Point p2;
	Point p3;
	Point p4;

	Vecteur n;
	unsigned char couleur;

} Facette;


struct Cube
{
	Facette f1;
	Facette f2;
	Facette f3;
	Facette f4;
	Facette f5;
	Facette f6;

} C;



void ColorierFacette(Facette f);

int Clipping(int *Axr, int *Ayr, int *Bxr, int *Byr)
{
	char codeHBDG_A=0;
	char codeHBDG_B=0;
	float m, h;

    
	// calcul du code pour l'extrémité A
	if(*Axr>MAXX)
		codeHBDG_A = codeHBDG_A | 0x02;
	if(*Axr<MINX)
		codeHBDG_A = codeHBDG_A | 0x01;
	if(*Ayr>MAXY)
		codeHBDG_A = codeHBDG_A | 0x08;
	if(*Ayr<MINY)
		codeHBDG_A = codeHBDG_A | 0x04;

	// calcul du code pour l'extrémité B
	if(*Bxr>MAXX)
		codeHBDG_B = codeHBDG_B | 0x02;
	if(*Bxr<MINX)
		codeHBDG_B = codeHBDG_B | 0x01;
	if(*Byr>MAXY)
		codeHBDG_B = codeHBDG_B | 0x08;
	if(*Byr<MINY)
		codeHBDG_B = codeHBDG_B | 0x04;
	
	if( (codeHBDG_A & codeHBDG_B)!=0)
		return 1; // code segment invisible

	if(codeHBDG_A == 0 && codeHBDG_B ==0)
		return 0; // droite totalement visible

    // calcul des nouvelles coordonnees des extremites




	m = (float)(*Byr-(*Ayr))/(float)(*Bxr-(*Axr));	
	h = *Ayr - m*(*Axr);
             
	if(codeHBDG_A == 0x01)
	{
		*Axr=MINX;
		*Ayr=(int)(m*(*Axr)+h);
	}
	else if(codeHBDG_A == 0x02)
	{
		*Axr=MAXX;
		*Ayr=(int)(m*(*Axr)+h);
	}
	else if(codeHBDG_A == 0x04)
 	{
		*Ayr=MINY;
		*Axr=(*Ayr-h)/m;
	}
	else if(codeHBDG_A == 0x08)
	{
		*Ayr=MAXY;
		*Axr=(*Ayr-h)/m;
	}
	else if(codeHBDG_A == 0x09)
	{
		*Axr=MINX;
  		*Ayr=(int)(m*(*Axr)+h);
		if(*Ayr>MAXY)
		{
			*Ayr=MAXY;
			*Axr=(*Ayr-h)/m;
		}
	}
	else if(codeHBDG_A == 0x0A)
	{
    	*Axr=MAXX;
		*Ayr=(int)(m*(*Axr)+h);
		if(*Ayr>MAXY)
		{
			*Ayr=MAXY;
			*Axr=(*Ayr-h)/m;
		}
	}
	else if(codeHBDG_A == 0x06)
	{
    	*Axr=MAXX;
		*Ayr=(int)(m*(*Axr)+h);
		if(*Ayr<MINY)
		{
			*Ayr=MINY;
			*Axr=(*Ayr-h)/m;
        }
	}
	else
	{
		*Axr=MINX;
		*Ayr=(int)(m*(*Axr)+h);
		if(*Ayr<MINY)
		{
			*Ayr=MINY;
			*Axr=(*Ayr-h)/m;
		}		
	}

	// test des limites de l'extrémité B
	if(codeHBDG_B == 0x01)
	{
		*Bxr=MINX;
		*Byr=(int)(m*(*Bxr)+h);
	}
	else if(codeHBDG_B == 0x02)
	{
		*Bxr=MAXX;
		*Byr=(int)(m*(*Bxr)+h);
	}
	else if(codeHBDG_B == 0x04)
 	{
		*Byr=MINY;
		*Bxr=(*Byr-h)/m;
	}
	else if(codeHBDG_B == 0x08)
	{
		*Byr=MAXY;
		*Bxr=(*Byr-h)/m;
	}
	else if(codeHBDG_B == 0x09)
	{
		*Bxr=MINX;
  		*Byr=(int)(m*(*Bxr)+h);
		if(*Byr>MAXY)
		{
			*Byr=MAXY;
			*Bxr=(*Byr-h)/m;
		}
	}
	else if(codeHBDG_B == 0x0A)
	{
    	*Bxr=MAXX;
		*Byr=(int)(m*(*Bxr)+h);
		if(*Byr>MAXY)
		{
			*Byr=MAXY;
			*Bxr=(*Byr-h)/m;
		}
	}
	else if(codeHBDG_B == 0x06)
	{
    	*Bxr=MAXX;
		*Byr=(int)(m*(*Bxr)+h);
		if(*Byr<MINY)
		{
			*Byr=MINY;
			*Bxr=(*Byr-h)/m;
        }
	}
	else
	{
		*Bxr=MINX;
		*Byr=(int)(m*(*Bxr)+h);
		if(*Byr<MINY)
		{
			*Byr=MINY;
			*Bxr=(*Byr-h)/m;
		}		
	}



	return 2;
	
}


int TracerDroite(int x1, int y1, int x2, int y2, unsigned char couleur)
{
	float m, h;
	int i;
	m = (y2-y1)/(x2-x1);	
	h = y1 - m*x1;
    for(i=x1;i<=x2;i++)
	{
		PutPixel(i,(int)(m*i+h),couleur);
  	}

	return 0;
}

int TracerCercle(int x1, int y1, float rayon, unsigned char couleur)
{
	float i;
 
    for(i=x1-rayon;i<=x1+rayon;i++)
	{
		PutPixel(i,(int)(sqrt((double)(rayon*rayon-(i-x1)*(i-x1)))+y1),couleur);
		PutPixel(i,(int)((-1)*sqrt((double)(rayon*rayon-(i-x1)*(i-x1)))+y1),couleur);
  	}

	for(i=y1-rayon;i<=y1+rayon;i++)
	{
		PutPixel((int)(sqrt((double)(rayon*rayon-(i-y1)*(i-y1)))+x1),i,couleur);
		PutPixel((int)((-1)*sqrt((double)(rayon*rayon-(i-y1)*(i-y1)))+x1),i,couleur);
  	}


	return 0;
}

// x0, y0 : coordonnées du coin inférieur gauche
int TracerRectangle(int hauteur, int largeur, int x0, int y0,unsigned char couleur)
{
	Bresenham(x0,y0,x0+largeur,y0,couleur);
	Bresenham(x0+largeur,y0,x0+largeur,y0+hauteur,couleur);
	Bresenham(x0+largeur,y0+hauteur,x0,y0+hauteur,couleur );
	Bresenham(x0,y0+hauteur,x0,y0,couleur);
	return 0;
}

int TracerCarre(int cote, int x0, int y0, unsigned char couleur)
{
    TracerRectangle(cote, cote, x0, y0,couleur);
	return 0;
}

int ChercherGraine(Point P1, Point P2, Point P3, Point P4, int *sx, int *sy)
{
	*sx = (P1.x+P2.x+P3.x+P4.x)/4;
	*sy = (P1.y+P2.y+P3.y+P4.y)/4;

	return 0;
}


int TracerPoly(Facette f1, unsigned char couleur)
{
	Bresenham(f1.p1.x,f1.p1.y,f1.p2.x,f1.p2.y,couleur);
	Bresenham(f1.p2.x,f1.p2.y,f1.p3.x,f1.p3.y,couleur);
	Bresenham(f1.p3.x,f1.p3.y,f1.p4.x,f1.p4.y,couleur);
	Bresenham(f1.p4.x,f1.p4.y,f1.p1.x,f1.p1.y,couleur);
	return 0;
}


void Rempli(Point p, unsigned char couleur)
{
	Point p1,p2,p3,p4;

	if(GetPixel(p.x,p.y)==couleur)
		return;

	PutPixel(p.x,p.y,couleur);

	p1.x = p.x+1;
	p1.y = p.y;

	p2.x = p.x;
	p2.y = p.y-1;

	p3.x = p.x-1;
	p3.y = p.y;

	p4.x = p.x;
	p4.y = p.y+1;

	Rempli(p1, couleur);
	Rempli(p2, couleur);
	Rempli(p3, couleur);
	Rempli(p4, couleur);

}


int Remplissage(int sx, int sy, Facette f1, unsigned char couleur)
{
	int i,j;
    Point centre;

	centre.x=sx;
	centre.y=sy;

	TracerPoly(f1,couleur);

	Rempli(centre,couleur);

	return 0;
}

Vecteur Vectoriel(Point pt1,Point pt2,Point pt3,Point pt4)
{
	Vecteur A, B, res;

	A.p.x = pt1.x - pt2.x;
	A.p.y = pt1.y - pt2.y;
	A.p.z = pt1.z - pt2.z;

   B.p.x = pt2.x - pt4.x;
	B.p.y = pt2.y - pt4.y;
	B.p.z = pt2.z - pt4.z;

	res.p.x = A.p.y*B.p.z - B.p.y*A.p.z;
	res.p.y = B.p.x*A.p.z - A.p.x*B.p.z;
	res.p.z = A.p.x*B.p.y - B.p.x*A.p.y;


   printf("\nvec.p.x = %d",res.p.x);
   printf("\nvec.p.y = %d",res.p.y);
   printf("\nvec.p.z = %d",res.p.z);


	return res;
}

double Scalaire(Vecteur v1, Vecteur v2)
{
	double res;
	res = v1.p.x * v2.p.x +  v1.p.y * v2.p.y + v1.p.z * v2.p.z;
	return res;
}


Point RotateX(Point p0, double teta)
{
	Point p;
	p=p0;

	p.y = cos(teta)*p.y+sin(teta)*p.z;
   	p.z = -sin(teta)*p.y+cos(teta)*p.z;

	return p;
}

Point RotateY(Point p0, double teta)
{
	Point p;
	p=p0;

	p.x = cos(teta)*p.x-sin(teta)*p.z;
   	p.z = sin(teta)*p.x+cos(teta)*p.z;

	return p;
}

Point RotateZ(Point p0, double teta)
{
	Point p;
	p=p0;

	p.x = cos(teta)*p.x+sin(teta)*p.y;
   	p.y = -sin(teta)*p.x+cos(teta)*p.y;

	return p;
}

Point Translate(Point p0, int tx, int ty, int tz)
{
	Point p;
	p=p0;

	p.x = p.x + tx;
   	p.y = p.y + ty;
   	p.z = p.z + tz;

	return p;

}

Point Projection_orthogonale(Point pt)
{
	Point p = pt;

	p = RotateX(p, M_PI*10.0/180.0);
	p = RotateY(p, (-1)*M_PI*35.0/180.0);
	
	p =	Translate(p,100,100,0);
	
	return p;
}

Point Projection_perspective(Point pt, int d)
{
	Point p = pt;
 
	p = RotateX(p, M_PI*10.0/180.0);
	p = RotateY(p, (-1)*M_PI*35.0/180.0);
	p =	Translate(p,0,0,40);
 
	p.x = d*(p.x)/(p.z);
   	p.y = d*(p.y)/(p.z);

	p =	Translate(p,100,100,0);
	return p;
}

void ProjectionPerspectiveCube(int d)
{
	C.f1.p1 = Projection_perspective(C.f1.p1,d);
	C.f4.p4 = C.f1.p1;
	C.f3.p3 = C.f1.p1;

	C.f1.p2 = Projection_perspective(C.f1.p2,d);
	C.f4.p3 = C.f1.p2;
	C.f5.p4 = C.f1.p2;

	C.f1.p3 = Projection_perspective(C.f1.p3,d);
	C.f2.p4 = C.f1.p3;
	C.f5.p3 = C.f1.p3;

	C.f1.p4 = Projection_perspective(C.f1.p4,d);
	C.f2.p3 = C.f1.p4;
	C.f3.p4 = C.f1.p4;

	C.f6.p1 = Projection_perspective(C.f6.p1,d);
	C.f2.p2 = C.f6.p1;
	C.f3.p1 = C.f6.p1;

	C.f6.p2 = Projection_perspective(C.f6.p2,d);
	C.f2.p1 = C.f6.p2;
	C.f5.p2 = C.f6.p2;

	C.f6.p3 = Projection_perspective(C.f6.p3,d);
	C.f4.p2 = C.f6.p3;
	C.f5.p1 = C.f6.p3;

	C.f6.p4 = Projection_perspective(C.f6.p4,d);	
	C.f3.p2 = C.f6.p4;
	C.f4.p1 = C.f6.p4;

}

void ProjectionOrthogonaleCube()
{
	C.f1.p1 = Projection_orthogonale(C.f1.p1);
	C.f4.p4 = C.f1.p1;
	C.f3.p3 = C.f1.p1;

	C.f1.p2 = Projection_orthogonale(C.f1.p2);
	C.f4.p3 = C.f1.p2;
	C.f5.p4 = C.f1.p2;

	C.f1.p3 = Projection_orthogonale(C.f1.p3);
	C.f2.p4 = C.f1.p3;
	C.f5.p3 = C.f1.p3;

	C.f1.p4 = Projection_orthogonale(C.f1.p4);
	C.f2.p3 = C.f1.p4;
	C.f3.p4 = C.f1.p4;

	C.f6.p1 = Projection_orthogonale(C.f6.p1);
	C.f2.p2 = C.f6.p1;
	C.f3.p1 = C.f6.p1;

	C.f6.p2 = Projection_orthogonale(C.f6.p2);
	C.f2.p1 = C.f6.p2;
	C.f5.p2 = C.f6.p2;

	C.f6.p3 = Projection_orthogonale(C.f6.p3);
	C.f4.p2 = C.f6.p3;
	C.f5.p1 = C.f6.p3;

	C.f6.p4 = Projection_orthogonale(C.f6.p4);	
	C.f3.p2 = C.f6.p4;
	C.f4.p1 = C.f6.p4;
}

void AfficherCube(unsigned char couleur)
{
	ColorierFacette(C.f1);
	ColorierFacette(C.f2);
	ColorierFacette(C.f3);
	ColorierFacette(C.f4);
	ColorierFacette(C.f5);
	ColorierFacette(C.f6);


	TracerPoly(C.f1, couleur);
	TracerPoly(C.f2, couleur);
	TracerPoly(C.f3, couleur);
	TracerPoly(C.f4, couleur);
	TracerPoly(C.f5, couleur);
	TracerPoly(C.f6, couleur);
}


void AfficherCubeFacesVisibles(unsigned char couleur)
{
   Vecteur Oeil;
	Oeil.p.x = 5;
 	Oeil.p.y = 5;
	Oeil.p.z = -50;

	if(Scalaire(C.f1.n,Oeil)>0)
   {
		ColorierFacette(C.f1);
   	TracerPoly(C.f1, couleur);
   }

	if(Scalaire(C.f2.n,Oeil)>0)
   {
		ColorierFacette(C.f2);
      TracerPoly(C.f2, couleur);
   }

	if(Scalaire(C.f3.n,Oeil)>0)
   {
		ColorierFacette(C.f3);
      TracerPoly(C.f3, couleur);
    }

	if(Scalaire(C.f4.n,Oeil)>0)
   {
		ColorierFacette(C.f4);
   	TracerPoly(C.f4, couleur);
   }

	if(Scalaire(C.f5.n,Oeil)>0)
   {
		ColorierFacette(C.f5);
		TracerPoly(C.f5, couleur);
    }
    
	if(Scalaire(C.f6.n,Oeil)>0)
   {
		ColorierFacette(C.f6);
      TracerPoly(C.f6, couleur);
    }
}

void CreerCube(int t)
{
	Point pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8;


	/* initialisation : données */
	pt1.x=0; pt1.y=0; pt1.z=0;
	pt2.x=t; pt2.y=0; pt2.z=0;
	pt3.x=t; pt3.y=0; pt3.z=t;
	pt4.x=0; pt4.y=0; pt4.z=t;
	pt5.x=0; pt5.y=t; pt5.z=t;
	pt6.x=0; pt6.y=t; pt6.z=0;
	pt7.x=t; pt7.y=t; pt7.z=0;
	pt8.x=t; pt8.y=t; pt8.z=t;


	/* face 1 du cube : dessous */
	C.f1.p1 = pt1; 
	C.f1.p2 = pt2;	
	C.f1.p3 = pt3; 	
	C.f1.p4 = pt4;
	C.f1.n=Vectoriel(pt1,pt2,pt1,pt4);
	C.f1.couleur = 1;

	/* face 2 du cube : face*/
	C.f2.p1= pt8; 	
	C.f2.p2= pt5;	
	C.f2.p3= pt4;	
	C.f2.p4= pt3;	
	C.f2.n=Vectoriel(pt8,pt5,pt8,pt3);
	C.f2.couleur = 2;

	/* face 3 du cube : coté gauche */
	C.f3.p1= pt5;	
	C.f3.p2= pt6;	
	C.f3.p3= pt1;	
	C.f3.p4= pt4;	
	C.f3.n=Vectoriel(pt5,pt6,pt5,pt4);
	C.f3.couleur = 3;

	/* face 4 du cube : arrière */
	C.f4.p1= pt6;	
	C.f4.p2= pt7;	
	C.f4.p3= pt2;	
	C.f4.p4= pt1;	
	C.f4.n=Vectoriel(pt6,pt7,pt6,pt1);	
	C.f4.couleur = 4;

	/* face 5 du cube : coté droit*/
	C.f5.p1= pt7;	
	C.f5.p2= pt8;	
	C.f5.p3= pt3;	
	C.f5.p4= pt2;	
	C.f5.n=Vectoriel(pt7,pt8,pt7,pt2);
	C.f5.couleur = 5;

	/* face 6 du cube : dessus */
	C.f6.p1= pt5;	
	C.f6.p2= pt8;	
	C.f6.p3= pt7;	
	C.f6.p4= pt6;	
	C.f6.n=Vectoriel(pt5,pt8,pt5,pt6);
	C.f6.couleur = 6;

}

void ColorierFacette(Facette f)
{
	double qte=0.0;
	Vecteur Source;
	int sx,sy;
   unsigned char coul;

	Source.p.x =  8;
 	Source.p.y = 20 ;
	Source.p.z = -50;

	qte = Scalaire(f.n,Source)/(sqrt(Source.p.x*Source.p.x+Source.p.y*Source.p.y + Source.p.z*Source.p.z)*sqrt(f.n.p.x*f.n.p.x+f.n.p.y*f.n.p.y + f.n.p.z*f.n.p.z));

   if(qte<=0.0)
		return;
	else
	{
   	coul= (unsigned char)(qte*255);
      //coul=150;
		ChercherGraine(f.p1,f.p2, f.p3, f.p4, &sx, &sy);
    	Remplissage(sx,sy, f, coul);
      printf("\n couleur = %d \n",coul);

	}
}



int main(void)
{
	int i;
	int x1,y1,x2,y2;
	int focale;
      Vecteur v1,v2;

	Point p1,p2,p3,p4;

	Facette poly;

   	AllouerMemoire();
 //  PutPixel(100,100,255);
	
 //   Bresenham(20,20,100,103,255);
	
//	TracerDroite(20,20,200,154,255);
//	Bresenham(20,20,200,154,128);

 //	TracerCercle(128,128,50,255);
//	TracerRectangle(50,120,20,30,128);
//	TracerCarre(50,120,100,200);
//	i=Clipping(&x1,&y1,&x2,&y2);
//	printf("retour :%d\nx1 : %d\ny1 : %d\nx2 : %d\ny2 : %d\n",i,x1,y1,x2,y2);
//unsigned char GetPixel(int x,int y)
 /*
    p1.x = 50;
	p1.y = 200;

    p2.x = 230;
	p2.y = 180;

    p3.x = 130;
	p3.y = 100;

    p4.x = 20;
	p4.y = 50;

	poly.p1 = p1;
	poly.p2 = p2;
	poly.p3 = p3;
	poly.p4 = p4;

    ChercherGraine(p1,p2,p3,p4,&x1,&y1);
	printf("x1 : %d\ny1 : %d\n",x1,y1);

	Remplissage(x1,y1,poly,255);*/

	focale = 60;

   CreerCube(30);
   // ProjectionPerspectiveCube(focale);
  	ProjectionOrthogonaleCube();
  	AfficherCubeFacesVisibles(255);
   //AfficherCube(255);

   SauvegarderMemoire();

   return 0;
}