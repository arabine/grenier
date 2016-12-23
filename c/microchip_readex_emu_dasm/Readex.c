#include <stdio.h>
#include <string.h>

#include "readex.h"

int mode;
struct proc pic;

/* masque, opcode , code assembleur, type de code

type 1 : byte-oriented file register operations b 1 bit, f 7 bits
type 2 : byte-oriented file register operations b 3 bit, f 7 bits
type 3 : une seule opérande de 8 bits
type 4 : goto et call seulement
type 5 : une seule opérande de 7 bits
type 6 : pas d'opérande

*/
unsigned char *opcodes[35][4]={
							 {"3F00","0700","addwf","1"},
							 {"3F00","0500","andwf","1"},
							 {"3F80","0180","clrf","5"},
							 {"3F80","0100","clrw","6"},
							 {"3F00","0900","comf","1"},
							 {"3F00","0300","decf","1"},
							 {"3F00","0B00","decfsz","1"},
							 {"3F00","0A00","incf","1"},
							 {"3F00","0F00","incfsz","1"},
							 {"3F00","0400","iorwf","1"},
							 {"3F00","0800","movf","1"},
							 {"3F80","0080","movwf","5"},
							 {"3F9F","0000","nop","6"},
							 {"3F00","0D00","rlf","1"},
							 {"3F00","0C00","rrf","1"},
							 {"3F00","0200","subwf","1"},
							 {"3F00","0E00","swapf","1"},
							 {"3F00","0600","xorwf","1"},
							 {"3C00","1000","bcf","2"},
							 {"3C00","1400","bsf","2"},
							 {"3C00","1800","btfsc","2"},
							 {"3C00","1C00","btfss","2"},
							 {"3E00","3E00","addlw","3"},
							 {"3F00","3900","andlw","3"},
							 {"3800","2000","call","4"},
							 {"3FFF","0064","clrwdt","6"},
							 {"3800","2800","goto","4"},
							 {"3F00","3800","iorlw","3"},
							 {"3C00","3000","movlw","3"},
							 {"3FFF","0009","retfie","6"},
							 {"3C00","3400","retlw","3"},
							 {"3FFF","0008","return","6"},
							 {"3FFF","0066","sleep","6"},
							 {"3E00","3C00","sublw","3"},
							 {"3F00","3A00","xorlw","3"}
							};



int main(int args, char** argv)
{
	FILE *fp;
	char filename[20];
	char opt[3];
	char *fichier;
	bool ret;
	long int taille;
	
	strcpy(opt, argv[1]);
	strcpy(filename, argv[2]);
	
	if(args!=3)
	{
		usage();
		return 1;
	}
	else switch(opt[0])
		{
			case '-':
				switch(opt[1])
				{
					case 'd':
						if(opt[2]=='\0')
							mode=0;
						else
						{
							usage();
							return 1;
						}
						break;
					case 'e':
						if(opt[2]=='\0')
							mode=1;
						else
						{
							usage();
							return 1;
						}
						break;
					default:
						usage();
						return 1;
				}
				break;
			default:
				usage();
				return 1;
		}

	razPic();
	
	printf("Ouverture du fichier %s\n",filename);
	fp = fopen(filename,"r");
	if(!fp)
	{
		printf("Impossible d'ouvrir le fichier %s. Vérifiez qu'il se trouve dans le même répertoire.\n",filename);
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
	free(fichier);
	
	if(ret==true)
	{
		printf("Fichier valide\n");
		if(mode==0)
			affDasm();
		else
			affEmu();
	}
	else
		printf("Fichier non valide\n");
	
	return 0;
}

void usage(void)
{
	printf("La syntaxe de la commande est incorrecte.\nUsage :\n\tReadex.exe [mode] fichier.hex\n");
	printf("[mode] peut etre :\n");
	printf("\t-d\t\tdesassemblage seulement\n");
	printf("\t-e\t\temulation\n");	
}

void affDasm(void)
{
	FILE *out;
	char *ans;
	int i;
	
	out=fopen("out.txt","w");
	if(!out)
	{
		printf("Impossible de générer le fichier de sortie.\n");
		exit(1);
	}
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
