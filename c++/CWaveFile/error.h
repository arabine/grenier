/*=============================================================================
 * error.h 1.0
 *=============================================================================
 * Liste des messages d'erreurs
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 23/02/2003 : premi�re version
 *
 *=============================================================================
 */

#ifndef ERROR_H
#define ERROR_H

// Erreurs sur le format WAVE
#define WAV_CANT_OPEN		1		// Impossible d'ouvrir le fichier
#define WAV_CANT_READ_HDR	2		// Probl�me lors de la lecture de l'ent�te
#define WAV_CANT_READ_DATA	3		// Probl�me lors de la lecture des donn�es
#define WAV_NO_RIFF			101		// Format de fichier inconnu : pas de type RIFF
#define WAV_BAD_FILESIZE	102		// En-t�te corrompu : mauvaise taille du fichier
#define WAV_NO_WAVE			103		// Format de fichier inconnu : pas de type WAVE
#define WAV_NO_SUPPORT		104		// Type de fichier WAVE inconnu ou non support�
#define WAV_NO_COMPRESSION	105		// Fichiers WAVE compress�s non support�s
#define WAV_NO_STEREO		110		// Fichiers WAVE st�r�os non support�s
#define WAV_BAD_CHANNELS	106		// En-t�te corrompu : mauvaise indication des cannaux
#define WAV_NO_BLOCKALIGN	107		// Mauvaise indication d'octets par �chantillons
#define WAV_BAD_BITS		108		// Mauvaise indication de bits par �chantillons
#define WAV_NO_DATA			109		// Format de fichier inconnu : impossible de trouver la zone de donn�es
#define WAV_BAD_PARAMETERS	142		// Erreur dans l'appel de la m�thode CWaveFile::mid()


#endif

//=============================================================================
// Fin du fichier error.h
//=============================================================================