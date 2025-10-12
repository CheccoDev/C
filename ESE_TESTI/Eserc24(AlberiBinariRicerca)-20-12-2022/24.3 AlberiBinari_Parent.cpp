#include <cstdlib>
#include <iostream>
using namespace std;
//definizione di un albero binario
typedef struct Node {
  int dato;
  Node * parent;
  Node * left;
  Node * right;
  Node(int d) {
     dato = d;
     parent = NULL;
     left = right = NULL;
  }
}; 

typedef Node* tree;

//costrisce un albero binario non ordinato
tree Costruisci_Albero(int ETICHETTA,tree T,tree S,tree D)
{
	tree RADICE;
	RADICE = (Node *) malloc(sizeof(Node)); //chiede l'indirizzo di una nuova cella di memoria
	RADICE->dato = ETICHETTA;
	RADICE->parent = T;
	RADICE->left = S;
	RADICE->right = D;
	return (RADICE);
}
//restituisce il numero dei nodi dell'albero
int ContaNodi(tree RADICE)
{
	if(RADICE==NULL) return(0);
	else return(1 + ContaNodi(RADICE->left) + ContaNodi(RADICE->right));
}
//calcolo dell'altezza di un albero
int height (tree RADICE) {
   if (RADICE == NULL) return -1;
   int u = height(RADICE->left); // ordine non importante 
   int v = height(RADICE->right);
   if (u > v) return u+1;
   return v + 1;
}
//lunghezza del cammino di un albero
int path_length_recur(tree RADICE, int h) {
   if (RADICE == NULL) return 0;
   int ll = path_length_recur(RADICE->left, h+1);
   int lr = path_length_recur(RADICE->right, h+1);
   return h + ll + lr;
 }
int path_length(tree RADICE) {
    return path_length_recur(RADICE, 0);
}
 
//Funzioni di attraversamento
void preorder(tree RADICE, void visit(tree)) {
   if (RADICE == NULL) return;
   visit(RADICE);
   preorder(RADICE->left, visit);
   preorder(RADICE->right, visit);
}
void inorder(tree RADICE, void visit(tree)) {
   if (RADICE == NULL) return;
   inorder(RADICE->left, visit);
   visit(RADICE);
   inorder(RADICE->right, visit);
}
void postorder(tree RADICE, void visit(tree)) {
   if (RADICE == NULL) return;
   postorder(RADICE->left, visit);
   postorder(RADICE->right, visit);
   visit(RADICE);
}

//stampa di un albero
void print_node(tree nodo)
  {    cout <<  nodo->dato << " "; } 
  
void printnode(char x, int h) {
   for( int i = 0; i < h; i++) cout << "   ";
   cout << x << endl;
 }

void draw(tree RADICE, int h) {
   if (RADICE == NULL) { printnode('*', h); return;}
   draw(RADICE->right, h +1);
   printnode(RADICE->dato + 48, h);  //codifica ascii numero 0 = 48
   draw(RADICE->left, h+1);
 }

int main(int argc, char *argv[])
{
    tree t1= new Node(5);
    t1->left=Costruisci_Albero(2,t1,NULL,NULL);
    t1->right=Costruisci_Albero(7,t1,NULL,NULL);

    tree t2= new Node(4);
    t2->left=Costruisci_Albero(6,t2,NULL,NULL);
    t2->right=Costruisci_Albero(9,t2,NULL,NULL);
    t1->right=t2;
    
   	cout << endl<< "Visita pre-ordine albero:" << endl;
    preorder(t1, print_node);
 	cout << endl<< "Visita in-ordine albero:" << endl;   
    inorder(t1, print_node);
	cout << endl<< "Visita post-ordine albero:" << endl;    
    postorder(t1, print_node);
    cout << endl << "numero di nodi presenti:"<<ContaNodi(t1)<< endl;
    cout << endl << "altezza dell'Albero:"<<height(t1)<< endl;
    cout << endl << "lunghezza cammino albero:" << path_length(t1) << endl;
    draw(t1,0);
    system("PAUSE");
    return EXIT_SUCCESS;
}
