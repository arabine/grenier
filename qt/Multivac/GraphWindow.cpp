/*=============================================================================
 * Multivac 1.0 - GraphWindow.cpp
 *=============================================================================
 * Fen�tre principale avec les graphiques
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 9/01/2003 : premi�re version
 *
 *=============================================================================
 */

// Classes internes
#include "GraphWindow.h"

/*****************************************************************************/
GraphWindow::GraphWindow( QWidget* parent, const char* name, WFlags f )
	: QMainWindow( parent, name, f )
{

	setupMenuBar();
	setupCentralWidgets();
	initValues();

//	pixmap = new QPixmap(note);
//	setIcon(*pixmap);

	setCaption("Multivac");
	resize(500, 400);
}
/*****************************************************************************/
void GraphWindow::setupMenuBar()
{

	menu = new QMenuBar(this , "Menu");
	
	// File menu
	filemenu = new QPopupMenu(this);
	menu->insertItem( "&Fichier", filemenu );
	filemenu->insertItem( "&Ouvrir", this, SLOT( openSoundFile() ), CTRL + Key_O );
	filemenu->insertSeparator();
	filemenu->insertItem( "&Quitter", qApp, SLOT( quit() ), CTRL + Key_Q );

	// Analyse menu
	analysemenu = new QPopupMenu(this);
	menu->insertItem( "&Analyse", analysemenu );
	analysemenu->insertItem( "&Param�tres...", this, SLOT( setupAnalyse() ), CTRL + Key_N );
	analysemenu->insertItem( "&Lancer", this, SLOT( startFFT() ), CTRL + Key_L );
	analysemenu->insertItem( "&Test", this, SLOT( testFREQ() ), CTRL + Key_T );

	// Help menu
	helpmenu = new QPopupMenu(this);
	menu->insertItem( "&Aide", helpmenu );
    helpmenu->insertItem( "� propos...", this, SLOT( aboutBox() ), CTRL + Key_A );

}
/*****************************************************************************/
void GraphWindow::setupCentralWidgets()
{
	statusbar = new QStatusBar(this, "StatusBar");
	
	onglets = new QTabWidget(this, "onglets");
	onglets->setGeometry(5,25,490,350);


	firstpane = new Plot(this);
	secondpane = new Freq(this);
	thirdpane = new QWidget();

    onglets->addTab( firstpane, "&Temps" );
	onglets->addTab( secondpane, "F&r�quence" );
	onglets->addTab( thirdpane, "&Infos" );
 
	// Troisi�me onglet
    infos = new QLabel(thirdpane);
    infos->setFrameStyle( QFrame::Panel | QFrame::Sunken );
    infos->setAlignment( AlignTop | AlignLeft );
	infos->setGeometry(50,50,300,110);
	
	// Objets cach�s
	opendialog = new QFileDialog(this, 0, false );
}
/*****************************************************************************/
void GraphWindow::resizeEvent(QResizeEvent *)
{
	onglets->setGeometry(5,25,this->width()-10,this->height()-50);
}

