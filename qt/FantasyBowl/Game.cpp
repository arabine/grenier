/*=============================================================================
 * FantasyBowl 1.0 - Game.cpp
 *=============================================================================
 * Classe principale de gestion du jeu
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 10/03/2003 : première version
 *
 *=============================================================================
 */

#include "Game.h"

/*****************************************************************************/
Game::Game(QWidget* parent)
{

	rouge = new Equipe(1);
	bleu = new Equipe(2);

	/* Terrain principal */
	
    canvas = new QCanvas( this, "Canvas" );
    canvas->setBackgroundPixmap( QPixmap( "pics/terrain.png" ) );
    canvas->setAdvancePeriod( 10 );
	// taille terrain : 377 x 652
	canvas->resize( 377, 652 );

	/* Banc de touche equipe 1 Rouge */

    canvasDug1 = new QCanvas( this, "Canvas" );
    canvasDug1->setBackgroundPixmap( QPixmap( "pics/dugout.png" ) );
    canvasDug1->setAdvancePeriod( 10 );
	// taille terrain : 400 x 200
	canvasDug1->resize( 400, 200 );

	/* Banc de touche equipe 2 bleu */
    canvasDug2 = new QCanvas( this, "Canvas" );
    canvasDug2->setBackgroundPixmap( QPixmap( "pics/dugout.png" ) );
    canvasDug2->setAdvancePeriod( 10 );
	// taille terrain : 400 x 200
	canvasDug2->resize( 400, 200 );

	connect(this, SIGNAL(sgnlSetError(QString)), parent, SLOT(showErrorMsg(QString)));

	newGame(); // initialize variables for a new game
}
/*****************************************************************************/
void Game::newGame()
{
	int i, j;

	scoreRed = 0;
	scoreBlue = 0;

	// initialisation de la grille de jeu
	for(i=0;i<15;i++)
		for(j=0;j<26;j++)
			grille[i][j] = 0;
	
	// initialisation des bancs de touche
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			gDugBlueReserve[i][j] = 0;
			gDugRedReserve[i][j] = 0;
		}
}
/*****************************************************************************/
/**
 * Return a pointer of canvas
 */
QCanvas* Game::getCanvas(int place)
{
	if(place == 0)
		return canvas; // playground
	else	if(place == 1)
				return canvasDug1; // Dugout team 1
			else	if(place == 2)
						return canvasDug2; // Dugout team 2
					else
						return canvas; // default
}
/*****************************************************************************/
/**
 * Load a team into memory from a XML file
 * Return 0 if everything's allright, else 1
 */
int Game::setTeam(int num, QString filePath)
{
	int ret;
	
	int x=0, y=0, i, j, numPlayer;

	if(num==1)
	{
		ret = rouge->readXMLFile(skillsList,"teams/" + filePath + ".xml", canvasDug1);
		if(ret)
		{
			emit sgnlSetError("Erreur lecture fichier équipe : " + QString().setNum(ret));
			return 1;
		}
		// on range les pions convenablement
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				x = i*26;
				y = j*26;
				numPlayer = i+j*4+1;
				if(rouge->setCoord(numPlayer, x, y))
					continue;
				gDugRedReserve[i][j] = 100 + numPlayer;
			}
		}

		// Show the correct pawn corresponding to the title
		rouge->setPawns(titleList);
	}
	else
	{
		ret = bleu->readXMLFile(skillsList,"teams/" + filePath + ".xml", canvasDug2);
		if(ret)
		{
			emit sgnlSetError("Erreur lecture fichier équipe : " + QString().setNum(ret));
			return 1;
		}
		// on range les pions convenablement
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				x=i*26;
				y=j*26;
				numPlayer = i+j*4+1;
				if(bleu->setCoord(numPlayer, x, y))
					continue;
				gDugBlueReserve[i][j] = 100 + numPlayer;
			}
		}
		// Show the correct pawn corresponding to the title
		bleu->setPawns(titleList);
	}

	return 0;
}
/*****************************************************************************/
/**
 * Return the status of a square (coord x,y) in the dugout dugNum
 */
int Game::getReserve(int dugNum, int x, int y)
{
	if(dugNum == 1)
		return gDugRedReserve[x][y];
	else
		return gDugBlueReserve[x][y];
}
/*****************************************************************************/
void Game::saveGame()
{

}
/*****************************************************************************/
void Game::loadGame()
{

}
/*****************************************************************************/
void Game::pauseGame()
{

}
/*****************************************************************************/
/**
 * Load into memory the titles of players
 */
int Game::readSkills()
{
	// initialisation de la liste des compétences skillsList
	// La liste des compétences est diponible dans le fichier data/skills.xml

	QDomDocument doc;
	QFile f("data/skills.xml");
	
	f.open(IO_ReadOnly);
	doc.setContent(&f);
	f.close();

	// On parse le fichier
	
	// On teste le tag "FBteam"
	QDomElement root=doc.documentElement();
	if(root.tagName()!="FBskills")
		return 1;

	if(root.attribute("version","0")!="1.0")
		return 2;

	// On parse les données

	QDomElement child=root.firstChild().toElement();

	while(!child.isNull())
	{
		if(child.tagName() == "skill")
		{
			skillsList.append( new Skill(child.attribute("id","0").toInt(),
									child.text(),
									child.attribute("type", "0").toInt() ));

		}
		child = child.nextSibling().toElement();
	}

	return 0;
}
/*****************************************************************************/
/**
 * Load into memory the titles of players
 */
int Game::readTitles()
{

	QDomDocument doc;
	titleList.clear();

	// On ouvre le fichier XML
	QFile f("data/titles.xml");
	
	f.open(IO_ReadOnly);
	doc.setContent(&f);
	f.close();

	// L'arbre est en mémoire, on le parse	
	// Commence par la balise "FBteam"
	QDomElement root=doc.documentElement();

	if(root.tagName()!="FBtitles")
		return 1;

	// On parse les données
	QDomElement child=root.firstChild().toElement();

	while(!child.isNull())
	{
		if(child.tagName() == "title")
		{
			titleList.insert(child.attribute("id", "0" ).toInt(), Title(child.text(),child.attribute("pawn", "B" )));
		}
		child = child.nextSibling().toElement();
	}
	
	return 0;
}
/*****************************************************************************/
void Game::placePion(int x, int y, int equipe, int joueurNum)
{
	int i, k, n, m;

	n=0;k=0;m=0;
	for(i=26;i<390;i=i+25)
	{
		if(i>=x)
		{
			x=i-26;
			k=1;
			break;
		}
		n++;
	}
	if(!k)
		return;

	k = 0;
	for(i=26;i<660;i=i+25)
	{
		if(i>=y)
		{
			y=i-26;
			k=1;
			break;
		}
		m++;
	}
	if(!k)
		return;

	if(equipe == 1)
	{
		rouge->setGround(joueurNum, canvas);
		rouge->setCoord(joueurNum, x, y);
	}
	else
	{
		bleu->setGround(joueurNum, canvas);
		bleu->setCoord(joueurNum, x, y);
	}

/*
	if(grille[n][m]!=0)
	{
		QMessageBox::warning( this, "Warning",
                            "Case occupée.");
		return;
	}

	grille[n][m]= .....;

	//affiche un pion
    Joueur *joueur1 = new Joueur(var,Canvas);

	joueur1->move( x, y );
	joueur1->show();
*/
}
//=============================================================================
// Fin du fichier Game.cpp
//=============================================================================