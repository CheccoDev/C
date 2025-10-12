#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i,j,n;
    printf("Lato: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (i==j)
            {
                     printf("X ");
            }
            else
            {
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if ((j+i) == (n-1))
            {
                     printf("X ");
            }
            else
            {
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
  system("PAUSE");	
  return 0;
}
