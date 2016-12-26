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
 * 23/02/2003 : première version
 *
 *=============================================================================
 */

#ifndef ERROR_H
#define ERROR_H

// Erreurs sur le format WAVE
#define WAV_CANT_OPEN		1		// Impossible d'ouvrir le fichier
#define WAV_CANT_READ_HDR	2		// Problème lors de la lecture de l'entête
#define WAV_CANT_READ_DATA	3		// Problème lors de la lecture des données
#define WAV_NO_RIFF			101		// Format de fichier inconnu : pas de type RIFF
#define WAV_BAD_FILESIZE	102		// En-tête corrompu : mauvaise taille du fichier
#define WAV_NO_WAVE			103		// Format de fichier inconnu : pas de type WAVE
#define WAV_NO_SUPPORT		104		// Type de fichier WAVE inconnu ou non supporté
#define WAV_NO_COMPRESSION	105		// Fichiers WAVE compressés non supportés
#define WAV_NO_STEREO		110		// Fichiers WAVE stéréos non supportés
#define WAV_BAD_CHANNELS	106		// En-tête corrompu : mauvaise indication des cannaux
#define WAV_NO_BLOCKALIGN	107		// Mauvaise indication d'octets par échantillons
#define WAV_BAD_BITS		108		// Mauvaise indication de bits par échantillons
#define WAV_NO_DATA			109		// Format de fichier inconnu : impossible de trouver la zone de données
#define WAV_BAD_PARAMETERS	142		// Erreur dans l'appel de la méthode CWaveFile::mid()


#endif

//=============================================================================
// Fin du fichier error.h
//=============================================================================