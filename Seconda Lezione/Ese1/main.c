#include <stdio.h>
#include <stdlib.h>
//Dato un numero intero, dire se è maggiore, minore o uguale a 0
int main(int argc, char *argv[])
{
    int n;
  printf("Scrivi un numero: ");
  scanf("%d",&n);
  if (n>0)
  {
        printf("%d > 0\n",n);
  }
  else
  {
      if (n<0)
      {
            printf("%d < 0\n",n);
      }
      else
      {
          printf("%d = 0\n",n);
      }
  }
  system("PAUSE");	
  return 0;
}
