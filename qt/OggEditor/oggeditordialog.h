/*=============================================================================
 * OggEditor - oggeditordialog.h
 *=============================================================================
 * Interface du logiciel
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


// Includes Qt
#include <qfiledialog.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qmultilineedit.h>
#include <qcombobox.h>
#include <qlistbox.h>

// Includes locales
#include "MainForm.h"
#include "OggLib/OggFile.h"

/*****************************************************************************/
class OggEditorDialog : public MainForm
{
	Q_OBJECT

private:
	QString oggFilePath;	// Chemin vers le fichier Ogg à décoder
	OggFile myFile;			// Fichier Ogg en mémoire

	void clearFields();		// vide les éléments de texte

public:
	OggEditorDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags f = 0 );

public slots:
	void openOggFile();
	void saveOggFile();
};

//=============================================================================
// Fin du fichier oggeditordialog.h
//=============================================================================
