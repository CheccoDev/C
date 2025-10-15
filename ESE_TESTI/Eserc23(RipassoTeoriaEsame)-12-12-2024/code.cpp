#include <iostream>
#include <cstdlib>
#include <strings.h>
#define MAX 30

using namespace std;
typedef struct Tnodo{
	int dato;
	Tnodo *next;
	Tnodo(int d) {	dato = d; next = NULL; }
} Tnodo;
int verificaDecrescente(Tnodo* s) {
	if (s==NULL){ return 1; }
	int last = s->dato;
	s = s->next;
	while (s != NULL) {
		if (last < s->dato) { return 0; }
		last = s->dato;
		s = s->next;
	}
	return 1;
}

void verificaControlloDecrescente() {
	Tnodo* nodo = new Tnodo(5);
	nodo->next = new Tnodo(3);
	nodo->next->next = new Tnodo(0); 
	cout << "Lista 1 decrescente: " << verificaDecrescente(nodo) << endl;
	Tnodo* nodo2 = new Tnodo(5);
	nodo2->next = new Tnodo(3);
	nodo2->next->next = new Tnodo(4); 
	cout << "Lista 2 non decrescente: " << verificaDecrescente(nodo2) << endl;
}

int leggiFile(){ 
	FILE *nomi;
	nomi = fopen("persone.txt", "r");
	if(nomi==NULL){
		printf("Errore apertura file dati.txt");
		return 1;
	} 
	char nome[MAX] = "\0";
	int eta = 0, minimo = 0, massimo = 0;
	char nome_minimo[MAX] = "\0", nome_massimo[MAX] = "\0";
	while( fscanf(nomi, "%s %d", nome, &eta) == 2 ){
		if (eta > massimo || massimo == 0) {
			massimo = eta;  strcpy(nome_massimo, nome); 
		}
		if (eta < minimo || minimo == 0) {
			minimo = eta; strcpy(nome_minimo, nome);
		}	
	}
	fclose(nomi);

	cout << "Massimo: " << nome_massimo << " " << massimo << endl;
	cout << "Minimo: " << nome_minimo << " " << minimo << endl;
} 


int main() {
	verificaControlloDecrescente();
	leggiFile();
}


