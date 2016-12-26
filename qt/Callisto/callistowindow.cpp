/*=============================================================================
 * callistowindow.cpp
 *=============================================================================
 * Fenêtre & fonctionalités principales
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0 + QT 2.3
 * Build : 14/09/2002
 * Updates :
 *
 *
 *
 *
 *=============================================================================
 */

#include "callistowindow.h"


CallistoWindow::CallistoWindow( QWidget* parent, const char* name, WFlags f )
	: QMainWindow( parent, name, f )
{
	setupMenuBar();
	setupCentralWidgets();
	initValues();

	DataBaseCnx = new DataBaseManager();

	if(!DataBaseCnx->initDataBase())
	{
		errorDataBase();
	}
	
	pixmap = new QPixmap(book);
	setIcon(*pixmap);

	setName("MainForm");
	setCaption("Callisto");
    resize(840, 600); 

	// initialisation des variables dynamiques et des fenêtres cachées
	newauteur = new NewAuthorFrame(this, TRUE);
	listauteurs = new BaseList(this, TRUE);
}

void CallistoWindow::setupMenuBar()
{

	menu = new QMenuBar(this , "Menu");
	
	// New sub-menu
	newmenu = new QPopupMenu(this);
	newmenu->insertItem( "&Nouveau livre", this, SLOT(newBook()), CTRL+Key_N);
	newmenu->insertItem( "&Nouvel auteur", this, SLOT(newAuthor()), CTRL+Key_M);

	// File menu
	filemenu = new QPopupMenu(this);
	menu->insertItem( "&Fichier", filemenu );
	filemenu->insertItem("Nouveau...", newmenu );
	filemenu->insertItem( "&Ouvrir", this, SLOT( openDataBase() ), CTRL + Key_O );
	filemenu->insertSeparator();
	filemenu->insertItem( "&Quitter", qApp, SLOT( quit() ), CTRL + Key_Q );
	

	// Options menu
	optionsmenu =  new QPopupMenu(this);
	menu->insertItem( "&Options", optionsmenu );
	optionsmenu->insertItem("&Bases de données", this, SLOT( listDataBase() ), CTRL + Key_B );

	// Help menu
	helpmenu = new QPopupMenu(this);
	menu->insertItem( "&Aide", helpmenu );
    helpmenu->insertItem( "À propos...", this, SLOT( aboutBox() ), CTRL + Key_A );
	
	
}

void CallistoWindow::setupCentralWidgets()
{
	GroupBox4 = new QGroupBox( this, "GroupBox4" );
    GroupBox4->setGeometry( QRect( 10, 320, 511, 260 ) ); 
    GroupBox4->setTitle( tr( "Informations" ) );

    LineEdit1 = new QLineEdit( GroupBox4, "LineEdit1" );
    LineEdit1->setGeometry( QRect( 50, 20, 311, 22 ) ); 

    TextLabel1 = new QLabel( GroupBox4, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 10, 20, 40, 31 ) ); 
    TextLabel1->setText( tr( "Titre :" ) );

    TextLabel2 = new QLabel( GroupBox4, "TextLabel2" );
    TextLabel2->setGeometry( QRect( 10, 50, 70, 31 ) ); 
    TextLabel2->setText( tr( "Titre original : " ) );

    LineEdit2 = new QLineEdit( GroupBox4, "LineEdit2" );
    LineEdit2->setGeometry( QRect( 90, 50, 271, 22 ) ); 

    TextLabel3 = new QLabel( GroupBox4, "TextLabel3" );
    TextLabel3->setGeometry( QRect( 10, 110, 100, 21 ) ); 
    TextLabel3->setText( tr( "Date de publication :" ) );

    TextLabel4 = new QLabel( GroupBox4, "TextLabel4" );
    TextLabel4->setGeometry( QRect( 10, 80, 60, 21 ) ); 
    TextLabel4->setText( tr( "Auteur :" ) );

    LineEdit4 = new QLineEdit( GroupBox4, "LineEdit4" );
    LineEdit4->setGeometry( QRect( 60, 80, 300, 22 ) ); 

    TextLabel5 = new QLabel( GroupBox4, "TextLabel5" );
    TextLabel5->setGeometry( QRect( 10, 140, 70, 20 ) ); 
    TextLabel5->setText( tr( "Commentaire :" ) );

    MultiLineEdit1 = new QMultiLineEdit( GroupBox4, "MultiLineEdit1" );
    MultiLineEdit1->setGeometry( QRect( 81, 140, 420, 111 ) ); 

    LineEdit3 = new QLineEdit( GroupBox4, "LineEdit3" );
    LineEdit3->setGeometry( QRect( 120, 110, 100, 22 ) ); 

    ListBox2 = new QListBox( this, "ListBox2" );
    ListBox2->setGeometry( QRect( 530, 30, 300, 550 ) ); 
	
	statusbar = new QStatusBar(this, "StatusBar");

    booklist = new QTable( 0, 4, this, "booklist" );
    booklist->setGeometry( QRect( 10, 30, 510, 280 ) ); 
	QHeader *th = booklist->horizontalHeader();
    th->setLabel(0, "Titre");
    th->setLabel(1, "Titre original");
	th->setLabel(2, "Date de parution");
	th->setLabel(3, "Commentaire");

}

