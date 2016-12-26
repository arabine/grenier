/*=============================================================================
 * Amorce50 - Amorce50.cpp
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

#include <QDir>
#include <QtXml>
#include <QTableWidget>
#include <QHeaderView>
#include <QListWidget>
#include "Amorce50.h"
#include "ui/ui_RaceEdit.h"
#include "ui/ui_PilotesPresents.h"

/*****************************************************************************/
Amorce50::Amorce50() : QMainWindow()
{
   ui.setupUi(this);

   setWindowTitle(QString("Amorce50") + " - " + QString(AMORCE50_VERSION));

	// On cherche le chemin du répertoire racine de l'application
	QDir b = qApp->applicationDirPath();
	b.cdUp();
	mainPath = b.path();

	//=========================== Fenêtres filles =====================================
	parametresWindow.hide();
	parametresWindow.setPath( mainPath );
	pointageWindow.hide();
	resultWindow.hide();
	aboutBoxWindow.hide();


	//===========================   Menu   =====================================
   connect( ui.actionQuitter, SIGNAL(triggered()), this, SLOT(exitAmorce50()) );
   connect( ui.actionAPropos, SIGNAL(triggered()), &aboutBoxWindow, SLOT(show()) );
   connect( ui.actionParametres, SIGNAL(triggered()), &parametresWindow, SLOT(exec()) );
   
   connect( ui.actionCategories, SIGNAL(triggered()), this, SLOT(showCategories()) );
   connect( ui.actionSaisons, SIGNAL(triggered()), this, SLOT(showSeasons()) );
   connect( ui.actionPilotes, SIGNAL(triggered()), this, SLOT(showDrivers()) );
   connect( ui.actionReglement, SIGNAL(triggered()), this, SLOT(showRules()) );


	//=========================== Interface =====================================
   ui.racesList->verticalHeader()->hide();
   ui.racesList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   ui.categoriesList->verticalHeader()->hide();
   ui.categoriesList->horizontalHeader()->hide();
   ui.categoriesList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   ui.roundsList->verticalHeader()->hide();
   ui.roundsList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

#ifndef _DEBUG

	ui.racesList->hideColumn(0);
	ui.roundsList->hideColumn(0);
   ui.categoriesList->hideColumn(0);

#endif // _DEBUG


	statusBar()->showMessage("Bienvenue sur Amorce50.");
	statusBar()->setSizeGripEnabled( true );

	setMinimumSize( 800, 500 );
	resize( 800, 500);

   //===========================  Signaux  =====================================
	connect( &parametresWindow, SIGNAL(sgnlUpdateSeasons()), this, SLOT(slotUpdateSeasons()) );
	connect( &parametresWindow, SIGNAL(sgnlUpdateCategories()), this, SLOT(slotUpdateCategories()) );
	connect( &parametresWindow, SIGNAL(sgnlUpdatePilotes()), this, SLOT(slotUpdatePilotes()) );
	connect( &parametresWindow, SIGNAL(sgnlUpdatePoints()), this, SLOT(slotUpdatePoints()) );

	connect( ui.seasonsList, SIGNAL(activated(int)), this, SLOT(updateRaces(int)) );
	connect( ui.racesList, SIGNAL(cellClicked (int,int)), this, SLOT(slotUpdateRounds()) );
	connect( ui.categoriesList, SIGNAL(cellClicked (int,int)), this, SLOT(slotUpdateRounds()) );

	// Course
	connect( ui.btnNewRace, SIGNAL( clicked() ), this, SLOT( newRace() ) );
	connect( ui.btnEditRace, SIGNAL( clicked() ), this, SLOT( editRace() ) );
	connect( ui.btnDeleteRace, SIGNAL( clicked() ), this, SLOT( deleteRace() ) );
	connect( ui.btnPilotesPresents, SIGNAL( clicked() ), this, SLOT( pilotesPresents() ) );
	
	// Manches
	connect( ui.btnPointage, SIGNAL( clicked() ), this, SLOT( showPointage() ) );
	connect( ui.btnEditRound, SIGNAL( clicked() ), this, SLOT( editRound() ) );
	connect( ui.btnAddRound, SIGNAL( clicked() ), this, SLOT( addRound() ) );
	connect( ui.btnDeleteRound, SIGNAL( clicked() ), this, SLOT( deleteRound() ) );

	// Classements
	connect( ui.btnClassCategorie, SIGNAL( clicked() ), this, SLOT( showClassementCategorie() ) );
   
   // Pointage
   connect( &pointageWindow, SIGNAL( sgnlSauvePointage() ), this, SLOT( sauvePointage() ) );

	// Initialisation des données enregistrées
	if( parametresWindow.initCnx() == false ) {
		QMessageBox::critical( 0, "Erreur",
								"Erreur lors de l'initialisation de la base de données." );
	}

	if( parametresWindow.loadBDD() != 0 ) {
		QMessageBox::critical( 0, "Erreur",
								"Erreur lors du chargement des données." );
	}

	// On charge le fichier XML des préférences (s'il existe)
	chargeXML();
}
/*****************************************************************************/
void Amorce50::showSeasons()
{
	parametresWindow.setCurrentPage( 0 );
	parametresWindow.exec();
}
/*****************************************************************************/
void Amorce50::showDrivers()
{
	parametresWindow.setCurrentPage( 1 );
	parametresWindow.exec();
}
/*****************************************************************************/
void Amorce50::showCategories()
{
	parametresWindow.setCurrentPage( 2 );
	parametresWindow.exec();
}
/*****************************************************************************/
void Amorce50::showRules()
{
	parametresWindow.setCurrentPage( 3 );
	parametresWindow.exec();
}
/*****************************************************************************/
void Amorce50::pilotesPresents()
{
	QDialog *pp = new QDialog(this);
   Ui::PilotesPresents pp_ui;
   pp_ui.setupUi(pp);
   QList<int> ids;

	pp_ui.listePresents->clear();
	
	QMap<int, Pilote>::Iterator it;
	for( it = parametresWindow.pilotes.begin(); it != parametresWindow.pilotes.end(); ++it ) {      
		QListWidgetItem *item = new QListWidgetItem( (*it).nom );
      if( (*it).present == true ) {
         item->setCheckState(Qt::Checked);
      } else {
         item->setCheckState(Qt::Unchecked);
      }
      pp_ui.listePresents->addItem(item);
      ids.append(it->id);
	}

	if( pp->exec() == QDialog::Accepted ) {
		// On crée le document
		QDomDocument doc("Amorce50");

		doc.appendChild( doc.createProcessingInstruction( "xml", "version=\"1.0\" encoding=\"ISO-8859-1\"" ) );
		doc.appendChild(doc.createTextNode("\n"));

		doc.appendChild(doc.createComment( QString("Généré par Amorce50 ")+QString(AMORCE50_VERSION) ) );
		doc.appendChild(doc.createTextNode("\n"));

		// root node
		QDomElement rootNode = doc.createElement("Amorce50");
		rootNode.setAttribute("version", "1.0");
		doc.appendChild(rootNode);
		
		// Liste des pilotes présents
		QDomElement presentsNode = doc.createElement("presents");
		rootNode.appendChild(presentsNode);
      
		for (int i=0; i<pp_ui.listePresents->count(); i++) {
			if( pp_ui.listePresents->item(i)->checkState() == Qt::Checked ) {
				parametresWindow.pilotes[ ids.at(i) ].present = true;
				// Pilote présent
				QDomElement piloteNode = doc.createElement("pilote");
				piloteNode.appendChild(doc.createTextNode( QString().setNum( ids.at(i) ) ));
				presentsNode.appendChild(piloteNode);
         } else {
				parametresWindow.pilotes[ ids.at(i) ].present = false;
         }
		}

		// Sauvegarde du document DOM en mémoire
		QFile f( "amorce50.xml" );
		if(!f.open(QIODevice::WriteOnly)) {
			QMessageBox::information( this, "Amorce50",
			"Impossible d'enregistrer les paramètres.\n" );
		} else {
         QTextStream out(&f);
         out << doc.toString();
			f.close();
		}
	}
}
/*****************************************************************************/
int Amorce50::chargeXML()
{
	QDomDocument doc;

	QFile f( "amorce50.xml" );

	// Fichier non trouvé, on sort
	if( f.open(QIODevice::ReadOnly) == false ) {
		f.close();
		return 1;
	}

	doc.setContent(&f);
	f.close();


	//=== On parse le fichier ===//

	// On teste le tag racine "TarotClub"
	QDomElement root=doc.documentElement();
   if(root.tagName()!="Amorce50") {
		return 2;
   }

   if(root.attribute("version","0")!="1.0") {
		return 3;
   }

	// On parse les données
	QDomElement child=root.firstChild().toElement();

	while(!child.isNull()) {
		if(child.tagName() == "presents") {
			QDomElement subchild = child.firstChild().toElement();
			while(!subchild.isNull()) {
				int val;

				if(subchild.tagName() == "pilote") {
					val = subchild.text().toInt();
               if( parametresWindow.pilotes.contains(val) ) {
					   parametresWindow.pilotes[ val ].present = true;
               }
				}
				
				subchild = subchild.nextSibling().toElement();
			}
		}
		child = child.nextSibling().toElement();
	}

	return 0;
}
/*****************************************************************************/
void Amorce50::showClassementCategorie()
{
   int index_round = ui.roundsList->currentRow();
   if( index_round < 0 ) {// pas de sélection
		return;
   }

   int index_cat = ui.categoriesList->currentRow();
   if( index_cat < 0 ) {// pas de sélection
		return;
   }

   int index_race = ui.racesList->currentRow();
   if( index_race < 0 ) {// pas de sélection
		return;
   }

 //  for( int i=0; i<ui.roundsList->rowCount(); i++ ) {
		int id_round = ui.roundsList->item(index_round,0)->text().toInt();

      parametresWindow.res.clear();
		parametresWindow.res.categorie = ui.categoriesList->item(index_cat,1)->text();
      parametresWindow.res.saison = ui.seasonsList->currentText();
		parametresWindow.res.course = parametresWindow.courses[ui.racesList->item(index_race,0)->text().toInt()];
		parametresWindow.res.manche = parametresWindow.manches[id_round];
		parametresWindow.res.points = parametresWindow.points;

		// On remplit par les épreuves et les pilotes ayant couru cette manche
		parametresWindow.fillResult();
//	}

	parametresWindow.res.makeTable();

   ResultWindow rw;
	rw.setText( parametresWindow.res.tableau );
	rw.exec();
}
/*****************************************************************************/
void Amorce50::addRound()
{
   int index = ui.racesList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }
	
   if( ui.categoriesList->rowCount() == 0  || ui.categoriesList->currentRow() <0 ) {
		return;
   }

	parametresWindow.ajouteManche(   ui.racesList->item(index,0)->text().toInt(), 
                                    categoriesKey[ui.categoriesList->currentRow()] );
	slotUpdateRounds();
}
/*****************************************************************************/
void Amorce50::editRound()
{
	pointage( true );
}
/*****************************************************************************/
void Amorce50::showPointage()
{
	pointage( false );
}
/*****************************************************************************/
void Amorce50::pointage( bool edit )
{
   int index = ui.roundsList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }
	
	int id_manche = ui.roundsList->item(index,0)->text().toInt();
   int index_cat = ui.categoriesList->currentRow();
   
   slotUpdatePilotes();

   /**
    * Edition
    */
   if( edit == true ) {
		if( parametresWindow.manches[id_manche].statut == 0 ) {
			QMessageBox::information( 0, "Information",
									"Aucune information à éditer.\n" );
			return;
		}

      pointageWindow.setInfos(	ui.roundsList->item(index,1)->text().toInt(), ui.categoriesList->item(index_cat,1)->text(), 
							            categoriesKey[ui.categoriesList->currentRow()] );
		pointageWindow.init();
		pointageWindow.setPointage( parametresWindow.manches[id_manche].pointage );
		pointageWindow.setPremier( parametresWindow.manches[id_manche].premier );
 
   /**
    * Nouveau pointage
    */
   } else {
		if( parametresWindow.manches[id_manche].statut == 2 || parametresWindow.manches[id_manche].statut == 1 ) {
			QMessageBox::information( 0, "Information",
									"Cette manche contient déjà des informations.\n"
									"Vous pouvez l'éditer ou visualiser le résultat si\n"
									"elle est terminée." );
			return;
		}

		pointageWindow.setInfos(	ui.roundsList->item(index,1)->text().toInt(), ui.categoriesList->item(index_cat,1)->text(), 
							            categoriesKey[ui.categoriesList->currentRow()] );
		pointageWindow.init();
	}

	if( pointageWindow.exec() == QDialog::Accepted ) {
		QList<Epreuve> epreuves;
      pointageWindow.getResult(epreuves,id_manche);

      if( edit == true ) {
			// on efface les épreuves associées à cette manche
			parametresWindow.razEpreuves( id_manche );
		}

		bool ret = parametresWindow.addEpreuves( epreuves ); // on crée les épreuves associées

		if( ret == true ) {
			parametresWindow.terminerManche( id_manche, 2, pointageWindow.getPointage(), pointageWindow.getPremier() );
			slotUpdateRounds();
		}
	}
   ui.roundsList->setCurrentCell(index,0);
}
/*****************************************************************************/
void Amorce50::deleteRound()
{
   int index = ui.roundsList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }

	switch( QMessageBox::warning( this, "Attention",
        "Attention, si vous supprimez cette manche vous\n"
        "supprimerez également toutes les épreuves associées.\n\n",
        "Continuer",
        "Annuler", 0, 0, 1 ) )
	{
		case 0: // On continue
			break;
		case 1:
			return;
			break;
		default:
			return;
			break;
    }

	parametresWindow.deleteManche( ui.roundsList->item(index,0)->text().toInt() );	
	slotUpdateRounds();
}
/*****************************************************************************/
/**
 * On sauvegarde juste le pointage et le premier pilote
 * On place cette manche en statut "en cours" (1)
 */
