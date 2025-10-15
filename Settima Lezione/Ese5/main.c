#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VMIN 0
#define VMAX 9
#define NR 4
#define NC 4
int main(int argc, char *argv[])
{
  unsigned i,j;
  int m[NR][NC];
  srand(time(NULL));
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          m[i][j] = rand()%(VMAX-VMIN+1)+VMIN;
          printf("%2d",m[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          if (m[i][j] > 6)
          {
                      m[i][j] = 5;
          }
          else if (m[i][j]>2 && m[i][j]<7)
          {
               m[i][j] = 0;
          }
          printf("%2d",m[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  system("PAUSE");	
  return 0;
}
