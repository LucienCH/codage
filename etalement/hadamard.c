#include <stdio.h>
#include <stdlib.h>
#include "hadamard.h"
#include <math.h>

int NombreUtilisateurs(){
    int nbUser = 0;
    int tabOK[5] = {1,2,4,8,16};
    int etat = 0;

    // on vérifie que le nombre d'utilisateur est correct 
    while(etat != 1){ 
        printf("Saisir le nombre d'utilisateurs (1, 2, 4, 8 ou 16): ");
        scanf("%d", &nbUser);
        for(int i = 0; i < 5; i++){
            if(nbUser == tabOK[i]){
                etat = 1;
            }
        }
        if(!etat) printf("Erreur dans la saisie du nombre d'utilisateur... \n");
    }
    
    return nbUser;
}

int NombreEtapes(int nombreUtilisateurs){ // N = 2^p
    int n = 0, nbEtapes = 0;

    while(n < nombreUtilisateurs){
        nbEtapes++;
        n = pow(2,nbEtapes);
    }
    return nbEtapes;  
}




int GenererMatrice(){
    int nbUser = NombreUtilisateurs();
    int nbEtapes = NombreEtapes(nbUser);
    printf("nb Etapes : %d \n", nbEtapes);
    int hInitial = 1;

    


    return 1;
}