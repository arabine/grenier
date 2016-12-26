/*=============================================================================
 * Amorce50 - ParametresWindow.cpp
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

#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTableWidget>
#include <QHeaderView>
#include "ParametresWindow.h"

/*****************************************************************************/
ParametresWindow::ParametresWindow() : QDialog()
{
   ui.setupUi(this);

	// Onglet Saisons
	connect( ui.btnAddSeason, SIGNAL(clicked()), this, SLOT(slotAddSeason()) );
	connect( ui.btnEditSeason, SIGNAL(clicked()), this, SLOT(slotEditSeason()) );
	connect( ui.btnDeleteSeason, SIGNAL(clicked()), this, SLOT(slotDeleteSeason()) );

	// Onglet Pilotes
	connect( ui.btnAddDriver, SIGNAL(clicked()), this, SLOT(slotAddDriver()) );
	connect( ui.btnEditDriver, SIGNAL(clicked()), this, SLOT(slotEditDriver()) );
	connect( ui.btnDeleteDriver, SIGNAL(clicked()), this, SLOT(slotDeleteDriver()) );

	// Onglet Catégories
	connect( ui.btnAddCategory, SIGNAL(clicked()), this, SLOT(slotAddCategory()) );
	connect( ui.btnEditCategory, SIGNAL(clicked()), this, SLOT(slotEditCategory()) );
	connect( ui.btnDeleteCategory, SIGNAL(clicked()), this, SLOT(slotDeleteCategory()) );
   connect( ui.btnSousCat, SIGNAL(clicked()), this, SLOT(slotSousCat()) );
   

	// Onglet Règlement
	connect( ui.btnAddPosition, SIGNAL(clicked()), this, SLOT(slotAddPosition()) );
	connect( ui.btnEditPosition, SIGNAL(clicked()), this, SLOT(slotEditPosition()) );

	connect( this, SIGNAL(sgnlUpdateCategories()), this, SLOT( slotUpdateCategories() ) );
	connect( this, SIGNAL(sgnlUpdatePilotes()), this, SLOT( slotUpdatePilotes() ) );
	connect( ui.categoriesCombo, SIGNAL(activated(int)), this, SLOT(slotUpdatePilotes()) );


   ui.categoriesList->verticalHeader()->hide();
   ui.categoriesList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   ui.driversList->verticalHeader()->hide();
   ui.driversList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   ui.pointsList->verticalHeader()->hide();
   ui.pointsList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
   ui.seasonsList->verticalHeader()->hide();
   ui.seasonsList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

#ifndef _DEBUG
	ui.seasonsList->hideColumn(0);
	ui.driversList->hideColumn(0);
	ui.categoriesList->hideColumn(0);

#endif // _DEBUG
}
/*****************************************************************************/
void ParametresWindow::setPath( const QString &p )
{
	mainPath = p;
}
/*****************************************************************************/
void ParametresWindow::setCurrentPage( int i )
{
	ui.ongletsParametres->setCurrentIndex( i );
}
/*****************************************************************************/
/**
 * Optimise la base de données (à partir de SQLite 2.8.1 et plus)
 */
