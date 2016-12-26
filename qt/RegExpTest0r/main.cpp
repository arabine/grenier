#include <qapplication.h>
#include "MainWindow.h"


int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	MainWindow dialog( 0, 0, TRUE );
	app.setMainWidget(&dialog);

	dialog.exec();

	return 0;
}