void Amorce50::sauvePointage()
{
   int index = ui.roundsList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }

	parametresWindow.terminerManche( ui.roundsList->item(index,0)->text().toInt(), 1, pointageWindow.getPointage(), pointageWindow.getPremier() );

	QMessageBox::information( this, "Opération réussie",
								"Le pointage et le premier pilote ont été sauvegardés avec succès." );

	slotUpdateRounds();
   ui.roundsList->setCurrentCell(index,0);
}
/*****************************************************************************/
void Amorce50::slotUpdatePilotes()
{
	pointageWindow.setPilotes( parametresWindow.pilotes );
}
/*****************************************************************************/
void Amorce50::slotUpdatePoints()
{
	pointageWindow.points = parametresWindow.points;
}
/*****************************************************************************/
void Amorce50::slotUpdateSeasons()
{
	int i;

	ui.seasonsList->clear();

	if( parametresWindow.saisons.count() == 0 ) {
		ui.racesList->setRowCount(0);
		ui.roundsList->setRowCount(0);
		return;
	}

	QMap<int, QString>::Iterator it;
   i = 0;
	for( it = parametresWindow.saisons.begin(); it != parametresWindow.saisons.end(); ++it ) {
      ui.seasonsList->addItem(it.value());
		saisonsKey[i++] = it.key();      
	}

	if( ui.seasonsList->count() != 0 ) {
		ui.seasonsList->setCurrentIndex( ui.seasonsList->count()-1 );
      updateRaces(ui.seasonsList->currentIndex());
	} else {
		ui.racesList->setRowCount(0);
		ui.roundsList->setRowCount(0);
	}

}
/*****************************************************************************/
/**
 * Rafraichi la liste des courses en cas de changements de saisons
 */
