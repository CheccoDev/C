#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NPUNTI 5
typedef struct punto{
       float x,y;
}punto;
int main(int argc, char *argv[])
{
    punto punti[NPUNTI];
    punto q;
    int i,ciao;
    float min;
    srand(time(NULL));
  printf("Inserisci la X di Q: ");
  scanf("%f",&q.x);
  printf("Inserisci la Y di Q: ");
  scanf("%f",&q.y);
  for (i=0;i<NPUNTI;++i)
  {
      punti[i].x = (rand()%100000)/1000.0;
      punti[i].y = 1.0*(rand()%100000)/1000;
  }
  min = sqrt(pow(q.x-punti[0].x,2)+pow(q.y-punti[0].y,2));
  for (i=0;i<NPUNTI;++i)
  {
      if (sqrt(pow(q.x-punti[i].x,2)+pow(q.y-punti[i].y,2)) < min)
      {
         min = sqrt(pow(q.x-punti[i].x,2)+pow(q.y-punti[i].y,2));
         ciao = i;
      }
  }
  printf("(%.2f;%.2f): %.2f\n",punti[ciao].x,punti[ciao].y,min);
  system("PAUSE");	
  return 0;
}
