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
 * 02/01/2003 : premi�re version
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
	bool isLoaded; // Vrai si des donn�es sont disponibles
	unsigned char *data; // donn�es � afficher
	unsigned long int elements, nb_elements ; // taille des donn�es / nombre d'�chantillons
	int resolution; // octets par �chantillon
	signed long int max, min, val_max; // �chantillons max et min
	// val_max : la valeur la plus grande (absolue) pour fixer la fen�tre

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