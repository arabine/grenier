/*=============================================================================
 * Amorce50 - GrilleWindow.h
 *=============================================================================
 * GrilleWindow : choix des pilotes sur la grille de départ
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
#include <QDialog>
#include <QPushbutton>
#include <QMap>
#include <QTextBrowser>

// Includes locales
#include "ui/ui_Grille.h"
#include "ResultWindow.h"
#include "Classes.h"


/****************************************************************************/
class GrilleWindow : public QDialog
{
	Q_OBJECT

private:
	
   Ui::Grille  ui;
	int			id_categorie;
	int			manche;
	QString		categorie;
	QMap<int, Pilote>	pilotes;		// Liste de tous les pilotes enregistrés
	
public:
	GrilleWindow();

	void init();
	void setPilotes( const QMap<int, Pilote> & );
	void setInfos( int, const QString &, int );
   void getPilotesDepart(QMap<int, Pilote> &p);

public slots:
	void transfert();
	void showStartGrid();
	void driverUp();
	void driverDown();

};

//=============================================================================
// Fin du fichier GrilleWindow.h
//=============================================================================
