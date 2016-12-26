#include <iostream.h>

class poly
{
private:
	unsigned int degre;
	double *coefs;

public:
   // constructeurs destructeurs
	poly(); // degré 0
	poly(const poly &a);
	poly(unsigned int n); // x^n
	poly(unsigned int n, double *data);

	~poly();

	// méthodes

	// surchage d'opérateurs, symétriques donc fonctions amies
	friend poly operator+(const poly &, const poly &);
	friend poly operator-(const poly &, const poly &);
	friend poly operator*(const poly &, const poly &);
	friend poly operator/(const poly &, const poly &);
	friend poly operator%(const poly &, const poly &);
	friend ostream& operator<<(ostream &, poly &);

	// surchage d'opérateurs, non symétriques donc méthode
	poly& operator()(unsigned int , double *);
	poly& operator=(const poly &);
	double& operator[](unsigned int n);

};
