


#include "UIRDevice.h"

UIRDevice::UIRDevice( QWaitCondition *waitCondition )
{
	managerThread = waitCondition;
	keyCode.a = 0;
	keyCode.b = 0;
}


// Entrée du thread
void UIRDevice::run()
{
   unsigned char buffer[6];

	for(;;)	{
		if( port.readData( buffer, 6, TRUE ) == true ) {
			keyCode.a = buffer[0]<<8 | buffer[1];
			keyCode.b = buffer[2]<<8 | buffer[3];
         keyCode.c = buffer[4]<<8 | buffer[5];
			// Data ready, send it to the main application
			managerThread->wakeAll();
		}
		
		Sleep(50);
	}
}



bool UIRDevice::init()
{
	bool ret = true;
	BYTE data[2];
	
	// Try to open the COM port
	if( port.open( 1, "9600,N,8,1") == true ) {
		powerOff();
		Sleep(250);
		powerOn();
		Sleep(250);
		port.purge();

		Sleep(2);
		port.writeData('I');
		Sleep(2);
		port.writeData('R');

		Sleep(100); // let's wait for the microcontrol's response

		if(port.readData(data,2,FALSE) == true) {
			if ((data[0] != 'O') || (data[1] != 'K')) {
				errMsg = "Could not initialize IR-device.\nMake sure you set the COM-port correct.\n"
					"After that, retry an initialization again.\n\nOnce initialized correctly you can setup your keys.";
				powerOff();
				port.close();
				ret = false;
			}
		} else {
			errMsg = "Could not initialize IR-device.\nMake sure you set the COM-port correct.\n"
				"After that, retry an initialization again.\n\nOnce initialized correctly you can setup your keys.";
			powerOff();
			port.close();
			ret = false;
		}
	} else {
		errMsg = QString(port.getErrMsg().c_str());
		powerOff();
		ret = false;
	}

	return (ret);
}



void UIRDevice::powerOff()
{
	port.clrDTR();
	port.clrRTS();
}


void UIRDevice::powerOn()
{
	port.setDTR();
	port.setRTS();

}


//=============================================================================
// Fin du fichier
//=============================================================================
