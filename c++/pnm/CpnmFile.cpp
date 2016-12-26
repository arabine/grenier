/*=============================================================================
 * CpnmFile 1.0 - CpxmFile.cpp
 *=============================================================================
 * Classe C++ de lecture/écriture de fichiers PGM PPM et PBM
 *=============================================================================
 * (c) Anthony RABINE - 2003
 * arabine@programmationworld.com
 * http://www.programmationworld.com
 * Environment : VC++ 6.0
 *  
 * Historique :
 * 
 * 08/03/2003 : première version
 *
 *=============================================================================
 */

#include "CpnmFile.h"

/*****************************************************************************/
CpnmFile::CpnmFile(int magicNumber, int width, int hight, unsigned int levelMax, unsigned char niveauInit)
{
	type = magicNumber;
	w = width;
	h = hight;
	levels = levelMax;
	
	if(type==3 || type==6)
		pixel = new unsigned char[3*w*h];
	else if(type==1 || type==2 || type==4 || type==5)
			pixel = new unsigned char[w*h];
		 else
		 {
			type = 5;
			pixel = new unsigned char[w*h];
		 }

	clearImage(niveauInit);

}
/*****************************************************************************/
CpnmFile::~CpnmFile()
{
	delete pixel;
}
/*****************************************************************************/
/**
 *	Affecter à l'image un niveau constant
 */
void CpnmFile::clearImage(unsigned char niveau)
{
	int l,c;

	for (l=0;l<h;l++)
		for (c=0;c<w;c++)
			pixel[l*w+c]=niveau;
}
/*****************************************************************************/
void CpnmFile::setPixel(int x,int y,unsigned char couleur)
{
	pixel[y*w+x] = couleur;
}
/*****************************************************************************/
unsigned char CpnmFile::getPixel(int x,int y)
{
	unsigned char couleur;

	couleur = pixel[y*w+x];
	return couleur;
}

//=============================================================================
// Fin du fichier CpnmFile.cpp
//=============================================================================
