/*=============================================================================
 * FantasyBowl 1.0 - Skill.h
 *=============================================================================
 * Classe repr�sentant les comp�tences des joueurs
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 02/03/2003 : premi�re version
 *
 *=============================================================================
 */

#ifndef SKILL_H
#define SKILL_H

#include <qstring.h>

/**
 *	Types :
 *			0 : comp�tence
 *			1 : trait
 *			2 : comp�tence raciale
 *
 */
class Skill
{
private:
	
	int id;			// num�ro associ� (voir doc)
	QString name;	// nom de la comp�tence
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