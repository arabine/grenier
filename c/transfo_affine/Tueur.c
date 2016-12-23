#include "Image.h"
#include "Tueur.h"


#define ISIN(x,y) (((x)<dx)&&((y)<dy)&&((x)>=0)&&((y)>=0))
#define NOTVISITE(x,y) ((visitefront[x][y]<temfront))
#define P(x) printf("%s\n",x)

typedef struct
{
  int x;
  int y;
}
point;


static int dx,dy,sz;
static unsigned char **ou,*in,*out;
static int tem,temfront,zero;
static point *points_voisinage; 
static int **visite,**visitefront; 
static int c8;
static point *frontiere[256];
static int occupation[256];

void initfrontiere()
{
  int i;
  for(i=0;i<256;i++)
    frontiere[i]=(point *)malloc((4*sz+4)*sizeof(point));
}


void initvisite ()
{
  int i,j;
  visite=(int **)malloc(dx*sizeof(int *));
  visitefront=(int **)malloc(dx*sizeof(int *));
  for (i=0;i<dx;i++)
    {
      visite[i]=(int *)malloc(dy*sizeof(int));
      visitefront[i]=(int *)malloc(dy*sizeof(int));
    }
  for(i=0;i<dx;i++)
    for(j=0;j<dy;j++)
      {
	visite[i][j]=0;
	visitefront[i][j]=0;
      }
}

void initout()
{
  int i,j;
  ou=(unsigned char **)malloc(dy*sizeof(unsigned char*));
  for (i=0;i<dy;i++)
    ou[i]=out+(i*dx);
  for(i=0;i<dx;i++)
    for(j=0;j<dy;j++)
      ou[j][i]=in[j*dx+i];
}

void initvoisinage()
{
  points_voisinage=(point *)malloc(sz*sizeof(point));
}

int ismax(int x,int y)
{
  unsigned char v;
  int n=0;
  v=ou[y][x];
  return
    (
     (x==dx-1 || ((ou[y][x+1]<v && ++n)||(ou[y][x+1]==v)))
     &&
     (x==0 || ((ou[y][x-1]<v && ++n)||(ou[y][x-1]==v)))
     &&
     (y==dy-1 || ((ou[y+1][x]<v && ++n )||(ou[y+1][x]==v)))
     &&
     (y==0 || ((ou[y-1][x]<v && ++n )||(ou[y-1][x]==v)))
     &&
     (!c8 
      ||
      (
       (x==dx-1 || y==0 || ((ou[y-1][x+1]<v  && ++n)||(ou[y-1][x+1]==v)))
       &&
       (x==dx-1 || y==dy-1 || ((ou[y+1][x+1]<v && ++n)||(ou[y+1][x+1]==v)))
       &&
       (x==0 || y==dy-1||((ou[y+1][x-1]<v && ++n)||(ou[y+1][x-1])))
       &&
       (x==0 || y==0 ||((ou[y-1][x-1]<v && ++n)||(ou[y-1][x-1])))
       )     
      )
     && 
     (n)
     )
    ;
}

int ismin(int x,int y)
{
  unsigned char v;
  int n=0;
  v=ou[y][x];
  return
    (
     (x==dx-1 || ((ou[y][x+1]>v && ++n)||(ou[y][x+1]==v)))
     &&
     (x==0 || ((ou[y][x-1]>v && ++n)||(ou[y][x-1]==v)))
     &&
     (y==dy-1 || ((ou[y+1][x]>v && ++n )||(ou[y+1][x]==v)))
     &&
     (y==0 || ((ou[y-1][x]>v && ++n )||(ou[y-1][x]==v)))
     &&
     (!c8
      ||
      (
       (x==dx-1 || y==0 || ((ou[y-1][x+1]>v  && ++n)||(ou[y-1][x+1]==v)))
       &&
       (x==dx-1 || y==dy-1 || ((ou[y+1][x+1]>v && ++n)||(ou[y+1][x+1]==v)))
       &&
       (x==0 || y==dy-1||((ou[y+1][x-1]>v && ++n)||(ou[y+1][x-1])))
       &&
       (x==0 || y==0 ||((ou[y-1][x-1]>v && ++n)||(ou[y-1][x-1])))
       )
      )
     && (n)
     )
    ;
}

void set(int n,unsigned char niv)
{
  int i;
  for (i=0;i<n;i++)
    ou[points_voisinage[i].y][points_voisinage[i].x]=niv;
}


