#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NR 3
#define NC 2
#define MIN 0
#define MAX 9
int main(int argc, char *argv[])
{
  unsigned int i,j;
  int a[NR][NC];
  int b[NR][NC];
  int s[NR][NC];
  srand(time(NULL));
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          a[i][j] = rand()%(MAX-MIN+1)+MIN;
          printf("%3d",a[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          b[i][j] = rand()%(MAX-MIN+1)+MIN;
          printf("%3d",b[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  for (i=0;i<NR;++i)
  {
      for (j=0;j<NC;++j)
      {
          s[i][j] = (a[i][j] + b[i][j]);
          printf("%3d",s[i][j]);
      }
      printf("\n");
  }
  system("PAUSE");	
  return 0;
}
