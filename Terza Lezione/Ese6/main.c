#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,max,min,x,i,somma;
  float media;
  printf("Quanti numeri? ");
  scanf("%d",&x);
  printf("Numero: ");
  scanf("%d",&n);
  somma = n;
  min = n;
  max = n;
  for (i=0;i<(x-1);i++)
  {
      printf("Numero: ");
      scanf("%d",&n);
      somma += n;
      if (n<min)
      {
                min = n;
      }
      else if (n>max)
      {
           max = n;
      }
      else if (n==max)
      {
           min = n;
           max = n;
      }
  }
  media = somma / (float)x;
  printf("Minimo: %d\n",min);
  printf("Massimo: %d\n",max);
  printf("Media: %.2f\n",media);	
  return 0;
}