void Amorce50::updateRaces( int saisonID )
{
   ui.racesList->setRowCount(0);
   ui.roundsList->setRowCount(0);

	int id = saisonsKey[saisonID];
	parametresWindow.updateRaceList( id );

   if( parametresWindow.courses.count() == 0 ) {
		return;
   }

	QMap<int, Course>::Iterator it;
	for( it = parametresWindow.courses.begin(); it != parametresWindow.courses.end(); ++it ) {
      int n = ui.racesList->rowCount();
      ui.racesList->setRowCount(n+1);
      ui.racesList->setItem(n, 0, new QTableWidgetItem(QString().setNum(it.key())) );
      ui.racesList->setItem(n, 1, new QTableWidgetItem((*it).nom) );
      ui.racesList->setItem(n, 2, new QTableWidgetItem((*it).date.toString( "d MMM yyyy" )) );
	}
	
   ui.racesList->setCurrentCell(ui.racesList->rowCount()-1,0);
}
/*****************************************************************************/
/**
 * Rafraichi la liste des Catégories
 */
void Amorce50::slotUpdateCategories()
{
	int i;
	// Catégories
	ui.categoriesList->setRowCount(0);
	categoriesKey.clear();

   i = 0;
   QMap<int, Categorie>::Iterator it;
	for( it = parametresWindow.categories.begin(); it != parametresWindow.categories.end(); ++it ) {
		// On n'affiche pas la catégorie fantômes
      if( it.key() == 1 ) {
			continue;
      }

      int n = ui.categoriesList->rowCount();
      ui.categoriesList->setRowCount(n+1);
      ui.categoriesList->setItem(n, 0, new QTableWidgetItem(QString().setNum(it.key())) );
      ui.categoriesList->setItem(n, 1, new QTableWidgetItem(it->nom) );

		categoriesKey[i++] = it.key();
	}
	
	if( ui.categoriesList->rowCount() != 0 ) {
      ui.categoriesList->setCurrentCell(ui.categoriesList->rowCount()-1,0);
		slotUpdateRounds();
   } else {
		ui.roundsList->setRowCount(0);
	}
}
/*****************************************************************************/
/**
 * Rafraichi la liste des manches
 */
