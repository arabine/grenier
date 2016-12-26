/*=============================================================================
 * FantasyBowl 1.0 - TeamManagement.h
 *=============================================================================
 * Fenêtre de gestion des équipes, édition + sauvegarde
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 24-Jul-2003 : changed all readXMLFile() function to use Equipe class
 * 02-Mar-2003 : première version
 *
 *=============================================================================
 */

#ifndef TEAMMANAGEMENT_H
#define TEAMMANAGEMENT_H

#include <stdlib.h>

// Librairies Qt
#include <qmainwindow.h>
#include <qtable.h>
#include <qlabel.h>
#include <qfiledialog.h>
#include <qfile.h>
#include <qdom.h>
#include <qmessagebox.h>
#include <qgroupbox.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qlist.h>
#include <qmap.h>
#include <qdatetime.h>
#include <qlineedit.h>
#include <qvalidator.h>
#include <qspinbox.h>
#include <qinputdialog.h>
#include <qstringlist.h>

// Classes internes
#include "Equipe.h"
#include "Skill.h"
#include "MyQTable.h"
#include "MyQLineEdit.h"
#include "PlayerSkills.h"
#include "MyFileDialog.h"
#include "MyQCombo.h"
#include "Title.h"

#define DEF_TITLE "Qt - Fantasy Bowl TeamEditor" // titre par défaut

/*****************************************************************************/
class MyLogo : public QFrame
{
	Q_OBJECT

public:
	MyLogo(QWidget *parent) : QFrame(parent)
	{
		connect(this,SIGNAL(sigDblClick()),parent,SLOT(loadLogo()));
	
	}

protected:
	void mouseDoubleClickEvent(QMouseEvent *)
	{
		emit sigDblClick();
	}
signals:
	void sigDblClick();
};
/*****************************************************************************/
class TeamManagement : public QMainWindow
{

	Q_OBJECT

private:
	MyQTable	*teamTable;
	
	QMenuBar	*menu;
	QPopupMenu	*file;
	QGroupBox	*infos;

	QLabel *name_text, *race_text, *rating_text, *rating, *treasury_text, *treasury, *coach_text, *rerollcost_text;
	QLabel *rerollnumber_text, *fanfactor_text;
	QLabel *assistants_text, *cheerleaders_text;
	QLabel *apothecary_text, *wizard_text, *totalCost_text, *totalCost;

	MyQLineEdit *team_name, *race, *coach;

	QSpinBox *assistants, *fanfactor, *cheerleaders, *apothecary, *wizard, *rerollnumber, *rerollcost;

	MyLogo *logo;


	QString lastDirectory;
	QString currentFilePath;	// file path + file name !
	bool	rosterModified;		// true if modifications made somewhere
	bool	goCalc;				// true to enable calcul of total cost & treasury
	QString logoPath;
	Equipe	*theTeam;

	QList<Skill> theSkillList;	// List of all game skills in memory
	QMap<int, Title> theTitleList; // List of all players titles
	
	// File menu Identificators
	int saveId;
	int saveAsId;
	int closeId;

	int		initValues();
	int		readXMLFile();
	int		saveXMLFile();

protected:
	void resizeEvent(QResizeEvent *);
	void closeEvent(QCloseEvent *); 

public:
	TeamManagement(QWidget* parent = 0, const char* name = 0, WFlags f = WType_TopLevel);

public slots:
	void	newRoster();
	void	openRoster();
	void	saveRoster();
	void	saveRosterAs();
	int		closeRoster();
	void	calculTotal();
	void	showPlayerSkills(int row, int col);
	void	loadLogo();
};

#endif // TEAMMANAGEMENT_H

//=============================================================================
// Fin du fichier TeamManagement.h
//=============================================================================