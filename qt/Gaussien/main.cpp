/*=============================================================================
 * main.cpp
 *=============================================================================
 * Fichier principal
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0 + QT 2.3
 * Build : 14/09/2002
 * Updates :
 *
 *
 *
 *
 *=============================================================================
 */

#include <qapplication.h>

#include "mainwindow.h"

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
	

	FrmMain window;
	window.setGeometry( 500, 300, 400, 400 );
	
	window.setCaption( "Bruit Gaussien - Qt 2.3 - (c) Anthony Rabine" );

    a.setMainWidget( &window );
    window.show();
    return a.exec();
}
//=============================================================================
// End of main.cpp
//=============================================================================