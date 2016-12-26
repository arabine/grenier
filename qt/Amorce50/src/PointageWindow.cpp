/*=============================================================================
 * Amorce50 - PointageWindow.cpp
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

#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include "PointageWindow.h"

/*****************************************************************************/
PointageWindow::PointageWindow() : QDialog()
{
	ui.setupUi(this);

	// Grille de départ
	gw = new GrilleWindow();
	gw->hide();

   ui.resultList->verticalHeader()->hide();
   ui.resultList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

	connect( ui.btnCalculer, SIGNAL(clicked()) , this, SLOT(calculer()) );
	connect( ui.btnGrille, SIGNAL(clicked()) , this, SLOT(showGrid()) );
	connect( ui.btnSauver, SIGNAL(clicked()) , this, SLOT(sauveEtQuitte()) );
   connect( ui.btnSauvePointage, SIGNAL(clicked()) , this, SLOT(slotSauvePointage()) );
   connect( ui.btnToggleQualif, SIGNAL(clicked()) , this, SLOT(slotToggleQualif()) );

#ifndef _DEBUG
	ui.resultList->hideColumn(0);
#endif

	pointageFini = false;
}
/*****************************************************************************/
void PointageWindow::slotSauvePointage()
{
   emit sgnlSauvePointage();
}
/*****************************************************************************/
void PointageWindow::setInfos( int manche, const QString & categorie, int id_categorie )
{
	ui.lblTitre->setText( QString("CATEGORIE : ") + categorie + QString("     MANCHE : ") + 
				QString().setNum( manche ) );

	gw->setInfos( manche, categorie, id_categorie );
}
/*****************************************************************************/
void PointageWindow::init()
{
	// Initialisation des champs et variables
	ui.textPointage->clear();
	ui.resultList->setRowCount(0);
   ui.premier->setValue(1);
	pointageFini = false;
}
/*****************************************************************************/
void PointageWindow::setPilotes( const QMap<int, Pilote> &pil )
{
	gw->setPilotes( pil );
}
/*****************************************************************************/
void PointageWindow::setPointage( const QString &txt )
{
   ui.textPointage->setText(txt);
}
/*****************************************************************************/
QString PointageWindow::getPointage() const
{
   return(ui.textPointage->toPlainText());
}
/*****************************************************************************/
void PointageWindow::setPremier( int first )
{
   ui.premier->setValue(first);
}
/*****************************************************************************/
int PointageWindow::getPremier()
{
   return(ui.premier->value());
}
/*****************************************************************************/
/**
 *	Sauvegarde et ferme la fenêtre
 */
