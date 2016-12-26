/*=============================================================================
 * FantasyBowl 1.0 - Dugout.h
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

#ifndef DUGOUT_H
#define DUGOUT_H

// Librairies Qt
#include <qdialog.h>
#include <qcanvas.h>

// Classes internes
#include "Terrain.h"
#include "Equipe.h"

class Dugout : public QDialog
{

	Q_OBJECT

private:
	Terrain		*CanvasView;
	int number;

protected:

	void hideEvent(QHideEvent *);
	
signals:
	void sgnlCloseDug(int);
	void sgnlDugClicked(int, int, int);

public:
	Dugout(QWidget *parent, QCanvas *can, int val);

public slots:
	void groundClicked(int x, int y);



};

#endif // DUGOUT_H

//=============================================================================
// Fin du fichier Dugout.h
//=============================================================================