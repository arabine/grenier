/*=============================================================================
 * FantasyBowl 1.0 - MyFileDialog.h
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

#include <qfiledialog.h>
#include <qframe.h>

/*****************************************************************************/

class MyFileDialog : public QFileDialog
{

	Q_OBJECT

private:
	QFrame *preview;

public:

	MyFileDialog(const QString & dirName, QWidget * parent);

public slots:
	void showImage(const QString &);

};


//=============================================================================
// Fin du fichier MyFileDialog.h
//=============================================================================