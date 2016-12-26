
#ifndef CLASSES_H
#define CLASSES_H

#include <QString>
#include <QDate>
#include <QAbstractItemModel>
#include "defines.h"

/*****************************************************************************/
class Categorie
{
public:
   int   id;
   int   id_cat_parent; // -1 = pas de catégorie parente, sinon l'id de la catégorie
   QString nom;

   Categorie()
   {
      id = 0;
      id_cat_parent = -1;
      nom = "";
   }
   
   Categorie( int i, int i2, QString n )
   {
      id = i;
      id_cat_parent = i2;
      nom = n;
   }

};
/*****************************************************************************/
class Arrivee
{

public:
   STATUT_PILOTE statut;
	int		tours;
	int		rang;

	Arrivee()
	{
		tours = 0;
		rang = 0;
	}
	Arrivee( int t, int r)
	{
		tours = t;
		rang = r;
	}

};
/*****************************************************************************/
class Pilote
{

public:

	int		id;
	QString nom;
	int		numero;
	QString club;
	int		id_categorie;
	bool	present;

	Pilote()
	{
		id = 0;
		nom = "";
		numero = 0;
		club = "";
		id_categorie = 0;
		present = false;
	}
	Pilote( int i, QString &s, int n, QString &c, int cat )
	{
		id = i;
		nom = s;
		numero = n;
		club = c;
		id_categorie = cat;
	}

};
/*****************************************************************************/
class Course
{

public:

	int		id;
	QString nom;
	QDate	date;

	Course()
	{
		id = 0;
		nom = "";
	}
	Course( int i, const QString &s, const QDate &d )
	{
		id = i;
		nom = s;
		date = d;
	}

};
/*****************************************************************************/
class Epreuve
{

public:

	int		id_manche;
	int		id_pilote;
	int		place;
	int		tours;
	int		statut;

	Epreuve()
	{
		id_manche = 0;
		id_pilote = 0;
		place = 0;
		tours = 0;
	}
	Epreuve( int m, int pi, int pl, int t, int s )
	{
		id_manche = m;
		id_pilote = pi;
		place = pl;
		tours = t;
		statut = s;
	}

};
/*****************************************************************************/
class Manche
{

public:

	int		id;
	int		numero;
	int		statut;
	/*
	statut =	0 : manche non courue
				1 : en cours
				2 : terminée
	*/

	QString pointage;
	int		premier;

	Manche()
	{
		id = 0;
		numero = 0;
		statut = 0;
		pointage = "";
		premier = 0;
	}
	Manche( int i, int n, int s, const QString &p, int f )
	{
		id = i;
		numero = n;
		statut = s;
		pointage = p;
		premier = f;
	}

};
/*****************************************************************************/




#endif // CLASSES_H

//=============================================================================
// Fin du fichier Classes.h
//=============================================================================
