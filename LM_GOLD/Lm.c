#include "Lm.h"

int estDans(int j,int * tab, int nbxor)
{
	int i;
	for(i = 0; i < nbxor; i++)
		if(j == tab[i])
			return 1;

	return 0;
}

void CodeLM(int registre[], int generation[],int tailleRegistre,int nbxor, int longueurSeq, int lm[])
{
  int i=1;
  int entree;
  int j=1;
  lm[0] = registre[tailleRegistre-1];

	printf("\n");
	while(j <= tailleRegistre)
	{
		if(!estDans(j, generation, nbxor))
				printf("   ");
		else 
				printf("  X");
		j++;
	}
	printf("\n");
	
	for(j = 0; j < tailleRegistre-1; j++)
		printf("%3i",registre[j]);
	printf(" |%i|",registre[tailleRegistre-1]);		
	printf("\n");

  while( i < longueurSeq )
  {
    entree = registre[generation[0]-1];
    //Calcul de la nouvelle entrée
    for(j = 1 ; j< nbxor ; j++)
      entree ^= registre[generation[j]-1];

    //Décalage à droite sur la taille d'un entier
    for( j = 0 ; j < tailleRegistre ; j++ )
      registre[tailleRegistre-j] = registre[tailleRegistre-j-1];
    //Insertion de la nouvelle entrée dans le décaleur à registre
    registre[0] = entree;
    //Stockage de la valeur i du code LM
    lm[i] = registre[tailleRegistre-1];
    i++;
		
		for(j = 0; j < tailleRegistre-1; j++)
			printf("%3i",registre[j]);	
		printf(" |%i|",registre[tailleRegistre-1]);	
		printf("\n");

  }
}