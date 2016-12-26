/*=============================================================================
 * OggEditor - main.cpp
 *=============================================================================
 * Point d'entrée
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environnement : VC++ 6.0 sous Windows, g++ sous Linux
 *  
 *
 *
 * Historique :
 * 
 * 10/2003 : première version
 *
 *=============================================================================
 */


#include <qapplication.h>
#include "oggeditordialog.h"

int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	OggEditorDialog dialog( 0, 0, TRUE );
	app.setMainWidget(&dialog);

	dialog.exec();

	return 0;

}

//=============================================================================
// Fin du fichier main.cpp
//=============================================================================
