#ifndef __DESETALEMENT_H__
#define __DESETALEMENT_H__

#include "etalement.h"



/*
 * Désétale le message reçu recu de taille : taille_recu, à l'aide de la séquence 
 * sequence_etalement de taille taille_sequence et inscrit le résultat dans le
 * tableau message de taille (taille_recu / taille_sequence).
 * La place nécessaire au tableau mémoire doit être allouée en mémoire.
 */
char * desetaler_un_message(char * recu, char * sequence_etalement, int taille_recu, int taille_sequence, char * message);

/*
 * Désétale le message reçu recu de taille taille_recu à l'aide de la matrice 
 * matrice_hadamard de taille taille_matrice * taille_matrice et écrit le
 * résultat dans messages, un tableau de taille_matrice * (taille_recu /
 * taille_matrice).
 * La place nécessaire au tableau message devra être allouée en mémoire.
 * Retourne le nombre de messages désétalés.
 */
int desetaler(char * recu, int taille_recu, char ** matrice_hadamard, int taille_matrice, char ** messages);


#endif
