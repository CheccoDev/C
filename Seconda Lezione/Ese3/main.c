#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n1,n2,n3,min,max;
    float media;
    printf("Primo numero: ");
    scanf("%d",&n1);
    printf("Secondo numero: ");
    scanf("%d",&n2);
    printf("Terzo numero: ");
    scanf("%d",&n3);
    max = n1;
    min = n1;
    if (n2>max) {max=n2;}
    if (n3>max) {max=n3;}
    if (n2<min) {min=n2;}
    if (n3<min) {min=n3;}
    printf("Massimo: %d\n",max);
    printf("Minimo: %d\n",min);
    media = (n1+n2+n3)/3.0;
    printf("Media: %.2f\n",media);
}
