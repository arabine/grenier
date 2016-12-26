/*=============================================================================
 * Phobos 1.0 - main.cpp
 *=============================================================================
 * Entrée du programme
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0 - Windows seulement
 * 
 *=============================================================================
 */

// Librairies Qt
#include <qapplication.h>
#include <qmainwindow.h>

// Classes internes
#include "PhobosPopup.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );

	PhobosPopup gestNote;
    TrayIcon tray( QPixmap( (const char**)phobos_icon ), "Menu", &gestNote );
 
//  si on clique-gauche sur l'icone
//	QObject::connect(&tray,SIGNAL(clicked(const QPoint&)),&gestNote,SLOT(addNote()));

	tray.show();
    return app.exec();
	return 0;
}

//=============================================================================
// Fin du fichier main.cpp
//=============================================================================
