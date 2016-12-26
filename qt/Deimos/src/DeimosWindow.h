
#ifndef _DEIMOSWINDOW_H_
#define _DEIMOSWINDOW_H_

#include <QMainWindow>
#include <QWidget>
#include <QEvent>
#include <QMenu>
#include <QAction>
#include <QList>
#include "PluginsManager.h"
#include "ui/ui_Deimos.h"
#include "ui/ui_TestDevice.h"
#include "trayicon/trayicon.h"
#include "Classes.h"

typedef enum {
   SLEEP,
	REMOTE_TEST,
	RUNNING
} DEIMOS_STATE;


class DeimosWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::Deimos ui;
   Ui::TestDevice test_ui;
	PluginsManager *plugins;
	DEIMOS_STATE state;
	TrayIcon *tray;
   QDialog  *test;
   QMenu    *trayMenu;
   QAction  *exitDeimos;
   QAction  *aboutDeimos;
   QAction  *testDeimos;
   QList<Application>   appliList;
   QList<Action>        actionList;

public:
	DeimosWindow( QWidget* parent = 0, Qt::WFlags f = 0 );

protected:
	void customEvent( QEvent *the_event );

public slots:
	void slotMenuNewConfig();
   void slotExitDeimos();
   void slotAboutDeimos();
   void slotTestDeimos();

};

#endif // _DEIMOSWINDOW_H_

//=============================================================================
// Fin du fichier
//=============================================================================
