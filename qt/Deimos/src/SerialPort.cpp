


#include "SerialPort.h"
#include <string>
#include <sstream>

using namespace std;

SerialPort::SerialPort()
{
	comPort = INVALID_HANDLE_VALUE;
	errMsg = "Unknown error.";
}


void SerialPort::purge()
{
	PurgeComm(comPort,PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);

}


bool SerialPort::open( int com_port, string params )
{
	DCB newComState;
	bool ret = true;
	stringstream port_string;

	port_string << "COM" << com_port << '\0';
	
   // Conversion en UNICODE
   wchar_t *lp_comport = new wchar_t(port_string.str().size());
   mbstowcs(lp_comport,port_string.str().c_str(),port_string.str().size());

	Rov.Internal=Rov.InternalHigh=Rov.Offset=Rov.OffsetHigh=0;
	Rov.hEvent=INVALID_HANDLE_VALUE;
	// create event for overlapped I/O
	Rov.hEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
	if(Rov.hEvent == INVALID_HANDLE_VALUE) {
		return (false);
	}

	Wov.Internal=Wov.InternalHigh=Wov.Offset=Wov.OffsetHigh=0;
	Wov.hEvent=INVALID_HANDLE_VALUE;
	// create event for overlapped I/O
	Wov.hEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
	if(Wov.hEvent == INVALID_HANDLE_VALUE) {
		return (false);
	}

	comPort = CreateFile( lp_comport, GENERIC_WRITE | GENERIC_READ, 
		0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED,NULL);
	if( comPort == INVALID_HANDLE_VALUE ) {
		errMsg = "Can't open " + port_string.str() + " port.";
		return (false);
	}
	
	if (GetCommState(comPort,&oldComState))
	{
		newComState=oldComState;
		BuildCommDCB( (LPCWSTR)params.c_str(), &newComState );
		newComState.fDtrControl = DTR_CONTROL_DISABLE;
		newComState.fRtsControl = RTS_CONTROL_DISABLE;

		if (!SetCommState(comPort,&newComState))
		{
			errMsg = "Could not open comport: SetCommState returned an Error";
			CloseHandle(comPort);
			comPort = INVALID_HANDLE_VALUE;
			ret = false;
		}
	}
	else
	{
		errMsg = "Could not open comport: GetCommState returned an Error";
		CloseHandle(comPort);
		comPort = INVALID_HANDLE_VALUE;
		ret = false;
	}

	return (ret);
}


void SerialPort::close()
{
	if (comPort!=INVALID_HANDLE_VALUE)
	{
		CloseHandle(comPort);
		SetCommState(comPort,&oldComState);
		comPort = INVALID_HANDLE_VALUE;
	}
}


void SerialPort::setDTR()
{
	EscapeCommFunction(comPort, SETDTR);
}

void SerialPort::clrDTR()
{
	EscapeCommFunction(comPort, CLRDTR);
}


void SerialPort::setRTS()
{
	EscapeCommFunction(comPort, SETRTS);
}

void SerialPort::clrRTS()
{
	EscapeCommFunction(comPort, CLRRTS);
}



bool SerialPort::writeData(BYTE data)
{
	DWORD write;
	int x;
	bool ret = true;
    

	if (!WriteFile(comPort,&data,1,&write,&Wov)) {
		x=GetLastError();
		if (x==ERROR_IO_PENDING) {
			while (!GetOverlappedResult(comPort,&Wov,&write,TRUE)) // wait until write completes!
			{
               if(GetLastError() != ERROR_IO_INCOMPLETE) // "incomplete" is normal result if not finished
               {	// an error occurred, try to recover
		   		   errMsg = "Something went wrong when calling Windows to write to comport.";
				   ret = false;
				   break;
               }
			}
		}
		else {
			errMsg = "Something went wrong when calling Windows to write to comport.";
			ret = false;
		}
	}

	return (ret);
}

bool SerialPort::readData(LPBYTE buffer,DWORD size,BOOL blocking)
{
	DWORD read = 0;
	int x;
	bool ret = true;

	if (ReadFile(comPort,buffer,size,&read,&Rov)) {
		if (read!=size) {
			errMsg = "Error during read from com port : buffers size mismatch";
			ret = false;
		}
	} else {
		switch (x=GetLastError())
		{
		case ERROR_IO_PENDING:
			if (blocking) {
				while (!GetOverlappedResult(comPort,&Rov,&read,TRUE)) // wait until read completes!
				{
					if(GetLastError() != ERROR_IO_INCOMPLETE)	// "incomplete" is normal result if not finished
					{
						errMsg = "Something went wrong when calling Windows to read from comport.";
						ret = false;
						break;	// an error occurred, try to recover
					}
				}

				if( read != size ) {
					ret = false;
				}
				
			} else {
				ret = false;
			}
			break;

		default:
			ret = false;
		}
	}

	return (ret);
}

//=============================================================================
// Fin du fichier
//=============================================================================
