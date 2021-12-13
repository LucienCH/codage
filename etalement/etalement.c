#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "etalement.h"
#include "message.h"
#include "hadamard.h"


char * etaler_un_message(char * message,
						 char * sequence_etalement,
						 int taille_message,
						 int taille_sequence,
						 char * message_etale) {
	int i, j;
	for(i = 0; i < taille_message; i++) {
		for(j = 0; j < taille_sequence; j++) {
			message_etale[i * taille_sequence + j] = message[i] *
				sequence_etalement[j];
		}
	}
	return message_etale;
}

char * etaler(char ** messages,
			  int nb_messages,
			  int taille_message,
			  char ** matrice_hadamard,
			  int taille_matrice,
			  char * etalement) {
	if(nb_messages > taille_matrice) {
		fprintf(stderr,
				"Le nombre de messages (%d) est supérieur aux nombre d'utilisateurs supporté (%d).",
				nb_messages,
				taille_matrice);
		return NULL;
	}
	// Intervalle entre deux séquences choisies de matrice_hadamard
	int intervalle = taille_matrice / nb_messages;
	char resultats[nb_messages][taille_message * taille_matrice];
	int i, j;
	for(i = 0; i < nb_messages; i++) {
		etaler_un_message(messages[i], matrice_hadamard[i * intervalle],
						  taille_message, taille_matrice, resultats[i]);
	}
	for(i = 0; i < taille_message * taille_matrice; i++) {
		etalement[i] = 0;
		for(j = 0; j < nb_messages; j++)
			etalement[i] += resultats[j][i];
	}
	return etalement;
}

void afficher_etalement(char * etalement,
						int taille_message,
						int taille_sequence) {
	int i;
	for(i = 0; i < taille_message; i++) {
		afficher_message(etalement + i * taille_sequence, taille_sequence);
		if( i < taille_message - 1)
			printf(" ||");
	}
}
