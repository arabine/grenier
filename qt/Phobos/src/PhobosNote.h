/*=============================================================================
 * Phobos 1.0 - PhobosNote.h
 *=============================================================================
 * Post-it (interface + popup menu)
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0 - Windows seulement
 * 
 *=============================================================================
 */

#ifndef PHOBOSNOTE_H
#define PHOBOSNOTE_H

// Librairies Qt
#include <qvariant.h>
#include <qdialog.h>
#include <qmultilineedit.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qpopupmenu.h>
#include <qinputdialog.h>

/*****************************************************************************/
class MyQMultiLineEdit : public QMultiLineEdit
{
	Q_OBJECT

protected:
	void mousePressEvent( QMouseEvent *);

public:
	MyQMultiLineEdit( QWidget * parent=0, const char * name=0 );

signals:
	void signalShowPopup();
};
/*****************************************************************************/
class PhobosNote : public QDialog
{ 
    Q_OBJECT

private:
    MyQMultiLineEdit* MultiLineEdit1;
	QPopupMenu *popup;
	int noteId;
	QString titreNote;

protected:
	void closeEvent(QCloseEvent *);

public:
    PhobosNote(QWidget* parent , const char* name , int id);

	QString getText();
	QString getTitle();

	void setText(QString txt);
	void setTitle(QString name);

signals:
	void signalDetruireNote(int);
	void signalSauverNote(int);
	void signalRenommerNote(int);

public slots:
	void cacherNote();
	void sauverNote();
	void detruireNote();
	void renommerNote();
	void affichePopup();
	void effacer();
	void copier();
	void couper();
	void coller();
	void defaire();
	void refaire();
};

#endif // PHOBOSNOTE_H

//=============================================================================
// Fin du fichier PhobosNote.h
//=============================================================================
