#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NR 8
#define NC 8
#define VMIN 0
#define VMAX 100
int main(int argc, char *argv[])
{
    unsigned i,j;
    int somma = 0;
  int m[NR][NC];
  float media;
  srand(time(NULL));
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          m[i][j] = rand()%(VMAX-VMIN+1)+VMIN;
          printf("%4d",m[i][j]);
          somma += m[i][j];
      }
      printf("\n");
  }
  media = (float)somma / (NR*NC);
  printf("Media: %.2f\n",media);
    for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          if (m[i][j] > media)
          {
                      printf("(%d,%d) --> %d\n",j,i,m[i][j]);
          }
      }
  }
  system("PAUSE");	
  return 0;
}
