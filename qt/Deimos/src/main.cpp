#include <QApplication>

#include "DeimosWindow.h"


int main( int argc, char** argv )
{
	QApplication app( argc, argv );
   Q_INIT_RESOURCE(deimos);

	DeimosWindow mainwindow;
	mainwindow.show();

	return app.exec();
}

// Fin fichier
