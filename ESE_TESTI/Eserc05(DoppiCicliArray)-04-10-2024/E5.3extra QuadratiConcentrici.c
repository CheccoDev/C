#include <stdio.h>
#include <stdlib.h>

/**
 * si crea una condizione, var cond (1=vera e 0=falsa) dove per ogni riga ed ogni colonna 
 * si stabilisce in funzione del valore di i e di j se va messo un carattere oppure l'altro
 * siccome ci sono quadrati concentrici, possiamo identificarli con 
 * K=0 primo quadrato, K=1 primo quadrato. ...
 * il ciclo su K tiene conto proprio della caratteristica (per stampare O oppure -) 
 * che deve avere ogni quadrato concentrico in funzione del valore di i e di j
 */
void soluzione1(int nr) {
	int i, j, k, cond;
	for (i=0; i<nr; i++) {
		for (j=0; j<nr; j++) {
			cond=0; //falso
			for (k=0; k<nr; k=k+2){
				if ( (i==k && j>=k && j<=nr-1-k) || (j==k && i>=k && i<=nr-1-k) || 
				     (i==nr-1-k && j>=k && j<=nr-1-k) || j==nr-1-k && i>=k && i<=nr-1-k){
				 	cond = 1;
				}
			}
			if ( cond==1 ){
				printf("O ");
			} else {
				printf("- ");
			}	
		}
		printf("\n");
	}
}

int soluzione2(int nr) {
	int i, j;
	/*
	Questa soluzione divide il qudrato in quattro parti e le scrive separatamente
	controllando l'indice della colonna e se la riga è pari o dispari
	Separando il quadrato in quarti posso decidere cosa stampare utilizzando un controllo
	delle condizioni più semplice e modificando solo la direzione di incremento di i e j
	*/

	// Se la dimensione è dispari non si può separare in quattro quarti esatti
	// quindi utilizzo un offset per aggiungere la riga e la colonna a due dei quarti
	int offset = 0;
	if (nr%2 != 0) {
		offset = 1;
	}
	
	// scrivo la prima metà in alto del quadrato		
	for (i=0; i<nr/2; i++) {
		// scrivo la metà sinistra del quadrato
		for (j=0; j<nr/2; j++) {
			// se mi trovo all'interno dello spazio compreso tra le diagonali
			// e sono su una riga pari scrivo O, se sono su una riga dispari scrivo -
			if (j >= i && j <nr-i) {
				if (i%2 == 0){
					printf("O ");
				} else {
					printf("- ");
				}
			} else {
				// altrimenti, sono fuori dallo spazio tra le diagonali
				// controllo su che colonna sono, se sono su una colonna pari metto O, altrimenti -
				// così da rispettare quanto scritto nell'iterazione precedente
				if (j%2 == 0) {
					printf("O ");
				} else {
					printf("- ");
				}
			}
		}
		// ripeto quanto fatto sopra ma contando al contrario fino a metà (+ offset se dimensione dispari)
		// per scrivere il quarto a destra
		for (j=nr/2-1+offset; j>=0; j--) {
			if (j >= i && j <nr-i) {
				if (i%2 == 0){
					printf("O ");
				} else {
					printf("- ");
				}
			} else {
				if (j%2 == 0) {
					printf("O ");
				} else {
					printf("- ");
				}
			}
		}
		printf("\n");
	}


	// ripeto il ciclo precedente contando al contrario dalla metà (+ offset se dispari)
	// per scrivere la metà inferiore
	for (i=nr/2-1+offset; i>=0; i--) {
		for (j=0; j<nr/2; j++) {
			if (j >= i && j <(nr-i)) {
				if (i%2 == 0){
					printf("O ");
				} else {
					printf("- ");
				}
			} else {
				if (j%2 == 0) {
					printf("O ");
				} else {
					printf("- ");
				}
			}
		}
		for (j=nr/2-1+offset; j>=0; j--) {
			if (j >= i && j <nr-i) {
				if (i%2 == 0){
					printf("O ");
				} else {
					printf("- ");
				}
			} else {
				if (j%2 == 0) {
					printf("O ");
				} else {
					printf("- ");
				}
			}
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]){
	int nr;
	printf("inserire il numero di righe:");
	scanf("%d", &nr);

	printf("\nSOLUZIONE 1: 3 CICLI ANNIDATI\n\n");
	soluzione1(nr);
	
	printf("\n\nSOLUZIONE 2: STAMPA A QUARTI\n\n");
	soluzione2(nr);

}
