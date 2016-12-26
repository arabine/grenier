/*=============================================================================
 * FantasyBowl 1.0 - Skill.h
 *=============================================================================
 * Classe représentant les compétences des joueurs
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

#ifndef SKILL_H
#define SKILL_H

#include <qstring.h>

/**
 *	Types :
 *			0 : compétence
 *			1 : trait
 *			2 : compétence raciale
 *
 */
class Skill
{
private:
	
	int id;			// numéro associé (voir doc)
	QString name;	// nom de la compétence
	int type;		// voir ci-dessus
	QString	description;

public:
	Skill();
	Skill(int num, QString nom, int genre);

	int getId();
	QString getName();
	int getType();

};

#endif // SKILL_H

//=============================================================================
// Fin du fichier Skill.h
//=============================================================================