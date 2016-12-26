/*=============================================================================
 * Phobos 1.0 - PhobosPopup.cpp
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

#include "PhobosPopup.h"

/*****************************************************************************/
/**
 * Constructeur : on lit le fichier de paramètres phobos.xml et on 
 * construit les Post-it
 */
PhobosPopup::PhobosPopup() : QPopupMenu()
{
	int size, nb_notes, i;
	char *buff;
	QString texte;
	PhobosNote *pUI;

//	setCheckable(true);

    insertItem( "Ajouter" , this, SLOT(ajouteNote()) ,0,-1);
    insertSeparator();
    insertItem( "&Quitter", this, SLOT(quitter()), 1, -1 );

	numberOfNotes = 0;
	for(i=0;i<MAX_NOTES;i++)
		idOfNotes[i] = -1;

	// on lit le fichier de paramètres phobos.xml
	QDomDocument doc;
	
	// On ouvre le fichier XML
	QFile f("phobos.xml");
	
	if(f.open(IO_ReadOnly)==false)
		return;

	doc.setContent(&f);
	f.close();

	QDomElement root=doc.documentElement();

	if(root.tagName()!="phobos")
		return;

	// On parse les données
	QDomElement child=root.firstChild().toElement();

	while(!child.isNull())
	{
		if(child.tagName() == "notes")
		{
			nb_notes = child.attribute("quantity", "0" ).toInt();
		}
		QDomElement grandChild=child.firstChild().toElement();
		while(!grandChild.isNull())
		{
			if(grandChild.tagName() == "note")
			{
				i = grandChild.attribute("num", "0" ).toInt();
				if(i<0 || i>MAX_NOTES-1)
				{
					grandChild = grandChild.nextSibling().toElement();
					continue;
				}
	
				f.setName("notes/note" + QString().setNum(i) + ".txt");
				if(f.open(IO_ReadOnly)==false)
				{
					grandChild = grandChild.nextSibling().toElement();
					continue;
				}

				createNote();
				pUI = listOfNotes[numberOfNotes-1];
				
				// on charge le contenu du Post-it
				size = f.size();
				buff = new char[size+1];
				f.readBlock(buff,size);
				buff[size]='\0';
				texte = buff;
				pUI->setText(texte);

				// on change les titres
				texte = grandChild.text();
				pUI->setTitle(texte);
				this->changeItem(numberOfNotes+99, texte);

				delete[] buff;
				f.close();	
			
			}
			grandChild = grandChild.nextSibling().toElement();
		}

		child = child.nextSibling().toElement();
	}


	connect(this, SIGNAL(activated(int)),this, SLOT(menuClicked(int)));
	connect(this, SIGNAL(signalQuitter()),qApp, SLOT(quit()));

}
/*****************************************************************************/
/**
 * Crée un Post-it et l'affiche
 */
void PhobosPopup::ajouteNote()
{
	// on limite à MAX_NOTES notes
	if(numberOfNotes == MAX_NOTES)
		return;

	PhobosNote *pUI;

	createNote();
	pUI = listOfNotes[numberOfNotes-1];
	pUI->show();

	// On sauve tous les paramètres
	saveParams();
}
/*****************************************************************************/
/**
 * Crée un post-it en mémoire mais ne l'affiche pas
 */
