#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int x,i;
  printf("Numero: ");
  scanf("%d",&x);
  for (i=1;i<=(x/2);i++)
  {
      if (x%i == 0)
      {
              printf("%d ",i);
      }
  }
  if (x%x == 0)
  {
          printf("%d",x);
  }
  return 0;
}
