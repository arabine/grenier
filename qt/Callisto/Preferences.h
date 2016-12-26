/*=============================================================================
 * Preferences.h
 *=============================================================================
 * Classe de gestion des préférences utilisateur (lecture de pref.xml)
 *=============================================================================
 * (c) Anthony RABINE - 2002
 * Environment : VC++ 6.0
 * Build : Anthony RABINE - 27/10/2002
 *=============================================================================
 */



//=============================================================================
// End of Preferences.h
//=============================================================================



/*
	QString s( QFileDialog::getOpenFileName( 
		QString::null, "Fichier XML (*.xml)", this ) );
	
	if ( s.isEmpty() )
        return;
	
	QDomDocument doc;
	
	// On charge le fichier
	QFile f(s);
	f.open(IO_ReadOnly);
	doc.setContent(&f);
	f.close();
	
	// on teste la validité du fichier XML
	QDomElement root=doc.documentElement();
	if(!(root.tagName() == "callisto"))
	{
		errXML();
		return;
	}
	QDomElement child=root.firstChild().toElement();
	if (child.tagName() != "infos")
	{
		errXML();
		return;
	}
	
    QDomElement infosElement=child.firstChild().toElement();
	if (infosElement.tagName() == "version")
	{
		version = infosElement.text();
	}
	else
	{
		errXML();
		return;
	}
	infosElement = infosElement.nextSibling().toElement();
	if (infosElement.tagName() == "date")
	{
		date = infosElement.text();
	}
	else
	{
		errXML();
		return;
	}
	infosElement = infosElement.nextSibling().toElement();
	if (infosElement.tagName() == "nom")
	{
		nom = infosElement.text();
	}
	else
	{
		errXML();
		return;
	}

	// A partir de maintenant le fichier est valide

	// on met à jour l'affichage et quelques variables globales
	curr_filename = s;
	bookLoaded = TRUE;
	statusbar->message("Fichier chargé : "+nom);
	fillTable(&doc);




-----------------------------------


/*
	int nbEntry=0;
	QDomElement bookParam;

	QDomElement root=doc->documentElement();
	
	QDomElement child=root.firstChild().toElement();
	child = child.nextSibling().toElement(); // on pointe sur la première entrée de livres

	while(!child.isNull())
	{
		nbEntry++;
		booklist->setNumRows(nbEntry);
		bookParam = child.firstChild().toElement();
		booklist->setText(0,1,bookParam.text());
		child = child.nextSibling().toElement();
	}


*/





*/