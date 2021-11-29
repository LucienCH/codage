#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure tableau stat
typedef struct
{
	char lettre;
	float bInf, bSup;
	int taille;
}STATISTIQ;


//fonction créant un tableau de stat
STATISTIQ *tabStat(char *message){

	int tailleMessage = strlen(message);
	STATISTIQ *stat = malloc(sizeof(STATISTIQ) * tailleMessage);
	int ASCII[128]; // Définition d'un tab de 128 représentant la table ascii
	int tailleTableauStatic = 0;

	for(int i = 0 ; i < ASCII ; i++)
		ASCII[i] = 0;

	for (int i = 0; i < tailleMessage ; i++ )
	{
		if( ASCII[ message[i] ] == 0 ){ tailleTableauStatic++; }
		ASCII[ message[i] ]++;
	}

	float bSup_precedente = 0.0;
	int indiceStatistique = 0; //

	for(int i = 0 ; i < tailleMessage ; i++)
	{
		int estPresent = 1;
		for(int j = 0 ; j < i ; j ++) if( stat[j].lettre == message[i] ) { estPresent = 0; }
		if(estPresent == 1)
		{
			stat[indiceStatistique].lettre =  message[i];
			stat[indiceStatistique].bInf = bSup_precedente;
			bSup_precedente = stat[indiceStatistique].bSup = stat[indiceStatistique].bInf + ( (float)ASCII[  message[i] ]/(float)tailleMessage );
			stat[indiceStatistique].size = tailleTableauStatic;
			indiceStatistique++;
		}
	}
	return stat;
}


//fonction pour rechercher des éléments dans le tab stat
STATISTIQ rechercher(char c , double valeur, STATISTIQ *stat)
{
	STATISTIQ stat;
	if ( valeur == -1)
	{
		for (int i = 0; i < stat[0].size ; i++)
		{
			if( stat[i].lettre == c )
			{
				stat.lettre = stat[i].lettre;
				stat.bInf = stat[i].bInf;
				stat.bSup = stat[i].bSup;
				stat.size = stat[i].size;
				break;
			}
		}

	}
	else
	{
		for (int i = 0; i < stat[0].size ; i++)
		{
			if( (valeur >= stat[i].bInf) && ( valeur < stat[i].bSup)  )
			{
				stat.lettre = stat[i].lettre; // Copie de la boucle for précédente
				stat.bInf = stat[i].bInf;
				stat.bSup = stat[i].bSup;
				stat.size = stat[i].size;
				break;
			}
		}
	}
	return stat;
}


//Fonction de codage, permettant au message d'être codé avec tab stat
float codage(char *message , STATISTIQ *statistique){
	int tailleMessage = strlen(message);
	STATISTIQ stat = rechercher(message[0], -1, statistique );
	float bInf = stat.bInf;
	float bSup = stat.bSup;

	for(int i = 1 ; i < tailleMessage ; i++)
	{
		stat = rechercher( message[i], -1, statistique );
		float tmp = bInf;
		bInf = bInf + ( bSup - bInf )* stat.bInf;
		bSup = tmp + ( bSup - tmp )* stat.bSup;
	}
	return bInf;
}

//fonction de décodage du message et de tab stat
char *decodage(int tailleMessage,double code, STATISTIQ *statistique){
	char *message = malloc(sizeof(char) * (tailleMessage+1) );
	if(!message){ exit(1); }

	for(int i = 0 ; i < tailleMessage ; i++)
	{
		STATISTIQ valeur_bis = rechercher(' ', code, statistique);
		message[i] = valeur_bis.lettre;
		code = (code - valeur_bis.bInf) / ( valeur_bis.bSup - valeur_bis.bInf );
	}
	return message;
}

//fonction d'affichage
void dispStat(STATISTIQ *stat)
{
	for (int i = 0; i < stat[0].size ; i++) {
		printf("==========================DISPLAY============================\n DISP: Valeur \"%c\" borneInf = %f , borneSup = %f\n=============================================================\n",stat[i].lettre , stat[i].bInf , stat[i].bSup);
	}
}


int main()
{
	char *message = "Codage";
	STATISTIQ *stats = 
}