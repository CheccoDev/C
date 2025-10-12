#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(int argc, char *argv[])
{
    int i,j;
  for (i=1;i<=N;i++)
  {
      for (j=1;j<=N;j++)
      {
          printf("X ");
      }
      printf("\n");
  }
  system("PAUSE");
  return 0;
}
