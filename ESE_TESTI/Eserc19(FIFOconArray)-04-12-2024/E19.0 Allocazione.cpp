#include <iostream>
using namespace std;

typedef struct Tdato{
	int index;
	float value;
	Tdato(){
		index=0; 
		value=0.0;
		cout << "Costruttore Tdato default" << endl;
	}
	Tdato(int _index, float _value){
		index=_index; 
		value=_value;
		cout << "Costruttore Tdato specifico" << endl;
	}
}Tdato;
typedef struct Tcoda{
	int n;
	int dim;
	int head;
	int tail;
	Tdato *s;
	Tcoda(){
		dim = 3;
		head = tail = 0;
		s = new Tdato[3];
		cout << "Costruttore Tcoda default" << endl;
	}
	Tcoda(int _dim){
		dim = _dim;
		head = tail = 0;
		s = new Tdato[_dim];
		cout << "Costruttore Tcoda specifico" << endl;
	}
	~Tcoda(){
		delete [] s;
	}
}Tcoda;
typedef Tcoda Coda;
typedef Tcoda* Codaptr;

int main(int argc, char** argv) {
	cout << "alloc statica Tcoda q1()" << endl;
	cout << "Coda q1" << endl;
	Coda q1;
	cout << "----" << endl;
	cout << "alloc statica Tcoda q2(6)" << endl;
	cout << "Coda q2(6)" << endl;
	Coda q2(6);
	cout << "----" << endl;
	
	cout << "dichiarazione puntatore Tcoda q3" << endl;
	cout << "Codaptr q3" << endl;
	Codaptr q3;
	// sarebbe meglio inizializzare q3=NULL
	cout << "----" << endl;
	
	cout << "allocazione puntatore Tcoda q4" << endl;
	cout << "Codaptr q4 = new Coda()" << endl;
	Codaptr q4 = new Coda();
	cout << "----" << endl;
	delete c4;
	
	cout << "allocazione puntatore Tcoda q4" << endl;
	cout << "Codaptr q5 = new Coda(8)" << endl;
	Codaptr q5 = new Coda(8);
	cout << "----" << endl;
	delete c5;
	
	cout << "dichirazione array di puntatori Tcoda q6[2]" << endl;
	cout << "Codaptr q6[2];" << endl;
	Codaptr q6[2];
	// sarebbe meglio inizializzare ogni elemento a NULL
	cout << "----" << endl;
	
	cout << "Codaptr q7[2];" << endl;
	Codaptr q7[2];
	cout << "q7[0] = new Coda();" << endl;
	q7[0] = new Coda();
	cout << "q7[1] = new Coda(6);" << endl;
	q7[1] = new Coda(6);
	cout << "----" << endl;
	delete q7[0];
	delete q7[1];
	
	return 0;
}
