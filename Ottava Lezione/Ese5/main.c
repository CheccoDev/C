#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_ESAMI 5
#define NUM_STUDENTI 4
typedef struct Tstudente {
        char nome[3];
        char cognome[3];
        int esami[NUM_ESAMI];
}studente;
int main(int argc, char *argv[])
{
    int i,j,k,sum,a;
    studente studente[NUM_STUDENTI];
    srand(time(NULL));
  for (i=0;i<NUM_STUDENTI;++i)
  {
      studente[i].nome[0] = rand()%('Z'-'A'+1)+'A';
      studente[i].nome[1] = rand()%('Z'-'A'+1)+'A';
      studente[i].nome[2] = '\0';
      studente[i].cognome[0] = rand()%('Z'-'A'+1)+'A';
      studente[i].cognome[1] = rand()%('Z'-'A'+1)+'A';
      studente[i].cognome[2] = '\0';
      for (j=0;j<NUM_ESAMI;++j)
      {
          studente[i].esami[j] = 0;
      }
  }
  for (i=0;i<NUM_STUDENTI;++i)
  {
      k = rand()%(NUM_ESAMI);
      sum = 0;
      printf("%s %s\n",studente[i].nome,studente[i].cognome);
      for (j=0;j<NUM_ESAMI;++j)
      {
          studente[i].esami[j] = rand()%(30-18+1)+18;
      }
      for (a=0;a<(NUM_ESAMI-k);++a)
      {
          studente[i].esami[a] = 0;
      }
      for (j=0;j<NUM_ESAMI;++j)
      {
          printf("\tEsame %d: %d\n",j+1,studente[i].esami[j]);
          sum += studente[i].esami[j];
      }
      if (k != 0)
      {
       printf("Media studente %d: %.2f\n",i+1,(float)sum/k);
      }
      else if (k==0)
      {
           printf("Media studente %d: N/A\n",i+1);
      }
  }
  system("PAUSE");	
  return 0;
}