void Amorce50::slotUpdateRounds()
{
	ui.roundsList->setRowCount(0);

   if( ui.categoriesList->rowCount() == 0  || ui.categoriesList->currentRow() <0 ) {
		return;
   }

   int index = ui.racesList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }

	// Manches
   parametresWindow.updateRounds( ui.racesList->item(index,0)->text().toInt(), categoriesKey[ui.categoriesList->currentRow()] );
	
   //  QTableWidgetItem newItem;
	QMap<int, Manche>::Iterator it;
	for( it = parametresWindow.manches.begin(); it != parametresWindow.manches.end(); ++it ) {
		QString txt;
		
      if( (*it).statut == 2 ) {
			txt = "Terminée";
      } else if( (*it).statut == 1 ) {
			txt = "En cours";
      } else {
			txt = "Non courue";
      }
      int n = ui.roundsList->rowCount();
      ui.roundsList->setRowCount(n+1);
      ui.roundsList->setItem(n, 0, new QTableWidgetItem(QString().setNum( it.key() )) );
      ui.roundsList->setItem(n, 1, new QTableWidgetItem(QString().setNum( (*it).numero )) );
      ui.roundsList->setItem(n, 2, new QTableWidgetItem(txt) );
   }
}
/*****************************************************************************/
void Amorce50::newRace()
{
	int ret;
   QDialog *re = new QDialog(this);
   Ui::RaceEdit re_ui;
   re_ui.setupUi(re);

	ret = ui.seasonsList->count();
	if( ret == 0 ) {
		QMessageBox::information( 0, "Information",
								"Créez d'abord une nouvelle saison." );
		return;
	}

	re_ui.date->setDate( QDate::currentDate() );

	if( re->exec() == QDialog::Accepted ) {

      if( re_ui.lneName->text().isEmpty() ) {
			return;
      }

		int id = parametresWindow.addRace(  re_ui.lneName->text(), 
                                          re_ui.date->date(), 
                                          saisonsKey[ui.seasonsList->currentIndex()] );
		if( id >= 0 ) {
         int n = ui.racesList->rowCount();
         ui.racesList->setRowCount(n+1);
         ui.racesList->setItem(n, 0, new QTableWidgetItem(QString().setNum(id)) );
         ui.racesList->setItem(n, 1, new QTableWidgetItem(re_ui.lneName->text()) );
         ui.racesList->setItem(n, 2, new QTableWidgetItem(re_ui.date->date().toString( "d MMM yyyy" )) );
			ui.racesList->setCurrentCell(ui.racesList->rowCount()-1,0);
		} else {
			QMessageBox::critical( 0, "Erreur",
						"Impossible de rajouter la course." );
		}
   }
}
/*****************************************************************************/
void Amorce50::editRace()
{
   QDialog *re = new QDialog(this);
   Ui::RaceEdit re_ui;
   re_ui.setupUi(re);

   int index = ui.racesList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }

	re_ui.lneName->setText(ui.racesList->item(index,1)->text());
	re_ui.date->setDate( parametresWindow.courses[ ui.racesList->item(index,0)->text().toInt()].date );

	if( re->exec() == QDialog::Accepted ) {
      if( re_ui.lneName->text().isEmpty() ) {
			return;
      }

		bool ret = parametresWindow.editRace(  re_ui.lneName->text(), 
                                             re_ui.date->date(), 
                                             ui.racesList->item(index,0)->text().toInt() );
		if( ret == true ) {
			ui.racesList->item(index,1)->setText( re_ui.lneName->text() );
			ui.racesList->item(index,2)->setText( re_ui.date->date().toString( "d MMM yyyy" ) );
		} else {
			QMessageBox::critical( 0, "Erreur",
						"Impossible d'éditer la course." );
		}
   }
}
/*****************************************************************************/
void Amorce50::deleteRace()
{
   int index = ui.racesList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }

	switch( QMessageBox::warning( this, "Attention",
        "Attention, si vous supprimez cette course vous\n"
        "supprimerez également toutes les épreuves associées.\n\n",
        "Continuer",
        "Annuler", 0, 0, 1 ) )
	{
		case 0: // The user clicked the Retry again button or pressed Enter

			if( parametresWindow.deleteRace( ui.racesList->item(index,0)->text().toInt() ) == true ) {
            ui.racesList->removeRow(index);
            ui.racesList->setCurrentCell(ui.racesList->rowCount()-1,0);
			} else {
				QMessageBox::critical( 0, "Erreur",
								"Impossible de supprimer la course." );
			}
			break;
		case 1:
			// exit
			break;
   }
}
/*****************************************************************************/
/**
 * Panneau de dialogue pour choisir quoi imprimer
 */
void Amorce50::print()
{

}
/*****************************************************************************/
void Amorce50::closeEvent( QCloseEvent * )
{
	exitAmorce50();
}
/*****************************************************************************/
void Amorce50::exitAmorce50()
{
   parametresWindow.optimizeDataBase();
	qApp->quit();
}

//=============================================================================
// Fin du fichier Amorce50.cpp
//=============================================================================
