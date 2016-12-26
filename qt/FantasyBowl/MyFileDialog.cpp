/*=============================================================================
 * FantasyBowl 1.0 - MyFileDialog.cpp
 *=============================================================================
 * Image file fialog with a preview widget
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 24/04/2003 : première version
 *
 *=============================================================================
 */

#include "MyFileDialog.h"


/*****************************************************************************/
MyFileDialog::MyFileDialog(const QString & dirName, QWidget * parent ) : 
	QFileDialog(dirName, "", parent, 0, true) 
{
	preview = new QFrame(this);
	preview->setFixedSize(150,150);
	preview->setFrameStyle(QFrame::Box | QFrame::Plain);
	preview->setPalette( QPalette( QColor(255, 255, 255))); // fond en blanc

	addRightWidget(preview);
	setFilter( "Image file (*.png)" );
	setMode(QFileDialog::ExistingFile);

	setWFlags(WStyle_Dialog | WType_Modal);

	connect(this, SIGNAL(fileHighlighted(const QString &)), this, SLOT(showImage(const QString &)));

}
/*****************************************************************************/
void MyFileDialog::showImage(const QString &img)
{

	QPixmap plm;
	if(plm.load(img))
		preview->setBackgroundPixmap( plm );

}

//=============================================================================
// Fin du fichier MyFileDialog.cpp
//=============================================================================