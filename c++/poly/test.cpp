#include <iostream.h>
#include "poly.h"


int main()
{
	double tab[5] = {-2,7,5,-3,2};
	double tab2[3] = {-2,1,1};

	poly a(4,tab);
	poly b(2,tab2);
	poly c;

//	cout << a;
//	cout << b;

	c=a%b;

	cout << c;

	cin.get();

	return 0;
}

