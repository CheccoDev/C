#include <stdio.h>     
#include <stdlib.h>   
#include <time.h>  
#include <iostream>
#include <string.h>
using namespace std;
#define NUMVEICOLI 3

// Creo una funzione che ritorni un numero intero random tra un minimo e un massimo
int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// definisco l'enum TipoV
typedef enum TipoV{ AUTO, MOTO, CAMPER } TipoV;
/*
Questo enum è equivalente alle seguenti istruzioni
#define AUTO 0
#define MOTO 1
#define CAMPER 2
ma permette in più di avere i vantaggi di un tipo di variabile
*/

typedef struct TVeicolo{
  char marca[20];
  unsigned int anno;
  TipoV tipo;
  
  // Creo il costruttore di default
  // La scelta di come settare le proprietà nel costruttore di default, se non specificato è a scelta del programmatore
  TVeicolo ()   {
    marca[0] = '\0'; // inizializzo una stringa vuota
    anno = 1970; // setto come anno un valore che sia riconoscibile
    tipo = AUTO; // metto di default il primo valore possibile dell'enum
  }
  
  // Creo un costruttore specifico che prende in ingresso tutte le proprietà della struct
  TVeicolo(char* _marca, int _anno, TipoV _tipo) {
	strcpy(marca, _marca); //necessaria libreria string
	anno = _anno;
	tipo = _tipo;
  }
  
  // Creo un distruttore che in questo caso non svolge funzioni particolari
  ~TVeicolo() {
	
  }

  // Nel metodo di stampa preparo una stringa che sia uguale a quella richiesta
  void stampa() const {
    cout << marca << " TIPO=";
    switch (tipo) { //stampo il tipo di veicolo confrontando il valore della proprietà con il valore dell'enum
      case AUTO: {
        cout << "AUTO";
        break;
      }
      case MOTO: {
        cout << "MOTO";
        break;
      }
      case CAMPER: {
        cout << "CAMPER";
        break;
      }
    }
    cout << " ANNO=" << anno;
  }
} TVeicolo;

typedef struct TRevisione {
    int head, tail;  //posizione inserimento, posizione prelevamento
    int dim;         // numero elementi array cio`e della coda FIFO
    int n;           // numero elementi presenti nella coda FIFO
    TVeicolo* s;     // array dinamico circolare

	// Creo un costruttore specifico con in ingresso il numero di veicoli che conterrà
    TRevisione (int num) {
        head = tail = 0; // setto sia head che tail a 0 perché l'array circolare è vuoto
        n = 0; // metto n a 0 perché appena creata la lista non ci sono elementi nell'array circolare
        dim = num; // setto la dimensione con il valore passato
        s = new TVeicolo[dim]; // istanzio l'array circolare di veicoli secondo la dimensione passata
    }

	// Creo un costruttore di default che sfrutta il costruttore specifico per settare la dimensione di default a 5
    TRevisione () {
        TRevisione(5);
    }

	// Creo un distruttore per eliminare l'array nell'heap quando la struttura viene ditrutta
	~TRevisione() {
		delete[] s;
	}

	// Per controllare se è vuoto mi basta verificare se n (il numero di elementi presenti) è 0
    bool isEmpty() const {
        return (n == 0);
    }

	// Per controllare se è pieno mi basta verificare se n (il numero di elementi presenti) è pari alla dimensione dell'array
    bool isFull() const {
        return (n == dim);
    }

	// Inserisco in testa, come da richiesta ma lascio al main il controllo se è pieno
    void put(TVeicolo v) {
		n++; // aumento il numero di elementi presenti nella lista
        s[head++] = v; // inserisco v in testa a s e poi incremento head
        /*
		Il comando di cui sopra è equivalente a scrivere:
		s[head] = v;
		head = head + 1;
		*/
        head = head % dim; // reimposto head sulla base della circolarità
    }

	// Prelevo dalla coda, come da richiesta. In questo caso controllo qui se l'array è vuoto
    TVeicolo get() {
		// Poiché viene restituito un TVeicolo ne creo uno temporaneo in cui copiare l'elemento dell'array
		// Se è vuoto ritornero il veicolo di default appena creato, lasciando però al main l'onere di controllare
		// se il veicolo ritornato è quello di default o quello corretto.
		// Per questo motivo è comunque opportuno controllare se è vuoto nel main prima di eseguire il get
        TVeicolo tmp;
        if (!isEmpty()){
            n--;	// riduco di 1 il numero di elementi presenti nell'array
            tmp = s[tail++];	// copio in tmp l'elemento dell'array in tail e poi incremento tail
            tail = tail % dim;	// reimposto tail sulla base della circolarità dell'array
        }
        return tmp;
    }
	
	// La stampa scorre l'array ed esegue la stampa
    void stampa() const{
        if (!isEmpty()){  // controllo se è vuoto
            int i = tail;	// comincio dalla coda
            do{				// poiché non è vuoto posso già iniziare con la stampa del primo elemento
                s[i++].stampa();  // eseguo la stampa del veicolo e poi incremento i
                cout << endl;	// vado a capo
                i = i % dim;	// reimposto i sulla base della circolarità
            } while(i != head);  // proseguo finché non raggiungo la testa
        }
    }
} TRevisione;

