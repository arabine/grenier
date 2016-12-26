/*=============================================================================
 * FantasyBowl 1.0 - Joueur.h
 *=============================================================================
 * Classe représentant un joueur sur le terrain
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Notes : utilise la classe Skill pour représenter ses compétences
 *			Cette classe est représentée graphiquement par un pion sur le 
 *			canevas.
 * 
 * 
 * Historique :
 * 
 * 24/07/2003 : added method
 * 02/03/2003 : première version
 *
 *=============================================================================
 */

#ifndef JOUEUR_H
#define JOUEUR_H

// Librairies Qt
#include <qcanvas.h>
#include <qlist.h>

// Classes du jeu
#include "Skill.h"

class Joueur : public QCanvasSprite
{

private:
	int numero;			// numéro du joueur
	int position;		// title number (see data/titles.xml)
	QString title;		// the title name
	int equipe;			// the team of the player
	QString name;		// nom du joueur
	QString pic;		// image du joueur
	int ma;				// Movement Allowance
	int st;				// Strength
	int ag;				// Agility
	int av;				// Armour Value
	int cost;			// coût

public:
	// call this constructor to use class Joueur to only store data
	Joueur() : QCanvasSprite(0,0) {}

	// use this one to store real players on field
    Joueur(int equipe, QCanvas *canvas);

	QList<Skill> playerSkills;

	// Mutateurs
	void setPawn(QString pawn);
	void setPic(QString image);
	void setName(QString nom);
	void setNumero(int num);
	void setPosition(int pos);
	void setTitle(QString titleName);
	void setMa(int mov);
	void setSt(int str);
	void setAg(int agi);
	void setAv(int arm);
	void setCost(int co);

	// Accesseurs
	QString getPic();
	QString getName();
	int		getPosition();
	QString getTitle();
	int		getNumero();
	int		getMa();
	int		getSt();
	int		getAg();
	int		getAv();
	int		getCost();
};

#endif // JOUEUR_H

//=============================================================================
// Fin du fichier Joueur.h
//=============================================================================