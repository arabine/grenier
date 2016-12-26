/*=============================================================================
 * FantasyBowl 1.0 - Terrain.h
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

#ifndef TERRAIN_H
#define TERRAIN_H

// Librairies Qt
#include <qcanvas.h>
#include <qpoint.h>

class Terrain : public QCanvasView
{

	Q_OBJECT

public:
    Terrain( QCanvas *canvas, QWidget *parent, const char *name );

protected:
	void contentsMousePressEvent( QMouseEvent *e );

signals:
	void sgnlGroundClicked(int, int);

};

#endif // TERRAIN_H

//=============================================================================
// Fin du fichier Terrain.h
//=============================================================================