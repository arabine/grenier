
#ifndef _SERIALPORT_H
#define _SERIALPORT_H

#include <windows.h>
#include <string>

using namespace std;

class SerialPort
{

private:
	HANDLE	comPort;
	DCB oldComState;
	string	errMsg;
	OVERLAPPED Rov,Wov;

public:
	SerialPort();


	bool open( int com_port, string params );
	void close();
	bool readData(LPBYTE buffer,DWORD size,BOOL blocking);
	bool writeData(BYTE data);

	void purge();

	
	void setDTR();
	void clrDTR();
	void setRTS();
	void clrRTS();
	

	string getErrMsg() { return errMsg; }
};

#endif // _SERIALPORT_H

//=============================================================================
// Fin du fichier
//=============================================================================
