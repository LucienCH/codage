#include <stdio.h>
#include <stdlib.h>

#define POSITIF 1					// Mise en place de ces définitions pour une meilleure
#define NEGATIF -1					// lisibilité dans le programme
#define NUL 0

#define DERNIER_VIOL NEGATIF		// à changer en fonction de la situation initiale
#define DERNIER_VOLT NEGATIF
#define TAILLE_MESSAGE 30


// Fonction de codage HDBN prenant en paramètre la valeur de l'HDBN, le message à coder, la taille du message ainsi que l'état des derniers volts et viols
int *codeur(int valeurN, int message[], int tailleDuMessage, int *volt, int *viol)
{
	int nbZeros = 0;
	int *tmpMessage = malloc(sizeof(int) * tailleDuMessage);
	if(!tmpMessage)					// On test si la création à bien été effectuée
	{
		exit(1);
	}
	
	for(int i = 0; i < tailleDuMessage; i++)
	{
		tmpMessage[i] = 0;		// On initialise la valeur initiale à NULL du tableau
		if(message[i] != 0)			// dans lequel on écrit le message codé
		{
			nbZeros = 0;			// On tombe sur 1, le total de 0 est reinitialisé
			if(*volt == POSITIF)
			{
				tmpMessage[i] = *volt = NEGATIF;
			}
			else
			{
				tmpMessage[i] = *volt = POSITIF;
			}
		}
		else
		{
			nbZeros++;
			if(nbZeros == valeurN)	// Le nombe de 0 à atteint la limite du HDBN
			{
				if(*viol == POSITIF)
				{
					if(*volt == POSITIF)
					{
						tmpMessage[i - valeurN + 1] = NEGATIF;
					}
					tmpMessage[i] = NEGATIF;
					*viol = NEGATIF;
					*volt = NEGATIF;
				}
				else
				{
					if(*volt == NEGATIF)
					{
						tmpMessage[i - valeurN + 1] = POSITIF;
					}
					tmpMessage[i] = POSITIF;
					*viol = POSITIF;
					*volt = POSITIF;
				}
				nbZeros = 0;	// On reinitialise le nombre de zéros
			}	
		}
	}
	return tmpMessage;
	free(tmpMessage);
}

int *decodeur(int ValeurN, int MessageCoD[], int tailleDuMessage)
{
	int *tmpMessage = malloc(sizeof(int) * tailleDuMessage);
	int nbZeros = 0;
	
	
	printf("En cours de création ...");
	return tmpMessage;
}

int main()
{
	int volt = DERNIER_VOLT;
	int viol = DERNIER_VIOL;
	int message[TAILLE_MESSAGE] = {1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0};
	
	int *messageCoD = codeur(2, message, TAILLE_MESSAGE, &volt, &viol);
	for(int i = 0; i < TAILLE_MESSAGE; i++)
	{
		printf("%d ", messageCoD[i]);
	}
}