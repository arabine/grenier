/*=============================================================================
 * Phobos 1.0 - PhobosPopup.h
 *=============================================================================
 * Popup menu principal dans le system tray
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0 - Windows seulement
 * 
 *=============================================================================
 */

#ifndef PHOBOSPOPUP_H
#define PHOBOSPOPUP_H

// Librairies Qt
#include <qpixmap.h>
#include <qpopupmenu.h>
#include <qapplication.h>
#include <qlist.h>
#include <qfile.h>
#include <qdom.h>
#include <qdatetime.h>

// Classes internes
#include "icon.h"
#include "trayicon.h"
#include "PhobosNote.h"

#define MAX_NOTES 5

class PhobosPopup : public QPopupMenu
{
    Q_OBJECT

private:
	int		numberOfNotes;
	PhobosNote *listOfNotes[MAX_NOTES];
	int		idOfNotes[MAX_NOTES];

signals:
	void	signalQuitter();

public slots:
	void	ajouteNote();
	void	sauverNote(int id);
	void	menuClicked(int itemId);
	void	quitter();
	void	detruireNote(int id);
	void	renommerNote(int id);
	void	saveParams();

public:
	PhobosPopup();

	void	createNote();
};

#endif // PHOBOSPOPUP_H

//=============================================================================
// Fin du fichier PhobosPopup.h
//=============================================================================
