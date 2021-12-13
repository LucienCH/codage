#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "desetalement.h"
#include "hadamard.h"

char * desetaler_un_message(char * recu, char * sequence_etalement, int taille_recu, int taille_sequence, char * message) {
	char inter[taille_recu];
	int i, j;
	
	for(i = 0; i < taille_recu; i++)
	{
		inter[i] = recu[i] * sequence_etalement[i % taille_sequence];
	}
	
	int taille_message = taille_recu / taille_sequence;
	char somme;
	
	for(i = 0; i < taille_message; i++)
	{
		somme = 0;
		
		for(j = 0; j < taille_sequence; j++)
		{
			somme += inter[i * taille_sequence + j];
		}
		
		message[i] = somme / taille_sequence;
	}
	return message;
}

int desetaler(char * recu, int taille_recu, char ** matrice_hadamard,int taille_matrice, char ** messages) {
	int i, j = 0;
	
	for(i = 0; i < taille_matrice; i++)
	{
		desetaler_un_message(recu, matrice_hadamard[i], taille_recu, taille_matrice, messages[j]);
		if(messages[j][0])
		{
			j++;
		}
	}
	return j;
}
