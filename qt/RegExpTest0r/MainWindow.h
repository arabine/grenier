

#include <qregexp.h>
#include <qstringlist.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlineedit.h>

#include "MainUI.h"


class MainWindow : public MainUI
{
	Q_OBJECT

private:


public:
	MainWindow( QWidget * parent=0, const char * name=0, bool modal=FALSE, WFlags f=0 );

public slots:
	
	void	slotBtnTest();

};

