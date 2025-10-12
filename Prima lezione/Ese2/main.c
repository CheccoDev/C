#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  //Scrivere un programma che esegue la divisione di 2 numeri x e y
  float x,y,z;
  printf("Si inserisca il primo numero: ");
  scanf("%f",&x);
  printf("Si inserisca il secondo numero: ");
  scanf("%f",&y);
  z = x / y;
  printf("Il quoziente tra il numero %.2f e il numero %.2f è %.2f\n",x,y,z);
  system("PAUSE");	
  return 0;
}
