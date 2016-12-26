/*=============================================================================
 * Multivac 1.0 - Plot.h
 *=============================================================================
 * Interface de visualisation temporelle d'un signal audio
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 02/01/2003 : première version
 *
 *=============================================================================
 */

#ifndef PLOT_H
#define PLOT_H


#include <qwidget.h>
#include <qpainter.h>
#include <qfont.h>

#include <math.h>

class Plot : public QWidget
{
	Q_OBJECT

private:
	bool isLoaded; // Vrai si des données sont disponibles
	unsigned char *data; // données à afficher
	unsigned long int elements, nb_elements ; // taille des données / nombre d'échantillons
	int resolution; // octets par échantillon
	signed long int max, min, val_max; // échantillons max et min
	// val_max : la valeur la plus grande (absolue) pour fixer la fenêtre

	unsigned short int bitsPerSample;

protected:
    void paintEvent( QPaintEvent * );
	void mouseDoubleClickEvent( QMouseEvent * );
	void mousePressEvent( QMouseEvent *e );

public:
    Plot(QWidget *parent, const char *name=0);

	void setData(unsigned long int taille, unsigned char *donnees, unsigned short int bits);

signals:
	void signalOpenNewWave(); // ouverture d'un fichier lors d'un double click
	void signalStatusMessage(QString);

};

#endif

//=============================================================================
// Fin du fichier Plot.h
//=============================================================================