void CallistoWindow::initValues()
{
	bookLoaded = FALSE;
	modified = FALSE;
	statusbar->message("Aucun fichier chargé.");
}

void CallistoWindow::newBook()
{
	if(bookLoaded==FALSE)
	{
		switch( QMessageBox::information( this, "Callisto",
                                      "Aucun auteur chargé.\n"
                                      "Que voulez vous faire ?",
                                      "&Créer un nouvel auteur" , "&Ouvrir une base existante" , "&Annuler",
                                      1,
									  2 ))
		{
			case 0:
				newAuthor();
				break;
			case 1:
				listDataBase();
				break;
			case 2:
				return;
				break;
			default:
				break;
		}
	}
}


/**
 * Ouvre une base de données
 */
void CallistoWindow::openDataBase(const char *auteur)
{
	char **elements;
	elements = new char*[255]; // 255 livres maximum par auteur... (suffisant ?)
/*	for(unsigned int i=0;i<n;i++)
		elements[i] = new char[255];

	if(DataBaseCnx->getInfos("livres","titre", elements, auteur)==false)
	{
		errorQuery();
		return;
	}
	*/
	listauteurs->hide();
	
	booklist->setNumRows(10);
	booklist->setText(0,1,"coucou");

}

/**
 * Liste les bases de données
 */
void CallistoWindow::listDataBase()
{
	unsigned int n;
	char **elements;
	
	if(DataBaseCnx->numberOfElements("auteurs", &n)==false)
	{
		errorQuery();
		return;
	}
	
	elements = new char*[n];
	for(unsigned int i=0;i<n;i++)
		elements[i] = new char[255];

	if(DataBaseCnx->getElements("auteurs", "nom", elements, n)==false)
	{
		errorQuery();
		return;
	}
	
	listauteurs->setAuthorsNames(n, elements);

	listauteurs->show();
}

/**
 * Ajoute un nouvel auteur à la base de données
 */
void CallistoWindow::newAuthor()
{
	QString nom, description;
	
	newauteur->show();

	// bouton annuler
	if(newauteur->result()==QDialog::Rejected)
		return;

	nom = newauteur->getNom();
	description = newauteur->getDescription();
	
	if(DataBaseCnx->setNewAuthor(nom, description)==false)
		errorQuery();

}

/**
 * Efface un auteur de la base de données
 */
void CallistoWindow::deleteAuthor(const char *text)
{
	if(DataBaseCnx->deleteEntry("auteurs", "nom", text)==false)
		errorQuery();
}


//=============================================================================
// Boîtes de dialogue
//=============================================================================

void CallistoWindow::errorQuery()
{
QMessageBox::critical ( this, "Erreur",
                            "Erreur de communication avec la base MySQL." );


}

void CallistoWindow::errorDataBase()
{
QMessageBox::critical ( this, "Erreur",
                            "Erreur de connexion au serveur MySQL." );


}

void CallistoWindow::aboutBox()
{

QMessageBox::information( this, "À propos...",
                            "Anthony Rabine (c) 2002.\n"
                            "arabine@programmationworld.com." );

}

//=============================================================================
// End of callistowindow.cpp
//=============================================================================