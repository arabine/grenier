/*=============================================================================
 * FantasyBowl 1.0 - Equipe.cpp
 *=============================================================================
 * Classe représentant une équipe
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0 / g++ Avec librairies Qt 2.3 minimum
 *  
 * Cette classe fait appel à la classe Joueur pour représenter les joueurs
 * sur le terrain.
 *
 *=============================================================================
 */

#include "Equipe.h"

/*****************************************************************************/
Equipe::Equipe(int num)
{

	numEquipe = num;
	playerList.setAutoDelete(true);
}
/*****************************************************************************/
int Equipe::getNum()
{
	return numEquipe;
}
/*****************************************************************************/
/**
 * Put a pawn on a specified canvas
 */
void Equipe::setGround(int joueurNum, QCanvas *can)
{
	Joueur *j;
	
	for(j = playerList.first(); j!=0; j = playerList.next())
	{
		if(joueurNum == j->getNumero())
			break;	// yes, I got it !
	}

	if(j == NULL)
		return;

	j->setCanvas(can);

}
/*****************************************************************************/
/**
 * Move a pawn at a specified place
 */
int Equipe::setCoord(int joueurNum, int x, int y)
{
	Joueur *j;
	
	for(j = playerList.first(); j!=0; j = playerList.next())
	{
		if(joueurNum == j->getNumero())
			break;	// yes, I got it !
	}

	if(j == NULL)
		return 1;
	
	j->move(x, y);
	j->show();

	return 0;
}
/*****************************************************************************/
void Equipe::setPawns(const QMap<int, Title> &titleList)
{
	Joueur *j;
	int titleNumber;
	Title ti;

	for(j = playerList.first(); j!=0; j = playerList.next())
	{
		titleNumber = j->getPosition();
		ti = titleList[titleNumber];
		j->setPawn(ti.getPawn());
		j->setTitle(ti.getName());
	}

}
/*****************************************************************************/
/**
 * Load a team file into memory
 * return 0 if ok, else an error code
 */
int Equipe::readXMLFile(QList<Skill> theSkillList, QString filePath, QCanvas *terrain)
{
	int ret=0;
	int id;
	
	if(!playerList.isEmpty())
		playerList.clear();


	QDomDocument doc;
	
	// On ouvre le fichier XML
	QFile f(filePath);
	
	if(f.open(IO_ReadOnly)==false)
		return 42;
	doc.setContent(&f);
	f.close();

	// L'arbre est en mémoire, on le parse	
	// Commence par la balise "FBteam"
	QDomElement root=doc.documentElement();

	if(root.tagName()!="FBteam")
		return 1;

	// On parse les données
	QDomElement child=root.firstChild().toElement();

	while(!child.isNull())
	{
		if(child.tagName() == "name")
			nom = child.text();
		else if(child.tagName() == "race")
				race = child.text();
			 else if(child.tagName() == "rating")
					rating = child.text().toInt();
				 else if(child.tagName() == "treasury")
						treasury = child.text().toInt();
	  				 else if(child.tagName() == "coach")
							coach = child.text();
						 else if(child.tagName() == "fanfactor")
								fanFactor = child.text().toInt();
							 else if(child.tagName() == "assistants")
									assistants = child.text().toInt();
								 else if(child.tagName() == "cheerleaders")
										cheerleaders = child.text().toInt();
									  else if(child.tagName() == "apothecary")
											apothecary = child.text().toInt();
										 else if(child.tagName() == "wizard")
												wizard = child.text().toInt();
											 else if(child.tagName() == "reroll")
													{
														rerollCost = child.attribute("cost", "0" ).toInt();
														reroll = child.text().toInt();
													}
												 else if(child.tagName() == "logo")
														logo = child.text();
														
		else if(child.tagName() == "player")
		{
			id = child.attribute("id", "1" ).toInt();
			if(id<=0 || id>16)
				return 2;		
			
			Joueur *j = new Joueur(numEquipe, terrain); // joueur courant

			j->setNumero(id);

			// propriétés du joueur courant
			QDomElement grandChild=child.firstChild().toElement();
			while(!grandChild.isNull())
			{
				if(grandChild.tagName() == "name")
					 j->setName(grandChild.text());
				else if(grandChild.tagName() == "position")
						j->setPosition(grandChild.text().toInt());
					else if(grandChild.tagName() == "ma")
							j->setMa(grandChild.text().toInt());
						else if(grandChild.tagName() == "st")
								j->setSt(grandChild.text().toInt());
							else if(grandChild.tagName() == "ag")
									j->setAg(grandChild.text().toInt());
								else if(grandChild.tagName() == "av")
										j->setAv(grandChild.text().toInt());
									else if(grandChild.tagName() == "cost")
											j->setCost(grandChild.text().toInt());
										else if(grandChild.tagName() == "image")
												j->setPic(grandChild.text());
				
				// Compétences du joueur courant
				else if(grandChild.tagName() == "skills")
				{
					int num;
					Skill *comp;

					// on est dans le noeud des skills d'un perso, on parse
					QDomElement skillsChild=grandChild.firstChild().toElement();
					while(!skillsChild.isNull())
					{
						if(skillsChild.tagName() == "skill")
						{
							num = skillsChild.attribute("id", "101").toInt();

							for( comp=theSkillList.first(); comp != 0; comp=theSkillList.next() )
							{
								if(comp->getId() == num)
								{
									// on rajoute la cométence lue au joueur courant
									j->playerSkills.append(new Skill(num, comp->getName(), comp->getType() ) );
								}
							}

						}

						skillsChild = skillsChild.nextSibling().toElement();
					}
				}
				
				grandChild = grandChild.nextSibling().toElement();
			}

			// on rajoute le joueur courant à l'équipe
			playerList.append(j);
		}

		child = child.nextSibling().toElement();
	}

	return ret;
}
/*****************************************************************************/
QString	Equipe::getName()
{
	return nom;
}
/*****************************************************************************/
QString Equipe::getRace()
{
	return race;
}
/*****************************************************************************/
int	Equipe::getRating()
{
	return rating;
}
/*****************************************************************************/
int	Equipe::getTreasury()
{
	return treasury;
}
/*****************************************************************************/
QString	Equipe::getCoach()
{
	return coach;
}
/*****************************************************************************/
QString	Equipe::getLogo()
{
	return logo;
}
/*****************************************************************************/
int	Equipe::getReroll()
{
	return reroll;
}
/*****************************************************************************/
int	Equipe::getRerollCost()
{
	return rerollCost;
}
/*****************************************************************************/
int	Equipe::getFanFactor()
{
	return fanFactor;
}
/*****************************************************************************/
int	Equipe::getAssistants()
{
	return assistants;
}
/*****************************************************************************/
int	Equipe::getCheerleaders()
{
	return cheerleaders;
}
/*****************************************************************************/
int	Equipe::getApothecary()
{
	return apothecary;
}
/*****************************************************************************/
int	Equipe::getWizard()
{
	return wizard;
}

//=============================================================================
// Fin du fichier Equipe.cpp
//=============================================================================
