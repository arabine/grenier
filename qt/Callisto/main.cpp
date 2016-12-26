#include <qapplication.h>
#include "callistowindow.h"




int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	CallistoWindow window;
	app.setMainWidget(&window);

	window.show();

	return app.exec();
}