void traitepointmax(int x,int y)
{
  unsigned char niv,top,v;
  int n=0,n1;
  int i;
  top=niv=ou[y][x];
  for(i=0;i<256;i++)
    occupation[i]=0;
  occupation[niv]=1;
  frontiere[niv][0].x=x;
  frontiere[niv][0].y=y;
  visitefront[x][y]=temfront;
  while(n<sz && top<=niv)
    {
      niv=top;
      n1=occupation[top];
      for (i=0;n<sz && i<n1;i++)
	{
	  x=frontiere[niv][i].x;
	  y=frontiere[niv][i].y;
	  points_voisinage[n].x=x;
	  points_voisinage[n].y=y;
	  n++;
	  visite[x][y]=tem;
	  if (x>0 && NOTVISITE(x-1,y))
	    {
	      v=ou[y][x-1];
	      frontiere[v][occupation[v]].x=x-1;
	      frontiere[v][occupation[v]++].y=y;
	      visitefront[x-1][y]=temfront;
	      if (v>top) top=v;
	    }
	  if ( x+1<dx && NOTVISITE(x+1,y))
	    {
	      v=ou[y][x+1];
	      frontiere[v][occupation[v]].x=x+1;
	      frontiere[v][occupation[v]++].y=y;
	      if (v>top) top=v;
	      visitefront[x+1][y]=temfront;
	    }
	  if (y>0 && NOTVISITE(x,y-1))
	    {
	      v=ou[y-1][x];
	      frontiere[v][occupation[v]].x=x;
	      frontiere[v][occupation[v]++].y=y-1;
	      visitefront[x][y-1]=temfront;
	      if (v>top) top=v;
	    }
	  if ( y+1<dy && NOTVISITE(x,y+1))
	    {
	      v=ou[y+1][x];
	      frontiere[v][occupation[v]].x=x;
	      frontiere[v][occupation[v]++].y=y+1;
	      if (v>top) top=v;
	      visitefront[x][y+1]=temfront;
	    }
	  if (c8)
	    {      
	      if (x>0 && y>0 && NOTVISITE(x-1,y-1))
		{
		  v=ou[y-1][x-1];
		  frontiere[v][occupation[v]].x=x-1;
		  frontiere[v][occupation[v]++].y=y-1;
		  visitefront[x-1][y-1]=temfront;
		  if (v>top) top=v;
		}
	      if ( x+1<dx && y>0 && NOTVISITE(x+1,y-1))
		{
		  v=ou[y-1][x+1];
		  frontiere[v][occupation[v]].x=x+1;
		  frontiere[v][occupation[v]++].y=y-1;
		  visitefront[x+1][y-1]=temfront;
		  if (v>top) top=v;
		}
	      if (y+1<dy && x+1<dx && NOTVISITE(x+1,y+1))
		{
		  v=ou[y+1][x+1];
		  frontiere[v][occupation[v]].x=x+1;
		  frontiere[v][occupation[v]++].y=y+1;
		  visitefront[x+1][y+1]=temfront;
		  if (v>top) top=v;
		}
	      if ( y+1<dy && x>0 && NOTVISITE(x-1,y+1))
		{
		  v=ou[y+1][x-1];
		  frontiere[v][occupation[v]].x=x-1;
		  frontiere[v][occupation[v]++].y=y+1;
		  visitefront[x-1][y+1]=temfront;
		  if (v>top) top=v;
		}  
	    }
	}  
      for(i=0;i<occupation[niv]-n1;i++)
	{
	  frontiere[niv][i].x=frontiere[niv][i+n1].x;
	  frontiere[niv][i].y=frontiere[niv][i+n1].y;
	}	  
      occupation[niv]-=n1;	  
      i=top;
      while(!occupation[i]) i--;
      top=i;
    }
  set(n,niv);
}

