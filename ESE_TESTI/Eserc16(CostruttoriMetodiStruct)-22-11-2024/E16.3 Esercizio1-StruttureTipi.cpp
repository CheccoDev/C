#include <cstdlib>
#include <iostream>
using namespace std;

void stampadata(int g, int m, int a);

//dichiarazione alternativa dell'header di una funzione
//è possibile omettere il nome dei paramentri formali
//void stampadata(int, int, int);

typedef struct Tdata {	
	int giorno;
	int mese;
	int anno;
	Tdata (int g, int m, int a)//costruttore specifico
	{ giorno=g; mese=m; anno=a;}
	Tdata (int g, int m)//costruttore specifico
	{ giorno=g; mese=m; anno=2009; } 
	Tdata (int g)//costruttore specifico
	{ giorno=g; mese=1; anno=2009; } 
	Tdata ()//costruttore di default
	{ giorno=1; mese=1; anno=2000; }
	void stampa(){
		cout << "Giorno = " << giorno ;
		cout << " Mese = " << mese;
		cout << " Anno = " << anno << endl;	
	}
	int cmp(Tdata d){
		if( anno > d.anno ) return 1;
		if( anno < d.anno ) return -1;
		if( mese > d.mese ) return 1;
		if( mese < d.mese ) return -1;
		if( giorno > d.giorno ) return 1;
		if( giorno < d.giorno ) return -1;
		return 0;
	}
	   
}Tdata;

int main(int argc, char *argv[])
{
	Tdata oggi = Tdata(4, 11, 2018); //inizializza i campi di specifica data 
	Tdata ieri(3, 11, 2018); //inizializza i campi di specifica data
	Tdata inizioanno; // inizializza campi con ti in costruttore default
	// stampa con funzione
	stampadata(oggi.giorno, oggi.mese, oggi.anno);
	stampadata(ieri.giorno, ieri.mese, ieri.anno);
	stampadata(inizioanno.giorno, inizioanno.mese, inizioanno.anno);
	// stampa con metodo
	oggi.stampa();
	ieri.stampa();
	inizioanno.stampa();
	
	switch(ieri.cmp(oggi)){
		case -1: cout << "data antecedente" << endl; break;
		case 1: cout << "data successiva" << endl; break;
		case 0: cout << "date uguali" << endl; break;
	}
	switch(oggi.cmp(ieri)){
		case -1: cout << "data antecedente" << endl; break;
		case 1: cout << "data successiva" << endl; break;
		case 0: cout << "date uguali" << endl; break;
	}
	switch(oggi.cmp(oggi)){
		case -1: cout << "data antecedente" << endl; break;
		case 1: cout << "data successiva" << endl; break;
		case 0: cout << "date uguali" << endl; break;
	}
	
	Tdata domani;
	domani=oggi;
	domani.stampa();
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

void stampadata(int g, int m, int a) {
	cout << "Giorno = " << g ;
	cout << " Mese = " << m;
	cout << " Anno = " << a << endl;
}
