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

#include "Resultat.h"

/****************************************************************************/
Resultat::Resultat()
{

}
/****************************************************************************/
void Resultat::clear()
{
	tableau = "";
	saison = "";
	categorie = "";
	
	pilotes.clear();
	epreuves.clear();
}
/****************************************************************************/
void Resultat::makeTable()
{
	QString abandons;

	tableau = "<center><h1>Résultats de la manche " + QString().setNum( manche.numero ) + "</h1>";
	tableau += "<h2>Saison : " + saison + "</h2>";
	tableau += "<h2>Course : " + course.nom + " - " + course.date.toString("d MMM yyyy") + "</h2>";
	tableau += "<h2>Catégorie : " + categorie + "</h2></center><br><br>";

	// On range dans l'ordre place, id_pilote
	QMap<int, int> ordre;
	QMap<int, int> tours;
	QMap<int, Epreuve>::Iterator it;
	for( it = epreuves.begin(); it != epreuves.end(); ++it ) {
		if( (*it).place == 0 ) {
			abandons += "<tr>";
			abandons += "<td>ABANDON</td>";
			abandons += "<td>" + QString().setNum(pilotes[(*it).id_pilote].numero) + "</td>";
			abandons += "<td>" + pilotes[(*it).id_pilote].nom + "</td>";
			abandons += "<td>" + QString().setNum((*it).tours) + "</td>";
			abandons += "<td>" + pilotes[(*it).id_pilote].club + "</td>";
			abandons += "<td>0</td>"; // points
			abandons += "</tr>";
		} else {
			tours[ (*it).place ] = (*it).tours;
			ordre[ (*it).place ] = (*it).id_pilote;
		}
	}

	// On génère le tableau HTML
	tableau += "<center><table  width=\"80%\" border=\"1\">";

	// le Header
	tableau += "<tr>";
	tableau += "<th>Place</th>";
	tableau += "<th>Numéro</th>";
	tableau += "<th>Pilote</th>";
	tableau += "<th>Tours</th>";
	tableau += "<th>Club</th>";
	tableau += "<th>Points</th>";
	tableau += "</tr>";

	QMap<int, int>::Iterator it2;
	for( it2 = ordre.begin(); it2 != ordre.end(); ++it2 ) {
		tableau += "<tr>";
		tableau += "<td align=\"center\">" + QString().setNum( it2.key() ) + "</td>";
		tableau += "<td align=\"center\">" + QString().setNum(pilotes[it2.value()].numero) + "</td>";
		tableau += "<td>" + pilotes[it2.value()].nom + "</td>";
		tableau += "<td align=\"center\">" + QString().setNum(tours[ it2.key() ]) + "</td>";
		tableau += "<td>" + pilotes[it2.value()].club + "</td>";
		tableau += "<td align=\"center\">" + QString().setNum( points[it2.key()] ) + "</td>";
		tableau += "</tr>";
	}

	tableau += abandons;
	tableau += "</table></center><br>";
}

//=============================================================================
// Fin du fichier Resultat.cpp
//=============================================================================