// La funzione di creazione di un nuovo veicolo riceve in input un veicolo per riferimento &veicolo
// Deve quindi essere dichiarata per un invocazione per indirizzo con un puntatore in ingresso
void nuovoVeicolo(TVeicolo *v) {
	// inzializzo le proprietà del veicolo sapendo che verranno settate nel veicolo originale
    v->tipo = (TipoV)random(0, 2);
    v->anno = random(2000, 2021);
	cout << "Marca?" << endl;
    cin >> v->marca;
}

// Sebbene in ingresso ci sia un array, come mostrato nel testo, non viene chiesta la dimensione dell'array in ingresso
// Per questo la funzione utilizzerà la dimensione nota dell'array, ovvero 3
void stampaRevisioni(TRevisione* r[], int dim ){
    for (int i = 0; i < dim; i++) {
        r[i]->stampa();
    }
}

// Sebbene in ingresso ci sia un array, come mostrato nel testo, non viene chiesta la dimensione dell'array in ingresso
// Per questo la funzione utilizzerà la dimensione nota dell'array, ovvero 3
void salvaRevisioni(TRevisione* r[], int dim, TipoV tv){
	// apro il file in scrittura e controllo che l'apertura sia andata a buon fine
    FILE *fp;
    if ((fp = fopen("revisioni.txt", "w")) == NULL) {
        cout << "Il file non puo essere aperto" << endl;
        exit(1);
    }
	// se è andatao a buon fine ciclo sull'array delle revisioni
    for (int i = 0; i < dim; i++) {
		// finché la lista non è vuota eseguo il get
        while(!r[i]->isEmpty()) {
            TVeicolo v = r[i]->get();
			// solo se il tipo è lo stesso di quello in argomento eseguo il salvataggio su file nel formato specificato
            if (v.tipo == tv) {
                fprintf(fp, "%s ANNO=%d\n", v.marca, v.anno);
                cout << endl;
            }
        }
    }
    fclose(fp);
}


int main() {
  // inizializzo il randomizzatore (sono necessarie le librerie stdlib.h e time.h)
  srand(time(0));
     
  // Per evitare il problema dovuto al distruttore di copia (v. Slide E19 - Dettagli Allocazione) creo l'array delle revisioni
  // utilizzando un doppio puntatore
  TRevisione* revisioni[3];

  // Inizializzo ogni revisione dell'array in una revisione di 10 veicoli
  for (int i = 0; i < NUMVEICOLI; i++){
      revisioni[i] = new TRevisione(10);
  }
  

  // Dichiaro il veicolo che dovrò inizializzare con la funzione nuovoVeicolo
  TVeicolo veicolo;
  // Come da richiesta, per 5 volte, creo un veicolo e lo inserisco in lista, controllando prima che questa non sia vuota
  for(int i=0; i<5; i++) {
     nuovoVeicolo(&veicolo);
	 // La lista in cui inserire il veicolo dipende dal tipo di veicolo.
     // Essendo il tipo un enum, può essere utilizzato come indice (0, 1 o 2)
     if (!revisioni[veicolo.tipo]->isFull()) {
        revisioni[veicolo.tipo]->put(veicolo); 
     }
  }
  
  // stampo le revisioni
  stampaRevisioni(revisioni, NUMVEICOLI);
  // salvo le revisioni solo se il tipo è AUTO
  salvaRevisioni(revisioni, NUMVEICOLI, AUTO);
  
  return 0;
}
