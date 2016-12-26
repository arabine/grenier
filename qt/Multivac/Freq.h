/*=============================================================================
 * Multivac 1.0 - Freq.h
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

#ifndef FREQ_H
#define FREQ_H

#include <qwidget.h>
#include <qpainter.h>
#include <math.h>

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])
#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
#define M_PI 3.1415926535897932384626433832795

class Freq : public QWidget
{
	Q_OBJECT

private:
	double *donnees;
	double *norme;

	double max;

	unsigned long taillefft;
	bool isLoaded;

protected:
    void paintEvent( QPaintEvent * );
	void mouseDoubleClickEvent( QMouseEvent * );
	void mousePressEvent( QMouseEvent *e );

public:
    Freq(QWidget *parent, const char *name=0);
	~Freq()
	{
		delete donnees;
		delete norme;
	}

	void setData(unsigned char *debutdonnees, unsigned long taille);
	void FFT(double data[], unsigned long nn, int isign);
	void testFFT();

signals:
	void signalOpenNewWave(); // ouverture d'un fichier lors d'un double click
	void signalStatusMessage(QString);

};

#endif

//=============================================================================
// Fin du fichier Freq.h
//=============================================================================