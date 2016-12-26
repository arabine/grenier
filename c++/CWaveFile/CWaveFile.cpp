/*=============================================================================
 * CWaveFile.cpp 1.0
 *=============================================================================
 * Classe C++ de validation/lecture de fichier Wave
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 31/01/2003 : première version
 *
 *=============================================================================
 */

// Classes internes
#include "CWaveFile.h"

/*****************************************************************************/
CWaveFile::CWaveFile()
{
	fileName = new char[1];
	strcpy(fileName,"");
	data = new unsigned char[1];
	data[0]='\0';

}
/*****************************************************************************/
CWaveFile::CWaveFile(const char *name)
{
	int taille;

	taille = strlen(name);
	fileName = new char[taille];
	strcpy(fileName,name);

}
/*****************************************************************************/
CWaveFile::~CWaveFile()
{
	delete data;
	delete fileName;
}
/*****************************************************************************/
void CWaveFile::setPath(const char *name)
{
	int taille;

	delete	fileName;
	taille = strlen(name);
	fileName = new char[taille];
	strcpy(fileName,name);

}
/*****************************************************************************/
/**
 *	Renvoie 0 en cas de succès, sinon un code d'erreur
 */
int CWaveFile::loadWaveFile()
{

	unsigned char WavHeader[HEADER_SIZE];
	FILE *fp;
	unsigned long int ret;

	fp = fopen(fileName,"rb");
	if(fp==NULL)
	{
		return WAV_CANT_OPEN; // Impossible d'ouvrir le fichier
	}
	waveFileSize = fileSize(fp);

	ret = fread(WavHeader, sizeof(unsigned char), HEADER_SIZE, fp); // retourne ret, le nombre d'octets lus

	if(ret!=HEADER_SIZE)
	{
		fclose(fp);
		return WAV_CANT_READ_HDR; // Probleme de lecture du fichier.
	}

	if((ret=verifWav(WavHeader))!=0)
	{
		fclose(fp);
		return ret; // Fichier .wav non valide (voir les messages d'erreurs dans error.h)
	}

	// le fichier est maintenant valide, on va capturer les données
	delete data;
	data = new unsigned char[dataSize];

	// position des données différente selon les formats wav
	if(fact==0)
		fseek(fp,44,0);

	ret = fread(data, sizeof(unsigned char), dataSize, fp);
	if(ret!=dataSize)
	{
		fclose(fp);
		return WAV_CANT_READ_DATA; // Probleme de lecture du fichier.
	}

	fclose(fp);
	return 0;
}
/*****************************************************************************/
/**
 * retour :
 *			0 : fichier wav valide
 *			sinon : fichier wav non valide : code de retour
 *				codes :
 *				42 : la fonction mid s'est mal déroulée	
 */
