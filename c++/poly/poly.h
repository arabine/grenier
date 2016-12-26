#include <iostream.h>

class poly
{
private:
	unsigned int degre;
	double *coefs;

public:
   // constructeurs destructeurs
	poly(); // degr� 0
	poly(const poly &a);
	poly(unsigned int n); // x^n
	poly(unsigned int n, double *data);

	~poly();

	// m�thodes

	// surchage d'op�rateurs, sym�triques donc fonctions amies
	friend poly operator+(const poly &, const poly &);
	friend poly operator-(const poly &, const poly &);
	friend poly operator*(const poly &, const poly &);
	friend poly operator/(const poly &, const poly &);
	friend poly operator%(const poly &, const poly &);
	friend ostream& operator<<(ostream &, poly &);

	// surchage d'op�rateurs, non sym�triques donc m�thode
	poly& operator()(unsigned int , double *);
	poly& operator=(const poly &);
	double& operator[](unsigned int n);

};
