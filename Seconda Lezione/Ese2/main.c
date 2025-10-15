#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int x,y;
  printf("Numero: ");
  scanf("%d",&x);
  printf("Numero: ");
  scanf("%d",&y);
  if (x>y)
  {
          printf("Il numero %d è maggiore del numero %d\n",x,y);
  }
  else if (x<y)
  {
       printf("Il numero %d è minore del numero %d\n",x,y);
  }
  else
  {
      printf("I due numeri sono uguali.\n");
  }
  system("PAUSE");	
  return 0;
}