int CWaveFile::verifWav(unsigned char WavHeader[HEADER_SIZE])
{
	char buff[HEADER_SIZE];
	unsigned int val=0;
	char chr[2];

	chr[1]='\0';

	// on teste le format
	if(mid(WavHeader,HEADER_SIZE,0,3,buff))
		return WAV_BAD_PARAMETERS;
	if(strcmp(buff,"RIFF"))
		return WAV_NO_RIFF;

	// on teste la taille du fichier
	val = WavHeader[4]+WavHeader[5]*256+WavHeader[6]*65536+WavHeader[7]*16777216;
	if(val+8!=waveFileSize)
		return WAV_BAD_FILESIZE;

	// on teste le format
	if(mid(WavHeader,HEADER_SIZE,8,15,buff))
		return WAV_BAD_PARAMETERS;
	if(strcmp(buff,"WAVEfmt "))
		return WAV_NO_WAVE;
	
	// nombre d'octets pour décrire le format souvent 16 ou 18 !! (d'autres tailles existent ???)
	val = WavHeader[16]+WavHeader[17]*256+WavHeader[18]*65536+WavHeader[19]*16777216;
	if(val==16)
		fact=0;
	else	if(val==18)
				fact=1;
			else
				return WAV_NO_SUPPORT;

	// on ne gère que le PCM non compressé
	val = WavHeader[20]+WavHeader[21]*256;
	if(val!=1)
		return WAV_NO_COMPRESSION;

	// canaux : mono = 1, stereo = 2
	val = WavHeader[22]+WavHeader[23]*256;
	if(val==1)
		channels = 1;
	else	if(val==2)
		//	{
				channels = 2;
		//		return WAV_NO_STEREO; // ne gère pas encore le format stéréo, on quitte !
		//	}
			else
				return WAV_BAD_CHANNELS;

	// fréquence d'échantillonnage
	samplesPerSec = WavHeader[24]+WavHeader[25]*256+WavHeader[26]*65536+WavHeader[27]*16777216;

	// nombre d'octets par seconde (== fréquence d'échantillonnage si mono)
	avgBytesPerSec = WavHeader[28]+WavHeader[29]*256+WavHeader[30]*65536+WavHeader[31]*16777216;

	
	// octets par échantillon : 1=8 bit Mono, 2=8 bit Stereo or 16 bit Mono, 4=16 bit Stereo
	val = WavHeader[32]+WavHeader[33]*256;
	if(val==1)
		BlockAlign = 1;
	else	if(val==2)
				BlockAlign = 2;
			else	if(val==4)
						BlockAlign = 4;
					else
						return WAV_NO_BLOCKALIGN;
	
	// bits par échantillon : 8, 12 ou 16
	val = WavHeader[34]+WavHeader[35]*256;
	if(val==8)
		bitsPerSample = 8;
	else	if(val==12)
				bitsPerSample = 12;
			else	if(val==16)
						bitsPerSample = 16;
					else
						return WAV_BAD_BITS;
	
	// On commence la zone de données proprement dite

	// on teste l'existance du label
	if(fact==0)
	{
		if(mid(WavHeader,HEADER_SIZE,36,39,buff))
			return WAV_BAD_PARAMETERS;
	}
	else
	{
		if(mid(WavHeader,HEADER_SIZE,50,53,buff))
			return WAV_BAD_PARAMETERS;
	}

	if(strcmp(buff,"data"))
		return WAV_NO_DATA;

	// taille des données
	if(fact==0)
		dataSize = WavHeader[40]+WavHeader[41]*256+WavHeader[42]*65536+WavHeader[43]*16777216;
	else
		dataSize = WavHeader[54]+WavHeader[55]*256+WavHeader[56]*65536+WavHeader[57]*16777216;

	return 0;
}
/*****************************************************************************/
/**
 * Retourne :	0 si bien passé
 *				1 en cas d'erreur
 */
int CWaveFile::mid(unsigned char *in, int taille, int debut, int fin, char *out)
{
	int i, ecart;

	ecart = fin-debut;
	if(taille<=0 || ecart>=taille || ecart<=0)
		return(1);
	
	for(i=0;i<=ecart;i++)
		out[i] = (char)in[debut+i];
	out[ecart+1]='\0';	// on termine la chaine de caractères
	
	return 0;
}
/*****************************************************************************/
/**
 * Retourne la taille du fichier en octets
 */
unsigned int CWaveFile::fileSize(FILE *stream)
{
	unsigned int curpos,length;

	curpos = ftell(stream); /* garder la position courante */
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek (stream, curpos, SEEK_SET); /* restituer la position */
	
	return length;
}
/*****************************************************************************/
/**
 * Accesseurs
 */
char *CWaveFile::getFileName()
{
	return fileName;
}
/*****************************************************************************/
unsigned int CWaveFile::getFileSize()
{
	return waveFileSize;
}
/*****************************************************************************/
unsigned int CWaveFile::getChannels()
{
	return channels;
}
/*****************************************************************************/
unsigned int CWaveFile::getSamplesPerSec()
{
	return samplesPerSec;
}
/*****************************************************************************/
unsigned int CWaveFile::getAvgBytesPerSec()
{
	return avgBytesPerSec;
}
/*****************************************************************************/
unsigned short int CWaveFile::getBlockAlign()
{
	return BlockAlign;
}
/*****************************************************************************/
unsigned short int CWaveFile::getBitsPerSample()
{
	return bitsPerSample;
}
/*****************************************************************************/
unsigned long int CWaveFile::getDataSize()
{
	return dataSize;
}
/*****************************************************************************/
unsigned char *CWaveFile::getData()
{
	return data;
}

//=============================================================================
// Fin du fichier CWaveFile.cpp
//=============================================================================