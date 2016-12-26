/*=============================================================================
 * Amorce50 - GrilleWindow.cpp
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

#include <QHeaderView>
#include "GrilleWindow.h"

#define PILOTE(a) pilote = "<td align=\"center\">" + ui.driversList->item((a),2)->text() + \
                  " (" + ui.driversList->item((a),3)->text() + ")" + "</td>"

/*****************************************************************************/
GrilleWindow::GrilleWindow() : QDialog()
{
   ui.setupUi(this);
   ui.driversListCat->verticalHeader()->hide();
   ui.driversListCat->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   ui.driversListNotCat->verticalHeader()->hide();
   ui.driversListNotCat->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   ui.driversList->verticalHeader()->hide();
   ui.driversList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

	connect( ui.btnShowGrid, SIGNAL(clicked()), this, SLOT(showStartGrid()) );
	connect( ui.btnTransfert, SIGNAL(clicked()), this, SLOT(transfert()) );
	connect( ui.btnDriverUp, SIGNAL(clicked()), this, SLOT(driverUp()) );
	connect( ui.btnDriverDown, SIGNAL(clicked()), this, SLOT(driverDown()) );

#ifndef _DEBUG
	ui.driversListCat->hideColumn(0);
	ui.driversListNotCat->hideColumn(0);
	ui.driversList->hideColumn(1);

#endif // _DEBUG
}
/*****************************************************************************/
void GrilleWindow::setPilotes( const QMap<int, Pilote> &pil )
{
	pilotes = pil;
}
/*****************************************************************************/
void GrilleWindow::setInfos( int round, const QString &cat, int id_cat )
{
	id_categorie = id_cat;
	categorie = cat;
	manche = round;
}
/*****************************************************************************/
void GrilleWindow::getPilotesDepart(QMap<int, Pilote> &p)
{
   int id;

   p.clear();
   for( int i=0; i<ui.driversList->rowCount(); i++ ) {
      id = ui.driversList->item(i,1)->text().toInt();
      p[id] = pilotes[id];
	}
}
/*****************************************************************************/
/**
 * On range les pilotes dans les deux listes
 */
