#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  int x,y,j,z,k;
  printf("X: ");
  scanf("%d",&x);
  printf("Y: ");
  scanf("%d",&y);
  z=1;
  for (j=1;j<=y;j++)
  {
      for (k=1;k<=y;k++)
      {
       z = k*j;
       printf("%3d ",z);
       }
       printf("\n");
  }
  return 0;
}
