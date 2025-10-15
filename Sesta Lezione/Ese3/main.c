#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define MIN 0
#define MAX 20
int main(int argc, char *argv[])
{
  int array[N];
  int i,min,max,somma;
  float media;
  somma=0;
  srand(time(NULL));
  for (i=0;i<N;++i)
  {
      array[i] = rand()%(MAX-MIN+1)+MIN;
      printf("%d ",array[i]);
      somma += array[i];
  }
  min = array[0];
  max = array[0];
  for (i=0;i<N;++i)
  {
      if (array[i]<min){min=array[i];}
      if (array[i]>max){max=array[i];}
  }
  media = (float)somma/N;
  printf("\n");
  printf("Minimo: %d\nMassimo: %d\nMedia: %.2f\n",min,max,media);
  system("PAUSE");	
  return 0;
}
