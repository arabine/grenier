#include "utils.h"

struct WavInfos
{
//	unsigned char *wav_name;
	unsigned int wav_size;				// taille du fichier (en octets)
	unsigned int header_size;			// talle du fichier - 8 octets
	unsigned char wav_channels;			// nombre de canaux (mono =1, stereo =2)
	unsigned int wav_freq;				// fréquence d'échantillonnage (en Hz)
	unsigned int bytes_per_sec;
	unsigned short bytes_per_sample;	
	unsigned short bits_per_sample;
	unsigned int data_size;				// taille des données (en octets)

} MyWave;


// retour :
// 0 : fichier wav valide
// sinon : fichier wav non valide : code de retour
int verifWav(unsigned char WavHeader[44])
{
	int ret=0;
	unsigned char buff[44];
	unsigned int val;
	
	// on teste le format
	if(mid(WavHeader,44,0,3,buff))
		return 42;
	if(strcmp(buff,"RIFF"))
		return 1;

	// on teste la taille du fichier
	val = WavHeader[4]+WavHeader[5]*256+WavHeader[6]*65536+WavHeader[7]*16777216;
	if(val+8!=MyWave.wav_size)
		return 2;

	// on teste le format
	if(mid(WavHeader,44,8,15,buff))
		return 42;
	if(strcmp(buff,"WAVEfmt "))
		return 3;
	
	// nombre d'octets pour décrire le format, toujours 16
	val = WavHeader[16]+WavHeader[17]*256+WavHeader[18]*65536+WavHeader[19]*16777216;
	if(val!=16)
		return 4;

	// on ne gère que le PCM non compressé
	val = WavHeader[20]+WavHeader[21]*256;
	if(val!=1)
		return 5;

	// canaux : mono = 1, stereo = 2
	val = WavHeader[22]+WavHeader[23]*256;
	if(val==1)
		MyWave.wav_channels = 1;
	else	if(val==2)
				MyWave.wav_channels = 2;
			else
				return 6;

	// fréquence d'échantillonnage
	MyWave.wav_freq = WavHeader[24]+WavHeader[25]*256+WavHeader[26]*65536+WavHeader[27]*16777216;

	// nombre d'octets par seconde (== fréquence d'échantillonnage si mono)
	MyWave.bytes_per_sec = WavHeader[28]+WavHeader[29]*256+WavHeader[30]*65536+WavHeader[31]*16777216;

	
	// octets par échantillon : 1=8 bit Mono, 2=8 bit Stereo or 16 bit Mono, 4=16 bit Stereo
	val = WavHeader[32]+WavHeader[33]*256;
	if(val==1)
		MyWave.bytes_per_sample = 1;
	else	if(val==2)
				MyWave.bytes_per_sample = 2;
			else	if(val==4)
						MyWave.bytes_per_sample = 4;
					else
						return 7;
	
	// bits par échantillon : 8, 12 ou 16
	val = WavHeader[34]+WavHeader[35]*256;
	if(val==8)
		MyWave.bits_per_sample = 8;
	else	if(val==12)
				MyWave.bits_per_sample = 12;
			else	if(val==16)
						MyWave.bits_per_sample = 16;
					else
						return 8;
	
	// On commence la zone de données proprement dite

	// on teste l'existance du label
	if(mid(WavHeader,44,36,39,buff))
		return 42;
	
	if(strcmp(buff,"data"))
		return 9;

	// taille des données
	MyWave.data_size = WavHeader[40]+WavHeader[41]*256+WavHeader[42]*65536+WavHeader[43]*16777216;


	return 0;
}


void WavAffiche()
{
	printf("\nTaille du fichier : %d octets",MyWave.wav_size);
	
	if(MyWave.wav_channels ==1)
	{
		if(MyWave.bytes_per_sample==1)
			printf("\n8 bit Mono");
		else
			printf("\n16 bit Mono");
	}
	else
	{
		if(MyWave.bytes_per_sample==2)
			printf("\n8 bit Stereo");
		else
			printf("\n16 bit Stereo");
	}

	printf("\nFrequence d'echantillonnage : %d Hz",MyWave.wav_freq);
	printf("\nFrequence moyenne : %d octets/seconde",MyWave.bytes_per_sec);
	printf("\nResolution : %d bits", MyWave.bits_per_sample);
	printf("\nTaille des donnees : %d octets\n", MyWave.data_size);
}

int main(void)
{
	unsigned char WavHeader[44];
	FILE *fp;
	int numread, ret;
	unsigned char *wav_data;

	fp = fopen("piano.wav","r");
	if(fp==NULL)
	{
		printf("Impossible d'ouvrir le fichier.\n");
		return 0;
	}
	MyWave.wav_size = filesize(fp);

	numread = fread(WavHeader, sizeof(unsigned char), 44, fp);

	if(numread!=44)
	{
		printf("Probleme de lecture du fichier.\n");
		fclose(fp);
		return 0;
	}

	if(ret=verifWav(WavHeader))
	{
		printf("\nFichier .wav non valide.\nCode retour : %d\n",ret);
		fclose(fp);
		return 0;
	}
	else
		printf("\nFichier .wav valide.\n");

	WavAffiche();

	// le fichier est maintenant valide, on va capturer les données
	wav_data = (unsigned char *) calloc(MyWave.data_size, sizeof(unsigned char));

	numread = fread(wav_data, sizeof(unsigned char), MyWave.data_size, fp);

	free(wav_data);
	fclose(fp);
	return 0;
}

