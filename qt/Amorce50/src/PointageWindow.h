/*=============================================================================
 * Amorce50 - PointageWindow.h
 *=============================================================================
 * PointageWindow : fenêtre de pointage des pilotes
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
#include <QTextEdit>
#include <QRegExp>
#include <QStringList>
#include <QMessageBox>
#include <QInputDialog>
#include <QMap>

// Includes locales
#include "ui/ui_Pointage.h"
#include "GrilleWindow.h"
#include "Classes.h"

/****************************************************************************/
class PointageWindow : public QDialog
{
	Q_OBJECT

private:

   Ui::Pointage   ui;
	bool	         pointageFini;
	int		      statut; // 0 = non courue, 1 = déjà courue
	GrilleWindow	*gw;
   QMap<int, Arrivee> course; //<numéro, Arrivée>

   void updatePoints();

public:
	PointageWindow();

	
	QMap<int, Pilote>	pilotesDepart;	// Sélection des pilotes au départ
	QMap<int, int>		points;

	void init();
	void setInfos( int, const QString &, int );
	void setPilotes( const QMap<int, Pilote> & );
   void setPointage( const QString &txt );
   void setPremier( int first );
   QString getPointage() const;
   int getPremier();
   void getResult( QList<Epreuve> &epreuves, int id_manche );

signals:
   void sgnlSauvePointage();

public slots:

   void slotSauvePointage();
	void calculer();
	void showGrid();
	void sauveEtQuitte();
   void slotToggleQualif();
};

//=============================================================================
// Fin du fichier PointageWindow.h
//=============================================================================
