/*=============================================================================
 * FantasyBowl 1.0 - Game.h
 *=============================================================================
 * Classe principale de gestion du jeu
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 10/03/2003 : première version
 *
 *=============================================================================
 */

#ifndef GAME_H
#define GAME_H

// Classes Qt
#include <qobject.h>
#include <qcanvas.h>
#include <qdom.h>

// Classes du jeu
#include "Equipe.h"
#include "Title.h"


#define WELCOME_MSG "<b>Welcome to FantasyBowl !</b><br>"\
		"<hr><br><br>"\
		"<big>You can start a new game in the <i>Game</i> menu, or manage your"\
		" team right now.</big><br><br>"

/*****************************************************************************/

class Game : public QObject
{

	Q_OBJECT

	/*
		rouge == 1
		bleu == 2
	*/

private:
	int scoreRed;
	int scoreBlue;

	int grille[15][26];			// matrice du plateau de jeu

	// 0 si vide, sinon 100 + numéro du joueur
	int gDugRedReserve[4][4];	// matrice dugout rouge, reserve 
	int gDugBlueReserve[4][4];	// matrice dugout bleu, reserve

	QCanvas		*canvas;		// terrain de jeu == 0
	QCanvas		*canvasDug1;	// banc de touche equipe 1 == 1
	QCanvas		*canvasDug2;	// banc de touche equipe 2 == 2

public:

	// Constructeurs et destructeur
	Game(QWidget* parent);

	// membres publiques
	QList<Skill> skillsList;
	QMap<int, Title> titleList;

	Equipe *bleu, *rouge;		// les deux équipes sur le terrain

	// Accesseurs
	QCanvas* getCanvas(int place);
	int getReserve(int dugNum, int x, int y);

	// Lecture des equipes
	int setTeam(int num, QString filePath);

	// Fonctions membres
	void newGame();
	void saveGame();
	void loadGame();
	void pauseGame();
	void placePion(int x, int y, int equipe, int joueurNum);
	int	readTitles();
	int readSkills();

signals:

	void sgnlSetError(QString err);

};

#endif // GAME_H

//=============================================================================
// Fin du fichier Game.h
//=============================================================================
