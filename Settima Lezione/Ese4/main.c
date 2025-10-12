#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NR 8
#define NC 6
#define VMIN 18
#define VMAX 30
int main(int argc, char *argv[])
{
  int m[NR][NC];
  unsigned i,j;
  int min,max,somma;
  float media;
  srand(time(NULL));
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          m[i][j] = rand()%(VMAX-VMIN+1)+VMIN;
          printf("%3d",m[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          if (m[i][j] > 25)
          {
                      printf("%3d",m[i][j]);
          }
          else
          {
              printf(" X ");
          }
      }
      printf("\n");
  }
  min = m[0][0];
  max = m[0][0];
  somma=0;
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          if (m[i][j]<=min){min=m[i][j];}
          if (m[i][j]>=max){max=m[i][j];}
          somma += m[i][j];
      }
  }
  media = (float)somma / (NR*NC);
  printf("Minimo: %d\n",min);
  printf("Massimo: %d\n",max);
  printf("Media: %.2f\n",media);
  system("PAUSE");	
  return 0;
}