void ParametresWindow::optimizeDataBase()
{
	QSqlQuery query(db);
	int ret = query.exec( QString("VACUUM") );
	
	if( ret == false ) {
		QMessageBox::critical( 0, "Erreur",
						"Erreur lors d'une requête SQL." );
	}
}
/*****************************************************************************/
bool ParametresWindow::initCnx()
{
	int ret;

	db = QSqlDatabase::addDatabase("QSQLITE"); 
	db.setDatabaseName( mainPath + "/bdd/amorce50.dat");

   
	if( db.open() == false ) {
        QMessageBox::warning(this, tr("Erreur"), db.lastError().text(),
                   QMessageBox::Ok);
        return false;
    }

	// On crée les tables si elles n'existent pas
	QStringList list = db.tables();
	if( list.contains( "Saisons" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Saisons ")+QString(TABLE_SAISONS) );
		if( ret == false )
			return false;
	}
	
	if( list.contains( "Pilotes" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Pilotes ")+QString(TABLE_PILOTES) );
		if( ret == false )
			return false;
	}
	
	if( list.contains( "Courses" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Courses ")+QString(TABLE_COURSES) );
		if( ret == false )
			return false;
	}
	
	if( list.contains( "Categories" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Categories ")+QString(TABLE_CATEGORIES) );
		if( ret == false )
			return false;

		// On initialise la BDD avec un Id = 1, réservé pour les pilotes fantômes
		// (c-a-d sans catégories)
		bool ret = query.exec( QString("INSERT INTO Categories VALUES ( 1, -1, 'GHOST' )") );

		if( ret == false )
			return false;
	}
	
	if( list.contains( "Epreuves" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Epreuves ")+QString(TABLE_EPREUVES) );
		if( ret == false )
			return false;
	}

	if( list.contains( "Manches" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Manches ")+QString(TABLE_MANCHES) );
		if( ret == false )
			return false;
	}

	if( list.contains( "Infos" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Infos ")+QString(TABLE_INFOS) );
		if( ret == false )
			return false;

		// Init de la table avec des valeurs par défaut
		bool ret = query.exec(	QString("INSERT INTO Infos VALUES ( '") + QString(AMORCE50_VERSION) +
								QString("')") );

		if( ret == false )
			return false;
	}
	
	if( list.contains( "Ids" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Ids ")+QString(TABLE_IDS) );
		if( ret == false )
			return false;

		// Init de la table avec des valeurs par défaut
		bool ret = query.exec( QString("INSERT INTO Ids VALUES ( 0,0,0,1,0,0 )") );

		if( ret == false )
			return false;
	}

	if( list.contains( "Points" ) == false ) // table non trouvée
	{
		QSqlQuery query(db);
		ret = query.exec( QString("CREATE TABLE Points ") + QString(TABLE_POINTS) );
		// Init de la table avec des valeurs par défaut
		bool ret = query.exec( QString("INSERT INTO Points VALUES ( 1,0 )") );

      if( ret == false ) {
			return false;
      }
	}


    return true;
}
/*****************************************************************************/
/**
 * Charge le contenu de la BDD
 */
int ParametresWindow::loadBDD()
{
	bool ret;

	// Saisons
	QSqlQuery query(db);
	ret = query.exec( QString("SELECT Id_saison, nom FROM Saisons") );

   if( ret == false ) {
		return 1;
   }
	while( query.next()) {
		QString id = query.value(0).toString();
		QString nom = query.value(1).toString();

		saisons[id.toInt()] = nom;

      int n = ui.seasonsList->rowCount();
      ui.seasonsList->setRowCount(n+1);
      QTableWidgetItem *newItem = new QTableWidgetItem(id);
      ui.seasonsList->setItem(n, 0, newItem);
      QTableWidgetItem *newItem2 = new QTableWidgetItem(nom);
      ui.seasonsList->setItem(n, 1, newItem2);
	}

	emit sgnlUpdateSeasons();

	// Catégories
	ret = query.exec( QString("SELECT Id_categorie, id_cat_parent, nom FROM Categories") );

   if( ret == false ) {
		return 1;
   }
	while( query.next()) {
		int id = query.value(0).toInt();
      int id_parent = query.value(1).toInt();
		QString nom = query.value(2).toString();

      if( id == 1 ) {
			nom = "Sans catégorie";
      }

		categories[id] = Categorie(id,id_parent,nom);
   }

   // affichage des catégories
   QMap<int, Categorie>::Iterator it;
   for ( it = categories.begin(); it != categories.end(); ++it ) {
		// On n'affiche pas la catégorie fantôme
      if( it.key() != 1 ) {
         int n = ui.categoriesList->rowCount();
         ui.categoriesList->setRowCount(n+1);
         ui.categoriesList->setItem(n, 0, new QTableWidgetItem(QString().setNum(it->id)));
         ui.categoriesList->setItem(n, 1, new QTableWidgetItem(it->nom));
         if( it->id_cat_parent == -1 ) {
            ui.categoriesList->setItem(n, 2, new QTableWidgetItem("-"));
         } else if( categories.find(it->id_cat_parent) != categories.end() ) {
            ui.categoriesList->setItem(n, 2, new QTableWidgetItem( categories[it->id_cat_parent].nom ));
         } else {
            ui.categoriesList->setItem(n, 2, new QTableWidgetItem("-"));
         }
      }
	}

	emit sgnlUpdateCategories();

	// Pilotes
	ret = query.exec( QString("SELECT Id_pilote, nom, numero, club, id_categorie FROM Pilotes") );

   if( ret == false ) {
		return 2;
   }
	while( query.next()) {
		int id = query.value(0).toInt();
		QString nom = query.value(1).toString();
		int numero = query.value(2).toInt();
		QString club = query.value(3).toString();
		int id_categorie = query.value(4).toInt();

		pilotes[id] = Pilote( id, nom, numero, club, id_categorie );
	}

	emit sgnlUpdatePilotes();

	// Points
	ret = query.exec( QString("SELECT position, points FROM Points") );

   if( ret == false ) {
		return 1;
   }
	while( query.next()) {
		QString pos = query.value(0).toString();
		QString pts = query.value(1).toString();

		points[ pos.toInt() ] = pts.toInt();

      int n = ui.pointsList->rowCount();
      ui.pointsList->setRowCount(n+1);
      QTableWidgetItem *newItem = new QTableWidgetItem(pos);
      ui.pointsList->setItem(n, 0, newItem);
      QTableWidgetItem *newItem2 = new QTableWidgetItem(pts);
      ui.pointsList->setItem(n, 1, newItem2);
	}

	emit sgnlUpdatePoints();

	return 0;
}
/*****************************************************************************/
void ParametresWindow::slotAddSeason()
{
	QDialog *se = new QDialog(this);
   Ui::SeasonEdit se_ui;
   se_ui.setupUi(se);

	if( se->exec() == QDialog::Accepted ) {
		// on ajoute la saison
		QString txt = se_ui.lneName->text();
		QString _txt = txt; _txt.replace( '\'', "''");
		int id_max=-1;

		// On va chercher l'Id de la table
		QSqlQuery query(db);
		bool ret = query.exec( QString("SELECT Id_saisons FROM Ids") );
		if( ret == true ) {
			if( query.last()) {
				id_max = query.value(0).toInt();		
			}
		} else {
			QMessageBox::critical( 0, "Erreur",
							"Erreur SQL : 11." );
			return;
		}

      if( id_max == -1 ) {
			return;
      }

		ret = query.exec( QString("INSERT INTO Saisons VALUES (") + QString().setNum(id_max+1) +
			QString(", '") + _txt + QString("')") );

		if( ret == true ) {
         int n = ui.seasonsList->rowCount();
         ui.seasonsList->setRowCount(n+1);
         QTableWidgetItem *newItem = new QTableWidgetItem(QString().setNum(id_max+1));
         ui.seasonsList->setItem(n, 0, newItem);
         QTableWidgetItem *newItem2 = new QTableWidgetItem(txt);
         ui.seasonsList->setItem(n, 1, newItem2);

			saisons[ id_max+1 ] = txt;
			emit sgnlUpdateSeasons();

			// On met à jour l'id max
			ret = query.exec( QString("UPDATE Ids SET Id_saisons=Id_saisons+1") );
		} else {
			QMessageBox::critical( 0, "Erreur",
								"Erreur SQL : 2." );
		}
	}
}
/*****************************************************************************/
void ParametresWindow::slotEditSeason()
{
   QDialog *se = new QDialog(this);
   Ui::SeasonEdit se_ui;
   se_ui.setupUi(se);

	int index = ui.seasonsList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }
   QTableWidgetItem  *item = ui.seasonsList->item( index, 1 );
	se_ui.lneName->setText( item->text() );
	
	// on sauve le nom de la saison
	QString nomTmp = item->text();

	if( se->exec() == QDialog::Accepted ) {
		// si le nom a changé on le sauve dans la base
		QString rep = se_ui.lneName->text();
		QString _rep = rep; _rep.replace( '\'', "''");
		
		if( rep != nomTmp ) {
			int id = QString(ui.seasonsList->item( index, 0 )->text()).toInt();

			QSqlQuery query(db);
			bool ret = query.exec( QString("UPDATE Saisons SET nom='") + _rep +
									QString("' WHERE Id_saison=") + QString().setNum( id ) );
			
			if( ret == true ) {
				item->setText( rep );
				
				if( saisons.find( id ) != saisons.end() ) {
					saisons[id] = rep;
					emit sgnlUpdateSeasons();
				}
			} else {
				QMessageBox::critical( 0, "Erreur",
								"Erreur SQL : 3." );
			}	
		}
	}
}
/*****************************************************************************/
void ParametresWindow::slotDeleteSeason()
{
	int index = ui.seasonsList->currentRow();
   if( index<0 ) { // pas de sélection
		return;
   }

	switch( QMessageBox::warning( this, "Attention",
        "Attention, si vous supprimez cette saison vous\n"
        "supprimerez également toutes les épreuves associées.\n\n",
        "Continuer",
        "Annuler", 0, 0, 1 ) )
	{
		case 0: // The user clicked the Retry again button or pressed Enter
			break;
		case 1:
			return;
			break;
   }

	int id = QString(ui.seasonsList->item( index, 0 )->text()).toInt();

	QSqlQuery query(db);
	bool ret = query.exec( QString("DELETE FROM Saisons WHERE Id_saison=") + QString().setNum( id ) );
	
	if( ret == true ) {
      ui.seasonsList->removeRow(index);

		if( saisons.find( id ) != saisons.end() ) {
			saisons.remove( id );
		}

		// Delete en cascade
		QSqlQuery query2(db);
		QSqlQuery query3(db);
		ret = query.exec( QString("SELECT Id_course FROM Courses WHERE id_saison=") + QString().setNum( id ) );
		while( query.next()) {
			int id_course = query.value(0).toInt();

			ret = query2.exec( QString("SELECT Id_manche FROM Manches WHERE id_course=") + QString().setNum( id_course ) );
			while( query2.next()) {
				int id_manche = query2.value(0).toInt();
				ret = query3.exec( QString("DELETE FROM Epreuves WHERE id_manche=") + QString().setNum( id_manche ) );
			}
			manches.clear();
			ret = query3.exec( QString("DELETE FROM Manches WHERE id_course=") + QString().setNum( id_course ) );	
		}
		courses.clear();
		ret = query3.exec( QString("DELETE FROM Courses WHERE id_saison=") + QString().setNum( id ) );
		
		emit sgnlUpdateSeasons();

	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 4." );
	}
}
/*****************************************************************************/
void ParametresWindow::slotAddDriver()
{
   QDialog *de = new QDialog(this);
   Ui::DriverEdit de_ui;
   de_ui.setupUi(de);

	if( ui.categoriesCombo->count() == 0 ) {
		QMessageBox::information( 0, "Information",
								"Créez d'abord une catégorie." );
		return;
	}

   // Init de la liste des catégories
   de_ui.cmbCategories->clear();
	QMap<int, Categorie>::Iterator it;
	for( it = categories.begin(); it != categories.end(); ++it ) {
		de_ui.cmbCategories->addItem( it->nom );
   }
   de_ui.cmbCategories->setCurrentIndex( ui.categoriesCombo->currentIndex() );
	// Init des champs
	de_ui.lneName->clear();
	de_ui.lneNumber->setValue(0);
	de_ui.lneClub->clear();

   if( de->exec() == QDialog::Accepted ) {

	   // on ajoute le pilote
	   QString nom = de_ui.lneName->text();
	   QString numero = de_ui.lneNumber->text();
	   QString club = de_ui.lneClub->text();
	   int cat = de_ui.cmbCategories->currentIndex();

	   // On cherche si le numéro n'existe pas déjà
	   QMap<int, Pilote>::Iterator it;
	   for( it = pilotes.begin(); it != pilotes.end(); ++it ) {
		   if( (*it).numero == numero.toInt() && (*it).id_categorie == categoriesKey[cat] ) {
			   QMessageBox::warning( this, "Note",
						   "Le numéro est déjà attribué à un autre pilote." );
   			
			   return;
		   }
	   }

	   // On va chercher l'Id de la table
	   QSqlQuery query(db);
	   int id_max=-1;

	   bool ret = query.exec( QString("SELECT Id_pilotes FROM Ids") );
	   if( ret == true ) {
		   if( query.last()) {
			   id_max = query.value(0).toInt();		
		   }
	   } else {
		   QMessageBox::critical( 0, "Erreur",
						   "Erreur SQL : 12." );

		   return;
	   }

	   if( id_max == -1 )
		   return;

	   QString _nom = nom; _nom.replace( '\'', "''");
	   QString _club = club; _club.replace( '\'', "''");

	   ret = query.exec( QString("INSERT INTO Pilotes VALUES (")+
							   QString().setNum(id_max+1) + QString(", '") +
							   _nom + QString("',")+
							   numero + QString(",'")+
							   _club + QString("',") +
							   QString().setNum(categoriesKey[cat]) + QString(")")	);

	   if( ret == true ) {			
		   pilotes[ id_max+1 ] = Pilote( id_max+1, nom, numero.toInt(), club, categoriesKey[cat] );
   		
		   // On met à jour l'id max
		   ret = query.exec( QString("UPDATE Ids SET Id_pilotes=Id_pilotes+1") );
		   emit sgnlUpdatePilotes();
	   } else {
		   QMessageBox::critical( 0, "Erreur",
							   "Erreur SQL : 6." );
	   }
   }
}
/*****************************************************************************/
void ParametresWindow::slotEditDriver()
{
   QDialog *de = new QDialog(this);
   Ui::DriverEdit de_ui;
   de_ui.setupUi(de);

	int index = ui.driversList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }

	de_ui.lneName->setText( ui.driversList->item(index,1)->text() );
	de_ui.lneNumber->setValue( ui.driversList->item(index,2)->text().toInt() );
	de_ui.lneClub->setText( ui.driversList->item(index,3)->text() );
   // Init de la liste des catégories
   de_ui.cmbCategories->clear();
	QMap<int, Categorie>::Iterator it;
	for( it = categories.begin(); it != categories.end(); ++it ) {
		de_ui.cmbCategories->addItem( it->nom );
   }
   de_ui.cmbCategories->setCurrentIndex( ui.categoriesCombo->currentIndex() );

   int numero_saved = de_ui.lneNumber->text().toInt();

   if( de->exec() == QDialog::Accepted ) {
	   int id = ui.driversList->item(index,0)->text().toInt();
   	
	   QString nom = de_ui.lneName->text();
	   QString numero = de_ui.lneNumber->text();
	   QString club = de_ui.lneClub->text();
	   int cat = de_ui.cmbCategories->currentIndex();
   	
      // Si le numéro a été changé, on cherche s'il n'existe pas déjà
      if( numero_saved != numero.toInt() ) {
	      QMap<int, Pilote>::Iterator it;
	      for( it = pilotes.begin(); it != pilotes.end(); ++it ) {
		      if( (*it).numero == numero.toInt() && (*it).id_categorie == categoriesKey[cat] ) {
			      QMessageBox::warning( this, "Note",
						      "Le numéro est déjà attribué à un autre pilote." );
			      return;
		      }
	      }
      }

	   QString _nom = nom; _nom.replace( '\'', "''");
	   QString _club = club; _club.replace( '\'', "''");

	   QSqlQuery query(db);
	   bool ret = query.exec(	QString("UPDATE Pilotes SET nom='") + _nom + QString("',numero=") +
							   numero + QString(",club='") +
							   _club + QString("',id_categorie=") +
							   QString().setNum( categoriesKey[cat] ) +
							   QString(" WHERE Id_pilote=") + QString().setNum( id ) );
   	
	   if( ret == true ) {

		   ui.driversList->item(index,1)->setText( nom );
		   ui.driversList->item(index,2)->setText( numero );
		   ui.driversList->item(index,3)->setText( club );

		   QMap<int, Pilote>::Iterator it;
		   it = pilotes.find( id );
		   if( it != pilotes.end() ) {
			   (*it).nom = nom;
			   (*it).numero = numero.toInt();
			   (*it).club = club;
			   (*it).id_categorie = categoriesKey[cat];

			   emit sgnlUpdatePilotes();
		   }
	   } else {
		   QMessageBox::critical( 0, "Erreur",
						   "Erreur SQL : 7." );
	   }
   }
}
/*****************************************************************************/
void ParametresWindow::slotDeleteDriver()
{
	int index = ui.driversList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }
	
	switch( QMessageBox::warning( this, "Attention",
        "Attention, si vous supprimez ce pilote vous\n"
        "supprimerez également toutes ses courses.\n\n",
        "Continuer",
        "Annuler", 0, 0, 1 ) )
	{
		case 0: // The user clicked the Retry again button or pressed Enter
			break;
		case 1:
			return;
			break;
    }

	int id = ui.driversList->item(index,0)->text().toInt();

	QSqlQuery query(db);
	bool ret = query.exec( QString("DELETE FROM Pilotes WHERE Id_pilote=") + QString().setNum( id ) );
	
	if( ret == true ) {
		ui.driversList->removeRow(index);

		if( pilotes.find( id ) != pilotes.end() ) {
			pilotes.remove( id );
			
		}

		// Delete en cascade
		QSqlQuery query2(db);
		ret = query.exec( QString("SELECT Id_epreuve FROM Epreuves WHERE id_pilote=") + QString().setNum( id ) );
		while( query.next()) {
			int id_epreuve = query.value(0).toInt();
			ret = query2.exec( QString("DELETE FROM Epreuves WHERE Id_epreuve=") + QString().setNum( id_epreuve ) );
		}
		emit sgnlUpdatePilotes();
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 8." );
	}
}
/*****************************************************************************/
void ParametresWindow::slotAddCategory()
{
   QDialog *ce = new QDialog(this);
   Ui::CategoryEdit ce_ui;
   ce_ui.setupUi(ce);

	if( ce->exec() == QDialog::Accepted ) {
		// on ajoute la catégorie
		QString txt = ce_ui.lneName->text();
		QString _txt = txt; _txt.replace( '\'', "''");

		QSqlQuery query(db);
		int id_max=-1;

		bool ret = query.exec( QString("SELECT Id_categories FROM Ids") );
		if( ret == true ) {
			if( query.last()) {
				id_max = query.value(0).toInt();		
			}
		} else {
			QMessageBox::critical( 0, "Erreur",
							"Erreur SQL : 13." );
			return;
		}

      if( id_max == -1 ) {
			return;
      }

		ret = query.exec( QString("INSERT INTO Categories VALUES (") +
							QString().setNum(id_max+1) + QString(",-1") + QString(", '") + _txt + QString("')") );

		if( ret == true ) {	
         int n = ui.categoriesList->rowCount();
         ui.categoriesList->setRowCount(n+1);
         ui.categoriesList->setItem(n, 0, new QTableWidgetItem(QString().setNum(id_max+1)));
         ui.categoriesList->setItem(n, 1, new QTableWidgetItem(txt));
         ui.categoriesList->setItem(n, 2, new QTableWidgetItem("-"));

			categories[ id_max+1 ] = Categorie(id_max+1,-1,txt);
			emit sgnlUpdateCategories();
		
			// On met à jour l'id max
			ret = query.exec( QString("UPDATE Ids SET Id_categories=Id_categories+1") );

		} else {
			QMessageBox::critical( 0, "Erreur",
								"Erreur SQL : 10." );
		}
	}
}
/*****************************************************************************/
void ParametresWindow::slotEditCategory()
{
   QDialog *ce = new QDialog(this);
   Ui::CategoryEdit ce_ui;
   ce_ui.setupUi(ce);

	int index = ui.categoriesList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }

   QTableWidgetItem  *item = ui.categoriesList->item( index, 1 );
	ce_ui.lneName->setText( item->text() );
	
	// on sauve le nom de la catégorie
	QString nomTmp = item->text();

	if( ce->exec() == QDialog::Accepted ) {
		// si le nom a changé on le sauve dans la base
		QString rep = ce_ui.lneName->text();
		QString _rep = rep; _rep.replace( '\'', "''");

		if( rep != nomTmp ) {
         int id = QString(ui.categoriesList->item( index, 0 )->text()).toInt();

			QSqlQuery query(db);
			bool ret = query.exec( QString("UPDATE Categories SET nom='") + _rep +
									QString("' WHERE Id_categorie=") + QString().setNum( id ) );
			
			if( ret == true ) {
				item->setText( rep );

				if( categories.find( id ) != categories.end() ) {
					categories[id].nom = rep;
					emit sgnlUpdateCategories();
				}
			} else {
				QMessageBox::critical( 0, "Erreur",
								"Erreur SQL : 11." );
			}	
		}
	}
}
/*****************************************************************************/
void ParametresWindow::slotDeleteCategory()
{	
   int index = ui.categoriesList->currentRow();
   if( index<0 ) { // pas de sélection
		return;
   }

	switch( QMessageBox::warning( this, "Attention",
        "Attention, si vous supprimez cette catégorie vous\n"
        "supprimerez également toutes les épreuves associées.\n\n",
        "Continuer",
        "Annuler", 0, 0, 1 ) )
	{
		case 0: // The user clicked the Retry again button or pressed Enter
			break;
		case 1:
			return;
			break;
    }

   int id = QString(ui.categoriesList->item( index, 0 )->text()).toInt();

	QSqlQuery query(db);
	bool ret = query.exec( QString("DELETE FROM Categories WHERE Id_categorie=") + QString().setNum( id ) );
	
	if( ret == true ) {
      ui.categoriesList->removeRow(index);

		if( categories.find( id ) != categories.end() ) {
			categories.remove( id );
		}
		
		// Delete en cascade
		QSqlQuery query2(db);
		ret = query.exec( QString("SELECT Id_manche FROM Manches WHERE id_categorie=") + QString().setNum( id ) );
		while( query.next())
		{
			int id_manche = query.value(0).toInt();
			ret = query2.exec( QString("DELETE FROM Epreuves WHERE id_manche=") + QString().setNum( id_manche ) );

		}
		ret = query2.exec( QString("DELETE FROM Manches WHERE id_categorie=") + QString().setNum( id ) );

		// Tous les pilotes de cette catégorie deviennent fantôme
		ret = query.exec( QString("UPDATE Pilotes SET id_categorie=1 WHERE id_categorie=") + QString().setNum( id ) );

		QMap<int, Pilote>::Iterator it;
		for( it = pilotes.begin(); it != pilotes.end(); ++it ) {
			if( (*it).id_categorie == id ) {
				(*it).id_categorie = 1;
			}
		}
		emit sgnlUpdateCategories();
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 12." );
	}
}
/*****************************************************************************/
void ParametresWindow::slotSousCat()
{
   QDialog *sc = new QDialog(this);
   Ui::SousCat sc_ui;
   sc_ui.setupUi(sc);
   QMap<int, int> relation; // <index_combo, id_categorie>

   int index = ui.categoriesList->currentRow();
   if( index<0 ) { // pas de sélection
		return;
   }

   // id de la catégorie courante
   int id = ui.categoriesList->item(index,0)->text().toInt();
   
   // Init de la liste des catégories
   sc_ui.cmbCategories->clear();
   int i = 0;
   sc_ui.cmbCategories->addItem( "Aucune" );
   relation[i++] = -1;
	QMap<int, Categorie>::Iterator it;
	for( it = categories.begin(); it != categories.end(); ++it ) {
      if( id != it->id && it->id != 1 ) {
		   sc_ui.cmbCategories->addItem( it->nom );
         relation[i++] = it.key();
      }
   }
   sc_ui.cmbCategories->setCurrentIndex( sc_ui.cmbCategories->count()-1 );

   if( sc->exec() == QDialog::Accepted ) {
      // la catégorie choisie devient la catégorie parente
      int cat = sc_ui.cmbCategories->currentIndex();
      QSqlQuery query(db);
      bool ret = query.exec(  QString("UPDATE Categories SET id_cat_parent=") + QString().setNum(relation[cat]) + 
								      QString(" WHERE Id_categorie=") + QString().setNum( id ) );
		
		if( ret == true ) {
         if( relation[cat] != -1 ) {
            ui.categoriesList->item(index,2)->setText( categories[relation[cat]].nom );
         } else {
            ui.categoriesList->item(index,2)->setText( "-" );
         }

			if( categories.find( id ) != categories.end() ) {
				categories[id].id_cat_parent = relation[cat];
				emit sgnlUpdateCategories();
			}
		} else {
			QMessageBox::critical( 0, "Erreur",
							"Erreur SQL : 124." );
		}	
   }
}
/*****************************************************************************/
int ParametresWindow::addRace( const QString &txt, const QDate &date, int id_s )
{
	// on ajoute la course
	QString _txt = txt; _txt.replace( '\'', "''");

	QSqlQuery query(db);
	int id_max=-1;

	bool ret = query.exec( QString("SELECT Id_courses FROM Ids") );
	if( ret == true ) {
		if( query.last()) {
			id_max = query.value(0).toInt();		
		}
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 14." );
		return -1;
	}

   if( id_max == -1 ) {
		return -1;
   }

	ret = query.exec(	QString("INSERT INTO Courses VALUES (") +
						QString().setNum( id_max+1 ) + QString(", ") + 
						QString().setNum( id_s ) + QString(", '") + 
						_txt + QString("', '") + date.toString( Qt::ISODate ) + QString("')") );

	if( ret == true ) {
		courses[ id_max+1 ] = Course( id_max+1, txt, date );
		// On met à jour l'id max
		ret = query.exec( QString("UPDATE Ids SET Id_courses=Id_courses+1") );
	} else {
		QMessageBox::critical( 0, "Erreur",
							"Erreur SQL : 14." );
	}

   if( ret == false ) {
		return -1;
   } else {
		return id_max+1;
   }
}
/*****************************************************************************/
bool ParametresWindow::editRace( const QString &txt, const QDate &date, int id )
{
	// on ajoute la course
	QString _txt = txt; _txt.replace( '\'', "''");

	QSqlQuery query(db);
	bool ret = query.exec( QString("UPDATE Courses SET nom='") + _txt +
							QString("',date='") + QString( date.toString( Qt::ISODate ) ) +
							QString("' WHERE Id_course=") + QString().setNum( id ) );
	
	if( ret == true ) {		
		QMap<int, Course>::Iterator it;
		it = courses.find( id );
		if( it != courses.end() ) {
			(*it).nom = txt;
			(*it).date = date;
		}
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 11." );
	}

	return ret;
}
/*****************************************************************************/
bool ParametresWindow::deleteRace( int id )
{
	QSqlQuery query(db);
	bool ret = query.exec( QString("DELETE FROM Courses WHERE Id_course=") + QString().setNum( id ) );
	
	if( ret == true ) {
		if( courses.find( id ) != courses.end() ) {
			courses.remove( id );
		}

		// Delete en cascade
		QSqlQuery query2(db);

		ret = query.exec( QString("SELECT Id_manche FROM Manches WHERE id_course=") + QString().setNum( id ) );
		while( query.next()) {
			int id_manche = query.value(0).toInt();
			ret = query2.exec( QString("DELETE FROM Epreuves WHERE id_manche=") + QString().setNum( id_manche ) );
		}
		manches.clear();
		ret = query2.exec( QString("DELETE FROM Manches WHERE id_course=") + QString().setNum( id ) );	

	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 15." );
	}

	return ret;
}
/*****************************************************************************/
void ParametresWindow::slotAddPosition()
{
   QDialog *pe = new QDialog(this);
   Ui::PointsEdit pe_ui;
   pe_ui.setupUi(pe);

	QSqlQuery query(db);
	int pos;

	bool ret = query.exec( QString("SELECT MAX(position) FROM Points") );
	if( query.last()) {
		pos = query.value(0).toInt();		
	} else {
		return ;
	}

	pe_ui.positionNum->setText( QString().setNum( pos+1 ) );

	if( pe->exec() == QDialog::Accepted ) {
		int pts;

		pts = pe_ui.pointsBox->value();
		ret = query.exec( QString("INSERT INTO Points VALUES (") + 
									QString().setNum(pos+1) + QString(",")+
									QString().setNum(pts) + QString(")") );

		if( ret == true ) {	
         int n = ui.pointsList->rowCount();
         ui.pointsList->setRowCount(n+1);
         QTableWidgetItem *newItem = new QTableWidgetItem(QString().setNum(pos+1));
         ui.pointsList->setItem(n, 0, newItem);
         QTableWidgetItem *newItem2 = new QTableWidgetItem(QString().setNum(pts));
         ui.pointsList->setItem(n, 1, newItem2);

			points[ pos+1 ] = pts;
			emit sgnlUpdatePoints();
		} else {
			QMessageBox::critical( 0, "Erreur",
								"Erreur SQL : 10." );
		}
	}
}
/*****************************************************************************/
void ParametresWindow::slotEditPosition()
{
   QDialog *pe = new QDialog(this);
   Ui::PointsEdit pe_ui;
   pe_ui.setupUi(pe);
   QTableWidgetItem *item;
   int pos;

	int index = ui.pointsList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }

   item = ui.pointsList->item( index, 0 );
	pe_ui.positionNum->setText( item->text() );
   pos = item->text().toInt();
   item = ui.pointsList->item( index, 1 );
	pe_ui.pointsBox->setValue( item->text().toInt() );

	if( pe->exec() == QDialog::Accepted ) {
		int pts;
		pts = pe_ui.pointsBox->value();

		QSqlQuery query(db);
		bool ret = query.exec( QString("UPDATE Points SET points=") + 
									QString().setNum(pts) +
									QString(" WHERE position=") +
									QString().setNum(pos) );

		if( ret == true ) {
			item->setText( QString().setNum(pts) );
			points[ pos ] = pts;
			emit sgnlUpdatePoints();
		} else {
			QMessageBox::critical( 0, "Erreur",
								"Erreur SQL : 10." );
		}
	}
}
/*****************************************************************************/
/**
 * Fin d'une manche, on sauve toutes les épreuves pour chaque joueur
 */
bool ParametresWindow::addEpreuves( QList<Epreuve> &epreuves )
{
	QSqlQuery query(db);
	bool ret = query.exec( QString("SELECT Id_epreuves FROM Ids") );
	int id_max=-1;

	if( ret == true ) {
		if( query.last()) {
			id_max = query.value(0).toInt();		
		}
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 42." );
		return false;
	}

	if( id_max == -1 )
		return false;

	QList<Epreuve>::Iterator it;
	for( it = epreuves.begin(); it != epreuves.end(); ++it ) {
		id_max++;
		ret = query.exec( QString("INSERT INTO Epreuves VALUES (") + 
									QString().setNum( id_max ) + QString(",")+
									QString().setNum( (*it).id_manche ) + QString(",") +
									QString().setNum( (*it).id_pilote ) + QString(",") +
									QString().setNum( (*it).place ) + QString(",") +
									QString().setNum( (*it).tours ) + QString(",") +
									QString().setNum( (*it).statut ) + QString(")") );

		// On met à jour l'id max
		if( ret == true ) {
			ret = query.exec( QString("UPDATE Ids SET Id_epreuves=Id_epreuves+1") );
		}
	}
	return ret;
}
/*****************************************************************************/
void ParametresWindow::ajouteManche( int id_course, int id_cat )
{
	QSqlQuery query(db);
	int id_max=-1;
	int num_manches = 0;

	bool ret = query.exec( QString("SELECT Id_manches FROM Ids") );
	if( ret == true ) {
		if( query.last()) {
			id_max = query.value(0).toInt();		
		}
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 17." );
		return;
	}

	if( id_max == -1 )
		return;

	ret = query.exec( QString("SELECT MAX(numero) FROM manches WHERE id_course=") +
									QString().setNum(id_course) + QString(" AND id_categorie=") +
									QString().setNum(id_cat) );
	if( ret == true ) {
		if( query.last()) {
			num_manches = query.value(0).toInt();		
		}
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 19." );
		return;
	}

	// On crée cette manche
	ret = query.exec( QString("INSERT INTO Manches VALUES ( ") + 
				QString().setNum(id_max+1) + // Id_manche
				QString(", ") +
				QString().setNum( id_course ) + // id_course
				QString(",") + 
				QString().setNum( id_cat ) + // id_categorie
				QString(",") + 
				QString().setNum( num_manches+1 ) + // numero
				QString(",") + 
				QString().setNum( 0 ) + // statut
				QString(",''") + // pointage
				QString(",0") + // premier
				QString(")")  );
	
	// On met à jour l'id max
	ret = query.exec( QString("UPDATE Ids SET Id_manches=Id_manches+1") );
}
/*****************************************************************************/
void ParametresWindow::deleteManche( int id_manche )
{
	QSqlQuery query(db);

	bool ret = query.exec( QString("DELETE FROM Epreuves WHERE id_manche=") + QString().setNum( id_manche ) );
	ret = query.exec( QString("DELETE FROM Manches WHERE Id_manche=") + QString().setNum( id_manche ) );

}
/*****************************************************************************/
void ParametresWindow::razEpreuves( int id_manche )
{
	QSqlQuery query(db);

	bool ret = query.exec( QString("DELETE FROM Epreuves WHERE id_manche=") + QString().setNum( id_manche ) );
}
/*****************************************************************************/
void ParametresWindow::terminerManche( int id_manche, int statut, const QString &pointage, int premier )
{
	QSqlQuery query(db);
	bool ret = query.exec( QString("UPDATE Manches SET statut=") + 
								QString().setNum(statut) + QString(", pointage='") +
								pointage + QString("', premier=") +
								QString().setNum( premier ) +	
								QString(" WHERE Id_manche=") + QString().setNum(id_manche) );

	if( ret == false ) {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 63." );
	}
}
/*****************************************************************************/
/**
 * Met à jour la liste des courses selon la saison choisie
 */
void ParametresWindow::updateRaceList( int id_s )
{
	courses.clear();

	// on va chercher l'Id
	QSqlQuery query(db);
	bool ret = query.exec( QString("SELECT Id_course, nom, date FROM Courses WHERE id_saison=") + QString().setNum( id_s ) );
	
	if( ret == true ) {
		while( query.next()) {
			QString id = query.value(0).toString();
			QString nom = query.value(1).toString();
			QString date = query.value(2).toString();

			courses[id.toInt()] = Course( id.toInt(), nom, QDate().fromString( date, Qt::ISODate ) );
		}
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 16." );
	}
}
/*****************************************************************************/
/**
 * Met à jour la liste des manches selon les paramètres choisis
 */
void ParametresWindow::updateRounds( int id_race, int id_category )
{
	manches.clear();

	QSqlQuery query(db);
	bool ret = query.exec( QString("SELECT Id_manche, numero, statut, pointage, premier FROM Manches WHERE id_course=") + 
						QString().setNum( id_race ) + QString(" AND id_categorie=") + 
						QString().setNum( id_category ) );
	
	if( ret == true ) {
		while( query.next()) {
			int id_manche = query.value(0).toInt();
			int numero = query.value(1).toInt();
			int statut = query.value(2).toInt();
			QString pointage = query.value(3).toString();
			int premier = query.value(4).toInt();

			manches[id_manche] = Manche( id_manche, numero, statut, pointage, premier );
		}
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 17." );
	}

}
/*****************************************************************************/
/**
 * Met à jour la classe Resultat pour préparer la génération du tableau
 */
void ParametresWindow::fillResult()
{
	// On va chercher tous les épreuves de cette manche
	
	QSqlQuery query(db);
	bool ret = query.exec( QString("SELECT Id_epreuve, id_pilote, place, tours, statut FROM Epreuves WHERE id_manche=") + 
						QString().setNum( res.manche.id ) );

	if( ret == true ) {
		while( query.next()) {
			int id_epreuve = query.value(0).toInt();
			int id_pilote = query.value(1).toInt();
			int place = query.value(2).toInt();
			int tours = query.value(3).toInt();
			int statut = query.value(4).toInt();

			res.epreuves[id_epreuve] = Epreuve( res.manche.id, id_pilote, place, tours, statut );
			res.pilotes[id_pilote] = pilotes[id_pilote];
		}
	} else {
		QMessageBox::critical( 0, "Erreur",
						"Erreur SQL : 462." );
	}
}
/*****************************************************************************/
void ParametresWindow::slotUpdateCategories()
{
	ui.categoriesCombo->clear();
	categoriesKey.clear();
	int i=0;

	QMap<int, Categorie>::Iterator it;
	for( it = categories.begin(); it != categories.end(); ++it ) {
		ui.categoriesCombo->addItem( it->nom );
		ui.categoriesCombo->setCurrentIndex( ui.categoriesCombo->count()-1 );
		categoriesKey[i++] = it.key();
	}

	slotUpdatePilotes();
}
/*****************************************************************************/
void ParametresWindow::slotUpdatePilotes()
{
	ui.driversList->setRowCount(0);

	if( ui.categoriesCombo->count() == 0 ) {
		return;
	}

	int cat = ui.categoriesCombo->currentIndex();

	QMap<int, Pilote>::Iterator it;
	for( it = pilotes.begin(); it != pilotes.end(); ++it ) {
		if( (*it).id_categorie == categoriesKey[cat] ) {
         int n = ui.driversList->rowCount();
         ui.driversList->setRowCount(n+1);
         ui.driversList->setItem(n, 0, new QTableWidgetItem(QString().setNum(it.key())) );
         ui.driversList->setItem(n, 1, new QTableWidgetItem((*it).nom) );
         ui.driversList->setItem(n, 2, new QTableWidgetItem(QString().setNum((*it).numero)) );
         ui.driversList->setItem(n, 3, new QTableWidgetItem((*it).club) );
		}
	}
}

//=============================================================================
// Fin du fichier ParametresWindow.cpp
//=============================================================================
