/*=============================================================================
 * CWaveFile.h 1.0
 *=============================================================================
 * Classe C++ de validation/lecture de fichier Wave
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *
 * Notes :
 *			Les noms des membres ont été choisis de façon à respecter la 
 *			plupart des API existantes (MS, Java...)
 *			Ne supporte QUE le format Microsoft Pulse Code Modulation (PCM)
 *
 * Historique :
 * 
 * 31/01/2003 : première version
 *
 *=============================================================================
 */

#ifndef CWAVEFILE_H
#define CWAVEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h" // messages d'erreurs

#define HEADER_SIZE 58

/*
Description des champs : 

avgBytesPerSec
	  Required average data transfer rate, in bytes per second. For example, 
	  16-bit stereo at 44.1 kHz has an average data rate of 176,400 bytes 
	  per second (2 channels, 2 bytes per sample per channel, 44,100 samples 
	  per second).  

samplesPerSec;
		fréquence d'échantillonnage (en Hz)

BlockAlign (Bytes per sample)
		Block alignment, in bytes. The block alignment is the minimum atomic 
		unit of data. For PCM data, the block alignment is the number of 
		bytes used by a single sample, including data for both channels if 
		the data is stereo. For example, the block alignment for 16-bit 
		stereo PCM is 4 bytes (2 channels — 2 bytes per sample). 

dataSize
		Taille du paquet de données

channels
		nombre de canaux (mono =1, stereo =2)

 */

class CWaveFile
{

private:
	char *fileName;
	unsigned int waveFileSize;		// taille du fichier en octets
	unsigned int channels;
	unsigned int samplesPerSec;
	unsigned int avgBytesPerSec;
	unsigned short int BlockAlign;
	unsigned short int bitsPerSample;
	unsigned long int dataSize;
	unsigned char *data;
	int fact; // fact=0, pas de champs fact, sinon un champ fact

	int mid(unsigned char *in, int taille, int debut, int fin, char *out);
	unsigned int fileSize(FILE *stream);
	int verifWav(unsigned char WavHeader[58]);

public:

	// constructeurs & destructeurs
	CWaveFile();
	CWaveFile(const char *name);
	~CWaveFile();

	// accesseurs
	char *getFileName();
	unsigned int getFileSize();
	unsigned int getChannels();
	unsigned int getSamplesPerSec();
	unsigned int getAvgBytesPerSec();
	unsigned short int getBlockAlign();
	unsigned short int getBitsPerSample();
	unsigned long int getDataSize();
	unsigned char *getData();
	
	// mutateurs
	void setPath(const char *name);
	
	
	int loadWaveFile();
};

#endif

//=============================================================================
// Fin du fichier CWaveFile.h
//=============================================================================
