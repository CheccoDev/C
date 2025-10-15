#include <stdio.h>
void somma_uno(int x) {
	x += 1;
	printf("\nValore var x: %d\n", x);
	return;
} 
void aggiungi_uno(int * x) { 
	*x += 1; 
	printf("\nValore var x: %d\n", *x);
	return;
} 
int main (int argc, const char * argv[]) {
	int a=2;
	printf("int a = 2\n");
	printf("Valore a: %d\n", a);
	printf("Indirizzo Mem a: 0x%0x\n", &a);
	
	printf("\npuntatore ad a: int* pa = &a\n");
	int *pa;
	pa = &a;
	printf("Valore pa: %d (0x%0x)\n", pa, pa);
	printf("Valore var puntata da pa (*pa): %d\n", *pa);
	
	printf("\ncopia tramite puntatore: int* pa1=pa\n");
	int *pa1;
	pa1 = pa;
	printf("Valore var puntata da pa1: %d\n", *pa1);
	
	printf("\nIncremento valore var puntata da pa: *pa=*pa+1\n");
	*pa=*pa+1;
	printf("Valore var puntata da pa: %d\n", *pa);
	printf("Valore var a: %d\n", a);
	printf("Valore var puntata da pa1: %d\n", *pa1);
	
	printf("\nIncremento valore var puntata da pa: (*pa)++\n");
	(*pa)++;
	printf("Valore var puntata da pa: %d\n", *pa);
	printf("Oppure: *pa += 1\n");
	*pa += 1;
	printf("Valore var puntata da pa: %d\n", *pa);
	
	printf("\nIncremento puntatore pa: *pa++\n");
	*pa++;
	printf("Valore var puntata da pa: %d\n", *pa);
	printf("Valore pa: %d  (0x%0x)\n", pa, pa);
	printf("Indirizzo Memoria a: 0x%0x\n", &a);
	printf("Dimensione var pa (sizeof(pa)): %d\n", sizeof(pa));
	
	printf("\nFunzioni e parametri:\n\n");
	printf("Valore var a: %d (Ind: %d 0x%0x)\n", a, &a, &a);
	
	printf("Uso var a come parametro (passaggio per valore):\n");
	printf("\"void somma_uno(int x) { x += 1; return; }\"\n");
	printf("chiamo: somma_uno(a)");
	somma_uno(a);
	printf("Valore var a: %d (Ind: %d 0x%0x)\n", a, &a, &a);	
	
	printf("\nUso indirizzo var a come parametro (passaggio per indirizzo):\n");
	printf("\"void aggiungi_uno(int * x) { *x += 1; return; }\"\n");
	printf("chiamo: aggiungi_uno(&a)\n");
	aggiungi_uno(&a);
	printf("Valore var a: %d (Ind: %d 0x%0x)\n", a, &a, &a);
	
	system("PAUSE");
	return 0;
}