void PhobosPopup::createNote()
{
	// on limite à MAX_NOTES notes
	if(numberOfNotes == MAX_NOTES)
		return;

	listOfNotes[numberOfNotes] = new PhobosNote(this,0,100+numberOfNotes);
	this->insertItem( "Note " + QString().setNum(numberOfNotes+1), 100+numberOfNotes, numberOfNotes );
	
	idOfNotes[numberOfNotes] = 100+numberOfNotes;
	numberOfNotes++;
}
/*****************************************************************************/
void PhobosPopup::sauverNote(int id)
{
	int i = id-100;
	PhobosNote *pUI;
	QFile out;
	QString buff;

	pUI = listOfNotes[i];
	buff = pUI->getText();

	out.setName("notes/note" + QString().setNum(i) + ".txt");
	out.open(IO_WriteOnly);
	out.writeBlock( buff.latin1(), buff.length() );
    out.close();
}
/*****************************************************************************/
void PhobosPopup::renommerNote(int id)
{
	int i = id-100;
	QString name;

	PhobosNote *pUI;
	pUI = listOfNotes[i];

	name = pUI->getTitle();
	this->changeItem(id, name);

	saveParams();
}
/*****************************************************************************/
void PhobosPopup::detruireNote(int id)
{

	PhobosNote *pUI = listOfNotes[id-100];
	delete[] pUI;
	listOfNotes[id-100] = NULL;

	this->removeItem(id);
	QFile f("notes/note" + QString().setNum(id-100) + ".txt");
	if(f.exists()==true)
	{
		f.remove();
	}
	f.close();

	for(int i=0;i<MAX_NOTES;i++)
	{
		if(idOfNotes[i]==id)
		{
			idOfNotes[i]= -1;
			break;
		}
	}
	numberOfNotes--;

	saveParams();
}
/*****************************************************************************/
/**
 * On arrive ici à chaque click sur un élément du menu
 */
void PhobosPopup::menuClicked(int itemId)
{
	// Seuls les clicks sur des Post-it nous intéressent
	if(itemId<100 || itemId>(100+MAX_NOTES-1))
		return;

	PhobosNote *pUI;

	pUI = listOfNotes[itemId-100];

	if(pUI->isVisible() == TRUE)
		pUI->hide();
	else
		pUI->show();
}
/*****************************************************************************/
/**
 * On sauve les post-it, les paramètres et on quitte
 */
void PhobosPopup::quitter()
{
	// On sauve tous les paramètres avant de quitter
	saveParams();

	// on quitte l'application
	emit signalQuitter();	
}
/*****************************************************************************/
/**
 * On sauve les post-it et les paramètres
 */
void PhobosPopup::saveParams()
{
	QFile out;
	PhobosNote *pUI;
	QString buff;
	int i;

	// on sauve les paramètres
	QDate theDate;
	theDate = theDate.currentDate();

	// Create the document
	QDomDocument doc("Phobos");
	
	doc.appendChild( doc.createProcessingInstruction( "xml", "version=\"1.0\" encoding=\"ISO-8859-1\"" ) );
	doc.appendChild(doc.createTextNode("\n"));

	doc.appendChild(doc.createComment("Generated by Phobos 1.0 - " + theDate.toString()  ));
	doc.appendChild(doc.createTextNode("\n"));

	// root node
	QDomElement rootNode = doc.createElement("phobos");
	rootNode.setAttribute("version", "1.0");
	doc.appendChild(rootNode);

	// Paramètres généraux
	QDomElement notesNode = doc.createElement("notes");
	notesNode.setAttribute("quantity", numberOfNotes);
	rootNode.appendChild(notesNode);

	for(i=0;i<MAX_NOTES;i++)
	{
		if(idOfNotes[i]==-1)
			continue;

		// on profite lachement d'une belle boucle 
		// pour sauver les post-it sur le disque
		pUI = listOfNotes[i];
		buff = pUI->getText();

		out.setName("notes/note" + QString().setNum(i) + ".txt");
		out.open(IO_WriteOnly);
		out.writeBlock( buff.latin1(), buff.length() );
        out.close();

		// Hop, on écrit une nouvelle balise pour la note courante
		buff = this->text(idOfNotes[i]);
		QDomElement noteNode = doc.createElement("note");
		noteNode.setAttribute("num", i);
		noteNode.appendChild(doc.createTextNode(buff));
		notesNode.appendChild(noteNode);
	}

	QFile f("phobos.xml");
	if(!f.open(IO_WriteOnly))
		return; // problème de création du fichier

	QString outfile = doc.toString();

    f.writeBlock( outfile, outfile.length() ); // hop on écrit le buffer
    f.close();
}
//=============================================================================
// Fin du fichier PhobosPopup.cpp
//=============================================================================
