/*=============================================================================
 * FantasyBowl 1.0 - Equipe.h
 *=============================================================================
 * Classe repr�sentant une �quipe
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0 / g++ Avec librairies Qt 2.3 minimum
 *  
 * Cette classe fait appel � la classe Joueur pour repr�senter les joueurs
 * sur le terrain.
 *
 * Historique :
 * 
 * 02/03/2003 : premi�re version
 *
 *=============================================================================
 */

#ifndef EQUIPE_H
#define EQUIPE_H

// Librairies Qt
#include <qlist.h>
#include <qdom.h>
#include <qlist.h>
#include <qfile.h>
#include <qcanvas.h>

// Classes du jeu
#include "Joueur.h"
#include "Title.h"

class Equipe
{

private:
	int numEquipe;		// num�ro de l'�quipe (bleu ou rouge)

	QString nom;		// nom de l'�quipe
	QString race;		// race de l'�quipe
	int rating;			// classement
	int treasury;		// argent restant
	QString coach;		// nom du coach
	QString logo;		// nom du fichier logo
	int reroll;			// nombre de relances
	int rerollCost;		// prix d'une relance
	int fanFactor;		// facteur de popularit� (1<=fanFactor<=9)
	int assistants;		// nombre d'assistants
	int cheerleaders;	// nombre de pom-pom girls
	int apothecary;		// nombre d'apothicaires
	int wizard;			// nombre de magos

public:
	Equipe(int num);

	QList<Joueur> playerList;

	int getNum();
	int	readXMLFile(QList<Skill> theSkillList, QString filePath, QCanvas *terrain);
	
	void setGround(int joueurNum, QCanvas *can);
	int setCoord(int joueurNum, int x, int y);
	void setPawns(const QMap<int, Title> &titleList);

	// Accesseurs
	QString	getName();
	QString getRace();
	int		getRating();
	int		getTreasury();
	QString	getCoach();
	QString	getLogo();
	int		getReroll();
	int		getRerollCost();
	int		getFanFactor();
	int		getAssistants();
	int		getCheerleaders();
	int		getApothecary();
	int		getWizard();

};

#endif // EQUIPE_H

//=============================================================================
// Fin du fichier Equipe.h
//=============================================================================