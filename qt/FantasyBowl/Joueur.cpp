/*=============================================================================
 * FantasyBowl 1.0 - Joueur.cpp
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
 *=============================================================================
 */

#include "Joueur.h"

/*****************************************************************************/
Joueur::Joueur(int equ, QCanvas *canvas) : 
		QCanvasSprite(new QCanvasPixmapArray( "pics/vide.png" ), canvas)
{
	equipe = equ;
}
/*****************************************************************************/
void Joueur::setPawn(QString pawn)
{
	if(equipe==1)
		setSequence( new QCanvasPixmapArray("pawns/" + pawn + "1.png"));	// pion rouge
	else
		setSequence( new QCanvasPixmapArray("pawns/" + pawn + "2.png"));	// pion bleu
}
/*****************************************************************************/
void Joueur::setName(QString nom)
{
	name = nom;
}
/*****************************************************************************/
void Joueur::setNumero(int num)
{
	numero = num;
}
/*****************************************************************************/
void Joueur::setPosition(int pos)
{
	position = pos;

}
/*****************************************************************************/
void Joueur::setTitle(QString titleName)
{
	title = titleName;
}
/*****************************************************************************/
void Joueur::setMa(int mov)
{
	ma = mov;
}
/*****************************************************************************/
void Joueur::setSt(int str)
{
	st = str;
}
/*****************************************************************************/
void Joueur::setAg(int agi)
{
	ag = agi;
}
/*****************************************************************************/
void Joueur::setAv(int arm)
{
	av = arm;
}
/*****************************************************************************/
void Joueur::setCost(int co)
{
	cost = co;
}
/*****************************************************************************/
void Joueur::setPic(QString image)
{
	pic = image;
}
/*****************************************************************************/
QString Joueur::getPic()
{
	return pic;
}
/*****************************************************************************/
QString Joueur::getName()
{
	return name;
}
/*****************************************************************************/
int Joueur::getPosition()
{
	return position;
}
/*****************************************************************************/
QString Joueur::getTitle()
{
	return title;
}
/*****************************************************************************/
int Joueur::getNumero()
{
	return numero;
}
/*****************************************************************************/
int	Joueur::getMa()
{
	return ma;
}
/*****************************************************************************/
int	Joueur::getSt()
{
	return st;
}
/*****************************************************************************/
int	Joueur::getAg()
{
	return ag;
}
/*****************************************************************************/
int	Joueur::getAv()
{
	return av;
}
/*****************************************************************************/
int	Joueur::getCost()
{
	return cost;
}

//=============================================================================
// Fin du fichier Joueur.cpp
//=============================================================================