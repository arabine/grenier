#ifndef _PLUGINSMANAGER_H_
#define _PLUGINSMANAGER_H_

#include "UIRDevice.h"

#include <QThread>
#include <QWaitCondition>
#include <QMutex>

// Gère les plugsins chargés en mémoire
class PluginsManager : public QThread
{

private:
	QWidget *applicationWidget;
	QWaitCondition waitForData;
	QMutex mutex;

public:

	PluginsManager();

	void run();
	void setWidget( QWidget *widget );

};

#endif // _PLUGINSMANAGER_H_

//=============================================================================
// Fin du fichier
//=============================================================================
