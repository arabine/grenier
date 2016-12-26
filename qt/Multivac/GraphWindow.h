/*=============================================================================
 * Multivac 1.0 - GraphWindow.h
 *=============================================================================
 * Fenêtre principale avec les graphiques
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 9/01/2003 : première version
 *
 *=============================================================================
 */

#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

// Librairies externes
//#include <gsl/gsl_errno.h>
//#include <gsl/gsl_fft_complex.h>

// Classes internes
#include "Plot.h"
#include "CWaveFile.h"
#include "ParamPanel.h"
#include "Freq.h"
#include "error.h" // codes d'erreurs
//#include "icon.h"

// Librairies QT
#include <qmainwindow.h>
#include <qpainter.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qapplication.h>
#include <qstatusbar.h>
#include <qfiledialog.h>
#include <qfileinfo.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qpixmap.h> 

class GraphWindow : public QMainWindow
{
	Q_OBJECT

private:
	// Interface principale
	QMenuBar	*menu;
	QPopupMenu	*filemenu;
	QPopupMenu	*analysemenu;
	QPopupMenu	*helpmenu;
	QStatusBar	*statusbar;
	QFileDialog	*opendialog;
	QTabWidget	*onglets;
//	QPixmap		*pixmap;
	
	ParamPanel	*mypan;
	
	// Premier onglet
	Plot	*firstpane;

	// Deuxième onglet
	Freq	*secondpane;

	// Troisième onglet
	QWidget	*thirdpane;
	QLabel	*infos;

	
	CWaveFile MyWaveFile;

	void setupMenuBar();
	void setupCentralWidgets();

	bool	fileLoaded;			// indique si un fichier est chargé ou non
	QString currentFilePath;	// emplacement du fichier courant chargé
	QString lastDirectory;		// mémorise le dernier répertoire visité
	QString infosString;

	unsigned long int debut;	// debut de l'intervalle pour la FFT
	bool paramSet;				// indique si un intervalle a été définie
	unsigned long taillefft;	// taille de l'intervalle (puissance de 2)

protected:
	void resizeEvent(QResizeEvent *);

public:
	// Constructeurs & Destructeurs
	GraphWindow( QWidget* parent = 0, const char* name = 0, WFlags f = WType_TopLevel );
	void initValues();
	void setInfos();

	// Messages d'erreurs
	void errorBox(int code);
	void noWaveLoadedBox();
	void noParamSet();

public slots:
	void openSoundFile();	
	void aboutBox();
	void setupAnalyse();
	void startFFT();
	void testFREQ();
	void recepIntervalle(unsigned long int min, unsigned long taille);
	void setMessage(QString mess);
};

#endif

//=============================================================================
// Fin du fichier GraphWindow.h
//=============================================================================