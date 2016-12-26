/*=============================================================================
 * Amorce50 - Amorce50.h
 *=============================================================================
 * Amorce50 : fenêtre principale d'Amorce50
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
#include <QApplication>
#include <QMainWindow>


// Includes locales
#include "ui/ui_Main.h"
#include "ui/ui_About.h"
#include "ui/ui_RaceEdit.h"
#include "ui/ui_PilotesPresents.h"
#include "ResultWindow.h"
#include "ParametresWindow.h"
#include "PointageWindow.h"
#include "Classes.h"

/*****************************************************************************/
class AboutWindow : public QDialog
{

private:
   Ui::About   ui;
public:
   AboutWindow() : QDialog() {
      ui.setupUi(this);
   }

};
/*****************************************************************************/
class Amorce50 : public QMainWindow
{
	Q_OBJECT

private:

	// Fenêtres
   Ui::Main				ui;
	ParametresWindow	parametresWindow;
	PointageWindow		pointageWindow;
	AboutWindow			aboutBoxWindow;
	ResultWindow		resultWindow;

	// Variables du jeu
	QString			mainPath;

	// Correspondance des key et des index dans les Widgets
	QMap<int, int>    categoriesKey;
	QMap<int, int>	   saisonsKey;

protected:
	void		closeEvent( QCloseEvent * );

public:
	Amorce50();

public slots:
	
	// Onglets du panneau de paramètres
	void		showSeasons();
	void		showDrivers();
	void		showCategories();
	void		showRules();

	// Groupbox Courses
	void		newRace();
	void		editRace();
	void		deleteRace();
	void		pilotesPresents();

	// Groupbox des manches
	void		showPointage();
	void		sauvePointage();
	void		pointage( bool );

	void		addRound();
	void		editRound();
	void		deleteRound();

	// Classements
	void		showClassementCategorie();

   void	   print();
   void     exitAmorce50();
   int		chargeXML();

	void		updateRaces( int );
	void		slotUpdateSeasons();
	void		slotUpdateCategories();
	void		slotUpdateRounds();
	void		slotUpdatePilotes();
	void		slotUpdatePoints();
};


//=============================================================================
// Fin du fichier Amorce50.h
//=============================================================================
