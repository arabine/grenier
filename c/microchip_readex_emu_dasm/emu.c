#include <stdio.h>
#include <string.h>
#include "readex.h"
#include "emu.h"

void affEmu(void)
{
	// on construit la console :
	printf("Lancement de la console. Tapez help pour afficher l'aide.\n");
	console();
}

void console(void)
{
	int ret;
	char *cmd;
	do
	{
		printf("\n>");
		scanf("%s",cmd);
		ret = traitement(cmd);
	}
	while(ret);
}

/*

idées :

commandes dispos 
lister le source désassemblé, tout ou une partie
mettre des points d'arrêts
lister le sfr
lister un octet précis dans la RAM

*/


int traitement(char *cmd)
{
	int ret,i;
	if(!strcmp(cmd,"help"))
	{
		printf("Commades valides :\n");
		printf("\thelp\taffiche l'aide\n");
		printf("\tquit\tquitte le programme\n");
		printf("\tgo\texécute le programme\n");
		printf("\tsfr\taffiche le contenu du SFR\n");
		ret = 1;
	}
	else if(!strcmp(cmd,"quit"))
		{
			ret = 0;	
		}
		else if(!strcmp(cmd,"sfr"))
			{
				ret = 1;
			}
			else
			{
				printf("%s : commande non reconnue, tapez help pour affichez l'aide",cmd);
				ret = 1;
			}
	return ret;
}

void razPic(void)
{
	int i;
	// Quelques initialisations
	for(i=0;i<1024;i++)
	{
		pic.flash[i][0]=63;
		pic.flash[i][1]=255;
	}	

	for(i=0;i<256;i++)
		pic.filereg[i]=0;
	
}
