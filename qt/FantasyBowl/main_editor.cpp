/*=============================================================================
 * TeamEditor 1.0 - main_editor.cpp
 *=============================================================================
 * Point d'entrée du programme
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 01/08/2003 : première version
 *
 *=============================================================================
 */

#include <qapplication.h>
#include "TeamManagement.h"

int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	TeamManagement window;
	app.setMainWidget(&window);

	window.show();

	return app.exec();
}
//=============================================================================
// Fin du fichier main.cpp
//=============================================================================
