/*=============================================================================
 * Multivac 1.0 - ParamPanel.cpp
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


#include "ParamPanel.h"


/*****************************************************************************/
ParamPanel::ParamPanel(QWidget *parent, bool modal, unsigned long int valMax)
	: QDialog(parent, "", modal, 0)
{

	instructions = new QLabel("Entrez l'intervalle de données pour le calcul de la FFT.\n"
								"Attention, la taille doit être une puissance de 2.",this);
	instructions->setGeometry(20,0,270,40);
	


	label1 = new QLabel("Limite minimale :",this);
	label1->move(20,35);

	spin1 = new QSpinBox (0, valMax, 1, this,"min");
	spin1->move(20,60);
	connect(spin1, SIGNAL(valueChanged(int)) ,this , SLOT(calculTaille()));

	label2 = new QLabel("Limite maximale :",this);
	label2->move(150,35);

	spin2 = new QSpinBox (0, valMax, 1, this,"max");
	spin2->move(150,60);
	connect(spin2, SIGNAL(valueChanged(int)) ,this , SLOT(calculTaille()));

	resultat = new QLabel("Nombre d'échantillons :",this);
	resultat->setGeometry(20,100,140,20);
	
	taille = new QLabel("0",this);
	taille->setGeometry(150,100,100,20);

	ok = new QPushButton("&Ok",this);
	ok->move(20,130);
	connect(ok, SIGNAL(clicked()) ,this , SLOT(saveParam()));
	
	cancel = new QPushButton("&Annuler",this);
	cancel->move(150,130);
	connect(cancel, SIGNAL(clicked()) ,this , SLOT(reject()));

	connect(this, SIGNAL(signalSaveParam(unsigned long int, unsigned long)) ,parent , SLOT(recepIntervalle(unsigned long int, unsigned long)));

	setCaption("Multivac");
	setFixedSize(290,165);
}
/*****************************************************************************/
void ParamPanel::saveParam()
{
	signed long int valeur = taille->text().toLong();
	unsigned long int val =  taille->text().toULong();
	unsigned long int j=0;

	if(valeur<=0)
	{
		errorOfSize();
		return;
	}
	
	for(unsigned long int i=0;j<val;i++)
		j=pow(2,i);
	
	if(j!=val)
	{
		errorOfBoundary();
		return;
	}
	
	emit signalSaveParam(spin1->text().toULong(),val);

	hide();
}
/*****************************************************************************/
void ParamPanel::calculTaille()
{
	signed long int val;

	val = spin2->text().toLong() - spin1->text().toLong();
	taille->setNum(val);

}
/*****************************************************************************/
void ParamPanel::errorOfSize()
{
QMessageBox::warning( this, "Erreur",
                            "Le maximum est inférieur ou égal au minimum.");

}
/*****************************************************************************/
void ParamPanel::errorOfBoundary()
{
QMessageBox::warning( this, "Erreur",
                            "La taille n'est pas une puissance de 2.");

}
//=============================================================================
// Fin du fichier ParamPanel.cpp
//=============================================================================