/*=============================================================================
 * NewAuthorFrame.h
 *=============================================================================
 * Crée un nouvel auteur dans la base de données
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 27/10/2002
 *=============================================================================
 */

#ifndef NEWAUTHORFRAME_H
#define NEWAUTHORFRAME_H

// Librairies QT
#include <qdialog.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qmultilineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>

// Librairies internes


class NewAuthorFrame : public QDialog
{

	Q_OBJECT

private:
	QLabel *TextLabel1;
    QMultiLineEdit* MultiLineEdit1;
	QLabel *TextLabel2;
    QLineEdit* LineEdit1;
	QPushButton *valide;
	QPushButton *annule;

	QString nom, description;

public:
	NewAuthorFrame(QWidget *parent, bool modal);
	~NewAuthorFrame(){}
	
	// Accesseurs
	QString getNom(){ return nom; }
	QString getDescription(){ return description; }

public slots:
	void save_entry();
	void showEvent (QShowEvent *);

};

#endif

//=============================================================================
// End of NewAuthorFrame.h
//=============================================================================