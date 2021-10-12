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

void afficher_matrice(int taille, int** matrice_Hadamard){
    printf("Affichage de la matrice : \n\n");
    printf("Taille de la matrice : %dx%d \n",taille,taille);

    for(int i=0; i < taille;i++){
      for (int j=0; j < taille; j++) {
          printf("|  %d  ",matrice_Hadamard[i][j]); 
      }
        printf("|\n" );
    }
}

void copier_matrice(int x, int y, int** matrice, int** matrice_finale, int n){
    int i,j;
    int indice_x=x, indice_y=y;
    for ( i=0; i < n; i++){

        for ( j=0; j < n ; j++){
              matrice_finale[indice_x][indice_y] = matrice[i][j];
              indice_y++;
        }
        indice_y=y;
        indice_x++;
    }
}

int** inverser_matrice(int ** mat_a_inverser, int taille, int** matrice_sortie){
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
          matrice_sortie[i][j] = mat_a_inverser[i][j]* (-1);
        }
    }
    return matrice_sortie;
}

int** CreerMatrice(int nbUser, int* taille_mat){
    int** mat;
    int** petite_matrice; //matrice initiale
    int** matrice_temp;
    int nInit = 1;
    int taille = NombreEtapes(nbUser);
    *taille_mat = taille;

    if((petite_matrice = malloc(sizeof(*mat))) == NULL){
        printf("Erreur d'allocation de mémoire pour petite matrice ...\n");
        exit(0);
    }

    if((petite_matrice[0] = malloc(sizeof(*mat))) == NULL){
        printf("Erreur d'allocation de mémoire pour petite matrice ...\n");
        exit(0);
    }
    petite_matrice[0][0]=1;

    if((matrice_temp = malloc(sizeof(*matrice_temp) * taille)) == NULL){
        printf("Erreur d'allocation de mémoire pour petite matrice ...\n");
        exit(0);
    }

    if((mat = malloc(sizeof(*mat)* taille)) == NULL){
        printf("Erreur d'allocation de mémoire pour mat ...\n");
        exit(0);
    }

    for(int i = 0; i < taille; i++){
        mat[i] = malloc(sizeof(int) * taille);
    }

    for(int i = 0; i < taille; i++){
        matrice_temp[i] = malloc(sizeof(int) * taille);
    }

    copier_matrice(0, 0,petite_matrice, mat, nInit); // matrice de base 2x2;

    while(nInit < taille){
        copier_matrice(nInit, 0,mat, mat,nInit);
        copier_matrice(0, nInit,mat, mat,nInit);
        inverser_matrice(mat, nInit, matrice_temp);
        copier_matrice(nInit, nInit,matrice_temp, mat,nInit);
        nInit*=2;
    }

    



     
    return mat;
}