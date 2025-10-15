#include <stdio.h>
#include <stdlib.h>
#define N 10
#define MIN 0
#define MAX 20
int main(int argc, char *argv[])
{
  int array[N];
  int i;
  for (i=0;i<N;++i)
  {
      array[i] = rand()%(MAX-MIN+1)+MIN;
  }
  for (i=0;i<N;++i)
  {
      printf("%d ",array[i]);
  }
  printf("\n");
  const int MIN1 = -5;
  const int MAX1 = 20;
  for (i=0;i<N;++i)
  {
      array[i] = rand()%(MAX1-MIN1+1)+MIN1;
  }
  for (i=0;i<N;++i)
  {
      if (array[i] > 10)
      {
                   printf("%d ",array[i]);
      }
  }
  printf("\n");
  for (i=N;i>0;--i)
  {
      if (array[i] > 10)
      {
                   printf("%d ",array[i]);
      }
  }
  printf("\n"); 
  system("PAUSE");	
  return 0;
}
