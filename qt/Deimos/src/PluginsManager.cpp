


#include "PluginsManager.h"
#include "DeimosEvent.h"
#include <QCoreApplication>

PluginsManager::PluginsManager()
{
	


}

void PluginsManager::setWidget( QWidget *widget )
{
	applicationWidget = widget;

}


// Scanne tous les plugins et agit selon les évènements détectés (erreurs etc.)
void PluginsManager::run()
{
	bool err, ret;

	// On lance le thread de comm avec UIR
	UIRDevice *uir = new UIRDevice( &waitForData );
   
   ret = uir->init();
   if( ret == false ) {
      DeimosMessageEvent *data_event = new DeimosMessageEvent();
		data_event->message = uir->getMessage();
		QCoreApplication::postEvent( (QObject*)applicationWidget, data_event );

      quit();
   }

	uir->start();
	Sleep(50);


   err = false;
	for(;;) {
		if( uir->isFinished() == true ) {
			err = true;
			break;
		}
		mutex.lock();
		waitForData.wait(&mutex);
		mutex.unlock();
		
		// we received data, read it and send it to the main application
		DeimosDataEvent *data_event = new DeimosDataEvent();
		data_event->keyCode = uir->getKeyCode();
		QCoreApplication::postEvent( (QObject*)applicationWidget, data_event );

		Sleep(50);
	}
	
	if( err == true ) {
		// On est sorti, il y a eu un problème, on envoie 
		// le message d'erreur à l'application
		DeimosMessageEvent *data_event = new DeimosMessageEvent();
		data_event->message = uir->getMessage();
		QCoreApplication::postEvent( (QObject*)applicationWidget, data_event );
	}
}




//=============================================================================
// Fin du fichier
//=============================================================================
