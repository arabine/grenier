/*=============================================================================
 * FantasyBowl 1.0 - TeamManagement.cpp
 *=============================================================================
 * Fenêtre de gestion des équipes, édition + sauvegarde
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *
 *=============================================================================
 */

#include "TeamManagement.h"


/*****************************************************************************/
TeamManagement::TeamManagement( QWidget* parent, const char* name, WFlags f )
	: QMainWindow( parent, name, f )
{
	int ret;
	ret = initValues();
	if(ret)
	{
		QMessageBox::warning( this, "Warning",
                            "Initialisation error.\n Error code : "
							+ QString().setNum(ret) +
							"Press Ok to quit.");
		exit(0);
	}

	theTeam = new Equipe(1); // équipe 1, arbitraire (il faut bien donner un chiffre)

	menu = new QMenuBar(this);
	file = new QPopupMenu(this);
	menu->insertItem( "&File", file );
	file->insertItem( "&New", this, SLOT(newRoster()), CTRL+Key_N );
	file->insertItem( "&Open", this, SLOT(openRoster()), CTRL+Key_O );
	saveId = file->insertItem( "&Save", this, SLOT(saveRoster()), CTRL+Key_S );
	saveAsId = file->insertItem( "Save &As...", this, SLOT(saveRosterAs()), CTRL+Key_A );
	closeId = file->insertItem( "&Close", this, SLOT( closeRoster() ), CTRL + Key_W );
	file->insertSeparator();
	file->insertItem( "E&xit", this, SLOT(close()), CTRL + Key_Q );

	file->setItemEnabled(saveId, false);
	file->setItemEnabled(saveAsId, false);
	file->setItemEnabled(closeId, false);


    teamTable = new MyQTable( 16, 16, this );
    teamTable->setGeometry( QRect( 5, 25, 590, 300 ) ); 
	QHeader *th = teamTable->horizontalHeader();

    th->setLabel(0, "Player name");
	teamTable->setColumnWidth(0,100);

	th->setLabel(1, "Position");

	th->setLabel(2, "MA");				// Movement Allowance
	teamTable->setColumnWidth(2,30);
	th->setResizeEnabled(false,2);

	th->setLabel(3, "ST");				// Strength
	teamTable->setColumnWidth(3,30);
	th->setResizeEnabled(false,3);
	
	th->setLabel(4, "AG");				// Agility
	teamTable->setColumnWidth(4,30);
	th->setResizeEnabled(false,4);

	th->setLabel(5, "AV");				// Armour Value
	teamTable->setColumnWidth(5,30);
	th->setResizeEnabled(false,5);

	th->setLabel(6, "Skills");

	th->setLabel(7, "INJ");				// Injuries
	teamTable->setColumnWidth(7,30);
	th->setResizeEnabled(false,7);

	th->setLabel(8, "COMP");			// Completions
	teamTable->setColumnWidth(8,30);
	th->setResizeEnabled(false,8);

	th->setLabel(9, "TD");				// Touchdowns
	teamTable->setColumnWidth(9,30);
	th->setResizeEnabled(false,9);

	th->setLabel(10, "INT");			// Interceptions
	teamTable->setColumnWidth(10,30);
	th->setResizeEnabled(false,10);

	th->setLabel(11, "CAS");			// Casualties
	teamTable->setColumnWidth(11,30);
	th->setResizeEnabled(false,11);

	th->setLabel(12, "MVP");			// Most Valuable Player
	teamTable->setColumnWidth(12,30);
	th->setResizeEnabled(false,12);

	th->setLabel(13, "SPP");			// Star Player Points
	teamTable->setColumnWidth(13,30);
	th->setResizeEnabled(false,13);

	th->setLabel(14, "Cost");
	th->setLabel(15, "Picture");

	infos = new QGroupBox("Infos", this);
	infos->setGeometry(5,395,600,160);
	infos->setDisabled(true);

	name_text = new QLabel("Team : ",infos);
	name_text->setGeometry(5,20,50,20);
	team_name = new MyQLineEdit(infos);
	team_name->setGeometry(60,20,140,20);

	race_text = new QLabel("Race : ",infos);
	race_text->setGeometry(5,45,50,20);
	race = new MyQLineEdit(infos);
	race->setGeometry(60,45,140,20);

	rating_text = new QLabel("Rating : ",infos);
	rating_text->setGeometry(5,70,50,20);
	rating = new QLabel("", infos);
	rating->setGeometry(60,70,140,20);

	treasury_text = new QLabel("Treasury : ",infos);
	treasury_text->setGeometry(5,95,50,20);
	treasury = new QLabel("",infos);
	treasury->setGeometry(60,95,140,20);

	coach_text = new QLabel("Coach : ",infos);
	coach_text->setGeometry(5,120,50,20);
	coach = new MyQLineEdit(infos);
	coach->setGeometry(60,120,140,20);

	fanfactor_text = new QLabel("Fan factor : ",infos);
	fanfactor_text->setGeometry(210,20,80,20);
	fanfactor = new QSpinBox(1,20,1,infos);
	fanfactor->setGeometry(295,20,40,20);
	connect(fanfactor, SIGNAL(valueChanged(int)), this, SLOT(calculTotal()));

	assistants_text = new QLabel("Assistants : ",infos);
	assistants_text->setGeometry(210,45,80,20);
	assistants = new QSpinBox(0,20,1,infos);
	assistants->setGeometry(295,45,40,20);
	connect(assistants, SIGNAL(valueChanged(int)), this, SLOT(calculTotal()));

	cheerleaders_text = new QLabel("Cheerleaders : ",infos);
	cheerleaders_text->setGeometry(210,70,80,20);
	cheerleaders = new QSpinBox(0,20,1,infos);
	cheerleaders->setGeometry(295,70,40,20);
	connect(cheerleaders, SIGNAL(valueChanged(int)), this, SLOT(calculTotal()));

	apothecary_text = new QLabel("Apothecary : ",infos);
	apothecary_text->setGeometry(210,95,80,20);
	apothecary = new QSpinBox(0,20,1,infos);
	apothecary->setGeometry(295,95,40,20);
	connect(apothecary, SIGNAL(valueChanged(int)), this, SLOT(calculTotal()));

	wizard_text = new QLabel("Wizard : ",infos);
	wizard_text->setGeometry(210,120,80,20);
	wizard = new QSpinBox(0,20,1,infos);
	wizard->setGeometry(295,120,40,20);
	connect(wizard, SIGNAL(valueChanged(int)), this, SLOT(calculTotal()));

	rerollcost_text = new QLabel("Re-roll cost : ",infos);
	rerollcost_text->setGeometry(365,20,80,20);
	rerollcost = new QSpinBox(0,90000,10000,infos);
	rerollcost->setGeometry(450,20,70,20);
	connect(rerollcost, SIGNAL(valueChanged(int)), this, SLOT(calculTotal()));

	rerollnumber_text = new QLabel("Re-rolls : ",infos);
	rerollnumber_text->setGeometry(365,45,80,20);
	rerollnumber = new QSpinBox(0,20,1,infos);
	rerollnumber->setGeometry(450,45,40,20);
	connect(rerollnumber, SIGNAL(valueChanged(int)), this, SLOT(calculTotal()));

	totalCost_text = new QLabel("Total cost : ",infos);
	totalCost_text->setGeometry(365,70,80,20);
	totalCost = new QLabel("",infos);
	totalCost->setGeometry(450,70,70,20);

	logo = new MyLogo(this);
	logo->setGeometry(620,395,160,160);
	logo->setFrameStyle(QFrame::Box | QFrame::Plain);
	logo->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc

	for(int i=0;i<16;i++)
		teamTable->setCellWidget(i, 1, new MyQCombo(this, theTitleList));


	setMinimumSize(800,560);
	setMaximumHeight(560);
	resize(800,560);
	setCaption(DEF_TITLE);

}
/*****************************************************************************/
void TeamManagement::resizeEvent(QResizeEvent *)
{
	teamTable->resize(width()-10,360);
	teamTable->setColumnWidth(6,width()-680);
}
/*****************************************************************************/
void TeamManagement::closeEvent(QCloseEvent *)
{
	if(closeRoster() == 1)
		return;
	
	destroy();
}
/*****************************************************************************/
/**
 * Return 0 if ok, else return error code
 */
