#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Tdata {
	int giorno;
	int mese;
	int anno;
	~Tdata(){
		cout << "data distrutta"<<endl;
	}
	Tdata(){
		giorno=mese=anno=0;
	}
	Tdata(int g, int m, int a){
		giorno=g; mese=m; anno=a;
	}
	/*const dopo la definizione del nome del metodo
	  rende il metodo in sola lettura
      degli attibuti della struct
	*/
	void stampa()const{
        printf("%d/%d/%d",giorno,mese,anno);
    }
}Tdata;
void stampaFunz (Tdata d);
Tdata foo ();

int main(int argc, char *argv[])
{
	Tdata d1(1, 11, 2016);
   	cout << "data in main " << &d1 << endl;
   	stampaFunz(d1);
   	Tdata d2;
   	d2 = foo();
   	cout << "data2 in main" << &d2 << endl;
   	Tdata d3 = foo();
   	cout << "data3 in main" << &d3 << endl;
      	
	return EXIT_SUCCESS;
}

void stampaFunz (Tdata d) { 
   cout << "data in Funz " << &d << endl; 
   d.stampa(); 
}

Tdata foo (){ 
   Tdata d(5, 12, 2016); 
   cout << "data in foo " << &d << endl;
   return d; 
}

