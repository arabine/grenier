
#ifndef _CLASSES_H
#define _CLASSES_H

typedef struct { unsigned short a,b,c;} KEY_TYPE;

class Application
{
private:

public:
	Application(){}
	
	int id;
	QString softName;
	QString className;
};



class Action
{

private:
	

public:
	Action(){}

	QString button;
	KEY_TYPE keycode;
	int key;	// touche clavier appuyée
   int applicationId;
};


#endif // _CLASSES_H

//=============================================================================
// Fin du fichier
//=============================================================================
