/*=============================================================================
 * OggEditor - OggFile.cpp
 *=============================================================================
 * Librairie de lecture/écriture d'informations contenues dans un fichier Ogg
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environnement : VC++ 6.0 sous Windows, g++ sous Linux
 *  
 * La majorité du code source de ce fichier a été pris dans l'utilitaire 
 * "vorbiscomment" disponible sur le site http://www.xiph.org/ogg/vorbis/
 * (vorbis-tools)
 *
 * Historique :
 * 
 * 10/2003 : première version
 *
 *=============================================================================
 */

#include "OggFile.h"

/*****************************************************************************/
/**
 * Initialisation par défaut des paramètres
 *
 */
OggFile::OggFile()
{
	/* filenames */
	infilename  = new char[1];
	outfilename = new char[1];

	vendor_string = new char[1];
	comments[0] = new char[1];

	/* file pointers */
	in = NULL;
	out = NULL;

	commentcount=1;
	tempoutfile=0;
    raw = 0;
}
/*****************************************************************************/
/**
 * Destructeur, on détruit... pour mieux reconstruire !!
 */
OggFile::~OggFile()
{
	int i;

	delete[] infilename;
	delete[] outfilename;
	delete[] vendor_string;
	
	for(i=0;i<commentcount;i++)
		delete[] comments[i];

}
/*****************************************************************************/
/**
 * Lit un fichier Ogg et extrait les commentaires
 * Entrée : chemin du fichier Ogg
 * Sortie : 0 si tout s'est bien passé
 *			sinon un code d'erreur
 */
int OggFile::readOggFile(const char *fileName)
{
	int i;
	vcedit_state *state;
	vorbis_comment *vc;
	vorbis_info *vi;
	ogg_stream_state *os;

	delete[] infilename;
	infilename = new char[strlen(fileName)+1];
	strcpy(infilename, fileName);

	delete[] outfilename;
	outfilename = new char[strlen(fileName)+1+4];
	strcpy(outfilename, fileName);
	strcat(outfilename, "-tmp");

	in = fopen(infilename, "rb");

	if(in == NULL)
	{
		return 1;
	}

	tailleFichier = filesize( in );
	state = vcedit_new_state();

	if(vcedit_open(state, in) < 0)
	{
		fclose(in);
        vcedit_clear(state);
		return 2;
	}

	/* extract the comments */
	vc = vcedit_comments(state);

	for(i=0;i<commentcount;i++)
		delete[] comments[i];

	commentcount = vc->comments;

	for (i = 0; i < commentcount; i++)
    {
		comments[i] = new char[strlen(vc->user_comments[i])+1];
		strcpy(comments[i],vc->user_comments[i]);
    }
	
	vi = state->vi;
	os = state->os;

	// On stocke les paramètres du fichier Ogg
	audio_channels = vi->channels;
	bitrate_nominal = vi->bitrate_nominal;
	audio_sample_rate = vi->rate;
	vorbis_version = vi->version;
	page_serial_number = os->serialno;

	delete[] vendor_string;
	vendor_string = new char[strlen(vc->vendor)+1];
	strcpy(vendor_string, vc->vendor);

	vcedit_clear(state);
	fclose(in);

	return 0;

}
/*****************************************************************************/
/**
 * Sauve les commentaires
 */
int OggFile::saveOggFile(char *cmt[256], int nb_commentaires)
{
	vcedit_state *state;
	vorbis_comment *vc;
	int i;

	in = fopen(infilename, "rb");

	if(in == NULL)
	{
		return 1;
	}

	out = fopen(outfilename, "wb");
	if(out == NULL)
	{
		return 2;
	}

	state = vcedit_new_state();

	if(vcedit_open(state, in) < 0)
	{
        fclose(in);
		fclose(out);
        vcedit_clear(state);
		return 3;
	}

	/* grab and clear the exisiting comments */
	vc = vcedit_comments(state);
	vorbis_comment_clear(vc);
	vorbis_comment_init(vc);

	// on efface les anciens commentaires
	for(i=0;i<commentcount;i++)
		delete[] comments[i];

	// Copie des commentaires en local
	commentcount = nb_commentaires;
	for(i=0;i<commentcount;i++)
	{
		comments[i] = new char[strlen(cmt[i])+1];
		strcpy(comments[i], cmt[i]);
	}


	for(i=0; i < commentcount; i++)
	{
		// tester le retour ici
		add_comment( comments[i], vc);
	}


	/* write out the modified stream */
	if(vcedit_write(state, out) < 0)
	{
		fclose(in);
		fclose(out);
        vcedit_clear(state);
		return 4;
	}

	/* done */
	vcedit_clear(state);
	
	fclose(in);
	fclose(out);

	// Astuce pour éviter le renomage qui peut bugguer sur certains OS
    if(rename(outfilename, infilename))
    {
        if(remove(infilename))
            return 5;
        else if(rename(outfilename, infilename)) 
            return 6;
    }


	return 0;
}
/*****************************************************************************/
int OggFile::add_comment(char *line, vorbis_comment *vc)
{
	char	*mark, *value;
	int len;

	/* strip any terminal newline */
	len = strlen(line);
	if (line[len-1] == '\n') line[len-1] = '\0';

	/* validation: basically, we assume it's a tag
	 * if it has an '=' after one or more valid characters,
	 * as the comment spec requires. For the moment, we
	 * also restrict ourselves to 0-terminated values */

	mark = strchr(line, '=');
	if (mark == NULL) return -1;

	value = line;
	while (value < mark) {
		if(*value < 0x20 || *value > 0x7d || *value == 0x3d) return -1;
		value++;
	}

	/* split the line by turning the '=' in to a null */
	*mark = '\0';	
	value++;

    vorbis_comment_add_tag(vc, line, value);
	return 0;
}
/*****************************************************************************/
/**
 * Retourne la taille du fichier en octets
 */
long OggFile::filesize(FILE *stream)
{
	long int curpos,length;

	curpos = ftell(stream); /* garder la position courante */
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek (stream, curpos, SEEK_SET); /* restituer la position */
	
	return length;
}

//=============================================================================
// Fin du fichier OggFile.cpp
//=============================================================================
