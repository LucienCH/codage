#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hadamard.h"

// -- Verification du nombre d'utilisateur compris entre 1 et 16 -- 
int NombreUtilisateurs()
{
    
    int nbUser = 0;
    int etat = 0;

    int listUser[5] = {1,2,4,8,16};

    // -- on vérifie que le nombre d'utilisateur est correct --
    while(etat != 1){ 
        printf("Saisir le nombre d'utilisateurs (1, 2, 4, 8 ou 16) : ");
        scanf("%d", &nbUser);
        for(int i = 0; i < 5; i++){
            if(nbUser == listUser[i]){
                etat = 1;
            }
        }
        if(!etat) printf("Erreur dans la saisie du nombre d'utilisateur... \n");
    }
    return nbUser;
}

// -- retourne le nombre d'étape --
int NombreEtapes(int nombreUtilisateurs)
{ 
    int n = 0, nbEtapes = 0;

    while(n < nombreUtilisateurs){
        nbEtapes++;
        n = pow(2,nbEtapes);
    }
    return nbEtapes;
}

// -- Permet d'afficher la matrice donnée en paramètre -- 
int AfficherMatrice(int ** mat, int tailleMat)
{
    for(int i = 0; i < tailleMat; i++)
    {
        printf("|");
        for(int j = 0; j < tailleMat; j++)
        {
            printf(" %2d |", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    return 1;
}


// -- Permet d'allouer l'espace mémoire à la matrice -- 
int ** CreerMatrice(int nbUser)
{
    int ** mat;

    printf("Tentative d'allocation de la matrice %d x %d ... \n", nbUser, nbUser);
    
    if( (mat = malloc(sizeof(int*) * nbUser)) == NULL)
    {
        perror("Erreur dans l'allocations de la matrice \n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < nbUser; i++)
    {
        if( (mat[i] = malloc(sizeof(int*) * nbUser)) == NULL)
        {
            perror("Erreur dans l'allocations de la matrice \n");
            exit(EXIT_FAILURE);
        }
        for(int j = 0; j < nbUser; j++)
        {
            mat[i][j] = -1;
        }
    }

    printf("Allocation terminée avec succès ! \n");

    return mat;
}

// -- Permet d'appliquer l'algo d'Hadammar --
int HadaMatrice(int ** mat, int nbUser)
{
    int tailleRemplissage = 1;
    int i = 0;
    int j = 0;

    while(tailleRemplissage <= nbUser)
    {
        if(tailleRemplissage == 1)
        {
            mat[i][j] = 1;
        }
        else
        {
            for(i = 0; i < tailleRemplissage; i++)
            {
                for(j = 0; j < tailleRemplissage; j++)
                {
                    // -- première moitié horizontal --
                    if(i < tailleRemplissage/2)
                    {   
                        // -- seconde matière vertical --
                        if(j >= tailleRemplissage/2)
                        {
                            mat[i][j] = mat[i][j - tailleRemplissage/2];
                        }
                    }
                    
                    // -- seconde moitié horizontale --
                    else
                    {
                        // -- première moitié verticale --
                        if(j < tailleRemplissage/2)
                        {
                            mat[i][j] = mat[i - tailleRemplissage/2][j];
                        }
                        else
                        {
                            mat[i][j] = - mat[i - tailleRemplissage/2][j - tailleRemplissage/2];
                        }
                    }
                }
            }
     
        }

        tailleRemplissage *= 2;
        // -- fin du while --
    }
    return 1;
}

