/*=============================================================================
 * Multivac 1.0 - main.cpp
 *=============================================================================
 * Point d'entrée dans le programme
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 9/01/2003 : première version
 *
 *=============================================================================
 */


#include <qapplication.h>
#include "GraphWindow.h"


int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	GraphWindow window;
	app.setMainWidget(&window);

	window.show();

	return app.exec();
}

//=============================================================================
// Fin du fichier main.cpp
//=============================================================================