void traitepointmin(int x,int y)
{
  unsigned char niv,top,v;
  int n=0,n1;
  int i,xp,yp;
  xp=x;
  yp=y;
  top=niv=ou[y][x];
  for(i=0;i<256;i++)
    occupation[i]=0;
  occupation[niv]=1;
  frontiere[niv][0].x=x;
  frontiere[niv][0].y=y;
  visitefront[x][y]=temfront;
  while(n<sz && top>=niv)
    {
      /*      printf("top=%d,n=%d,occ=%d\n",top,n,occupation[top]);*/
      niv=top;
      n1=occupation[top];
      for (i=0;n<sz && i<n1;i++)
	{
	  x=frontiere[niv][i].x;
	  y=frontiere[niv][i].y;
	  points_voisinage[n].x=x;
	  points_voisinage[n].y=y;
	  n++;
	  visite[x][y]=tem;
	  if (x>0 && NOTVISITE(x-1,y))
	    {
	      v=ou[y][x-1];
	      frontiere[v][occupation[v]].x=x-1;
	      frontiere[v][occupation[v]].y=y;
	      occupation[v]++;
	      visitefront[x-1][y]=temfront;
	      if (v<top) top=v;
	    }
	  if ( x+1<dx && NOTVISITE(x+1,y))
	    {
	      v=ou[y][x+1];
	      frontiere[v][occupation[v]].x=x+1;
	      frontiere[v][occupation[v]].y=y;
	      occupation[v]++;
	      if (v<top) top=v;
	      visitefront[x+1][y]=temfront;
	    }
	  if (y>0 && NOTVISITE(x,y-1))
	    {
	      v=ou[y-1][x];
	      frontiere[v][occupation[v]].x=x;
	      frontiere[v][occupation[v]].y=y-1;
	      occupation[v]++;
	      visitefront[x][y-1]=temfront;
	      if (v<top) top=v;
	    }
	  if ( y+1<dy && NOTVISITE(x,y+1))
	    {
	      v=ou[y+1][x];
	      frontiere[v][occupation[v]].x=x;
	      frontiere[v][occupation[v]].y=y+1;
	      occupation[v]++;
	      if (v<top) top=v;
	      visitefront[x][y+1]=temfront;
	    }
	  if (c8)
	    {      
	      if (x>0 && y>0 && NOTVISITE(x-1,y-1))
		{
		  v=ou[y-1][x-1];
		  frontiere[v][occupation[v]].x=x-1;
		  frontiere[v][occupation[v]++].y=y-1;
		  visitefront[x-1][y-1]=temfront;
		  if (v<top) top=v;
		}
	      if ( x+1<dx && y>0 && NOTVISITE(x+1,y-1))
		{
		  v=ou[y-1][x+1];
		  frontiere[v][occupation[v]].x=x+1;
		  frontiere[v][occupation[v]++].y=y-1;
		  visitefront[x+1][y-1]=temfront;
		  if (v<top) top=v;
		}
	      if (y+1<dy && x+1<dx && NOTVISITE(x+1,y+1))
		{
		  v=ou[y+1][x+1];
		  frontiere[v][occupation[v]].x=x+1;
		  frontiere[v][occupation[v]++].y=y+1;
		  visitefront[x+1][y+1]=temfront;
		  if (v<top) top=v;
		}
	      if ( y+1<dy && x>0 && NOTVISITE(x-1,y+1))
		{
		  v=ou[y+1][x-1];
		  frontiere[v][occupation[v]].x=x-1;
		  frontiere[v][occupation[v]++].y=y+1;
		  visitefront[x-1][y+1]=temfront;
		  if (v<top) top=v;
		}  
	    }
	}
      for(i=0;i<occupation[niv]-n1;i++)
	{
	  frontiere[niv][i].x=frontiere[niv][i+n1].x;
	  frontiere[niv][i].y=frontiere[niv][i+n1].y;
	}	  
      occupation[niv]-=n1;     
      i=top;
      while(!occupation[i]) i++;
      top=i;
    }
  set(n,niv);
  /*  printf("n=%d,niv=%d,x=%d,y=%d\n",n,niv,xp,yp);*/
}

void traitemax()
{
  int i,j;
  for(i=0;i<dx;i++)
    for(j=0;j<dy;j++)
      if (
	  (visite[i][j]<=zero)
	  &&
	  (ismax(i,j))
	  )
	{
	  traitepointmax(i,j);
	  tem++;
	  temfront++;
	}
}
void traitemin()
{
  int i,j;
  for(i=0;i<dx;i++)
    for(j=0;j<dy;j++)
      if (
	  (visite[i][j]<=zero)
	  &&
	  (ismin(i,j))
	  )
	{
	  traitepointmin(i,j);
	  tem++;
	  temfront++;
	}
}


/*********************************************/

void Kext(s,c,input,output)
     int s;
     int c;
     IMAGE *input;
     IMAGE *output;
{
  c8=c;
  dx=input->h;
  dy=input->w;
  //output=mw_change_cimage(output,dy,dx);
  out=output->pixel;
  in=input->pixel;
  sz=s;
  initout();
  initfrontiere();
  initvoisinage();
  initvisite();
  zero=0;
  tem=1;
  temfront=1;
  traitemin();
  zero=tem-1;
  traitemax();
}
