/*=============================================================================
 * Multivac 1.0 - Freq.cpp
 *=============================================================================
 * Interface de visualisation fréquentielle d'un signal audio
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 06/02/2003 : première version
 *
 *=============================================================================
 */



#include "Freq.h"
/*****************************************************************************/
Freq::Freq( QWidget *parent, const char *name ) : QWidget( parent, name )
{
	setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc
	donnees = new double[1];
	norme = new double[1];

	donnees[0] = 0.0;
	norme[0] = 0.0;
	max = 2;
	taillefft = 2;

	// un double click sur le graphique ouvre la boite de dialogue de choix du fichier
	connect(this, SIGNAL(signalOpenNewWave()) ,parent, SLOT(openSoundFile()));

	// affichage des coordonnées dans le statusbar
	connect(this, SIGNAL(signalStatusMessage(QString)) ,parent, SLOT(setMessage(QString)));

	isLoaded = false;
	update();
}
/*****************************************************************************/
void Freq::setData(unsigned char *debutdonnees, unsigned long taille)
{
	unsigned long int i;
	signed short int val;
	unsigned char val0;

	isLoaded = false;

	taillefft = taille;

	delete donnees;
	donnees = new double[2*taillefft+1];
	delete norme;
	norme = new double[taillefft];

	for(i=1;i<taillefft;i=i+2)
	{
		val = debutdonnees[i+1]<<8;
		val0 = debutdonnees[i];
		val = val + val0;
		REAL(donnees,i) = val*1.0;
		IMAG(donnees,i) = 0.0;
	}

	FFT(donnees,taillefft,1);

	max=0;

	for(i=1;i<=taillefft;i++)
	{
		norme[i-1] = sqrt (REAL(donnees,i)*REAL(donnees,i) + IMAG(donnees,i)*IMAG(donnees,i));
		if(norme[i-1]>max) max = norme[i-1];
	}
	
	isLoaded = true;

	update();
}
/*****************************************************************************/
void Freq::paintEvent( QPaintEvent * )
{
	unsigned long int i;
	QPainter paint( this );

	paint.save();
	paint.setWindow( 0,-max, taillefft/2-1, max);

	if(isLoaded==true)
	{
		// on dessine ici les fréquences
		for(i=0;i<taillefft/2;i++)
			paint.drawLine(i,0,i,-norme[i]);
	}

	paint.restore();

}
/*****************************************************************************/
void Freq::mouseDoubleClickEvent( QMouseEvent * )
{
	emit signalOpenNewWave();
}
/*****************************************************************************/
void Freq::mousePressEvent( QMouseEvent *e )
{
	QString x,y;
	signed long int real_x, real_y; // coordonnées dans le painter

	if(isLoaded==true)
	{
		QPoint pnt = e->pos();
		real_x = (pnt.x()*taillefft/2)/this->width();
		real_y = max - (pnt.y()*max)/this->height();

		x = x.setNum(real_x);
		y = y.setNum(real_y);
		// on affiche les coordonnées du curseur dans la statusbar
		emit signalStatusMessage("x=" + x + " y=" + y);
		
	}

}
/*****************************************************************************/
/**
 * Routine de Test de la FFT. Le signal est composé de 2 sinusoïdes de 
 * 2 fréquences différentes. Doit donc afficher 2 raies.
 */
void Freq::testFFT()
{
	unsigned long int i;
	unsigned long int nbpoints = 1024;	// nombre de points numérisés
	unsigned long int frequence1 = 50;	// nbre de pérode = fréquence du signal samplé
	unsigned long int frequence2 = 35;	// nbre de pérode = fréquence du signal samplé

	isLoaded = false;

	taillefft = nbpoints;
	max = 0;

	delete donnees;
	delete norme;
	donnees = new double[2*nbpoints];
	norme = new double[nbpoints];

	for(i=0;i<nbpoints;i++)
	{
		REAL(donnees,i) = sin(i*frequence1*2*M_PI/nbpoints)+2*sin(i*frequence2*2*M_PI/nbpoints);
		IMAG(donnees,i) = 0.0;
	}

	FFT(donnees-1,nbpoints,1);

	for(i=1;i<=taillefft;i++)
	{
		norme[i-1] = sqrt (REAL(donnees,i)*REAL(donnees,i) + IMAG(donnees,i)*IMAG(donnees,i));
		if(norme[i-1]>max) max = norme[i-1];
	}

	isLoaded = true;
	update();
}
/*****************************************************************************/
/*
Replaces data[1..2*nn] by its discrete Fourier transform, if isign is input as 1; or replaces
data[1..2*nn] by nn times its inverse discrete Fourier transform, if isign is input as -1.
data is a complex array of length nn or, equivalently, a real array of length 2*nn. nn MUST
be an integer power of 2 (this is not checked for!).
*/
void Freq::FFT(double data[], unsigned long nn, int isign)
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
//=============================================================================
// Fin du fichier Freq.cpp
//=============================================================================