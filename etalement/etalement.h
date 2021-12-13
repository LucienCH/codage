#ifndef __ETALEMENT_H__
#define __ETALEMENT_H__

/*
 * Étale le message message de taille taille_message grâce à la séquence
 * sequence_etalement de taille taille_sequence et écrit le message étalé de 
 * taille taille_message * taille_sequence dans message_etale (la place
 * nécessaire devra être allouée).
 * 
 * Chaque octet de message, sequence_etalement et de message_etale représente la
 * valeur d'un bit.
 */
char * etaler_un_message(char * message,
						 char * sequence_etalement,
						 int taille_message,
						 int taille_sequence,
						 char * message_etale);



/*
 * Étale les nb_messages messages de taille taille_message du tableau messages
 * à l'aide de la matrice matrice_hadamard de taille taille_matrice *
 * taille_matrice et écrit le résultat dans le tableau etalement de taille
 * taille_message * taille_sequence.
 * 
 * Chaque octet de messages et matrice_hadamard représente un bit.
 * 
 * Le nombre de messages doit être inférieur ou égal à la taille de la matrice.
 * 
 * Les séqences d'étalement sont choisies en partant de matrice_hadamard[0] et
 * en ajoutant à l'indice le résultat de taille_matrice / nb_messages.
 * 
 * Exemple pour taille_matrice = 8 et nb_messages = 3 :
 * taille_matrice / nb_messages = 2 => les séquences 0, 2 et 4 sont choisies.
 */
char * etaler(char ** messages,
			  int nb_messages,
			  int taille_message,
			  char ** matrice_hadamard,
			  int taille_matrice,
			  char * etalement);


/*
 * Affiche l'étalement du message de longueur taille_message par la séquence de
 * taille taille_sequence en marquant la séparation entre les différents bits.
 */
void afficher_etalement(char * etalement,
						int taille_message,
						int taille_sequence);



#endif // __ETALEMENT_H__
