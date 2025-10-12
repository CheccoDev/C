#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VMIN 0
#define VMAX 9
#define NR 4
#define NC 4
int main(int argc, char *argv[])
{
  unsigned i,j,k;
  int m[NR][NC];
  int primo;
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
          if (m[i][j] >= 2)
          {
          primo=1;
          for (k=2;k<m[i][j];++k)
          {
              if (m[i][j]%k == 0)
              {
                       primo = 0;
                       break;  
              }
              else if ((m[i][j]%k != 0) && primo==1)
              {
                   primo = 1;
              }
          }
          if (primo == 1)
              {
                        m[i][j] = -1;
              }    
          }
          printf("%3d",m[i][j]);
      }
      printf("\n");
  }
printf("\n");
}
