/*=============================================================================
 * FantasyBowl 1.0 - GameWizard.h
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

#ifndef GAMEWIZARD_H
#define GAMEWIZARD_H

// Librairies Qt
#include <qwizard.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlistbox.h>
#include <qstringlist.h>
#include <qdir.h>
#include <qiconset.h>

class GameWizard : public QWizard
{
    Q_OBJECT

private:

    QFrame *page1,*page2;

	QComboBox *gameChoice;
	QListBox *teamsList;
	QPushButton *bt1,*bt2; // page 2
	QLabel *lbl1,*lbl2,*lbl3,*lbl4; // page 2

	int cptTeams;

protected:
    void setupPage1();
	void setupPage2();

public:
    GameWizard( QWidget *parent = 0, const char *name = 0 );

    void showPage(QWidget* page);

public slots:
	void clickTeam1();
	void clickTeam2();
	QString getTeam1();
	QString getTeam2();


};

#endif // GAMEWIZARD_H

//=============================================================================
// Fin du fichier GameWizard.h
//=============================================================================