void PointageWindow::sauveEtQuitte()
{
	if( pointageFini == false ) {
		QMessageBox::critical( 0, "Information",
							"Terminez d'abord le pointage." );
		return;
	}
	accept();
}
/*****************************************************************************/
void PointageWindow::slotToggleQualif()
{
   int index = ui.resultList->currentRow();
   if( index < 0 ) {// pas de sélection
		return;
   }
   int num_pilote = ui.resultList->item(index,2)->text().toInt();

   if( course[num_pilote].statut == ARRIVE ) {
      course[num_pilote].statut = DISQUALIFIE;
   } else if( course[num_pilote].statut == DISQUALIFIE ) {
      course[num_pilote].statut = ARRIVE;
   } else {
      return;
   }
   updatePoints();
}
/*****************************************************************************/
void PointageWindow::calculer()
{
	QString txt = ui.textPointage->toPlainText();
	QList<int> pointage; // Contient le pointage brut
   course.clear();
   ui.resultList->clearContents();

   if( txt.isEmpty() ) {
		return;
   }

	// Il y a-t-il des pilotes au départ ?
	if( pilotesDepart.isEmpty() ) {
		QMessageBox::critical( 0, "Erreur",
							"Il n'y a aucun pilote sur la gille de départ." );
		return;
	}

	// On teste si le numéro du premier pilote est valide
	bool ok=false;
	QMap<int, Pilote>::Iterator itp;
	for( itp = pilotesDepart.begin(); itp != pilotesDepart.end(); ++itp  ) {
		if( (*itp).numero == ui.premier->value() ) {
			ok=true;
			break;
		}
	}

	if( ok == false ) {
		QMessageBox::critical( 0, "Erreur",
						QString("Le premier pilote n'est pas sur la grille de départ.") );
		return;
	}

	QRegExp qre;
	qre.setPattern( "[\\s,]+" );
	QStringList drivers = txt.split( qre );

   for( int i=0; i<drivers.size(); i++ ) {
      if( drivers.at(i).length() == 0 ) {
         drivers.removeAt(i);
      }
   }

   if( drivers.count() == 0 ) {
		return;
   }

	// On range le pointage dans un tableau d'entiers
	QStringList::Iterator it;
   for ( it = drivers.begin(); it != drivers.end(); ++it ) {
		int num = (*it).toInt();
		bool ok=false;

		// On teste si ce pilote existe sur la grille de départ
		QMap<int, Pilote>::Iterator itp;
		for( itp = pilotesDepart.begin(); itp != pilotesDepart.end(); ++itp  ) {
			if( (*itp).numero == num ) {
				ok=true;
				break;
			}
		}

		if( ok == false ) {
			QMessageBox::critical( 0, "Erreur",
							QString("Le pilote numéro ") + QString().setNum(num) +
							QString(" n'est pas sur la grille de départ.") );
			return;
		}
      pointage.append( num );
	}


	// On scanne le tableau, et on remplit les statistiques de la course
	QList<int>::Iterator it2;
   for ( it2 = pointage.begin(); it2 != pointage.end(); ++it2 ) {
      if( course.find( (*it2) ) == course.end() ) { // pas encore de stats sur ce pilote
			// on rajoute ce pilote
			course[ (*it2) ] = Arrivee( 1, 0);		
      } else {// on incrémente
			course[ (*it2) ].tours++;
		}
	}

	int r=1;
	int pilotesArrivee=0;

	// On classe les joueurs selon leur ordre d'arrivée (et s'ils sont bien arrivés)
   for ( it2 = pointage.end(); it2 != pointage.begin(); --it2 ) { // on commence par la fin
		pilotesArrivee++;
		if( (*it2) == ui.premier->value() ) {
			course[ (*it2) ].rang = r;
			
			int Max = course[ (*it2) ].tours;
			bool ok=false;
			int cpt = 1;

			it2++;
			QList<int>::Iterator debut, it21;
			debut = it2;
			
         while( ok==false ) {
				for( it21=debut; it21 != pointage.end(); ++it21 ) {
					int n= course[ (*it21) ].tours;
					if( n == Max ) {
						r++;
						course[ (*it21) ].rang = r;
						cpt++;
					}
				}
				
            if( cpt == pilotesArrivee-1 ) {
					ok = true;
            } else {
					Max--;
					if( Max == 0 ) {
						QMessageBox::critical( 0, "Erreur dans le calcul",
							"Un problème est survenu dans le calcul.\n"
							"Vérifiez le pointage et le numéro du premier pilote.\n\n"
							"Les données semblent incohérentes." );
						return;
					
					}
				}
			}
			break;
		}
	}
   
   // On affiche le classement de cette manche
	ui.resultList->setRowCount(0);
	QMap<int, Arrivee>::Iterator it3;
   for ( it3 = course.begin(); it3 != course.end(); ++it3 ) {
		QString place;
		int id;
		
		QMap<int, Pilote>::Iterator itp;
		for( itp = pilotesDepart.begin(); itp != pilotesDepart.end(); ++itp  ) {
			if( (*itp).numero == it3.key() ) {
				id = itp.key();
				break;
			}
		}

		if( (*it3).rang == 0 ) {
         (*it3).statut = ABANDON;
		} else {
         // un pilote doit avoir effectué un nombre minimum de tours pour être classé
         if( (*it3).tours < course[ui.premier->value()].tours*0.75 ) {
            (*it3).statut = NON_CLASSE;
         } else {
            (*it3).statut = ARRIVE;
            place.setNum(0);
         }
		}

      int n = ui.resultList->rowCount();
      ui.resultList->setRowCount(n+1);
      ui.resultList->setItem(n, 0, new QTableWidgetItem( QString().setNum(id) ));
      ui.resultList->setItem(n, 1, new QTableWidgetItem( pilotesDepart[id].nom ));
      ui.resultList->setItem(n, 2, new QTableWidgetItem( QString().setNum(it3.key()) ));
      ui.resultList->setItem(n, 3, new QTableWidgetItem( QString().setNum((*it3).tours) ));
      ui.resultList->setItem(n, 4, new QTableWidgetItem( place ));
      ui.resultList->setItem(n, 5, new QTableWidgetItem( QString("0") )); // points
	}
   ui.resultList->setSortingEnabled(false);
   updatePoints();
	pointageFini = true;
}
/*****************************************************************************/
void PointageWindow::updatePoints()
{
   int i;
   int pos;
   int pts;
   int num_pilote;

#ifdef _DEBUG
   QFile file("out.txt");
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
      return;
   QTextStream out(&file);

   QMap<int, Arrivee>::Iterator it3;
   for ( it3 = course.begin(); it3 != course.end(); ++it3 ) {
      out   << "Numéro : " << (int)it3.key()
            << " Statut : " << (int)(it3->statut)
            << " Rang : " << it3->rang
            << " Tours : " << it3->tours
          << endl;
   }
   file.close();
#endif

   pos = 0;
   for( i=0; i<ui.resultList->rowCount(); i++ ) {
      num_pilote = ui.resultList->item(i,2)->text().toInt();
      if( course[num_pilote].statut == ARRIVE ) {
         char c_pos[3];
         pos++;
         sprintf(c_pos,"%02d",pos);
         ui.resultList->item(i,4)->setText(QString(c_pos));
         if( points.find( pos ) != points.end() ) {
            pts = points[ pos ];
			} else {
				pts = 0;
			}
         ui.resultList->item(i,5)->setText(QString().setNum(pts));
      } else {
         if( course[num_pilote].statut == DISQUALIFIE ) {
            ui.resultList->item(i,4)->setText("DISQUALIFIÉ");
         } else if( course[num_pilote].statut == NON_CLASSE ) {
            ui.resultList->item(i,4)->setText("NON CLASSÉ");
         } else if( course[num_pilote].statut == ABANDON ) {
            ui.resultList->item(i,4)->setText("ABANDON");
         }
         ui.resultList->item(i,5)->setText(QString("0"));
      }
   }
}
/*****************************************************************************/
void PointageWindow::showGrid()
{
   // Init de la grille de départ
	gw->init();

	if( gw->exec() == QDialog::Accepted ) {
      gw->getPilotesDepart(pilotesDepart);
	}
}
/*****************************************************************************/
void PointageWindow::getResult( QList<Epreuve> &epreuves, int id_manche )
{
   for (int i=0; i<ui.resultList->rowCount(); i++) {
	   int place;
	   int statut;
   	
	   if( ui.resultList->item(i,4)->text() == "ABANDON" ) {
		   place = 0;
		   statut = 1;
	   } else if( ui.resultList->item(i,4)->text() == "DISQUALIFIÉ" ) {
		   place = 0;
		   statut = 2;
	   } else if( ui.resultList->item(i,4)->text() == "HORS CATEGORIE" ) {
		   place = 0;
		   statut = 3;
	   } else {
		   place = ui.resultList->item(i,4)->text().toInt();
		   statut = 0;
	   }

	   // id_manche, id_pilote, place
	   epreuves.append( Epreuve( id_manche, ui.resultList->item(i,0)->text().toInt(), place, ui.resultList->item(i,3)->text().toInt(), statut ) );
   }
}

//=============================================================================
// Fin du fichier PointageWindow.cpp
//=============================================================================
