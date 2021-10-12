#ifndef _HADAMARD_H
#define _HADAMARD_H

// Verifie le nombre utilisateur
int NombreUtilisateurs();

// Calcule le nombre détapes 
int NombreEtapes(int nombreUtilisateur);

// genere la matrice d'hadamard
int** CreerMatrice(int nbUser, int* taille_mat);

void afficher_matrice(int taille, int** matrice_Hadamard);


#endif