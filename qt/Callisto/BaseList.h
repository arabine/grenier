/*=============================================================================
 * BaseList.h
 *=============================================================================
 * Affiche et gère la liste des auteurs présents dans la base
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 30/11/2002
 *=============================================================================
 */

#ifndef BASELIST_H
#define BASELIST_H

// Librairies QT
#include <qdialog.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qlistbox.h> 

class BaseList : public QDialog
{

	Q_OBJECT

private:
	QListBox *ListBox1;
	QPushButton *ouvrir;
	QPushButton *supprime;
	QPushButton *ferme;

	unsigned int nb_auteurs;
	
public:
	BaseList(QWidget *parent, bool modal);
	~BaseList(){}
	
	// Mutateurs
	void setAuthorsNames(unsigned int n, char **elements);

public slots:
	void deleteSelectedAuthor();
	void openSelectedAuthor();

signals:
	void signalDeleteAuthor(const char *);
	void signalOpenAuthor(const char *);
};


#endif

//=============================================================================
// End of BaseList.h
//=============================================================================