/*=============================================================================
 * FantasyBowl 1.0 - Interface.h
 *=============================================================================
 * Fenêtre principale avec les graphiques + paramètres globaux du jeu
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

#ifndef INTERFACE_H
#define INTERFACE_H

// Librairies standards
#include <stdlib.h>

// Librairies Qt
#include <qapplication.h>
#include <qmainwindow.h>
#include <qwidget.h>
#include <qcanvas.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qstatusbar.h>
#include <qgroupbox.h>
#include <qtextview.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qdom.h>
#include <qlist.h>
#include <qlistbox.h>

// Classes du jeu
#include "Terrain.h"
#include "Joueur.h"
#include "Skill.h"
#include "GameWizard.h"
#include "Game.h"
#include "Dugout.h"

class Interface : public QMainWindow
{

	Q_OBJECT

private:

	// divers éléments de l'interface & des fenêtres quelconques
	Terrain		*CanvasView;
	QGroupBox	*player, *logs, *infos;
	QTextView	*logPanel;
	QPopupMenu	*windows;
	Dugout *dug1, *dug2;

	// panneau player characteristics
	QLabel *nom, *mvmt1, *mvmt2, *force1, *force2, *agilite1, *agilite2, *armor1, *armor2;
	QLabel *skillsList1;
	QFrame *playerPic;
	QListBox *skillsList2;

	// panneau infos
	QPushButton *dice1, *dice2, *dice3;
	QWidget *d61, *d62;
	QLabel *score, *temps1, *temps2, *currentTurn;
	QPushButton *endTurn;

	// Id du menu
	int dugOutRedId;
	int dugOutBlueId;

	// Variables globales du jeu
	Game *game;

	// Saved values of last pawn clicked
	bool pawnClicked; // true if user clicked on a pawn
	int pawnTeam;
	int pawnNumber;


	// Méthodes privées
	int initValues();

public:
	// Constructeurs & Destructeurs
	Interface( QWidget* parent = 0, const char* name = 0, WFlags f = WType_TopLevel );

public slots:
	int groundClicked(int x, int y);
	void effaceJoueur();
	void afficheJoueur(Joueur *j);

//	void effaceTerrain();

	void newGame();
	void manageTeams();
	void showDugout(int equipe);
	void showDug();
	void showDug2();
	void closeDug(int equipe);

	void showErrorMsg(QString errorMsg);
	void showLogMsg(QString logMsg);

	void dugClicked(int dugNum, int x, int y);


signals:
	void sgnlShowDug(int);

protected:
	void resizeEvent(QResizeEvent *);
};

#endif // INTERFACE_H

//=============================================================================
// Fin du fichier Interface.h
//=============================================================================