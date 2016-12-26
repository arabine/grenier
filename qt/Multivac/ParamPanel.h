/*=============================================================================
 * Multivac 1.0 - ParamPanel.h
 *=============================================================================
 * Boîte de dialog de paramétrage de la transformée de Fourier
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 02/01/2003 : première version
 *
 *=============================================================================
 */

#ifndef PARAMPANEL_H
#define PARAMPANEL_H

// Librairies externes
#include <math.h>

// Librairies QT
#include <qdialog.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qlabel.h>
#include <qmessagebox.h>

class ParamPanel : public QDialog
{

	Q_OBJECT

private:
	QPushButton *ok,*cancel;
	QLabel *instructions,*label1, *label2, *resultat, *taille;
	QSpinBox *spin1, *spin2;

public:
	ParamPanel(QWidget *parent, bool modal, unsigned long int valMax);

public slots:
	void saveParam();
	void calculTaille();
	void errorOfSize();
	void errorOfBoundary();

signals:
	void signalSaveParam(unsigned long int, unsigned long);

};

#endif

//=============================================================================
// Fin du fichier ParamPanel.h
//=============================================================================