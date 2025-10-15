#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n,i,j;
  do
  {
             printf("Numero: ");
             scanf("%d",&n);
  }
  while (!(n>=0 && n<=10));
  if (n<5)
  {
          for (i=n;i<=10;i++)
          {
              printf("%d ",i);
          }
  }
  else if (n>=5)
  {
       for (j=n;j>=0;j--)
       {
           printf("%d ",j);
       }
  }
  return 0;
}
