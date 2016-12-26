

#include "DeimosWindow.h"
#include "DeimosEvent.h"
#include "NewSoft.h"


#include <QMessageBox>
#include <QInputDialog>
#include <QAction>
#include <QStringList>
#include <QDialog>
#include <QPixmap>
#include <QTreeWidget>
#include <QStringList>

DeimosWindow::DeimosWindow( QWidget* parent, Qt::WFlags f )
	: QMainWindow( parent, f )
{
	ui.setupUi(this);
   test = new QDialog(this);
   test_ui.setupUi(test);

   exitDeimos = new QAction(tr("Exit"),this);
   aboutDeimos = new QAction(tr("About..."),this);
   testDeimos = new QAction(tr("Test remote"),this);

   trayMenu = new QMenu(this);
   trayMenu->addAction(testDeimos);
   trayMenu->addAction(aboutDeimos);
	trayMenu->addSeparator();
   trayMenu->addAction(exitDeimos);
   
	tray = new TrayIcon(this);
	tray->setWMDock(false);
	tray->setPopup(trayMenu);
   tray->setIcon(QPixmap(":/deimos.png"));
	tray->show();
   
	state = SLEEP;

	plugins = new PluginsManager();
	plugins->setWidget( this );
	plugins->start();

   connect( ui.newConfig, SIGNAL(activated()), this, SLOT(slotMenuNewConfig()) );

   connect(exitDeimos, SIGNAL(triggered()), this, SLOT(slotExitDeimos()));
   connect(aboutDeimos, SIGNAL(triggered()), this, SLOT(slotAboutDeimos()));
   connect(testDeimos, SIGNAL(triggered()), this, SLOT(slotTestDeimos()));

   QStringList head;
   head.append(tr("Logiciel"));
   ui.softList->setHeaderLabels(head);

   head.clear();
   head.append(tr("Touche"));
   head.append(tr("Raccourcis clavier"));
   ui.keyList->setHeaderLabels(head);

   state = RUNNING;
}


void DeimosWindow::slotExitDeimos()
{

}

void DeimosWindow::slotAboutDeimos()
{

}

void DeimosWindow::slotTestDeimos()
{
   state = REMOTE_TEST;
   test->exec();
   state = RUNNING;
}


void DeimosWindow::slotMenuNewConfig()
{
   NewSoft ns;
	QString softName, className;
   if( ns.exec() == QDialog::Accepted ) {
      

	}
}



// reçoit les événements des récepteurs
void DeimosWindow::customEvent( QEvent *the_event )
{
	if( (int)the_event->type() == DeimosMessage ) {
		DeimosMessageEvent *msgEvt = (DeimosMessageEvent*)the_event;
		QMessageBox::critical( this, "Deimos error", msgEvt->message );
	
	} else if( (int)the_event->type() == DeimosData ) {
      DeimosDataEvent *dataEvt = (DeimosDataEvent*)the_event;
      wchar_t *class_name = new wchar_t(256);
      HWND hKTV;

		switch( state ) {
			
			case REMOTE_TEST:
            test_ui.keyCodeA->setText(QString().setNum(dataEvt->keyCode.a));
            test_ui.keyCodeB->setText(QString().setNum(dataEvt->keyCode.b));
            test_ui.keyCodeC->setText(QString().setNum(dataEvt->keyCode.c));

			/*	
				HWND hMediaplayer = FindWindow("Winamp v1.x",NULL);

				SetForegroundWindow(hMediaplayer);
				PostMessage(hMediaplayer,WM_KEYDOWN,'X',0);
*/
				break;
		
			case SLEEP:
            break;

         case RUNNING:
            {


            mbstowcs(class_name,"BaseWindow_RootWnd",sizeof("BaseWindow_RootWnd"));
            HWND hMediaplayer = FindWindow(class_name,NULL);

				SetForegroundWindow(hMediaplayer);
				PostMessage(hMediaplayer,WM_KEYDOWN,'X',0);
            }
/*            
            mbstowcs(class_name,"K!TV",sizeof("K!TV"));
            hKTV = FindWindow(class_name,NULL);
            PostMessage(hKTV,WM_KEYDOWN,'M',0);
*/
            break;

			default:
				break;
		}
	}
}



//=============================================================================
// Fin du fichier
//=============================================================================