int TeamManagement::initValues()
{
	lastDirectory = "teams";
	currentFilePath = "";
	rosterModified = false;
	goCalc = false;

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
			theSkillList.append( new Skill(child.attribute("id","0").toInt(),
									child.text(),
									child.attribute("type", "0").toInt() ));

		}
		child = child.nextSibling().toElement();
	}


	theTitleList.clear();

	// On ouvre le fichier XML
	f.setName("data/titles.xml");
	
	f.open(IO_ReadOnly);
	doc.setContent(&f);
	f.close();

	// L'arbre est en mémoire, on le parse	
	// Commence par la balise "FBteam"
	root=doc.documentElement();

	if(root.tagName()!="FBtitles")
		return 1;

	// On parse les données
	child=root.firstChild().toElement();

	while(!child.isNull())
	{
		if(child.tagName() == "title")
		{
			theTitleList.insert(child.attribute("id", "0" ).toInt(), Title(child.text(),child.attribute("pawn", "B" )));
		}
		child = child.nextSibling().toElement();
	}

	return 0;
}
/*****************************************************************************/
void TeamManagement::newRoster()
{
	closeRoster();

	infos->setDisabled(false);
	file->setItemEnabled (saveId, true);
	file->setItemEnabled (saveAsId, true);
	file->setItemEnabled (closeId, true);

	bool ok = FALSE;
	int res = QInputDialog::getInteger( tr( "Create a new team" ), tr("Enter maximum team cost"),1000000, 50000, 2000000, 10000, &ok, this );
	if ( ok )
	  treasury->setText(QString().setNum(res));// user entered something and pressed ok
	else
	  treasury->setText("1000000");// user pressed cancel

	goCalc = true;
}
/*****************************************************************************/
void TeamManagement::openRoster()
{
	int ret;
	QString s;

	closeRoster();

	currentFilePath = QFileDialog::getOpenFileName(lastDirectory, "TEAM file (*.xml)", this) ;
    
	if ( currentFilePath.isEmpty() )
        return;
	
	lastDirectory = QFileInfo(currentFilePath).dirPath();

	ret = readXMLFile();
	if(ret)
	{
		s = s.setNum(ret);
		QMessageBox::warning( this, "Retour","Code : " + s);
		return;
	}
	
	setCaption(DEF_TITLE  " - " + currentFilePath);

	infos->setDisabled(false);
	file->setItemEnabled (saveId, true);
	file->setItemEnabled (saveAsId, true);
	file->setItemEnabled (closeId, true);

	goCalc = true;
	calculTotal();

}
/*****************************************************************************/
void TeamManagement::saveRoster()
{
	QString s;
	int ret;
	
	if(treasury->text().toInt() < 0)
	{
		QMessageBox::warning( this, "Attention","Impossible de sauver, trésorerie négative.");
		return;
	}


	if(currentFilePath.length()==0)
	{
		saveRosterAs();
		return;
	}

	ret = saveXMLFile();
	if(ret)
	{
		s = s.setNum(ret);
		QMessageBox::warning( this, "Retour","Code : " + s);
	}
	
	rosterModified = false;
	setCaption(DEF_TITLE  " - " + currentFilePath);
}
/*****************************************************************************/
void TeamManagement::saveRosterAs()
{
	QString s;
	int ret;

	QString fileName = QFileDialog::getSaveFileName(lastDirectory, "TEAM file (*.xml)", this );
    if (!fileName.isNull())
	{
		currentFilePath = fileName;
     
    }
	else
		return;
	
	ret = saveXMLFile();
	if(ret)
	{
		s = s.setNum(ret);
		QMessageBox::warning( this, "Retour","Code : " + s);
	}

	rosterModified = false;
	setCaption(DEF_TITLE  " - " + currentFilePath);
}
/*****************************************************************************/
/**
 *  Return 1 if dialog canceled, 0 elsewhere
 */
