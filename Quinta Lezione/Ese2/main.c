#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(int argc, char *argv[])
{
    int i,j;
  for (i=0;i<N;i++)
  {
      for (j=0;j<N;j++)
      {
          if (i==0 || i==(N-1) || j==0 || j==(N-1))
          {
                   printf("X ");
          }
          else
          {
              printf("O ");
          }
      }
      printf("\n");
  }
  system("PAUSE");	
  return 0;
}
