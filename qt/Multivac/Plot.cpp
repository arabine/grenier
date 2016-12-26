/*=============================================================================
 * Multivac 1.0 - Plot.cpp
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


#include "Plot.h"
/*****************************************************************************/
Plot::Plot( QWidget *parent, const char *name ) : QWidget( parent, name )
{
	setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc
	isLoaded = false;
	elements = 2;
	resolution = 2;
	val_max = 2;
	nb_elements = 1;

	// un double click sur le graphique ouvre la boite de dialogue de choix du fichier
	connect(this, SIGNAL(signalOpenNewWave()) ,parent, SLOT(openSoundFile()));

	// affichage des coordonnées dans le statusbar
	connect(this, SIGNAL(signalStatusMessage(QString)) ,parent, SLOT(setMessage(QString)));

	update();
}
/*****************************************************************************/
void Plot::setData(unsigned long int taille, unsigned char *donnees, unsigned short int bits)
{
	unsigned long int i;
	signed short int val;
	unsigned char val0;

	data = donnees;
	elements = taille;
	bitsPerSample = bits;

	// Calcul des extrêmes
	max = 0;
	min = 0;
	val_max = 0;

	// recherche des extrêmes
	if(bitsPerSample==16)
	{
		for(i=0;i<elements;i=i+2)
		{
			val = data[i+1]<<8;
			val0 = data[i];
			val = val + val0;
			if(val>max) max=val;
			if(val<min) min=val;
		}

		nb_elements = elements>>2;
	}
	else
	{
		for(i=0;i<elements;i++)
		{
			val = data[i]-128;
			if(val>max) max=val;
			if(val<min) min=val;
		}

		nb_elements = elements;
	}

	if(abs(max)>abs(min))
		val_max = abs(max);
	else
		val_max = abs(min);

	isLoaded = true;
	update();
	emit signalStatusMessage("Cliquez sur le graphique pour obtenir les coordonnées d'un point.");
}
/*****************************************************************************/
void Plot::paintEvent( QPaintEvent * )
{
	QPainter paint( this );
	unsigned long int i;
	signed short int val;
	unsigned char val0;

	paint.save();
	
	paint.setWindow( 0,-val_max, nb_elements, 2*val_max);

	if(isLoaded==true)
	{
		if(bitsPerSample==16)
		{
			// on dessine ici le wav
			for(i=0;i<elements;i=i+2)
			{
				val = data[i+1]<<8;
				val0 = data[i];
				val = val + val0;
			
				paint.drawLine(i>>2,0,i>>2,-val);
			}
			// on trace par dessus l'axe du zéro
			paint.setPen(Qt::red);
			paint.drawLine(0,0,nb_elements,0);
		}
		else
		{
			// on dessine ici le wav
			for(i=0;i<elements;i++)
			{
				val = data[i]-128;
				paint.drawLine(i,0,i,-val);
			}
			// on trace par dessus l'axe du zéro
			paint.setPen(Qt::red);
			paint.drawLine(0,0,nb_elements,0);
		}


	}
	else
	{
		// on trace par dessus l'axe du zéro
		paint.setPen(Qt::red);
		paint.drawLine(0,0,nb_elements,0);
	}

	paint.restore();

}
/*****************************************************************************/
void Plot::mouseDoubleClickEvent( QMouseEvent * )
{
	emit signalOpenNewWave();
}
/*****************************************************************************/
void Plot::mousePressEvent( QMouseEvent *e )
{
	QString x,y;
	signed long int real_x, real_y; // coordonnées dans le painter



	if(isLoaded==true)
	{
		QPoint pnt = e->pos();
		real_x = (pnt.x()*nb_elements)/this->width();
		real_y = ((-1)*pnt.y()*2*val_max)/this->height()+val_max;

		x = x.setNum(real_x);
		y = y.setNum(real_y);
		// on affiche les coordonnées du curseur dans la statusbar
		emit signalStatusMessage("x=" + x + " y=" + y);
		
	}

}
//=============================================================================
// Fin du fichier Plot.cpp
//=============================================================================