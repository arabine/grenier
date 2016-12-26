#include "poly.h"
#include "stdlib.h"

poly::poly()
{
	degre=0;
   coefs = new double[1];
   coefs[0]=0;
}

poly::poly(unsigned int n)
{
	degre = n;
   coefs = new double[degre+1];
   for(unsigned int i=0;i<n;i++)
   	coefs[i] = 0;
   coefs[degre]=1;
}

poly::poly(unsigned int n, double *data)
{
	degre = n;
   coefs = new double[degre+1];
   for(unsigned int i=0;i<=n;i++)
   	coefs[i] = data[i];
}

poly::poly(const poly &a)
{
   degre = a.degre;
   coefs = new double[degre+1];
   for(unsigned int k=0;k<=degre;k++)
   	coefs[k] = a.coefs[k];
}

poly::~poly()
{
	delete[] coefs;
}

ostream& operator<<(ostream &os, poly &a)
{
   for(unsigned int i=a.degre;i>0;i--)
   	os << a.coefs[i] << "x^" << i << " ";
   os << a.coefs[0] << endl;
   return os;
}

poly operator*(const poly &a, const poly &b)
{
   unsigned int deg;
   double *tab;
   deg = a.degre + b.degre;
 	tab = new double[deg+1];

   for(unsigned int k=0;k<=deg;k++)
   	tab[k] = 0;

   for(unsigned int i=0; i<=a.degre;i++)
   {
   	for(unsigned int j=0;j<=b.degre;j++)
      	tab[j+i]=tab[j+i]+a.coefs[i]*b.coefs[j];
   }

	poly ret(deg,tab);

   return ret;
}

poly operator+(const poly &a, const poly &b)
{
   unsigned int deg;
   double *tab;
   if(a.degre<b.degre)
      deg=b.degre;
   else
   	deg=a.degre;
 	tab = new double[deg+1];
   for(unsigned int i=0;i<=deg;i++)
   {
       if(a.degre<=b.degre)
       {
       	if(i<=a.degre)
           	tab[i] = a.coefs[i]+ b.coefs[i];
         else
            tab[i] = b.coefs[i];
       }
       if(a.degre>b.degre)
       {
       	if(i<=b.degre)
           	tab[i] = a.coefs[i]+ b.coefs[i];
         else
            tab[i] = a.coefs[i];
       }
   }
   poly ret(deg,tab);
   return ret;

}

poly operator-(const poly &a, const poly &b)
{
   unsigned int deg;
   double *tab;
   if(a.degre<b.degre)
      deg=b.degre;
   else
   	deg=a.degre;

	tab = new double[deg+1];
   for(unsigned int i=0;i<=deg;i++)
   {
       if(a.degre<=b.degre)
       {
       	if(i<=a.degre)
           	tab[i] = a.coefs[i]- b.coefs[i];
         else
            tab[i] = -b.coefs[i];
       }
       if(a.degre>b.degre)
       {
       	if(i<=b.degre)
           	tab[i] = a.coefs[i]- b.coefs[i];
         else
            tab[i] = a.coefs[i];
       }
   }
   poly ret(deg,tab);
   return ret;

}

poly operator/(const poly &a, const poly &b)
{
   unsigned int deg_quotient, deg_diviseur;
   double *tab,*temp;
	unsigned int k;


   if(a.degre<b.degre)
		exit(1);

   deg_diviseur = a.degre;
   deg_quotient = a.degre-b.degre;
   tab = new double[deg_quotient+1]; // coeffs du quotient
   temp = new double[deg_diviseur+1]; // coeffs du résultat des soustractions successives

   for(unsigned int j=0;j<=deg_diviseur;j++)
		temp[j] = a.coefs[j];


   for( k=0;k<=deg_quotient;k++)
		tab[k] = 0;


   poly u,q;// q : quotient temporaire
	
   // on initialise u = a pour le premier coup
   u(deg_diviseur,temp); // calcul temporaire : résultat des soustractions succesives
	

   for(unsigned int i=0;i<=deg_quotient;i++)
   {
	   tab[deg_quotient-i] = u.coefs[deg_diviseur-i]/b.coefs[b.degre];
	   q(deg_quotient-i,tab);
	   u=(u-(q*b));
	   for(k=0;k<=deg_diviseur-i;k++)
		   temp[k] = u.coefs[k];
   }
   poly ret(deg_quotient,tab);
   return ret;
}

poly operator%(const poly &a, const poly &b)
{
	unsigned int deg;
   if(a.degre<b.degre)
		exit(1);
	poly quotient, reste;
	quotient=a/b;
	
	reste = a-quotient*b;

   return reste;

}


poly& poly::operator=( const poly &b)
{
	// on regarde si on affecte pas le même objet sur lui même...
   if(this==&b)
   	return *this; // on renvoit b
   if(degre!=b.degre)
   {
		delete [] coefs;
		degre = b.degre;
   	coefs = new double[degre+1];
   }
   for(unsigned int k=0;k<=degre;k++)
   	coefs[k] = b.coefs[k];
   return *this;  // this est un pointeur sur l'objet courant
}

double& poly::operator[](unsigned int n)
{
	if(n>degre)
   {
   	cout << "Accès interdit";
      exit(1);
   }
	return coefs[n];
}


poly& poly::operator()(unsigned int n, double *tab)
{
	delete[] coefs;
	degre = n;
	coefs = new double[degre+1];
	for(unsigned int i=0;i<=degre;i++)
		coefs[i] = tab[i];
	return *this;
}