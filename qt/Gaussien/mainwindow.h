#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qapplication.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include "graph.h"

class FrmMain : public QWidget
{
	Q_OBJECT

private:
	QGridLayout *grid;
	QPushButton *quit;
	QPushButton *about;
	QPushButton *mkenoise;
	QPushButton *result;
	Graph *graphique1;
	Graph *graphique2;

	int val[200];
	int gauss[200];
	float resultat[200];

public:
    FrmMain( QWidget *parent=0, const char *name=0 );
	~FrmMain(){}
	
public slots:
	void aboutBox(void);
	void genBruit(void);
	void afficheBruit(void);
};

#endif