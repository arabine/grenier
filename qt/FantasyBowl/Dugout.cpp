/*=============================================================================
 * FantasyBowl 1.0 - Dugout.cpp
 *=============================================================================
 * Fenêtre de gestion du banc de touche
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 09/04/2003 : première version
 *
 *=============================================================================
 */

#include "Dugout.h"

/*****************************************************************************/
Dugout::Dugout(QWidget *parent, QCanvas *can, int val): QDialog(parent, 0, FALSE, 
				WStyle_Customize | WStyle_SysMenu | WStyle_MinMax | WStyle_NormalBorder | WStyle_Title)
{
	number = val;

    CanvasView = new Terrain( can, this, "CanvasView" );
	CanvasView->setGeometry(0,1,404,204);

	connect(this, SIGNAL(sgnlCloseDug(int)), parent, SLOT(closeDug(int)));
	connect(this, SIGNAL(sgnlDugClicked(int, int, int)), parent, SLOT(dugClicked(int, int, int)));

	setFixedSize(405,205);
}
/*****************************************************************************/
void Dugout::groundClicked(int x, int y)
{
	emit sgnlDugClicked(number, x, y);
}
/*****************************************************************************/

void Dugout::hideEvent(QHideEvent *)
{
	emit sgnlCloseDug(number);
}

//=============================================================================
// Fin du fichier Dugout.cpp
//=============================================================================