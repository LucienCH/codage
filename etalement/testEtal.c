#include <stdio.h>
#include <stdlib.h>
#include "hadamard.h"


int main(int argc, char const *argv[])
{
    // char m1[] = {+1, -1, +1}; [1 -1 1 1] ==> [1 -1 1 1] [-1 1 -1 -1] 
	// char m2[] = {-1, -1, +1};
	// char m3[] = {-1, +1, +1};
	// char m4[] = {+1, +1, -1};
	// char * messages[] = {m1, m2, m3, m4};
	// int nb_messages = 4;
	// int taille_message = 3;

    int nbUser = NombreUtilisateurs();
    int nbEtapes = NombreEtapes(nbUser);

    printf("NBUser : %d \n nbEtapes %d \n", nbUser, nbEtapes);

    int ** mat = CreerMatrice(nbUser);
    AfficherMatrice(mat, nbUser);
    
    HadaMatrice(mat, nbUser);
    AfficherMatrice(mat, nbUser);
    return 0;
}
