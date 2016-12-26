/*=============================================================================
 * FantasyBowl 1.0 - Interface.cpp
 *=============================================================================
 * Fenêtre principale avec les graphiques + paramètres globaux du jeu
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 02/03/2003 : première version
 *
 *=============================================================================
 */

#include "Interface.h"

/*****************************************************************************/
Interface::Interface( QWidget* parent, const char* name, WFlags f )
	: QMainWindow( parent, name, f )
{
	int ret;

	game = new Game(this);
	ret = game->readTitles();
	if(ret)
	{
		QMessageBox::warning( this, "Warning",
                            "File error : data/titles.xml.\n"
							"Press Ok to quit.");
		exit(0);
	}

	ret = game->readSkills();
	if(ret)
	{
		QMessageBox::warning( this, "Warning",
                            "File error :  data/skills.xml.\n"
							"Press Ok to quit.");
		exit(0);
	}

	ret = initValues();
	if(ret)
	{
		QMessageBox::warning( this, "Warning",
                            "Fichiers de données non valides.\nLe preogramme va se terminer.");
		exit(0);
	}

	// Menu
    QPopupMenu *file = new QPopupMenu( this );
	menuBar()->insertItem( "&File", file );
	//   file->insertItem( "&New Game", this, SLOT(newGame()), CTRL+Key_N );
	// load game
	// save game
	// 

	file->insertSeparator();
	file->insertItem( "&Quit", qApp, SLOT( quit() ), CTRL + Key_Q );

	QPopupMenu *teams = new QPopupMenu( this );
	menuBar()->insertItem( "&Teams", teams );
	teams->insertItem( "&Team management", this, SLOT(manageTeams()), CTRL+Key_M );
	// Create new team
	// 

	QPopupMenu *gameMenu = new QPopupMenu( this );
	menuBar()->insertItem( "&Game", gameMenu );
	gameMenu->insertItem( "&New Game", this, SLOT(newGame()), CTRL+Key_N );
	
	windows = new QPopupMenu( this );
	menuBar()->insertItem( "&Windows", windows );
	dugOutRedId = windows->insertItem( "&Dugout Team 1 (red)", this, SLOT(showDug()), CTRL+Key_D );
	dugOutBlueId = windows->insertItem( "&Dugout Team 2 (blue)", this, SLOT(showDug2()), CTRL+Key_E );

	connect(this,SIGNAL(sgnlShowDug(int)),this, SLOT(showDugout(int)));


	windows->setItemEnabled (dugOutRedId, false);
	windows->setItemEnabled (dugOutBlueId, false);

	// Statusbar
	statusBar()->message("Welcome to FantasyBowl !");

    CanvasView = new Terrain( game->getCanvas(0), this, "CanvasView" );
	CanvasView->setGeometry(5,25,398,654);

	////// Player characteristics panel //////

		player = new QGroupBox("Player characteristics", this);
		player->setGeometry(420,25,370,250);

		nom = new QLabel("",player);
		nom->setGeometry(10,15,350,30);
		nom->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		nom->setFrameStyle(QFrame::Box | QFrame::Plain);
		nom->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc

		playerPic = new QFrame(player);
		playerPic->setGeometry(10,95,150,150);
		playerPic->setFrameStyle(QFrame::Box | QFrame::Plain);

		mvmt1 = new QLabel("Movement",player);
		mvmt1->setGeometry(10,50,89,20);
		mvmt1->setFrameStyle(QFrame::Box | QFrame::Plain);
		mvmt1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		mvmt2 = new QLabel("",player);
		mvmt2->setGeometry(10,69,89,20);
		mvmt2->setFrameStyle(QFrame::Box | QFrame::Plain);
		mvmt2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		force1 = new QLabel("Force",player);
		force1->setGeometry(98,50,87,20);
		force1->setFrameStyle(QFrame::Box | QFrame::Plain);
		force1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		force2 = new QLabel("",player);
		force2->setGeometry(98,69,87,20);
		force2->setFrameStyle(QFrame::Box | QFrame::Plain);
		force2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		
		agilite1 = new QLabel("Agility",player);
		agilite1->setGeometry(184,50,87,20);
		agilite1->setFrameStyle(QFrame::Box | QFrame::Plain);
		agilite1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		
		agilite2 = new QLabel("",player);
		agilite2->setGeometry(184,69,87,20);
		agilite2->setFrameStyle(QFrame::Box | QFrame::Plain);
		agilite2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		
		armor1 = new QLabel("Armor",player);
		armor1->setGeometry(270,50,89,20);
		armor1->setFrameStyle(QFrame::Box | QFrame::Plain);
		armor1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		
		armor2 = new QLabel("",player);
		armor2->setGeometry(270,69,89,20);
		armor2->setFrameStyle(QFrame::Box | QFrame::Plain);
		armor2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		skillsList1 = new QLabel("Skills",player);
		skillsList1->setGeometry(170,95,190,20);
		skillsList1->setFrameStyle(QFrame::Box | QFrame::Plain);
		skillsList1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		skillsList1->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc

		skillsList2 = new QListBox(player);
		skillsList2->setGeometry(170,114,190,130);
		skillsList2->setFrameStyle(QFrame::Box | QFrame::Plain );
		skillsList2->setLineWidth(1);

	//////////////////////////////

	////// Infos panel //////

		infos = new QGroupBox("Infos", this);
		infos->setGeometry(420,280,370,200);

		dice1 = new QPushButton(infos);
		dice1->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc
		dice1->setGeometry(5,15,40,40);
		dice1->setFlat(true);

		dice2 = new QPushButton(infos);
		dice2->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc
		dice2->setGeometry(50,15,40,40);
		dice2->setFlat(true);

		dice3 = new QPushButton(infos);
		dice3->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc
		dice3->setGeometry(95,15,40,40);
		dice3->setFlat(true);

/*		QPixmap pm;
		if (pm.load("pics/skull.png"))
		{
			dice3->setPixmap( pm );
			dice2->setPixmap( pm );
		}
*/
		d61 = new QWidget(infos);
		d61->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc
		d61->setGeometry(150,15,30,30);

		d62 = new QWidget(infos);
		d62->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc
		d62->setGeometry(190,15,30,30);
//		if (pm.load("pics/dice6.png"))
//			d62->setBackgroundPixmap(pm);

//		score = new QLabel("Touchdowns :  Orcs 1    Dwarf 2",infos);
		score = new QLabel("",infos);
		score->setGeometry(5,65,300,20);
		score->setFrameStyle(QFrame::Box | QFrame::Plain);
		score->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		score->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc

//		temps1 = new QLabel("Temps de jeu Orcs : 01:35 (00:25:17)", infos);
		temps1 = new QLabel("", infos);
		temps1->setGeometry(5,90,300,20);

//		temps2 = new QLabel("Temps de jeu Nains : 00:05 (00:19:47)", infos);
		temps2 = new QLabel("", infos);
		temps2->setGeometry(5,115,300,20);

//		currentTurn = new QLabel("Tour en cours : Nains", infos);
		currentTurn = new QLabel("", infos);
		currentTurn->setGeometry(5,150,200,20);

		endTurn = new QPushButton("End turn", infos);
		endTurn->setGeometry(270,150,80,30);

	//////////////////////////////

	logs = new QGroupBox("Messages", this);
	logs->setGeometry(420,485,370,190);
	logPanel = new QTextView( logs );
	logPanel->setGeometry(5,15,360,170);

	logPanel->setText(WELCOME_MSG);

	infos->setDisabled(true);

	dug1 = new Dugout(this, game->getCanvas(1), 1);
	dug2 = new Dugout(this, game->getCanvas(2), 2);

	resize(800, 750);
	setMaximumSize(800,700);

	setCaption("Qt - FantasyBowl");
}
/*****************************************************************************/
/**
 *	Retourne 0 en cas de succès, sinon code d'erreur
 */
