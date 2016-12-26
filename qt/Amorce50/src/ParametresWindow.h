/*=============================================================================
 * Amorce50 - ParametresWindow.h
 *=============================================================================
 * ParametresWindow : fenêtre d'édition de la BDD
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
#include <QSqlDatabase>

// Includes locales
#include "ui/ui_Parametres.h"
#include "ui/ui_SeasonEdit.h"
#include "ui/ui_CategoryEdit.h"
#include "ui/ui_DriverEdit.h"
#include "ui/ui_PointsEdit.h"
#include "ui/ui_SousCat.h"
#include "Classes.h"
#include "Resultat.h"
#include "defines.h"


/*****************************************************************************/
class ParametresWindow : public QDialog
{
	Q_OBJECT

private:

   Ui::Parametres ui;
	QString			mainPath;
	QSqlDatabase	db;

public:
	ParametresWindow();

	QMap<int, QString>	saisons;
	QMap<int, Categorie>	categories;
	QMap<int, int>			categoriesKey;		// pour le comboBox
	QMap<int, int>			points;

	QMap<int, Pilote>		pilotes;
	QMap<int, Course>		courses;			// stocke les courses de la saison sélectionnée
	QMap<int, Manche>		manches;			// stocke les manches selon la catégorie/course choisies

	Resultat	res;							// stocke toutes les infos d'un classement et génère un tableau

	void	setPath( const QString & );
	bool	initCnx();
	void	setCurrentPage( int );
	int	loadBDD();
	void	optimizeDataBase();
	void	fillResult();

	// Courses
	int	addRace( const QString &, const QDate &, int );
	bool	editRace( const QString &, const QDate &, int );
	bool	deleteRace( int );
	void	updateRaceList( int );

	// Manches
	void	updateRounds( int, int );
	void	ajouteManche( int, int );
	void	deleteManche( int );
	void	terminerManche( int, int, const QString &, int );
	
	// Epreuves
	bool	addEpreuves( QList<Epreuve> & );
	void	razEpreuves( int );

signals:
	void	sgnlUpdateSeasons();
	void	sgnlUpdateCategories();
	void	sgnlUpdatePilotes();
	void	sgnlUpdatePoints();

public slots:

	// Onglet Saisons
	void	slotAddSeason();
	void	slotEditSeason();
	void	slotDeleteSeason();

	// Onglet Pilotes
	void	slotAddDriver();
	void	slotEditDriver();
	void	slotDeleteDriver();

	// Onglet Catégories
	void	slotAddCategory();
	void	slotEditCategory();
	void	slotDeleteCategory();
   void	slotSousCat();

	// Onglet Règlement
	void	slotAddPosition();
	void	slotEditPosition();

	void	slotUpdateCategories();
	void	slotUpdatePilotes();
};

//=============================================================================
// Fin du fichier ParametresWindow.h
//=============================================================================
