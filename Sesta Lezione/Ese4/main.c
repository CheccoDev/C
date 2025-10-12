#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VAL_MIN 0
#define VAL_MAX 20
#define N 100
int main(int argc, char *argv[])
{
    unsigned int i;
    int occorrenze[VAL_MAX+1];
    int genera[N];
    srand(time(NULL));
    for (i=0;i<=VAL_MAX;++i)
    {
        occorrenze[i] = 0;
    }
    for (i=0;i<N;++i)
    {
        genera[i] = rand()%(VAL_MAX-VAL_MIN+1)+VAL_MIN;
        printf("%d ",genera[i]);
        occorrenze[genera[i]]++;
    }
    printf("\n");
    min=occorrenze[0];
    max=occorrenze[0];
    for (i=0;i<=VAL_MAX;++i)
    {
        printf("%d: %d\n",i,occorrenze[i]);
        if (occorrenze[i]<=min) {min=occorrenze[i];}
        if (occorrenze[i]>=max) {max=occorrenze[i];}
    }
  system("PAUSE");	
  return 0;
}
