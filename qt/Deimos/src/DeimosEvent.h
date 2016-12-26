

#include <QEvent>
#include "UIRDevice.h"

enum { DeimosMessage = 1001 , DeimosData = 1002 };


class DeimosMessageEvent : public QEvent
{

public:
	DeimosMessageEvent();

	QString message;

};


class DeimosDataEvent : public QEvent
{

public:
	DeimosDataEvent();

	KEY_TYPE keyCode;

};


//=============================================================================
// Fin du fichier
//=============================================================================