/*****************************************************************************/
void GraphWindow::initValues()
{
	fileLoaded = false;
	paramSet = false;
	currentFilePath=QString::null;
	lastDirectory=QString::null;
	statusbar->message("Aucun fichier charg�.");
	infosString="Aucun fichier charg�.";
	infos->setText(infosString);
}
/*****************************************************************************/
void GraphWindow::setInfos()
{
	char chaine[500];

	sprintf(chaine,
			"Nom : %s\n"
			"Taille : %d octets\n"
			"Canaux : %d\n"
			"Fr�quence d'�chantillonnage : %d Hz\n"
			"Taux de transfert : %d octets/seconde\n"
			"Octets par �chantillon : %d octets\n"
			"Bits par �chantillon : %d bits\n"
			"Taille des donn�es : %ld octets\n",
			MyWaveFile.getFileName(),
			MyWaveFile.getFileSize(),
			MyWaveFile.getChannels(),
			MyWaveFile.getSamplesPerSec(),
			MyWaveFile.getAvgBytesPerSec(),
			MyWaveFile.getBlockAlign(),
			MyWaveFile.getBitsPerSample(),
			MyWaveFile.getDataSize() );
	
	infosString = chaine;
	infos->setText(infosString);
}
/*****************************************************************************/
void GraphWindow::setupAnalyse()
{
	if(fileLoaded==false)
	{
		noWaveLoadedBox();
		return;
	}

	unsigned long int valMax;
	valMax = MyWaveFile.getDataSize()/2;
	mypan = new ParamPanel(this, true, valMax);
	mypan->show();

}
/*****************************************************************************/
void GraphWindow::startFFT()
{
	if(fileLoaded==false)
	{
		noWaveLoadedBox();
		return;
	}
	
	if(paramSet == false)
	{
		noParamSet();
		return;
	}

	// on envoie l'adresse du d�but de l'intervalle (=adresse de base + offset)
	// 2*debut car on est en 16 bits
	if((MyWaveFile.getBlockAlign())==2)
		secondpane->setData(MyWaveFile.getData()+2*debut,taillefft);
	else
		secondpane->setData(MyWaveFile.getData()+debut,taillefft);

	onglets->setCurrentPage(1);
}
/*****************************************************************************/
void GraphWindow::openSoundFile()
{
	int ret;
	unsigned long int taille;

	currentFilePath = opendialog->getOpenFileName(lastDirectory, "WAVE file (*.wav)", this) ;
    if ( currentFilePath.isEmpty() )
        return;
	
	statusbar->message(currentFilePath);
	lastDirectory = QFileInfo(currentFilePath).dirPath();
	fileLoaded = true;
	MyWaveFile.setPath(currentFilePath);

	if((ret = MyWaveFile.loadWaveFile())!=0)
	{
		errorBox(ret);
		return;
	}
	setInfos();
	

	taille = MyWaveFile.getDataSize();
	firstpane->setData(taille,MyWaveFile.getData(), MyWaveFile.getBitsPerSample());

}
/*****************************************************************************/
void GraphWindow::testFREQ()
{
	secondpane->testFFT();
	onglets->setCurrentPage(1);
}
/*****************************************************************************/
void GraphWindow::recepIntervalle(unsigned long int min, unsigned long taille)
{
	debut = min;
	taillefft = taille;
	paramSet = true;
}
/*****************************************************************************/
void GraphWindow::setMessage(QString mess)
{
	statusbar->message(mess);
}
/*****************************************************************************/
/* Boites de dialogues														 */
/*****************************************************************************/
void GraphWindow::aboutBox()
{

QMessageBox::information( this, "� propos...",
                            "Anthony Rabine (c) 2003.\n"
                            "arabine@programmationworld.com." );

}
/*****************************************************************************/
void GraphWindow::errorBox(int code)
{

	QString number, mess;
	number = number.setNum(code);
	switch(code)
	{
		case WAV_CANT_OPEN:
			mess = "Impossible d'ouvrir le fichier";
			break;
		case WAV_CANT_READ_HDR:
			mess = "Probl�me lors de la lecture de l'ent�te";
			break;
		case WAV_CANT_READ_DATA:
			mess = "Probl�me lors de la lecture des donn�es";
			break;
		case WAV_NO_RIFF:
			mess = "Format de fichier inconnu : pas de type RIFF";
			break;
		case WAV_BAD_FILESIZE:
			mess = "En-t�te corrompu : mauvaise taille du fichier";
			break;
		case WAV_NO_WAVE:
			mess = "Format de fichier inconnu : pas de type WAVE";
			break;
		case WAV_NO_SUPPORT:
			mess = "Type de fichier WAVE inconnu ou non support�";
			break;
		case WAV_NO_COMPRESSION:
			mess = "Fichiers WAVE compress�s non support�s";
			break;
		case WAV_NO_STEREO:
			mess = "Fichiers WAVE st�r�os non support�s";
			break;
		case WAV_BAD_CHANNELS:
			mess = "En-t�te corrompu : mauvaise indication des cannaux";
			break;
		case WAV_NO_BLOCKALIGN:
			mess = "Mauvaise indication d'octets par �chantillons";
			break;
		case WAV_BAD_BITS:
			mess = "Mauvaise indication de bits par �chantillons";
			break;
		case WAV_NO_DATA:
			mess = "Format de fichier inconnu : impossible de trouver la zone de donn�es";
			break;
		case WAV_BAD_PARAMETERS:
			mess = "Erreur dans l'appel de la m�thode CWaveFile::mid()";
			break;
		default:
			mess = "Code d'erreur non rapport� : " + number;
	}

QMessageBox::critical( this, "Erreur",
                            "L'erreur suivante est survenue en ouvrant le fichier :\n" + mess);

}
/*****************************************************************************/
void GraphWindow::noWaveLoadedBox()
{

QMessageBox::warning( this, "Erreur",
                            "Op�ration impossible, aucun fichier charg�.");

}
/*****************************************************************************/
void GraphWindow::noParamSet()
{

QMessageBox::warning( this, "Erreur",
                            "Sp�cifiez un intervalle avant d'effectuer l'analyse.");

}

//=============================================================================
// Fin du fichier GraphWindow.h
//=============================================================================