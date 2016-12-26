/*=============================================================================
 * mainwindow.cpp
 *=============================================================================
 * Construit la fenêtre principale
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0 + QT 2.3
 * Build : 14/09/2002
 * Updates :
 *
 *
 *
 *
 *=============================================================================
 */

// Qt libs
#include <qapplication.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qlayout.h>

// Program libs
#include "mainwindow.h"
#include "graph.h"

// Standard libs
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define PI 3.1415927

FrmMain::FrmMain(QWidget *parent, const char *name) : QWidget( parent, name )
{
	// width, height
    setMinimumSize( 400, 400 );
    setMaximumSize( 100, 100 );
	
	// rows, cols, space
	grid = new QGridLayout( this, 3, 2, 10 );
    
	quit = new QPushButton( "Quitter", this );
	about = new QPushButton("À propos...",this);
	
	mkenoise = new QPushButton("Générer",this);
	result = new QPushButton("Résultat",this);
	
	graphique1 = new Graph(this,"bruit");
	graphique2 = new Graph(this,"gaussien");
	
	grid->addWidget( graphique1, 0, 0 );
	grid->addWidget( graphique2, 0, 1 );
	grid->addWidget( mkenoise, 1, 0 );
	grid->addWidget( result, 1, 1 );
	grid->addWidget( about, 2, 0);
	grid->addWidget( quit, 2, 1 );
   

	connect( quit, SIGNAL(clicked()), qApp, SLOT(quit()) );
	connect( about, SIGNAL(clicked()), this, SLOT(aboutBox()) );
	connect( mkenoise, SIGNAL(clicked()), this, SLOT(genBruit()) );
	connect( result, SIGNAL(clicked()), this, SLOT(afficheBruit()) );
}

void FrmMain::aboutBox(void)
{

QMessageBox::information( this, "About...",
                            "Anthony Rabine (c) 2002.\n"
                            "arabine@programmationworld.com." );

}

void FrmMain::genBruit(void)
{
	srand((unsigned)time(NULL));
	for(int i=0;i<200;i++)
	{
		val[i]=rand()%200;
		gauss[i] = 100-val[i];
	}

	graphique1->paintRandom(val);
}

void FrmMain::afficheBruit(void)
{

	FILE *f;
	char buffer[20];
	f=fopen("out.txt","w");

	for(int i=0;i<200;i++)
	{
/*		itoa(gauss[i],buffer,10);
		fprintf(f,buffer);
		fprintf(f," ");
*/		
		resultat[i] = (1.0/sqrt(2*PI))*exp(val[i]*val[i]/2.0)+100;
		
		itoa(resultat[i],buffer,10);
		fprintf(f,buffer);
		fprintf(f,"\n");

	}
//	fclose(f);

	graphique2->afficheGaussien(resultat);
}

//=============================================================================
// End of mainwindow.cpp
//=============================================================================