

#include "PlayerSkills.h"

PlayerSkills::PlayerSkills(QWidget * parent, QString name, QList<Skill> skills, QList<Skill> playerSkills) 
					: QDialog(parent,0,true)
{
	skillsList = skills;
	playerComp = playerSkills;

	text = new QLabel("Modifiez les compétences du joueur : ", this);
	text->setGeometry(5,0,250,20);
	playerName = new QLabel("<b>" + name + "</b>", this);
	playerName->setGeometry(5,25,290,40);
	playerName->setAlignment(Qt::AlignHCenter);

	listOfSkills = new QListBox(this);
	listOfSkills->setGeometry(5,50,290,365);
	listOfSkills->setSelectionMode(QListBox::Multi);

	ok = new QPushButton("&Ok",this);
	ok->setGeometry(5,420,100,30);
	connect(ok,SIGNAL(clicked()), this, SLOT(accept()));

	cancel = new QPushButton("&Cancel",this);
	cancel->setGeometry(110,420,100,30);
	connect(cancel,SIGNAL(clicked()), this, SLOT(reject()));

	Skill *comp, *compj;
	int i=0;

	for(comp=skillsList.first(); comp != 0; comp=skillsList.next())
	{
		listOfSkills->insertItem(comp->getName());
		for(compj=playerComp.first(); compj!=0; compj=playerComp.next())
		{
			 if(comp->getId() == compj->getId())
				 listOfSkills->setSelected(i,true);

		}
		i++;
	}

	setFixedSize(300,455);
}
/*****************************************************************************/
QList<Skill> PlayerSkills::getPlayerSkills()
{
	playerComp.clear();

	for(unsigned int i=0; i<listOfSkills->count(); i++)
	{
		if(listOfSkills->isSelected(i))
			playerComp.append(skillsList.at(i));
	
	}

	return playerComp;
}
//=============================================================================
// Fin du fichier PlayerSkills.cpp
//=============================================================================