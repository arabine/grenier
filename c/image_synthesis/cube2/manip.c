#include <stdio.h>
#include <math.h>

#define MAXX 255
#define MAXY 255
#define MINX 0
#define MINY 0

unsigned char *I;     

#include "PgmManip.c"

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

   Vecteur sommet1;
   Vecteur sommet2;
   Vecteur sommet3;
   Vecteur sommet4;

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

// tableau stockant les pixels constituant les arrêtes         
int tab_x[500];
int tab_y[500];
int nb=0;


void Bresenham(int x1, int y1, int x2, int y2, unsigned char couleur1,unsigned char couleur2)
{
int c,dx,dy;
int x,y;
int couleur;

int incx, incy,i;
                   
dx = abs(x2-x1);
dy = abs(y2-y1);

if (y2>y1) incy = 1;
else incy = -1;

if (x2>x1) incx = 1;
else incx = -1;

x = x1;
y = y1;


/* direction en x preponderante */
if (dx > dy) {

	c = 2*dy - dx;
	for (i=0;i<dx;i++) {

   	couleur = couleur1 + (couleur2-couleur1) * sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)) / sqrt(dy*dy + dx*dx);
      tab_x[nb] = x;
      tab_y[nb] = y;
     // printf("\nx = %d,    y = %d,  nb = %d, couleur = %d, couleur1 = %d,  couleur = %d",tab_x[nb],tab_y[nb],nb,couleur, couleur1,couleur);
      nb++;

		PutPixel(x,y,couleur);
		x=x+incx;
		if (c<0) c = c + 2*dy;
		else {
			y = y+incy;
			c = c + 2*dy - 2*dx;
		}
	}
}

/* direction en y preponderante */
else {
	c = 2*dx - dy;
	for (i=0;i<dy;i++) {

		couleur = couleur1 + (couleur2-couleur1) * sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)) / sqrt(dy*dy + dx*dx);
      tab_x[nb] = x;
      tab_y[nb] = y;
     // printf("\nx = %d,    y = %d,  nb = %d, couleur = %d, couleur1 = %d,  couleur = %d",x,y,nb,couleur, couleur1,couleur);
      nb++;

		PutPixel(x,y,couleur);
		y=y+incy;
		if (c<0) c = c + 2*dx;
		else {
			x = x+incx;
			c = c + 2*dx - 2*dy;
		}
	}
}

}


TracerPoly(Facette f1, unsigned char couleur1, unsigned char couleur2, unsigned char couleur3, unsigned char couleur4)
{
   nb = 0;
	Bresenham(f1.p1.x,f1.p1.y,f1.p2.x,f1.p2.y,couleur1,couleur2);
	Bresenham(f1.p2.x,f1.p2.y,f1.p3.x,f1.p3.y,couleur2,couleur3);
	Bresenham(f1.p3.x,f1.p3.y,f1.p4.x,f1.p4.y,couleur3,couleur4);
	Bresenham(f1.p4.x,f1.p4.y,f1.p1.x,f1.p1.y,couleur4,couleur1);
}



