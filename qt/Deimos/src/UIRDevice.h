
#ifndef _UIRDEVICE_H
#define _UIRDEVICE_H

#include <QThread>
#include <QString>
#include <QWaitCondition>
#include "SerialPort.h"
#include "Classes.h"

class UIRDevice : public QThread
{

private:

	SerialPort	port;
	QString errMsg;
	KEY_TYPE keyCode;
	QWaitCondition *managerThread;

public:
	UIRDevice( QWaitCondition *waitCondition );
	
	void run();

	bool init();
	void powerOff();
	void powerOn();

	QString getMessage() { return errMsg; }
	KEY_TYPE getKeyCode() { return keyCode; }

};

#endif // _UIRDEVICE_H

//=============================================================================
// Fin du fichier
//=============================================================================
