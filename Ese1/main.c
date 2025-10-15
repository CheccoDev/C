#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NPUNTI 5
#define DIMENSIONI 2
int main(int argc, char *argv[])
{
  float punti[NPUNTI][DIMENSIONI];
  float xq,yq,min;
  int i,j,p;
  for (i=0;i<NPUNTI;++i)
  {
      for (j=0;j<DIMENSIONI;++j)
      {
          if (j==0)
          {
                   punti[i][j] = (rand()%100000)/1000.0;
          }
          if (j==1)
          {
                  punti[i][j] = 1.0*(rand()%100000)/1000;
          }
      }
      printf("(%.2f;%.2f)\n",punti[i][0],punti[i][1]);
  }
  printf("Inserisci la X di Q: ");
  scanf("%f",&xq);
  printf("Inserisci la Y di Q: ");
  scanf("%f",&yq);
  min = sqrt(pow(xq-punti[0][0],2)+pow(yq-punti[0][1],2));
  for (i=0;i<NPUNTI;++i)
  {
      if (sqrt(pow(xq-punti[i][0],2)+pow(yq-punti[i][1],2))<min)
      {
         min = sqrt(pow(xq-punti[i][0],2)+pow(yq-punti[i][1],2));
         p = i;
      }
  }
  printf("Punto (%.2f;%.2f): %.2f\n",punti[p][0],punti[p][1],min);
  system("PAUSE");	
  return 0;
}
