#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NRA 2
#define NCA 3
#define NRB 3
#define NCB 2
#define MIN 0
#define MAX 9
int main(int argc, char *argv[]){
    unsigned int i,j;
    int k;
  srand(time(NULL));
  int a[NRA][NCA];
  int b[NRB][NCB];
  int c[NRA][NCB];
  for (i=0;i<NRA;++i)
  {
      for (j=0;j<NCA;++j)
      {
          a[i][j] = rand()%(MAX-MIN+1)+MIN;
          printf("%3d",a[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  for (i=0;i<NRB;++i)
  {
      for (j=0;j<NCB;++j)
      {
          b[i][j] = rand()%(MAX-MIN+1)+MIN;
          printf("%3d",b[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  for (i=0;i<NRA;++i)
  {
      for (j=0;j<NCB;++j)
      {
          c[i][j] = 0;
          for (k=0;k<NCA;++k)
          {
              c[i][j] += a[i][k]*b[k][j];
          }
          printf("%3d",c[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  system("PAUSE");	
  return 0;
}
