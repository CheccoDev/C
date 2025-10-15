#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n,i,j;
    printf("Lunghezza: ");
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        for (j=0;j<(i+1);++j)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;++i)
    {
        for (j=0;j<(i+1);++j)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;++i)
    {
        for (j=0;j<(i+1);++j)
        {
            if (j==0 || i==(n-1) || i==j)
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
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j)
        {
            if ((i+j)>=(n-1))
            {
               printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j)
        {
            printf("%d ",i+j);
        }
        printf("\n");
    }
  system("PAUSE");	
  return 0;
}
