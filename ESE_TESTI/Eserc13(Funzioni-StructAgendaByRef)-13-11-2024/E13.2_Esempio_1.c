#include <stdio.h>

int stampa(int a);   /*passaggio dati per valore*/
int stampa1(int *a); /*passaggio dati per riferimento*/
int stampa2(int *b); /*passaggio dati per riferimento*/

int main (int argc, const char * argv[]) {
    int a=4;
	printf("(main) a %d\n",a);
	stampa(a);
	printf("(main) a %d\n",a);
	/*passare al momento della chiamata della funzione 
	 come parametro attuale un indirizzo di variabile 
	 (usando l'operatore &).*/
	stampa1(&a);
	printf("(main) a %d\n",a);  
	stampa2(&a);
	printf("(main) a %d\n",a);
	
	system("PAUSE");
    return 0;
}

int stampa(int a){ 
	a=a+1; 
	printf("(stampa) %d\n",a);
}
/*usare l'operatore di dereferenziazione di puntatore 
 (operatore *) all'interno del corpo della funzione */
int stampa1(int *a){
	*a=*a+1; 
	printf("(stampa1) %d\n",*a);
}
int stampa2(int *b){
	*b=*b+1; 
	printf("(stampa2) %d\n",*b);
}

