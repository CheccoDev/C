#include <stdio.h>
#include <stdlib.h>
#define N 10
int main(int argc, char *argv[])
{
    int i,j;
  int array[N];
  for (i=0;i<N;++i)
  {
      array[i] = 4;
  }
  for (j=0;j<N;++j)
  {
      printf("%d",array[j]);
  }
  printf("\n");
  system("PAUSE");	
  return 0;
}
