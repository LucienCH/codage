#include <stdio.h>
#include <stdlib.h>

#include "Lm.h"
#include "Gold.h"

void TestGold() {
  int registre1[5] = {1,1,1,1,1};
  int registre2[5] = {1,1,1,1,1};
  int generation1[2] = {5,2};
  int generation2[4] = {5,4,2,1};
  int longueurSeq = 10;
  int gold[longueurSeq];

  printf("\n====== Test Gold ======\n\n");
  CodeGold(registre1,registre2,5,5,generation1,2,generation2,4,longueurSeq,gold);
  printf("\n");
}


int TestLM()
{
  int registre1[5] = {1,1,1,1,1};
  int generation1[2] = {5,2};
  int longueurSeq = 10;
  int lm[longueurSeq];
  int i;
  
  printf("\n====== Test LM ======\n\n");
  CodeLM(registre1,generation1,5,2,longueurSeq,lm);
	printf("\nCode de longueur maximale :\n");
  for(i=0;i<longueurSeq;i++)
    printf("%3d",lm[i]);

  printf("\n");
  return 0;
}

int main(int argc, char const *argv[])
{
    printf("Test gold : \n");

    TestGold();
	
    printf("Test LM :\n");
    TestLM();   
    
    return 0;
}
