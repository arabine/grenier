/*=============================================================================
 * Amorce50 - Resultat.h
 *=============================================================================
 * Resultat : regroupe les infos d'un classement et génère le tableau
 *=============================================================================
 * Amorce50 est un logiciel de pointage manuel pour courses amateurs de 50cm3
 * Copyright (C) 2004-2007  Anthony Rabine
 * anthony@ooso.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *=============================================================================
 */

// Includes Qt
#include <Qmap>

// Includes locales
#include "Classes.h"

/****************************************************************************/
class Resultat
{
public:

	QString		tableau;

	Course		course;
	Manche		manche;
	QString		saison;
	QString		categorie;
	
	QMap<int, Pilote>	pilotes;
	QMap<int, Epreuve>	epreuves;
	QMap<int, int>		points;

	Resultat();

	void	clear();
	void	makeTable();

};

//=============================================================================
// Fin du fichier Resultat.h
//=============================================================================