int TeamManagement::closeRoster()
{
	if(rosterModified==true)
	{
	
		switch( QMessageBox::information( this, "Fantasy Bowl - Roster Management",
										  "The document contains unsaved work\n"
										  "Do you want to save it before closing ?",
										  "&Save", "&Don't Save", "&Cancel",
										  0,      // Enter == button 0
										  2 ) ) { // Escape == button 2
		case 0: // Save clicked, Alt-S or Enter pressed.
			saveRoster();
			break;
		case 1: // Don't Save clicked or Alt-D pressed
			break;
		case 2: // Cancel clicked, Alt-C or Escape pressed
			return 1;
		}
	
	
	}

	// On nettoie la liste d'équipe en mémoire
	if(!theTeam->playerList.isEmpty())
		theTeam->playerList.clear();

	// On initialise les box de paramétrage

	assistants->setValue(0);
	fanfactor->setValue(1);
	cheerleaders->setValue(0);
	apothecary->setValue(0);
	wizard->setValue(0);
	rerollnumber->setValue(0);
	rerollcost->setValue(50000);

	team_name->clear();
	race->clear();
	coach->clear();

	rating->clear();
	treasury->clear();
	totalCost->clear();



	setCaption(DEF_TITLE);

	MyQCombo *cellCombo;

	for(int i=0;i<=15;i++)
		for(int j=0;j<=15;j++)
		{
			if(j==1)
			{
				cellCombo = (MyQCombo *)teamTable->cellWidget(i, 1);
				if(cellCombo!=NULL)
					cellCombo->setCurrentItem(0);
			}
			else
				teamTable->setText(i,j,"");
		}

	infos->setDisabled(true);
	file->setItemEnabled (saveId, false);
	file->setItemEnabled (saveAsId, false);
	file->setItemEnabled (closeId, false);

	logo->repaint(true);

	QPixmap plm;
	plm.fill();	// rempli le pixmap en blanc
	logo->setBackgroundPixmap( plm );


	currentFilePath = "";
	rosterModified = false;
	goCalc = false;

	return 0;
}
/*****************************************************************************/
/**
 * A chaque modification effectuée on met à jour le total et la tresorerie
 */
