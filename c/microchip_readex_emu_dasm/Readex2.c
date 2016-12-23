#include <stdio.h>
#include <string.h>
#include <math.h>
#include "readex.h"

int main(int args, char** argv)
{
	FILE *fp, *out;
	char filename[20];
	char *fichier;
	bool ret;
	int i;
	long int taille;
	char *ans;
	
	if(args!=2)
	{
		printf("La syntaxe de la commande est incorrecte.\n%s",usage);
		return 1;
	}
	
	
	// Quelques initialisations
	for(i=0;i<1024;i++)
	{
		pic.flash[i][0]=63;
		pic.flash[i][1]=255;
	}
	
	strcpy(filename, argv[1]);
	
	printf("Ouverture du fichier %s\n",filename);
	fp = fopen(filename,"r");
	if(!fp)
	{
		printf("Impossible d'ouvrir le fichier %s\n",filename);
		return 1;
	}
		
	/* On range tout le fichier dans un tableau */
	
	taille = filesize(fp);
	if(taille<=11)
	{
		// Le fichier doit au moins contenir la ligne de fin de fichier
		printf("Le contenu du fichier est trop faible.\n");
		return 1;	
	}

	printf("taille fichier : %ld octet(s)\n",taille);
	
	fichier = (char *) calloc( taille,sizeof(char));

	if (fichier == NULL)
	{
       printf("Pas assez de memoire pour charger le fichier.\n");
       return 1;
    }

	fread(fichier, sizeof(unsigned char), taille, fp);
	
	fclose(fp);
	
	taille = strlen(fichier); /* On remet la taille à jour, qui peut être fausse dans certains cas */
	
	printf("Fichier ouvert\nValidation du format Intel...\n");
	ret = verifIntel(fichier,taille);
	if(ret==true)
	{
		printf("Fichier valide\n");
		out=fopen("out.txt","w");
	
		fprintf(out, "Espace mémoire :\n");
		fprintf(out, "---------------------------\n");
		fprintf(out, "Adresse\tDonnee\tCode asm\n");
		
		for(i=0;i<1024;i++)
		{
			fprintf(out, "%d\t",i);
			
			fprintf(out, "%2.2X",pic.flash[i][0]);
			fprintf(out, "%2.2X",pic.flash[i][1]);
			
			ans = (char *)malloc(20*sizeof(char));
			ans = dasm(pic.flash[i][0],pic.flash[i][1]);
			
			fprintf(out, "\t%s\n",ans);
				
		}
		fclose(out);
	}
	else
		printf("Fichier non valide\n");
	
	
	free(fichier);
	return 0;
}

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
		if((code & HexToInt(opcodes[i][0],4))==HexToInt(opcodes[i][1],4))
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
	
	// ensuite, on recherche et on construit l'opérande
	if(HexToInt(opcodes[codeOk][3],1)==1)
	{
		
	}
	else	if(HexToInt(opcodes[codeOk][3],1)==2)
			{
		
			}
			else	if(HexToInt(opcodes[codeOk][3],1)==3)
					{
						
						
					}
					else	if(HexToInt(opcodes[codeOk][3],1)==4)
							{
								strcat(asmcode,"0x");
								itoa(code & 0x7FF,buffer,16);
								strcat(asmcode, buffer);
							}
							else
							{
								
								
							}
	return asmcode;
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
      		printf("%s",p);
      		ret = verifLigne(p);
      		if(ret==true)
				printf(" --> ligne valide\n");
			else
			{
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
	
	dataBits = mid(ligne,1,2);
	offset = mid(ligne,3,6);
	dataType = mid(ligne,7,8);
	checksum = mid(ligne,taille-2,taille-1);
	
	_databits = HexToInt(dataBits,2);

	// On teste ici la longueur des données
	if(!(_databits==(taille-11)/2))
		return false;
	
	// On fait la somme des octets de toute la ligne (hormis le checksum et les deux points
	for(i=1;i<=taille-4;i=i+2)
		somme += HexToInt(mid(ligne,i,i+1),2);
	
	// On teste le checksum...
	if(HexToInt(checksum,2)!=CalculateChecksum(somme))
		return false;
	
	// A partir de maintenant, la ligne est bonne on stocke les données à l'adresse voulue
	
	
	if(HexToInt(dataType,2)!=0)
		return true;
	
	
	j=0;
	deb = HexToInt(offset,4)/2;
	fin = deb+(_databits)/2-1;
	for(i=deb;i<=fin;i++)
	{
		var = mid(ligne,9+j,10+j);
		pic.flash[i][1] = HexToInt(var,2);
		var = mid(ligne,11+j,12+j);
		pic.flash[i][0] = HexToInt(var,2);
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


/**
 * Retourne une partie d'une chaine délimitée par deux positions
 */
char *mid(char *chaine, int debut, int fin)
{
	int taille;
	char *buf;
	int i;
	
	taille = fin-debut+1;
	
	if(taille<=0 || taille>=strlen(chaine))
	{
		printf("\nAppel non valide.\n");
		return NULL;
	}
	
	buf = (char *)calloc(taille+1,sizeof(char));
	
	for(i=0;i<taille;i++)
		buf[i] = chaine[debut+i];
	buf[taille]='\0';	// on termine la chaine de caractères
	return buf;
}

/**
 * Convertit une chaine de caractères hexadécimaux en valeur entière
 */
unsigned long int HexToInt(char *string)
{
	int i,j;
	unsigned long int val=0;
	char a;
	
	j = strlen(string)-1;
	for(i=0;i<strlen(string);i++)
	{
		a = asciiToHex(string[i]);
		val = val + a*pow(16,j);
		j--;
	}

	return val;
}

/**
 * Convertit un caractère ASCII en valeur hexadécimale
 */
char asciiToHex(char c)
{
	if(c<58 && c >47)
		return c-48;
	else if(c<71 && c>64)
			return c-55;
		else if(c<103 && c>96)
				return c-87;
			else
				return 0;
}


/**
 * Retourne la taille du fichier en octets
 */
long filesize(FILE *stream)
{
	long curpos,length;

	curpos = ftell(stream); /* garder la position courante */
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek (stream, curpos, SEEK_SET); /* restituer la position */
	
	return length;
}
