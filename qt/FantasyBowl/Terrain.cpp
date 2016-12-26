/*=============================================================================
 * FantasyBowl 1.0 - Terrain.cpp
 *=============================================================================
 * Terrain de jeu - Objet Canvas
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 02/03/2003 : première version
 *
 *=============================================================================
 */

#include "Terrain.h"

/*****************************************************************************/
Terrain::Terrain( QCanvas *canvas, QWidget *parent, const char *name )
    : QCanvasView( canvas, parent, name )
{
	connect( this, SIGNAL( sgnlGroundClicked(int, int) ), parent, SLOT( groundClicked(int, int) ) );
	
}
/*****************************************************************************/
void Terrain::contentsMousePressEvent( QMouseEvent *e )
{
	QPoint pnt = e->pos();
    emit sgnlGroundClicked(pnt.x(), pnt.y());
}
//=============================================================================
// Fin du fichier Terrain.cpp
//=============================================================================