void TeamManagement::calculTotal()
{
	int cout=0, sumSaved, tresorSaved, rate;
	QString coutAff;

	sumSaved = totalCost->text().toInt();
	tresorSaved = treasury->text().toInt();

	rosterModified = true;
	setCaption(DEF_TITLE  " - " + currentFilePath + " *");

	for(int i=0;i<16;i++)
	{
		if(teamTable->text(i,14).length()!=0)
			cout = cout + teamTable->text(i,14).toInt();
	}
	cout =	cout + assistants->text().toInt()*10000+wizard->text().toInt()*150000+
			cheerleaders->text().toInt()*10000+apothecary->text().toInt()*50000+
			fanfactor->text().toInt()*10000+rerollnumber->text().toInt()*rerollcost->text().toInt();


	coutAff = coutAff.setNum(cout);
	totalCost->setText(coutAff);

	if(goCalc == false)
		return;

	if(cout - sumSaved >= 0)
		treasury->setText(QString().setNum(tresorSaved - (cout - sumSaved)));
	else
		treasury->setText(QString().setNum(tresorSaved + (sumSaved - cout)));

	// calcul du classement (sans prise en compte des joueurs 
	// avec expérience
	rate = cout + treasury->text().toInt();
	rating->setText(QString().setNum(rate/10000));

}
/*****************************************************************************/
/**
 *  Ouvre la fenêtre d'édition des compétences du joueur
 */
