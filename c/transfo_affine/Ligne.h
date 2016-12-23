
#define Eniv 2
#define PI   3.1415926535897932384626433832795
#define SQRPI  1.7724538509055160272981674833411


#define NBDIR 8
#define ANGLE ((2.*PI)/NBDIR)


#define PORTEEMAX 255
#define PORTEEMIN 4
#define DISTMAX (2.)


#define testMax(x,y)  ( (x) > (y) ? (x) : (y) )
#define testMin(x,y)  ( (x) < (y) ? (x) : (y) )
#define testEniv(a,b) (((a)-(b))>Eniv)
#define testLimite(a,b,ox,oy,nx,ny) (((a)>=(ox))&&((b)>=(oy))&&((a)<(nx))&&((b)<(ny)))
#define testSup(a,b) ((a)>(b))
#define testInf(a,b) ((a)<(b))
#define testDistance(xo,yo,x1,y1,x2,y2) ( (abs(xo-x1)+abs(yo-y1))<= (abs(xo-(x2))+abs(yo-(y2))))



typedef struct 
{
	int x;	/* point d'arrivée */
	int y;
	int pas;
	int diffNiv;
	int a;
	int b;
} DIR;



typedef struct 
{	

	int nbDirections;
	DIR * right;

} LN;


LN *AllouerDirLig(int w, int h);
void FreeDirLig(LN *DirLig, int w, int h);
void ClearDirLig(LN *DirLig, int w, int h);
int CalculerDirection(int dx, int dy, double angle, int nbDir);
void SauverDirLig(IMAGE *I0, COULEUR * PAL, const char *rep,const char *base,int numFich, LN *DirLig);
