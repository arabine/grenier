/*=============================================================================
 * OggEditor - oggeditordialog.cpp
 *=============================================================================
 * Interface du logiciel
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environnement : VC++ 6.0 sous Windows, g++ sous Linux
 *  
 *
 *
 * Historique :
 * 
 * 10/2003 : première version
 *
 *=============================================================================
 */

#include "oggeditordialog.h"

/*****************************************************************************/
OggEditorDialog::OggEditorDialog( QWidget* parent, const char* name, bool modal, WFlags f )
	: MainForm( parent, name, modal, f )
{
	clearFields();

	connect( btnClose, SIGNAL(clicked()), qApp, SLOT(quit()) );
	connect( btnFile, SIGNAL(clicked()), this, SLOT(openOggFile()));
	connect( btnUpdate, SIGNAL(clicked()), this, SLOT(saveOggFile()));

}
/*****************************************************************************/
/**
 * Affiche la fenêtre de dialogue pour choisir un fichier Ogg
 */
void OggEditorDialog::openOggFile()
{
	int ret;
	unsigned int nbComments, i;

	QString s( QFileDialog::getOpenFileName( QString::null, "Fichiers Ogg (*.ogg)", this ) );
    if ( s.isEmpty() )
        return;

	clearFields();
	oggFilePath = s;

	ret = myFile.readOggFile(s.latin1());
	if(ret)
	{
		QMessageBox::information( this, "OggEditor", "Erreur : " + QString().setNum(ret));
		return;
	}

	// Les caractéristiques sont en mémoire, on les affiches dans les contrôles
	lneFile->setText(s);
	lblLength->setText("Length : ");
    lblAvgBitrate->setText("Average bitrate : ");
    lblFileSize->setText("File size : " + QString().setNum(myFile.getFileSize()) + " bytes");
    lblNominalBitrate->setText("Nominal bitrate : " + QString().setNum(myFile.getNominalBitrate()) );
    lblChannels->setText("Channels : " + QString().setNum(myFile.getChannels()) );
    lblSamplingRate->setText("Sampling rate : " + QString().setNum(myFile.getSampleRate()) + " Hz");
    lblSerial->setText("Serial : " + QString().setNum(myFile.getSerialNumber()) );
    lblVersion->setText("Version : " + QString().setNum(myFile.getVorbisVersion()));
    lblVendor->setText("Vendor : " + QString(myFile.getVendor()));

	nbComments = myFile.getNbComments(); // nombre de commentaires

	QString comment;

	QString field, content;

	for(i=0; i<nbComments; i++)
	{
		comment = myFile.getComment(i);
		ret = comment.find('=');
		if(ret != -1)
		{
			field = comment.mid(0,ret);
			content = comment.mid(ret+1,comment.length());
			if(field == "TITLE")
				lneTitle->setText(content);
			else if(field == "ARTIST")
				lneArtist->setText(content);
			else if(field == "ALBUM")
				lneAlbum->setText(content);
			else if(field == "TRACKNUMBER")
				lneTrack->setText(content);
			else if(field == "DATE")
				lneDate->setText(content);
			else if(field == "COMMENT")
				mlneComment->insertLine(content);
			else
				listBoxOther->insertItem(comment);
		}
	}

}
/*****************************************************************************/
/**
 * Sauve les commentaires dans le fichier Ogg
 */
void OggEditorDialog::saveOggFile()
{
	
	char *comments[256];			// commentaires
	QString ctrl_string;			// copie d'un commentaire
	unsigned int i,j;
	int ret;

	i = 0;
	j = 0;
	for(i=0;i<6;i++)
	{
		if(i==0)
			ctrl_string = QString("TITLE=") + lneTitle->text();
		else if(i==1)
			ctrl_string = QString("TRACKNUMBER=") + lneTrack->text();
		else if(i==2)
			ctrl_string = QString("ALBUM=") + lneAlbum->text();
		else if(i==3)
			ctrl_string = QString("DATE=") + lneDate->text();
		else if(i==4)
			ctrl_string = QString("ARTIST=") + lneArtist->text();
		else if(i==5)
			ctrl_string = QString("COMMENT=") + mlneComment->text();

		if(ctrl_string.length()>0)
		{
			comments[j] = new char[ctrl_string.length()+1];
			strcpy(comments[j], ctrl_string.latin1());
			j++;
		}
	}

	ret = myFile.saveOggFile(comments, j);

	for(i=0; i<j; i++ )
	{
		delete comments[i];
	}
	
	if(ret)
	{
		QMessageBox::information( this, "OggEditor", "Erreur sauvegarde : " + QString().setNum(ret));
	}


}
/*****************************************************************************/
/**
 * Efface les contrôles de l'interface
 */
void OggEditorDialog::clearFields()
{
	listBoxOther->clear();
    lneTrack->clear();
    lneDate->clear();
    lneAlbum->clear();
    lneArtist->clear();
    lneTitle->clear();
    mlneComment->clear();
    listBoxOther->clear();
    lneFile->clear();
	ComboBox1->clear();

	lblLength->setText("Length : ");
    lblAvgBitrate->setText("Average bitrate : ");
    lblFileSize->setText("File size : ");
    lblNominalBitrate->setText("Nominal bitrate : ");
    lblChannels->setText("Channels : ");
    lblSamplingRate->setText("Sampling rate : ");
    lblSerial->setText("Serial : ");
    lblVersion->setText("Version : ");
    lblVendor->setText("Vendor : ");

}
//=============================================================================
// Fin du fichier oggeditordialog.h
//=============================================================================
