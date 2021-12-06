#ifndef _HADAMARD_H
#define _HADAMARD_H

// -- Verification du nombre d'utilisateur compris entre 1 et 16 -- 
int NombreUtilisateurs();

// -- retourne le nombre d'étape --
int NombreEtapes(int nombreUtilisateurs);

// -- Permet d'allouer l'espace mémoire à la matrice -- 
int ** CreerMatrice(int nbUser);

// -- Permet d'afficher la matrice donnée en paramètre -- 
int AfficherMatrice(int ** mat, int tailleMat);

// -- Permet d'appliquer l'algo d'Hadammar --
int HadaMatrice(int ** mat, int nbUser);

#endif