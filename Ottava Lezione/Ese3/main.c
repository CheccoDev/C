#include <stdio.h>
#include <stdlib.h>
#define NUM_STUDENTI 4
#define NUM_ESAMI 5
typedef struct studenti {
       int esami[NUM_ESAMI];
}studenti;
int main(int argc, char *argv[])
{
    int i,j,sum_st,sum_es,sum_med,conta;
  studenti studente[NUM_STUDENTI];
  sum_med = 0;
  for (i=0;i<NUM_STUDENTI;++i)
  {
      sum_st = 0;
      printf("Studente %d\n",i+1);
      for (j=0;j<NUM_ESAMI;++j)
      {
          studente[i].esami[j] = rand()%(30-18+1)+18;
      }
      studente[i].esami[rand()%(NUM_ESAMI)] = 0;
      for (j=0;j<NUM_ESAMI;++j)
      {
          printf("\tEsame %d: %d\n",j+1,studente[i].esami[j]);
          if (studente[i].esami[j] != 0)
          {
             sum_st += studente[i].esami[j];
          }
      }
      printf("Media Studente %d: %.2f\n",i+1,sum_st/(float)(NUM_ESAMI-1));
      sum_med += sum_st/(float)(NUM_ESAMI-1);
  }
  printf("\n");
  for (i=0;i<NUM_ESAMI;++i)
  {
      sum_es = 0;
      conta = 0;
      for (j=0;j<NUM_STUDENTI;++j)
      {
          if (studente[j].esami[i] != 0)
          {
             sum_es += studente[j].esami[i];
          }
          else if (studente[j].esami[i] == 0)
          {
               conta += 1;
          }
      }
      printf("Media Esame %d: %.2f\n",i+1,sum_es/(float)(NUM_STUDENTI-conta));
  }
  printf("\nSomma medie degli studenti: %.2f\n",sum_med/(float)NUM_STUDENTI);
  system("PAUSE");	
  return 0;
}
