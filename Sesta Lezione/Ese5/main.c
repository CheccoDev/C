#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10
int main(int argc, char *argv[])
{
    int grado;
    unsigned int i;
    unsigned int j;
    float xmax,ymax,xmin,ymin;
    float risultato;
    float coeff[MAX+1];
    float punti[MAX] = {-2.0,-1.5,-1,-0.5,0,0.5,1.0,1.5,2.0,2.5};
    
  do
  {
             printf("Grado del polinomio: ");
             scanf("%d",&grado);
  }
  while (!(grado>0 && grado<10));
  for (i=0;i<=grado;++i)
  {
      printf("Inserire coefficiente: ");
      scanf("%f",&coeff[i]);
  }
  risultato = 0;
  ymax = coeff[0] * pow(punti[0],0);
  ymin = coeff[0] * pow(punti[0],0);
  xmax = coeff[0];
  xmin = coeff[0];
  for (i=0;i<MAX;++i)
      {
                     risultato = 0;
                    for (j=0;j<=grado;++j)
                    {
                    risultato += (coeff[j] * pow(punti[i],j));
                    if (risultato<=ymin){ymin=risultato;xmin=punti[i];}
                    if (risultato>=ymax){ymax=risultato;xmax=punti[i];}
                    }
                    printf("%.1f: %.1f\n",punti[i],risultato);
      }
  printf("YMIN: %.1f\nYMAX: %.1f\nXMIN: %.1f\nXMAX: %.1f\n",ymin,ymax,xmin,xmax);
  system("PAUSE");	
  return 0;
}
