#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NR 4
#define NC 4
#define MIN 0
#define MAX 9
int main(int argc, char *argv[])
{
  unsigned int i,j,k;
  int m[NR][NC];
  int arr[MAX];
  srand(time(NULL));
  for (k=0;k<MAX;++k)
  {
      arr[k] = 0;
  }
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          m[i][j] = rand()%(MAX-MIN+1)+MIN;
          printf("%2d",m[i][j]);
      }
      printf("\n");
  }
  for (i=0;i<NR;++i)
  {
      for (j=1;j<NC;++j)
      {
          if ((m[i][j] == m[i][j-1]) || (m[i][j] == m[i][j+1]) && j!=0)
          {
                    printf("%d\n",m[i][j]);
          }
          
      }
  }
  system("PAUSE");	
  return 0;
}
