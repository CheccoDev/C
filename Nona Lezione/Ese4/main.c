#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_CAR 20
#define NUM_STUDENTI 4
#define NUM_ESAMI 5
typedef struct Tstudente {
       char nome[NUM_CAR];
       char cognome[NUM_CAR];
       int esami[NUM_ESAMI];
}studente;
int main(int argc, char *argv[])
{
    srand(time(NULL));
  studente studente[NUM_STUDENTI];
  int i,j,sum_st,sum_es;
  for (i=0;i<NUM_STUDENTI;++i)
  {
      printf("Nome studente %d: ",i+1);
      fflush(stdin);
      scanf("%s",studente[i].nome);
      printf("Cognome studente %d: ",i+1);
      fflush(stdin);
      scanf("%s",studente[i].cognome);
      for (j=0;j<NUM_ESAMI;++j)
      {
          studente[i].esami[j] = rand()%(30-18+1)+18;
      }
  }
  for (i=0;i<NUM_STUDENTI;++i)
  {
      sum_st = 0;
      printf("%s %s",studente[i].nome,studente[i].cognome);
      for (j=0;j<NUM_ESAMI;++j)
      {
          sum_st += studente[i].esami[j];
          printf("\n\tEsame %d: %d",j+1,studente[i].esami[j]);
      }
      printf("\nMedia: %.2f\n",sum_st/(float)NUM_ESAMI);
  }
  for (i=0;i<NUM_ESAMI;++i)
  {
      sum_es = 0;
      for (j=0;j<NUM_STUDENTI;++j)
      {
          sum_es += studente[j].esami[i];
      }
      printf("\nMedia Esame %d: %.2f",i+1,sum_es/(float)NUM_STUDENTI);
  }
  printf("\n");
  system("PAUSE");	
  return 0;
}
