#include <stdio.h>
#include <stdlib.h>
#include "hadamard.h"
#include <math.h>

int NombreUtilisateurs(){
    int nbUser = 0;
    int tabOK[5] = {1,2,4,8,16};
    int etat = 0;

    // -- on vérifie que le nombre d'utilisateur est correct --
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

void afficher_matrice(int taille, int * matrice_Hadamard){
    printf("Affichage de la matrice : \n\n");
    printf("Taille de la matrice : %dx%d \n",taille,taille);

    for(int i=0; i < taille;i++){
      for (int j=0; j < taille; j++) {
          printf("|  %d  ",matrice_Hadamard[i + j]); 
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

int * AllocHadamard(int tailleMatrice){
    int* mat;

    if((mat = malloc(sizeof(int*) * tailleMatrice)) == (int *)-1 ){
        printf("Erreur dans l'allocation de la matrice d'Hadamard \n");
        exit(0);
    }else{
        printf("Allocation de la mémoire réussie ... \n");
        for(int i = 0; i < tailleMatrice; i++){
            for(int j = 0; j < tailleMatrice; j++){
                mat[i + j] = 0;
            }
        }

        // printf("Init reussie \n");
    }

    return mat;
}

void detruire_matrice(int taille,int* matrice_Hadamard){
  for (int i = 0; i < taille; i++){
      free(matrice_Hadamard[i]);
  }
  free(matrice_Hadamard);
}

int* CreerMatrice(int tailleMatrice){
  int * mat = AllocHadamard(tailleMatrice);

  afficher_matrice(tailleMatrice, mat);
  
  int nbEtape = NombreEtapes(tailleMatrice);

  int i = 0, j = 0;

  if(nbEtape == 1){
      mat[tailleMatrice * 0 + 0] = 1;
  }else{
      for(int i = 0; i < nbEtape; i++){
          for(int j = 0; j < nbEtape; j++){
              
              // on ne s'occupe que de la première moitié verticale de la matrice 
              if(i < (nbEtape / 2) ){
                  if(j >= (nbEtape / 2)){
                      mat[tailleMatrice * i + j] = mat[tailleMatrice * i + (j - (nbEtape / 2))];
                  }else{
                      
                  }
              }
          }
      }
  }

//   // Remplissage de la matrice
//   while(tailleRemplissage <= tailleMatrice)
//   {
//       if(tailleRemplissage == 1)
//         mat[tailleMatrice*0+0] = 1;
//       else
//       {
//           for(i = 0 ; i < tailleRemplissage ; i++)
//           {
//               for(j = 0 ; j < tailleRemplissage ; j++)
//               {
//                   if(i < tailleRemplissage/2) // Première moitié horizontale
//                   {
//                       if(j >= tailleRemplissage / 2)
//                         mat[tailleMatrice*i+j] = mat[tailleMatrice*i+(j-tailleRemplissage/2)]; // Seconde moitié verticale
//                   }//fin if
//                   else // Seconde moitié horizontale
//                   {
//                       if(j < tailleRemplissage/2) // Première moitié verticale
//                         mat[tailleMatrice*i+j] = mat[tailleMatrice*(i-tailleRemplissage/2)+j];
//                       else // Quart inférieur droit
//                         mat[tailleMatrice*i+j] = - mat[tailleMatrice*(i-tailleRemplissage/2)+(j-tailleRemplissage/2)];
//                   } //fin else
//               } //fin for
//             } //fin for
//       } //fin else

//       tailleRemplissage *= 2;

//  } //fin while

  return mat;    
}



