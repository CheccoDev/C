#include <iostream>
#include <cstring>
//per usare cout (oggetto libreria standard) si dovrebbe richiamare
//std::cout
//usando namespace std si può omettere std:: prima di cout
using namespace std;

typedef struct Tpersona {
	//proprietà della struttura Persone
	char* nome;
	char* cognome;
	int eta;

	//costruttore di default
	Tpersona() {
        /*
        ATTENZIONE: allocando dinamicamente se si effettua un passaggio
        per valore (per esempio metodo confronta) si possono avere problemi 
        */      
		//nome = new char[strlen("Jane")+1];
		//strcpy(nome, "Jane");
		//cognome = new char[strlen("Doe")+1];
		//strcpy(cognome, "Doe");
		nome="Jane"; cognome="Doe";
		eta=0;
		cout << "Persona Inizializzata per default\n";
	}

	//costruttore specifico
	Tpersona(char* _nome, char* _cognome, int _eta) {
        /*
        ATTENZIONE: allocando dinamicamente se si effettua un passaggio
        per valore (per esempio metodo confronta) si possono avere problemi 
        */                    
		//nome = new char[strlen(_nome)+1];
	 	//strcpy(nome, _nome);
	 	//cognome = new char[strlen(_cognome)+1];
		//strcpy(cognome, _cognome);
		nome= _nome; cognome = _cognome;
		eta= _eta;
		cout << "Persona Inizializzata in modo specifico\n";
	}

	//distruttore
	~Tpersona() {
		cout << "Distuggo: " << nome << " " << cognome << ". ";
		//in caso di allocazione dinamica con new
		delete[] nome;
		delete[] cognome;
		cout << "Persona distrutta\n";
	}

 	// metodo = 
	// nome per chiamare una funzione all'interno di una classe
	void stampa() const {  //questo metodo non cambia l'istanza
		 //si fa riferimento direttamente ai nomi dei campi
		 cout << nome << " " << cognome  << endl;
	 }

	//const Tpersona p2
	//    l'istanza p2 passata come riferimento non può essere cambiata
	// (..) const 
	//    l'istanza Tpersona (su cui è invocato il metodo) non può essere cambiata
	int confronta(const Tpersona p2) const {
		if (eta>p2.eta){
			 //cout << nome << " più vecchio di " << P2.nome;
			return -1;
		}
		if (eta<p2.eta){
			//cout << nome << " più giovane di " << P2.nome;
			return 1;
		}
		return 0;
	 }

};//end struct

// funzione stampa all'esterno della classe
// const 
//    perchè la funzione Stampa non deve cambiare l'istanza p
//    p.nome="aaa" non è permesso
void stampa(const Tpersona p){
	printf("\nlocazione persona in stampa: %0xd", &p);
	printf("\nlocazione nome in stampa: %0xd", p.nome);
	printf("\nlocazione cognome in stampa: %0xd\n\n", p.cognome);
		
	cout << p.nome << " " << p.cognome  << endl;
	//oppure
	// p.Stampa();
}

// funzione stampa all'esterno della classe
// const 
//    perchè la funzione Stampa non deve cambiare l'istanza p
//    p.nome="aaa" non è permesso
void stampa2(const Tpersona* p){
	printf("\nlocazione persona in stampa2: %0xd", p);
	printf("\nlocazione nome in stampa2: %0xd", p->nome);
	printf("\nlocazione cognome in stampa2: %0xd\n\n", p->cognome);
	cout << p->nome << " " << p->cognome  << endl;
	//oppure
	// p->Stampa();
}

int main(){	
	//Mario non esiste all'infuori del blocco delle {}
	//visibilità ristretta dell'istanza dell'oggetto Mario
	{
		Tpersona Mario;
		Tpersona Anna("Anna", "Rossi", 18);
		// invocazione funzione Stampa
		cout << "invocazione stampa Mario" << endl;
		printf("\nlocazione persona: %0xd", &Mario);
		printf("\nlocazione nome: %0xd", Mario.nome);
		printf("\nlocazione cognome: %0xd\n\n", Mario.cognome);
		stampa(Mario);	//passaggio di valore	
        	
		cout << "invocazione stampa Anna" << endl;
		printf("\nlocazione persona: %0xd", &Anna);
		printf("\nlocazione nome: %0xd", Anna.nome);
		printf("\nlocazione cognome: %0xd\n\n", Anna.cognome);
		stampa2(&Anna); //passaggio per riferimento
		
        // invocazione metodo Stampa
		cout << "invocazione Mario.stampa" << endl;
		Mario.stampa();
	    cout << "invocazione Anna.stampa" << endl;
		Anna.stampa();
		cout << "invocazione Mario.confronta Anna" << endl;
		cout << Mario.confronta(Anna) << endl;
		cout << "invocazione Anna.confronta Mario" << endl;
		cout << Anna.confronta(Mario) << endl;
		cout << "Prossima riga: chiusura blocco istruzioni" << endl;
	}
	cout << "Blocco istruzioni chiuso" << endl;
	// Mario viene distrutto dopo il blocco che lo contiene
	// Anna viene distrutto dopo il blocco che lo contiene
	//oppure 
	// si sarebbe dovuto invocare il rispettivo distrutture
    system("pause"); 
	return 0;
}