int Interface::initValues()
{

	pawnClicked = false;
	
	return 0;
}
/*****************************************************************************/
int Interface::groundClicked(int x, int y)
{
	if(pawnClicked == false)
		return -1;


	Joueur *j;
	if(pawnTeam == 1)
	{
		// find the player
		j = game->rouge->playerList.at(pawnNumber-1);

		if(j == NULL)
			return 462;
		
		game->placePion(x, y, 1, pawnNumber);

	}
	else
	{
		// find the player
		j = game->bleu->playerList.at(pawnNumber-1);

		if(j == NULL)
			return 462;
		
		game->placePion(x, y, 2, pawnNumber);
	
	}
	
	
	return 0;
	
}
/*****************************************************************************/
void Interface::effaceJoueur()
{

	nom->clear();

	QPixmap plm;
	plm.fill();	// rempli le pixmap en blanc
	playerPic->setBackgroundPixmap( plm );

	mvmt2->clear();
	force2->clear();
	agilite2->clear();
	armor2->clear();

	skillsList2->clear();
}
/*****************************************************************************/
void Interface::afficheJoueur(Joueur *j)
{

	nom->setText(j->getName() + " - " + j->getTitle());

	QPixmap plm;
	if(plm.load("players/" + j->getPic()))
		playerPic->setBackgroundPixmap(plm);
	else
	{
		plm.fill();	// rempli le pixmap en blanc
		playerPic->setBackgroundPixmap( plm );
	}

	mvmt2->setText(QString().setNum(j->getMa()));
	force2->setText(QString().setNum(j->getSt()));
	agilite2->setText(QString().setNum(j->getAg()));
	armor2->setText(QString().setNum(j->getAv()));

	skillsList2->clear();

	Skill *comp;
	for ( comp=j->playerSkills.first(); comp != 0; comp=j->playerSkills.next() )
	{
		skillsList2->insertItem(comp->getName(), comp->getId()) ;
	}

}
/*****************************************************************************/
void Interface::manageTeams()
{
	// Launch TeamEditor executable
}
/*****************************************************************************/
void Interface::resizeEvent( QResizeEvent * )
{
	CanvasView->resize(398,height()-46);
}
/*****************************************************************************/
void Interface::newGame()
{
	QString f1, f2;


	GameWizard *gw = new GameWizard(this);
	gw->show();

	
	if(gw->result()==QDialog::Accepted)
	{
		game->newGame();

		f1 = gw->getTeam1();
		f2 = gw->getTeam2();

		if(game->setTeam(1,f1))
			return;

		if(game->setTeam(2,f2))
			return;

		windows->setItemEnabled(dugOutRedId, true);
		windows->setItemEnabled(dugOutBlueId, true);
		
		showLogMsg("Open the Dugout window to manage your team.");

	}


}
/*****************************************************************************/
void Interface::dugClicked(int dugNum, int x, int y)
{
	int x_coor, y_coor, ret;


	// contrôle de la zone de click
	if( x<0 || x>=104 || y<0 || y>=104)
		return;

	// on est dans la zone de réserve, on détermine les coordonnées de la matrice
	x_coor = x/26;
	y_coor = y/26;

	// on teste s'il y a un joueur à cette position...
	if((ret = game->getReserve(dugNum, x_coor, y_coor))==0)
		return;
	
	ret-=100;
	if(ret<=0)
		return;	// hum, y'a un problème

	// on affiche les caractéristiques de ce joueur...

	Joueur *j;

	if(dugNum == 1)
	{
		for(j = game->rouge->playerList.first(); j!=0; j = game->rouge->playerList.next())
		{
			if(ret == j->getNumero())
				break;	// yes, I got it !
		}

		if(j == NULL)
			return;
		afficheJoueur(j);
		pawnClicked = true;
		pawnTeam = 1;
		pawnNumber = ret;
	}
	else
	{
		for(j = game->bleu->playerList.first(); j!=0; j = game->bleu->playerList.next())
		{
			if(ret == j->getNumero())
				break;	// yes, I got it !
		}

		if(j == NULL)
			return;
		afficheJoueur(j);
		pawnClicked = true;
		pawnTeam = 2;
		pawnNumber = ret;
	}

}
/*****************************************************************************/
void Interface::showDugout(int equipe)
{
	if(equipe==1)
	{
		windows->setItemEnabled(dugOutRedId, false);
		dug1->show();
	}
	else
	{
		windows->setItemEnabled(dugOutBlueId, false);
		dug2->show();
	}

}
/*****************************************************************************/
void Interface::showDug()
{
	emit sgnlShowDug(1);
}
/*****************************************************************************/
void Interface::showDug2()
{
	emit sgnlShowDug(2);
}
/*****************************************************************************/
void Interface::closeDug(int equipe)
{
	if(equipe==1)
		windows->setItemEnabled(dugOutRedId, true);
	else
		windows->setItemEnabled(dugOutBlueId, true);

}
/*****************************************************************************/
void Interface::showErrorMsg(QString errorMsg)
{
	if(errorMsg.length()==0)
		return;

	QMessageBox::warning( this, "Qt - FantasyBowl error !", errorMsg);

}
/*****************************************************************************/
void Interface::showLogMsg(QString logMsg)
{
	QString t;
	t = logPanel->text() + "<hr>" + logMsg;

	logPanel->setText(t);

}
//=============================================================================
// Fin du fichier Interface.cpp
//=============================================================================