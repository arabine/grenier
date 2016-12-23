#include <stdio.h>
#include <string.h>

#include "readex.h"
#include "dasm.h"

/**
 * Renvoie le code assembleur du codeop passé en paramètre
 */
char *dasm(unsigned char high, unsigned char low)
{
	unsigned short int code, temp=0;
	int i;
	bool ok=false;
	int codeOk;
	char *asmcode;
	char buffer[10];
	
	asmcode = (char *)calloc(20,sizeof(char));
	temp = (unsigned short int)high;
	temp=temp<<8;
	code = temp + low;

	// On scan les 35 codes op pour trouver le bon
	for(i=0;i<35;i++)
	{
		if((code & HexToInt(opcodes[i][0]))==HexToInt(opcodes[i][1]))
		{
			ok = true;
			codeOk = i;
		}
	}
	
	// code non trouvé, il y a une erreur quelque part...
	if(!ok)
		return "**OPCODE ERROR**";
	
	strcat(asmcode,opcodes[codeOk][2]);
	strcat(asmcode,"\t");
	
	// ensuite, on recherche et on construit les opérandes
	if(HexToInt(opcodes[codeOk][3])==1)
	{
		strcat(asmcode,"0x");
		itoa(code & 0x7F,buffer,16);
		strcat(asmcode,buffer);
		strcat(asmcode,",0x");
		itoa((code & 0x80)>>7,buffer,16);
		strcat(asmcode, buffer);
	}
	else	if(HexToInt(opcodes[codeOk][3])==2)
			{
				strcat(asmcode,"0x");
				itoa(code & 0x7F,buffer,16);
				strcat(asmcode,buffer);
				strcat(asmcode,",0x");
				itoa((code & 0x380)>>7,buffer,16);
				strcat(asmcode, buffer);
			}
			else	if(HexToInt(opcodes[codeOk][3])==3)
					{
						strcat(asmcode,"0x");
						itoa(code & 0xFF,buffer,16);
						strcat(asmcode, buffer);
					}
					else	if(HexToInt(opcodes[codeOk][3])==4)
							{
								strcat(asmcode,"0x");
								itoa(code & 0x7FF,buffer,16);
								strcat(asmcode, buffer);
							}
							else	if(HexToInt(opcodes[codeOk][3])==5)
									{
										strcat(asmcode,"0x");
										itoa(code & 0x7F,buffer,16);
										strcat(asmcode, buffer);
									}
	return asmcode; // si 6 = pas d'opérandes ! on retourne donc le mnémonique sans opérandes
}


/**
 * Renvoie true si le fichier est valide, false autrement
 */
bool verifIntel(char *fichier, long int taille)
{
	char *file;
	char *separateurs = SEPARATEUR;
	char *p;
	bool ret,isEndfile=false;
	
	file = (char *)calloc(taille,sizeof(char));
	
	strcpy(file,fichier);

	/* on va maintenant découper par lignes */
	
	//premier appel, renvoie la première ligne
    p = strtok(file, separateurs);
    do
    {
      	if(strcmp(p,":00000001FF"))
      	{
      		if(mode==0)
      			printf("%s",p);
      		ret = verifLigne(p);
      		if(ret==true)
      		{
      			if(mode==0)
					printf(" --> ligne valide\n");
			}
			else
			{
				if(mode==0)
					printf(" --> ligne fausse\n");
				return false;
			}
      	}
      	else
			isEndfile = true;
    }
    while((p = strtok(NULL, separateurs))!= NULL);

	if(isEndfile)
		return true;
	else
	{
		if(mode==0)
			printf("Pas d'indication de fin de fichier\n");
		return false;
	}
}

/**
 * Valide une ligne
 */
bool verifLigne(char *ligne)
{
	int taille,i,j,k;
	unsigned long int _databits;
	unsigned int somme=0;
	char *dataBits, *offset, *dataType, *checksum;
	char *var;
	int deb,fin;
	// Première vérification, et la plus simple, on regarde si
	// la ligne commence par un deux points
	if(ligne[0]!=':')
		return false;
	
	// On enregistre les éléments de la ligne pour les vérifier
	
	taille = strlen(ligne);
	
	// On réserve les espaces mémoires
	dataBits = (char *)malloc(2*sizeof(char));
	offset = (char *)malloc(4*sizeof(char));
	dataType = (char *)malloc(2*sizeof(char));
	checksum = (char *)malloc(2*sizeof(char));
	
	dataBits = mid(ligne,1,2);
	offset = mid(ligne,3,6);
	dataType = mid(ligne,7,8);
	checksum = mid(ligne,taille-2,taille-1);
	
	_databits = HexToInt(dataBits);

	// On teste ici la longueur des données
	if(!(_databits==(taille-11)/2))
		return false;

	// On fait la somme des octets de toute la ligne (hormis le checksum et les deux points
	for(i=1;i<=taille-4;i=i+2)
		somme += HexToInt(mid(ligne,i,i+1));
	
	// On teste le checksum...
	if(HexToInt(checksum)!=CalculateChecksum(somme))
		return false;
	
	// A partir de maintenant, la ligne est bonne on stocke les données à l'adresse voulue
		
	if(HexToInt(dataType)!=0)
		return true;
	
	
	j=0;
	deb = HexToInt(offset)/2;
	fin = deb+(_databits)/2-1;
	for(i=deb;i<=fin;i++)
	{
		var = mid(ligne,9+j,10+j);
		pic.flash[i][1] = HexToInt(var);
		var = mid(ligne,11+j,12+j);
		pic.flash[i][0] = HexToInt(var);
		j=j+4;
	}
	return true;
}

/**
 * Retourne le checksum d'une valeur passée en paramètre
 */
unsigned char CalculateChecksum(int val)
{
	// On transforme en binaire et on garde les 8 premiers bits
	int temp=val;
	if(temp>=256)
	{
		while(temp>=256)
			temp -= 256;
	}
	return (256-temp);
}
