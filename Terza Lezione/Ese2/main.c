#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n,i;
    do
    {
             printf("Numero: ");
             scanf("%d",&n);
    }
    while (!(n>=0 && n<=10));
    for (i=0;i<=n;i++)
    {
        printf("%d ",i);
    }
  return 0;
}
