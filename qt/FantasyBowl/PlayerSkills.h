


// Librairies Qt
#include <qdialog.h>
#include <qlabel.h>
#include <qlist.h>
#include <qlistbox.h>
#include <qpushbutton.h>

// Classes internes
#include "Skill.h"

class PlayerSkills : public QDialog
{

private:

	QLabel *text,*playerName;
	QListBox *listOfSkills;
	QPushButton *ok, *cancel;

	QList<Skill> skillsList;
	QList<Skill> playerComp;

public:
	PlayerSkills(QWidget * parent, QString name, QList<Skill> skills, QList<Skill> skillsList);
	
	QList<Skill> getPlayerSkills();
};

