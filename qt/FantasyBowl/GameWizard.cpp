/*=============================================================================
 * FantasyBowl 1.0 - GameWizard.cpp
 *=============================================================================
 * Écrans de configuration pour démarrer une nouvelle partie
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0 / g++ Avec librairies Qt 2.3 minimum
 *
 * Historique :
 * 
 * 02/03/2003 : première version
 *
 *=============================================================================
 */

#include "GameWizard.h"

/*****************************************************************************/
GameWizard::GameWizard( QWidget *parent, const char *name ) : QWizard( parent, name, TRUE )
{
    setupPage1();
	setupPage2();
	setCaption("New game wizard");
	
	cptTeams = 0;

	setFixedSize(350,300);
}
/*****************************************************************************/
void GameWizard::setupPage1()
{
	page1 = new QFrame(this);
	
	gameChoice = new QComboBox(page1);
	
	gameChoice->setGeometry(10,10,130,30);

	gameChoice->insertItem("Human Vs Human",0);
	gameChoice->insertItem("Human Vs Computer",1);
	gameChoice->insertItem("Net game",2);

    addPage(page1, "Choose game type" );

    setNextEnabled( page1, TRUE );
    setHelpEnabled( page1, FALSE );
}
/*****************************************************************************/
void GameWizard::setupPage2()
{
	page2 = new QFrame(this);
	
	teamsList = new QListBox(page2);
	teamsList->setGeometry(10,10,150,200);

	bt1 = new QPushButton(page2);
	bt1->setGeometry(165,50,30,30);
	bt1->setIconSet ( QIconSet( QPixmap("pics/arrow_right.png") ) );
	connect(bt1, SIGNAL(clicked()) ,this, SLOT(clickTeam1()));

	bt2 = new QPushButton(page2);
	bt2->setGeometry(165,140,30,30);
	bt2->setIconSet ( QIconSet( QPixmap("pics/arrow_right.png") ) );
	connect(bt2, SIGNAL(clicked()) ,this, SLOT(clickTeam2()));

	lbl1 = new QLabel("Équipe 1 (rouge) :",page2);
	lbl1->setGeometry(210,30,150,20);

	lbl2 = new QLabel("",page2);
	lbl2->setGeometry(210,50,150,20);

	lbl3 = new QLabel("Équipe 2 (bleu) :",page2);
	lbl3->setGeometry(210,120,150,20);

	lbl4 = new QLabel("",page2);
	lbl4->setGeometry(210,140,150,20);


    addPage(page2, "Choose teams" );

	setFinish( page2, FALSE );
    setHelpEnabled( page2, FALSE );
}
/*****************************************************************************/
void GameWizard::showPage( QWidget* page )
{
	if(page == page2)
	{
			
		QDir d("teams");
		d.setFilter(QDir::Files);
		d.setSorting(QDir::Name);

		QFileInfo fi;
		QStringList filelist = d.entryList();
		
		teamsList->clear(); // Clear the listbox
		
		for( QStringList::Iterator i = filelist.begin(); i != filelist.end(); ++i)
		{
			fi.setFile( (*i).latin1() );
			if(fi.extension(FALSE).lower() == "xml")
				teamsList->insertItem(fi.baseName());
		}

	}

    QWizard::showPage(page);

}
/*****************************************************************************/
void GameWizard::clickTeam1()
{
	QString nom;

	nom = teamsList->currentText();
	if(nom.length()==0)
		return;

	cptTeams++;
	lbl2->setText(nom);

	if(cptTeams >= 2 && lbl4->text().length()!=0)
        finishButton()->setEnabled( TRUE );
    else
        finishButton()->setEnabled( FALSE );
}
/*****************************************************************************/
void GameWizard::clickTeam2()
{
	QString nom;

	nom = teamsList->currentText() ;
	if(nom.length()==0)
		return;

	cptTeams++;
	lbl4->setText(nom);

	if(cptTeams >= 2 && lbl2->text().length()!=0)
        finishButton()->setEnabled( TRUE );
    else
        finishButton()->setEnabled( FALSE );
}
/*****************************************************************************/
QString GameWizard::getTeam1()
{
	return lbl2->text();
}
/*****************************************************************************/
QString GameWizard::getTeam2()
{
	return lbl4->text();
}

//=============================================================================
// Fin du fichier GameWizard.cpp
//=============================================================================