void RempliGouraud(Facette f,unsigned char couleur1,unsigned char couleur2,unsigned char couleur3,unsigned char couleur4)
{
	int j,i,nb2;
   unsigned char coul1, coul2;
	TracerPoly(f,couleur1,couleur2,couleur3,couleur4);
   nb2=nb;
 // for(i=0;i<nb2;i++)
 //     printf("\ntab_x = %d,  tab_y = %d, nb2 = %d",tab_x[i],tab_y[i],nb2);

   for(j=0;j<nb2;j++)
  		for(i=0;i<nb2;i++)
   	{
      	//printf("\nxi = %d, yi = %d, xj = %d, yj = %d,  i = %d,  j = %d",tab_x[i],tab_y[i],tab_x[j],tab_y[j],i,j);
     		if((tab_y[j]==tab_y[i]) && (i < j))
      	{
      	  	//printf("\nxi = %d, yi = %d, xj = %d, yj = %d,  i = %d,  j = %d",tab_x[i],tab_y[i],tab_x[j],tab_y[j],i,j);
       		coul1 = GetPixel(tab_x[i],tab_y[i]);
        		coul2 = GetPixel(tab_x[j],tab_y[j]);
            nb=0;
           	Bresenham(tab_x[i],tab_y[i],tab_x[j],tab_y[j],coul1,coul2);
      	}
   }
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

   /*
   printf("\nvec.p.x = %d",res.p.x);
   printf("\nvec.p.y = %d",res.p.y);
   printf("\nvec.p.z = %d",res.p.z);
   */

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



// calcul de la norme d'un sommet
Vecteur Calcul1Sommet(Facette f1, Facette f2, Facette f3)
{
	Vecteur sommet;
   sommet.p.x=(f1.n.p.x + f2.n.p.x + f3.n.p.x)/3;
   sommet.p.y=(f1.n.p.y + f2.n.p.y + f3.n.p.y)/3;
   sommet.p.z=(f1.n.p.z + f2.n.p.z + f3.n.p.z)/3;
   return sommet;
}

// calcul de la norme de tous les sommets du cube
void CalculTousSommets()
{
   C.f1.sommet1 = Calcul1Sommet(C.f1,C.f3,C.f4);
   C.f1.sommet2 = Calcul1Sommet(C.f1,C.f5,C.f4);
   C.f1.sommet3 = Calcul1Sommet(C.f1,C.f5,C.f2);
   C.f1.sommet4 = Calcul1Sommet(C.f1,C.f2,C.f3);

   C.f6.sommet1 = Calcul1Sommet(C.f6,C.f3,C.f2);
   C.f6.sommet2 = Calcul1Sommet(C.f6,C.f2,C.f5);
   C.f6.sommet3 = Calcul1Sommet(C.f6,C.f5,C.f4);
   C.f6.sommet4 = Calcul1Sommet(C.f6,C.f3,C.f4);

   C.f2.sommet1 = C.f6.sommet2;
   C.f2.sommet2 = C.f6.sommet1;
   C.f2.sommet3 = C.f1.sommet4;
   C.f2.sommet4 = C.f1.sommet3;

   C.f3.sommet1 = C.f6.sommet1;
   C.f3.sommet2 = C.f6.sommet4;
   C.f3.sommet3 = C.f1.sommet1;
   C.f3.sommet4 = C.f1.sommet4;

   C.f4.sommet1 = C.f6.sommet4;
   C.f4.sommet2 = C.f6.sommet3;
   C.f4.sommet3 = C.f1.sommet2;
   C.f4.sommet4 = C.f1.sommet1;

   C.f5.sommet1 = C.f6.sommet3;
   C.f5.sommet2 = C.f6.sommet2;
   C.f5.sommet3 = C.f1.sommet3;
   C.f5.sommet4 = C.f1.sommet2;
}




void ColorierFacetteGouraud(Facette f)
{
	double qte=0.0;
	Vecteur Source;
   unsigned char couleur1,couleur2,couleur3,couleur4;

	Source.p.x =  10;
 	Source.p.y = 10;
	Source.p.z = -10;

	couleur1 = (unsigned char)(Scalaire(f.sommet1,Source)/(sqrt(Source.p.x*Source.p.x+Source.p.y*Source.p.y + Source.p.z*Source.p.z)*sqrt(f.sommet1.p.x*f.sommet1.p.x+f.sommet1.p.y*f.sommet1.p.y + f.sommet1.p.z*f.sommet1.p.z))*255);
	couleur2 = (unsigned char)(Scalaire(f.sommet2,Source)/(sqrt(Source.p.x*Source.p.x+Source.p.y*Source.p.y + Source.p.z*Source.p.z)*sqrt(f.sommet2.p.x*f.sommet2.p.x+f.sommet2.p.y*f.sommet2.p.y + f.sommet2.p.z*f.sommet2.p.z))*255);
	couleur3 = (unsigned char)(Scalaire(f.sommet3,Source)/(sqrt(Source.p.x*Source.p.x+Source.p.y*Source.p.y + Source.p.z*Source.p.z)*sqrt(f.sommet3.p.x*f.sommet3.p.x+f.sommet3.p.y*f.sommet3.p.y + f.sommet3.p.z*f.sommet3.p.z))*255);
	couleur4 = (unsigned char)(Scalaire(f.sommet4,Source)/(sqrt(Source.p.x*Source.p.x+Source.p.y*Source.p.y + Source.p.z*Source.p.z)*sqrt(f.sommet4.p.x*f.sommet4.p.x+f.sommet4.p.y*f.sommet4.p.y + f.sommet4.p.z*f.sommet4.p.z))*255);

   printf("\ncouleur1 = %d",couleur1);
   printf("\ncouleur2 = %d",couleur2);
   printf("\ncouleur3 = %d",couleur3);
   printf("\ncouleur4 = %d",couleur4);
   
   RempliGouraud(f,couleur1,couleur2,couleur3,couleur4);
}



void ColorierGouraud()
{
   Vecteur Oeil;
	Oeil.p.x = 5;
 	Oeil.p.y = 5;
	Oeil.p.z = -20;

	CalculTousSommets();

  	if(Scalaire(C.f1.n,Oeil)>0)
  		ColorierFacetteGouraud(C.f1);
	if(Scalaire(C.f2.n,Oeil)>0)
		ColorierFacetteGouraud(C.f2);
  	if(Scalaire(C.f3.n,Oeil)>0)
		ColorierFacetteGouraud(C.f3);
	if(Scalaire(C.f4.n,Oeil)>0)
		ColorierFacetteGouraud(C.f4);
  	if(Scalaire(C.f5.n,Oeil)>0)
		ColorierFacetteGouraud(C.f5);
 	if(Scalaire(C.f6.n,Oeil)>0)
  		ColorierFacetteGouraud(C.f6);
}


int main(void)
{
	int i;
	int x1,y1,x2,y2;
	int focale;

   AllouerMemoire();

	focale = 40;

   CreerCube(60);


  	ProjectionOrthogonaleCube();

   ColorierGouraud();
   SauvegarderMemoire();
   return 0;
}