void GrilleWindow::init()
{
	ui.driversListCat->setRowCount(0);
	ui.driversListNotCat->setRowCount(0);
	
	QMap<int, Pilote>::Iterator it;
	for( it = pilotes.begin(); it != pilotes.end(); ++it ) {
		if( (*it).present == true ) {
			if( (*it).id_categorie == id_categorie ) {
            int n = ui.driversListCat->rowCount();
            ui.driversListCat->setRowCount(n+1);
            ui.driversListCat->setItem(n, 0, new QTableWidgetItem(QString().setNum(it.key())) );
            ui.driversListCat->setItem(n, 1, new QTableWidgetItem((*it).nom) );
            ui.driversListCat->setItem(n, 2, new QTableWidgetItem(QString().setNum( (*it).numero )) );
			} else {
				int n = ui.driversListNotCat->rowCount();
            ui.driversListNotCat->setRowCount(n+1);
            ui.driversListNotCat->setItem(n, 0, new QTableWidgetItem(QString().setNum(it.key())) );
            ui.driversListNotCat->setItem(n, 1, new QTableWidgetItem((*it).nom) );
            ui.driversListNotCat->setItem(n, 2, new QTableWidgetItem(QString().setNum( (*it).numero )) );
			}
		}
	}
}
/*****************************************************************************/
void GrilleWindow::transfert()
{
	int cpt, i;

	ui.driversList->setRowCount(0);
	cpt = 1;

   // On ajoute les pilotes de la catégorie sélectionnés ...
   for( i=0; i<ui.driversListCat->rowCount(); i++ ) {
		QTableWidgetItem *item = ui.driversListCat->item(i,0);
      if( item->isSelected() == true ) {
         int n = ui.driversList->rowCount();
         ui.driversList->setRowCount(n+1);
         ui.driversList->setItem(n, 0, new QTableWidgetItem(QString().setNum(cpt)) );
         ui.driversList->setItem(n, 1, new QTableWidgetItem(ui.driversListCat->item(i,0)->text()) );
         ui.driversList->setItem(n, 2, new QTableWidgetItem(ui.driversListCat->item(i,1)->text()) );
         ui.driversList->setItem(n, 3, new QTableWidgetItem(ui.driversListCat->item(i,2)->text()) );
         cpt++;
      }
	}

   // ... puis les pilotes hors catégorie sélectionnés
   for( i=0; i<ui.driversListNotCat->rowCount(); i++ ) {
		QTableWidgetItem *item = ui.driversListNotCat->item(i,0);
      if( item->isSelected() == true ) {
         int n = ui.driversList->rowCount();
         ui.driversList->setRowCount(n+1);
         ui.driversList->setItem(n, 0, new QTableWidgetItem(QString().setNum(cpt)) );
         ui.driversList->setItem(n, 1, new QTableWidgetItem(ui.driversListNotCat->item(i,0)->text()) );
         ui.driversList->setItem(n, 2, new QTableWidgetItem(ui.driversListNotCat->item(i,1)->text()) );
         ui.driversList->setItem(n, 3, new QTableWidgetItem(ui.driversListNotCat->item(i,2)->text()) );
         cpt++;
      }
	}
}
/*****************************************************************************/
void GrilleWindow::showStartGrid()
{
	QString text;
	int i;

	text = "<center><h1>Grille de départ</h1><br><h2>Catégorie : " + categorie +
			"<br>Manche : " + QString().setNum( manche ) + "</h2><br>";
	
	text += "<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"70%\">";
   
   for( i=0; i<ui.driversList->rowCount(); i++ ) {
		if( i% 2 ) {
         if( ui.radioLeft->isChecked() ) {
				text +=  "<tr><td align=\"center\">" + 
                     ui.driversList->item(i,2)->text() + 
                     " (" + ui.driversList->item(i,3)->text() + ")" + 
                     "</td><td>&nbsp;</td></tr>";
         } else {
				text +=  "<tr><td>&nbsp;</td><td align=\"center\">" + 
                     ui.driversList->item(i,2)->text() + 
                     " (" + ui.driversList->item(i,3)->text() + ")" + 
                     "</td></tr>";
         }
		} else {
         if( ui.radioLeft->isChecked() ) {
				text +=  "<tr><td>&nbsp;</td><td align=\"center\">" + 
                     ui.driversList->item(i,2)->text() + 
                     " (" + ui.driversList->item(i,3)->text() + ")" + 
                     "</td></tr>";
         } else {
				text +=  "<tr><td align=\"center\">" + 
                     ui.driversList->item(i,2)->text() + 
                     " (" + ui.driversList->item(i,3)->text() + ")" + 
                     "</td><td>&nbsp;</td></tr>";
         }
		}
	}

	text += "</table></center>";

   ResultWindow rw;
//	rw.setCaption( QString("Grille de départ") ); // TODO : mettre à jour le titre de la fenêtre
	rw.setText( text );
	rw.exec();
}
/*****************************************************************************/
void GrilleWindow::driverUp()
{
   int index = ui.driversList->currentRow();
   QString tmp;

   if( index<1 ) {
      return;
   }
	
   tmp = ui.driversList->item(index,1)->text();
   ui.driversList->item(index,1)->setText(ui.driversList->item(index-1,1)->text());
   ui.driversList->item(index-1,1)->setText(tmp);
	
   tmp = ui.driversList->item(index,2)->text();
   ui.driversList->item(index,2)->setText(ui.driversList->item(index-1,2)->text());
   ui.driversList->item(index-1,2)->setText(tmp);

   tmp = ui.driversList->item(index,3)->text();
   ui.driversList->item(index,3)->setText(ui.driversList->item(index-1,3)->text());
   ui.driversList->item(index-1,3)->setText(tmp);

   ui.driversList->setCurrentCell(index-1,0);
}
/*****************************************************************************/
void GrilleWindow::driverDown()
{
   int index = ui.driversList->currentRow();
   QString tmp;

   if( index>=(ui.driversList->rowCount()-1) ) {
      return;
   }
	
   tmp = ui.driversList->item(index,1)->text();
   ui.driversList->item(index,1)->setText(ui.driversList->item(index+1,1)->text());
   ui.driversList->item(index+1,1)->setText(tmp);
	
   tmp = ui.driversList->item(index,2)->text();
   ui.driversList->item(index,2)->setText(ui.driversList->item(index+1,2)->text());
   ui.driversList->item(index+1,2)->setText(tmp);

   tmp = ui.driversList->item(index,3)->text();
   ui.driversList->item(index,3)->setText(ui.driversList->item(index+1,3)->text());
   ui.driversList->item(index+1,3)->setText(tmp);

   ui.driversList->setCurrentCell(index+1,0);
}

//=============================================================================
// Fin du fichier GrilleWindow.cpp
//=============================================================================
