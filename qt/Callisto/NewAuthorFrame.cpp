/*=============================================================================
 * NewAuthorFrame.cpp
 *=============================================================================
 * Classe de gestion des préférences utilisateur (lecture de pref.xml)
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 27/10/2002
 *=============================================================================
 */

#include "NewAuthorFrame.h"

NewAuthorFrame::NewAuthorFrame(QWidget *parent, bool modal)
	: QDialog(parent, "", modal, 0)
{
	setFixedSize(310,250);
	setCaption("Nouvel auteur");

	TextLabel1 =  new QLabel( this, "TextLabel2" );
    TextLabel1->setGeometry( QRect( 5, 5, 80, 31 ) ); // int x, int y, int w, int h
    TextLabel1->setText( tr( "Nom de l'auteur : " ) );

	LineEdit1 = new QLineEdit( this, "LineEdit3" );
    LineEdit1->setGeometry( QRect( 5, 30, 300, 22 ) ); 
	
	TextLabel2 = new QLabel( this, "TextLabel2" );
    TextLabel2->setGeometry( QRect( 5, 55, 130, 31 ) ); 
    TextLabel2->setText( tr( "Informations sur l'auteur : " ) );
    
	MultiLineEdit1 = new QMultiLineEdit( this, "MultiLineEdit1" );
    MultiLineEdit1->setGeometry( QRect( 5, 80, 300, 120 ) ); 

	valide = new QPushButton( "&Ok", this, "ok" );
	valide->move(5,210);
	connect(valide, SIGNAL(clicked()) ,this , SLOT(save_entry ()));

	annule = new QPushButton( "&Annuler", this, "cancel" );
	annule->move(115,210);
	connect(annule, SIGNAL(clicked()) ,this , SLOT(reject ()));
}

void NewAuthorFrame::save_entry()
{
	nom = LineEdit1->text();
	if(nom=="")
	{
		QMessageBox::information( this, "Callisto","Entrez un nom.");
		return;
	}

	description = "";
	for(int i=0;i<MultiLineEdit1->numLines();i++)
		description = description + MultiLineEdit1->textLine(i) + "\n\r";

	this->hide();
	this->setResult(QDialog::Accepted);
}

void NewAuthorFrame::showEvent(QShowEvent *ev)
{
	MultiLineEdit1->clear();
	LineEdit1->clear();
}

//=============================================================================
// End of NewAuthorFrame.cpp
//=============================================================================