void TeamManagement::showPlayerSkills(int row, int col)
{

	// Un nom est obligatoire pour le joueur !!
	if(teamTable->text(row, 0).length()==0)
		return;

	// boite de dialogue pour choisir l'image du joueur
	if(col==15)
	{
		QString picPath;
		MyFileDialog *fileDiag = new MyFileDialog("players/", this);
		
		fileDiag->show();

		if(fileDiag->result()==QDialog::Rejected)
			return;
		
		picPath = fileDiag->selectedFile();

		picPath = QFileInfo(picPath).fileName();
		if( picPath.isEmpty() )
			return;

		teamTable->setText(row,col,picPath);

		return;
	}

	if(col!=6)
		return;

	Joueur *j;
	j = theTeam->playerList.at(row);
	if(j == NULL)
		return;

	PlayerSkills *ps = new PlayerSkills(this, teamTable->text(row, 0), theSkillList, j->playerSkills);
	ps->show();

	if(ps->result()==QDialog::Accepted)
		j->playerSkills = ps->getPlayerSkills(); // on met à jour ses compétences
	
	// on met à jour l'affichage
	teamTable->setText(row,col,"");
	
	Skill *comp, *compj;
	for( comp=theSkillList.first(); comp != 0; comp=theSkillList.next() )
	{
		for( compj=j->playerSkills.first(); compj != 0; compj=j->playerSkills.next() )
		{
			if(comp->getId() == compj->getId())
				teamTable->setText(row,col,teamTable->text(row,col) + comp->getName() + ",");
		}
	}

}
/*****************************************************************************/
void TeamManagement::loadLogo()
{
	logoPath = QFileDialog::getOpenFileName("logos/", "Image file (*.png)", this);
    logoPath = QFileInfo(logoPath).fileName();
	QPixmap plm;
	if(plm.load("logos/" + logoPath))
		logo->setBackgroundPixmap( plm );
}
/*****************************************************************************/
int TeamManagement::readXMLFile()
{
	int ret=0;
	int id;
	
	if(!theTeam->playerList.isEmpty())
		theTeam->playerList.clear();

	ret = theTeam->readXMLFile(theSkillList, currentFilePath, 0);
	if(ret)
		return ret;

	// Let's fill out the controls

	team_name->setText(theTeam->getName());
	race->setText(theTeam->getRace());
	rating->setText(QString().setNum(theTeam->getRating()));
	treasury->setText(QString().setNum(theTeam->getTreasury()));
	coach->setText(theTeam->getCoach());
	fanfactor->setValue(theTeam->getFanFactor());
	assistants->setValue(theTeam->getAssistants());
	cheerleaders->setValue(theTeam->getCheerleaders());
	apothecary->setValue(theTeam->getApothecary());
	wizard->setValue(theTeam->getWizard());
	rerollcost->setValue(theTeam->getRerollCost());
	rerollnumber->setValue(theTeam->getReroll());

	QPixmap plm;
	logoPath = theTeam->getLogo();
	if (plm.load("logos/" + logoPath)) logo->setBackgroundPixmap( plm );
	
	Joueur *j;
	Skill *comp;
	MyQCombo *cellCombo;

	for(j=theTeam->playerList.first(); j != 0; j=theTeam->playerList.next())
	{
		id = j->getNumero();
		teamTable->setText(id-1,0,j->getName());
		cellCombo = (MyQCombo *)teamTable->cellWidget(id-1, 1);
		if(cellCombo!=NULL)
			cellCombo->setCurrentItem(j->getPosition());
		teamTable->setText(id-1,2,QString().setNum(j->getMa()));
		teamTable->setText(id-1,3,QString().setNum(j->getSt()));
		teamTable->setText(id-1,4,QString().setNum(j->getAg()));
		teamTable->setText(id-1,5,QString().setNum(j->getAv()));
		teamTable->setText(id-1,14,QString().setNum(j->getCost()));
		teamTable->setText(id-1,15,j->getPic());

		for(comp=j->playerSkills.first(); comp != 0; comp=j->playerSkills.next())
		{
			teamTable->setText(id-1,6,teamTable->text(id-1,6) + comp->getName() + ",");

		}
	}

	calculTotal();

	return ret;
}
/*****************************************************************************/
/**
 * Sauvegarde le tableau dans le fichier courant
 * 0 si bien passé, sinon message d'erreur
 */
