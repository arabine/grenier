/*=============================================================================
 * BaseList.cpp
 *=============================================================================
 * Affiche et gère la liste des auteurs présents dans la base
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 30/11/2002
 *=============================================================================
 */

#include "BaseList.h"

BaseList::BaseList(QWidget *parent, bool modal)
	: QDialog(parent, "", modal, 0)
{

	setFixedSize(335,250);
	setCaption("Liste des auteurs");

	ListBox1 = new QListBox(this, "",0);
	ListBox1->setGeometry(QRect(5, 5, 325, 195)); 

	ouvrir = new QPushButton( "&Ouvrir", this, "open" );
	ouvrir->move(5,210);
	connect(ouvrir, SIGNAL(clicked()) ,this , SLOT(openSelectedAuthor()));

	supprime = new QPushButton( "&Supprimer", this, "delete" );
	supprime->move(115,210);
	connect(supprime, SIGNAL(clicked()) ,this , SLOT(deleteSelectedAuthor()));

	connect(this, SIGNAL(signalDeleteAuthor(const char *)) ,parent, SLOT(deleteAuthor(const char *)));
	connect(this, SIGNAL(signalOpenAuthor(const char *)) ,parent, SLOT(openDataBase(const char *)));

	ferme = new QPushButton( "&Fermer", this, "close" );
	ferme->move(225,210);
	connect(ferme, SIGNAL(clicked()) ,this , SLOT(reject()));

}

void BaseList::setAuthorsNames(unsigned int n, char **elements)
{
	nb_auteurs = n;
	ListBox1->clear();
	for(unsigned int i=0;i<n;i++)
		ListBox1->insertItem(tr(elements[i]));

}

void BaseList::deleteSelectedAuthor()
{
	int ret;
	if(ret = ListBox1->currentItem()==-1)
	{
		QMessageBox::information( this, "Callisto","Sélectionnez un auteur.");
		return;
	}
	
	switch( QMessageBox::warning( this, "Callisto",
								"Êtes-vous sûr de vouloir supprimer l'auteur : " + ListBox1->currentText() + " ?",
						  "Oui", "Non", 0,
						  0, 1 ))
	{
		case 0:
			break;
		case 1:
			return;
			break;
	}

	emit signalDeleteAuthor(ListBox1->currentText().latin1());
	ListBox1->removeItem(ret);
}

void BaseList::openSelectedAuthor()
{
	int ret;
	if(ret = ListBox1->currentItem()==-1)
	{
		QMessageBox::information( this, "Callisto","Sélectionnez un auteur.");
		return;
	}

	emit signalOpenAuthor(ListBox1->currentText().latin1());
}

//=============================================================================
// End of BaseList.cpp
//=============================================================================