#include <stdio.h>

void swap(int *x, int *y) {
	int temp;
	temp = *x; 
	*x = *y;
	*y = temp;
}

int main (int argc, const char * argv[]) {
	int a=10, b=20;
	
	printf("Prima di swap:\n");
	printf("a=%d, b=%d\n", a, b);
	printf("&a=%d, &b=%d\n", &a, &b);
	printf("&a=0x%0x, &b=0x%0x\n", &a, &b);
	printf("\n");
	
	//invocazione
	swap(&a,&b);
	
	printf("Dopo swap:\n"); 
	printf("a=%d, b=%d\n", a, b);
	printf("&a=%d, &b=%d\n", &a, &b);
	printf("&a=0x%0x, &b=0x%0x\n", &a, &b);
	printf("\n");
	system("PAUSE");
	
    return 0;
}