int TeamManagement::saveXMLFile()
{
	QDate theDate;
	theDate = theDate.currentDate();

	// Create the document
	QDomDocument doc("FBteam");
	
	doc.appendChild( doc.createProcessingInstruction( "xml", "version=\"1.0\" encoding=\"ISO-8859-1\"" ) );
	doc.appendChild(doc.createTextNode("\n"));

	doc.appendChild( doc.createProcessingInstruction( "xml-stylesheet", "href=\"fbstyle.xsl\" type=\"text/xsl\"" ) );
	doc.appendChild(doc.createTextNode("\n"));

	doc.appendChild(doc.createComment("Generated by FantasyBowl 1.0 - " + theDate.toString()  ));
	doc.appendChild(doc.createTextNode("\n"));

	// root node
	QDomElement rootNode = doc.createElement("FBteam");
	rootNode.setAttribute("version", "1.0");
	doc.appendChild(rootNode);
	
	/*
   <name>Bugman Warriors</name>
   <race>Nains</race>
   <rating>100</rating>
   <treasury>0</treasury>
   <coach>Belegar</coach>
   <logo>nain.png</logo>
   <reroll cost="40000">0</reroll>
   <fanfactor>1</fanfactor>
   <assistants>1</assistants>
   <cheerleaders>1</cheerleaders>
   <apothecary>0</apothecary>
   <wizard>0</wizard>
	*/

	// Paramètres de l'équipe
	QDomElement nameNode = doc.createElement("name");
	nameNode.appendChild(doc.createTextNode(team_name->text()));
	rootNode.appendChild(nameNode);

	QDomElement raceNode = doc.createElement("race");
	raceNode.appendChild(doc.createTextNode(race->text()));
	rootNode.appendChild(raceNode);

	QDomElement ratingNode = doc.createElement("rating");
	ratingNode.appendChild(doc.createTextNode(rating->text()));
	rootNode.appendChild(ratingNode);

	QDomElement treasuryNode = doc.createElement("treasury");
	treasuryNode.appendChild(doc.createTextNode(treasury->text()));
	rootNode.appendChild(treasuryNode);

	QDomElement coachNode = doc.createElement("coach");
	coachNode.appendChild(doc.createTextNode(coach->text()));
	rootNode.appendChild(coachNode);

	QDomElement logoNode = doc.createElement("logo");
	logoNode.appendChild(doc.createTextNode(logoPath));
	rootNode.appendChild(logoNode);

	QDomElement rerollNode = doc.createElement("reroll");
	rerollNode.appendChild(doc.createTextNode(rerollnumber->text()));
	rerollNode.setAttribute("cost", rerollcost->text());
	rootNode.appendChild(rerollNode);

	QDomElement fanfactorNode = doc.createElement("fanfactor");
	fanfactorNode.appendChild(doc.createTextNode(fanfactor->text()));
	rootNode.appendChild(fanfactorNode);

	QDomElement assistantsNode = doc.createElement("assistants");
	assistantsNode.appendChild(doc.createTextNode(assistants->text()));
	rootNode.appendChild(assistantsNode);

	QDomElement cheerleadersNode = doc.createElement("cheerleaders");
	cheerleadersNode.appendChild(doc.createTextNode(cheerleaders->text()));
	rootNode.appendChild(cheerleadersNode);
	
	QDomElement apothecaryNode = doc.createElement("apothecary");
	apothecaryNode.appendChild(doc.createTextNode(apothecary->text()));
	rootNode.appendChild(apothecaryNode);

	QDomElement wizardNode = doc.createElement("wizard");
	wizardNode.appendChild(doc.createTextNode(wizard->text()));
	rootNode.appendChild(wizardNode);
	
/*
   <player id="1">
      <name>Gimli</name>
      <position>Longue Barbe</position>
      <ma>4</ma>
      <st>3</st>
      <ag>2</ag>
      <av>9</av>
      <skills>
         <skill id="102"/>
         <skill id="113"/>
         <skill id="603"/>
      </skills>
      <cost>70000</cost>
      <image></image>
   </player>
*/

	QDomElement playerNode;
	QDomElement playerNameNode;
	QDomElement positionNode;
	QDomElement maNode;
	QDomElement stNode;
	QDomElement agNode;
	QDomElement avNode;
	QDomElement skillsNode;
	QDomElement costNode;
	QDomElement imageNode;

	Joueur *j;
	MyQCombo *cellCombo;

	for(int i=0;i<16;i++)
	{
		if(teamTable->text(i,0).length()==0)
			continue;

		// on prend le joueur courant dans la liste
		j = theTeam->playerList.at(i);

		if(j == NULL)
			return 462;

		playerNode = doc.createElement("player");
		playerNode.setAttribute("id", QString().setNum(i+1));
		rootNode.appendChild(playerNode);

		playerNameNode = doc.createElement("name");
		playerNameNode.appendChild(doc.createTextNode(teamTable->text(i,0)));
		playerNode.appendChild(playerNameNode);

		positionNode = doc.createElement("position");
		cellCombo = (MyQCombo *)teamTable->cellWidget(i, 1);
		if(cellCombo!=NULL)
			positionNode.appendChild(doc.createTextNode(QString().setNum(cellCombo->currentItem())));
		else
			positionNode.appendChild(doc.createTextNode(""));
		
		playerNode.appendChild(positionNode);

		maNode = doc.createElement("ma");
		maNode.appendChild(doc.createTextNode(teamTable->text(i,2)));
		playerNode.appendChild(maNode);

		stNode = doc.createElement("st");
		stNode.appendChild(doc.createTextNode(teamTable->text(i,3)));
		playerNode.appendChild(stNode);

		agNode = doc.createElement("ag");
		agNode.appendChild(doc.createTextNode(teamTable->text(i,4)));
		playerNode.appendChild(agNode);

		avNode = doc.createElement("av");
		avNode.appendChild(doc.createTextNode(teamTable->text(i,5)));
		playerNode.appendChild(avNode);

		Skill *comp;
		skillsNode = doc.createElement("skills");

		for ( comp=j->playerSkills.first(); comp != 0; comp=j->playerSkills.next() )
		{
			QDomElement skillNode = doc.createElement("skill");
			skillNode.setAttribute("id", comp->getId());
			skillsNode.appendChild(skillNode);
		}
        playerNode.appendChild(skillsNode);

		costNode = doc.createElement("cost");
		costNode.appendChild(doc.createTextNode(teamTable->text(i,14)));
		playerNode.appendChild(costNode);

		imageNode = doc.createElement("image");
		imageNode.appendChild(doc.createTextNode(teamTable->text(i,15)));
		playerNode.appendChild(imageNode);

	}

	QString fileName = QFileInfo(currentFilePath).fileName();
	
	QFile f("teams/" + fileName);
	if(!f.open(IO_WriteOnly))
		return 1; // problème de création du fichier

	QString out = doc.toString();

    f.writeBlock( out, out.length() ); // write to file
    f.close();

	return 0;
}


//=============================================================================
// Fin du fichier TeamManagement.cpp
//=============================================================================