#include <stdio.h>
#include <conio.h>

extern float CALC(float *rayon);

float multi(float rayon)
{
	return(rayon*rayon*3.14159265);

}

int main(void)
{
	float ret,rayon;

	rayon=3.0;
	ret = CALC(&rayon);
	printf("\nSurface : %f\n",ret);

	getch();
	return 0;
}