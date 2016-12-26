/*=============================================================================
 * graph.cpp
 *=============================================================================
 * Fenêtre graphique
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0 + QT 2.3
 * Build : 15/09/2002
 * Updates :
 *
 *
 *
 *
 *=============================================================================
 */

// Qt libs
#include <qapplication.h>
#include <qpainter.h>
#include <qmessagebox.h>

// Program libs
#include "graph.h"


Graph::Graph(QWidget *parent, const char *name) : QWidget(parent, name)
{
	// width, height
	setFixedSize(200,200);
	setPalette( QPalette( QColor(250, 250, 200)));
	paint = new QPainter(this);

}

void Graph::paintEvent(QPaintEvent *)
{
	
}

void Graph::paintRandom(int tab[200])
{
	paint->setPen( Qt::black );
	paint->drawLine(0,100,200,100);
	paint->setPen( Qt::red );
	for(int i=0;i<200;i++)
		paint->drawPoint(i,tab[i]);
}

void Graph::afficheGaussien(float tab[200])
{
	paint->setPen(Qt::red);
	for(int i=0;i<200;i++)
		paint->drawPoint(i,tab[i]);
}

//=============================================================================
// End of graph.cpp
//=============================================================================