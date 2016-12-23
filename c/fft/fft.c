#include <math.h>
#include <stdio.h>
#include <conio.h>
//#include <gsl/gsl_fft_real.h>
//#include <gsl/gsl_errno.h>

#define M_PI 3.1415926535897932384626433832795
#define NB_POINTS 1024 // nombre de points numérisés
#define FREQUENCE 10 // nbre de pérode = fréquence du signal samplé

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
void FFT(double data[], unsigned long nn, int isign);

int main(void)
{
	double data[2*NB_POINTS];
//	double data[NB_POINTS];
	double magnitude[NB_POINTS];
	int i;

	for(i=0;i<NB_POINTS;i++)
	{
		REAL(data,i) = sin(i*FREQUENCE*2*M_PI/NB_POINTS);
		IMAG(data,i) = 0.0;
//		data[i] = sin(i*FREQUENCE*2*M_PI/NB_POINTS);
	}


//	for(i=0;i<NB_POINTS;i++)
//		printf("%f ",REAL(data,i));

	printf("\n\n\n\n");

	FFT(data-1,NB_POINTS,1);


	for(i=0;i<NB_POINTS;i++)
	{
		magnitude[i] = sqrt (REAL(data,i)*REAL(data,i) + IMAG(data,i)*IMAG(data,i));
		printf("%.1f ",magnitude[i]);
	}

	getch();

	return 0;


}

/*
Replaces data[1..2*nn] by its discrete Fourier transform, if isign is input as 1; or replaces
data[1..2*nn] by nn times its inverse discrete Fourier transform, if isign is input as -1.
data is a complex array of length nn or, equivalently, a real array of length 2*nn. nn MUST
be an integer power of 2 (this is not checked for!).
*/
void FFT(double data[], unsigned long nn, int isign)
{
	unsigned long n,mmax,m,j,istep,i;
	double wtemp,wr,wpr,wpi,wi,theta; // double precision for the trigonometric recurrences. 
	double tempr,tempi; // can be float if data is float !! 
	n=nn << 1;
	j=1;
	for (i=1;i<n;i+=2) // This is the bit-reversal section of the routine.
	{
		if (j > i)
		{
			SWAP(data[j],data[i]);		// Exchange the two complex numbers.
			SWAP(data[j+1],data[i+1]);
		}
		m=n >> 1;
		while (m >= 2 && j > m)
		{
			j -= m;
			m >>= 1;
		}
		j += m;
	}

	// Here begins the Danielson-Lanczos section of the routine.
	mmax=2;
	while (n > mmax) // Outer loop executed log2 nn times.
	{
		istep=mmax << 1;
		theta=isign*(6.28318530717959/mmax); // Initialize the trigonometric recurrence.
		wtemp=sin(0.5*theta);
		wpr = -2.0*wtemp*wtemp;
		wpi=sin(theta);
		wr=1.0;
		wi=0.0;
		for (m=1;m<mmax;m+=2) //  Here are the two nested inner loops.
		{
			for (i=m;i<=n;i+=istep)
			{
				j=i+mmax;	// This is the Danielson-Lanczos formula:
				tempr=wr*data[j]-wi*data[j+1];
				tempi=wr*data[j+1]+wi*data[j];
				data[j]=data[i]-tempr;
				data[j+1]=data[i+1]-tempi;
				data[i] += tempr;
				data[i+1] += tempi;
			}
			wr=(wtemp=wr)*wpr-wi*wpi+wr; // Trigonometric recurrence.
			wi=wi*wpr+wtemp*wpi+wi;
		}
		mmax=istep;
	}
}