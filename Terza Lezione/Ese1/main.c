#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,i;
  printf("Numero: ");
  scanf("%d",&n);
  if (n>=0)
  {
           for (i=0;i<=n;i++)
           {
               printf("%d ",i);
           }
  }
  else
  {
      printf("Numero non valido.\n");
  }
  return 0;
}
