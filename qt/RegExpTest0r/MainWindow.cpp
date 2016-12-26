
#include "MainWindow.h"

MainWindow::MainWindow( QWidget *parent, const char *name, bool modal, WFlags f )
	: MainUI( parent, name, modal, f )
{

	connect( btnTest, SIGNAL(clicked()), this, SLOT(slotBtnTest()) );

}

void MainWindow::slotBtnTest()
{
	resultText->clear();

	QRegExp qre;
	qre.setPattern( patternText->text() );

	QStringList res = QStringList::split( qre, searchText->text() );

	QStringList::Iterator it;
	for( it = res.begin(); it != res.end(); ++it )
	{
		resultText->append( (*it) );
	}

}

