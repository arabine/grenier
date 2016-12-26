/*=============================================================================
 * OggEditor - OggFile.h
 *=============================================================================
 * Librairie de lecture/écriture d'informations contenues dans un fichier Ogg
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

#ifndef OGGFILE_H
#define OGGFILE_H

// Includes standards
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Includes Ogg/Vorbis
#include <ogg/ogg.h>
#include <vorbis/codec.h>

// Includes locales
#include "vcedit.h"

/*****************************************************************************/
class OggFile
{

private:

	// Informations du fichier Ogg
	int		audio_channels;
	int		vorbis_version;
	long	audio_sample_rate;
	char	*vendor_string;
	long	page_serial_number;
	long	bitrate_nominal;
	long	tailleFichier;

	// on retrouve ici la structure située dans le fichier vcomment.c ...

	char	*infilename, *outfilename;
	char	*commentfilename;
	FILE	*in, *out, *com;
	int		commentcount;
	char	*comments[256]; // limitation ici ...
	int		tempoutfile;
    int		raw;

public:
	// Constructeur et destructeur
	OggFile();
	~OggFile();

	// La méthode principale d'accès en lecture aux commentaires du fichier Ogg
	int				readOggFile(const char *fileName);
	int				saveOggFile(char *cmt[256], int nb_commentaires);
	
	long			filesize(FILE *stream);
	int				add_comment(char *line, vorbis_comment *vc);

	// Accesseurs
	int				getNbComments()		{ return commentcount; }
	char			*getComment(unsigned int i)	{ return comments[i]; }
	long int		getFileSize()		{ return tailleFichier; }
	int				getChannels()		{ return audio_channels; }
	char			*getVendor()		{ return vendor_string; }
	int				getSerialNumber()	{ return page_serial_number; }
	signed int		getNominalBitrate()	{ return bitrate_nominal; }
	unsigned int	getVorbisVersion()	{ return vorbis_version; }
	unsigned int	getSampleRate()		{ return audio_sample_rate; }
	


};

#endif // OGGFILE_H

//=============================================================================
// Fin du fichier OggFile.cpp
//=============================================================================
