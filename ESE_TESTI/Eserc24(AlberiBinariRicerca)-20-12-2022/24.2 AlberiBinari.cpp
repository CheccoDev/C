#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Tdato{
  int val;
  Tdato(){val=0;}
  Tdato(int d){val=d;}
  void stampa()const{ cout <<val;}      
} Tdato;
typedef struct Tnodo{
  Tdato dato;
  Tnodo* DX;
  Tnodo* SX;
  Tnodo(){DX=NULL, SX=NULL;}
  Tnodo(Tdato d, Tnodo* sx, Tnodo* dx){ dato=d; SX=sx; DX=dx; }
  void stampa()const{ dato.stampa();}        
} Tnodo;
typedef Tnodo* tree;
tree costruisci(Tdato d, tree sx, tree dx){
  tree Radice;   
  Radice = new Tnodo(d, sx, dx);  //C++
  //Radice = (Tnodo*)malloc(sizeof(Tnodo));  //C
  //Radice->dato = d;  Radice->SX = sx;  Radice->DX = dx; 
  return Radice;  
}
void preordine(tree Radice){
   if (!(Radice==NULL))   {
      Radice->stampa(); cout << ", ";                  
      preordine(Radice->SX);
      preordine(Radice->DX);
   }  
}
void inordine(tree Radice){
  if (!(Radice==NULL))  {
    inordine(Radice->SX);
    Radice->stampa(); cout << ", ";   
    inordine(Radice->DX);
  }   
}
void postordine(tree Radice){
  if (!(Radice==NULL))  
  {
    postordine(Radice->SX);
    postordine(Radice->DX);
    Radice->stampa(); cout << ", ";   
  }   
}
int ContaNodi(tree Radice){
 if (Radice==NULL){
   return 0;
 } else { 
   return (1 + ContaNodi(Radice->SX) + ContaNodi(Radice->DX)); 
 }   
}
int ContaFoglie(tree Radice){
   if (Radice==NULL)
    { return 0; }
   if ( (Radice->SX==NULL) && (Radice->DX==NULL) )
    { return 1; } 
   else
    { return (ContaFoglie(Radice->SX)+ContaFoglie(Radice->DX)); } 
}    

int Altezza(tree Radice){
 int AltSX=0, AltDX=0;
 if (Radice==NULL) { 
   return -1; 
 } else {
   AltSX=Altezza(Radice->SX);
   AltDX=Altezza(Radice->DX);
   if (AltSX>AltDX)
    { return (1+AltSX); }
   else
    { return (1+AltDX); } 
 }
}
void Stampa(tree Radice, int h){ 
  int i;
  if (Radice==NULL)
  {
    for(i=0; i<h; i++) {cout << " ";}
    cout << "*" << endl;
    return;
  }
  Stampa(Radice->DX, h+1);
  for (i=0; i<h; i++) {cout << " ";}
  Radice->stampa(); cout << endl;
  Stampa(Radice->SX, h+1);
}
bool Ricerca(tree Radice, Tdato x){
 if (Radice==NULL) {return false;} 
 if (Radice->dato.val==x.val) {return true;}
 else
 { return ( Ricerca(Radice->SX,x) || Ricerca(Radice->DX,x) );  }   
}
tree ins_ord(tree Radice, Tdato x){
  if (Radice==NULL) {
   Radice = new Tnodo(x,NULL,NULL);
   //Radice->dato=x;  Radice->SX=NULL;  Radice->DX=NULL;
   return Radice;                  
  } else {
   if (x.val<Radice->dato.val)
   { Radice->SX = ins_ord(Radice->SX,x); return Radice;}
   else
   { Radice->DX = ins_ord(Radice->DX,x); return Radice;}    
  }
}
bool RicercaBin(tree Radice, Tdato x){
  if (Radice==NULL) {return false;}
  if (Radice->dato.val == x.val) {return true;}
  else
  {
    if (Radice->dato.val > x.val)
      { return RicercaBin(Radice->SX,x); } 
    else
      { return RicercaBin(Radice->DX,x); }   
  }
}
bool PerfBil(tree Radice){
 if (Radice==NULL) { return true; }    
 if ( (Radice->SX==NULL) && (Radice->DX==NULL) )
   {return true;}
 else
   {
     if ( (Radice->SX!=NULL) && (Radice->DX!=NULL) )      
       { return (PerfBil(Radice->SX) && PerfBil(Radice->DX)); }
     else
       { return false; } 
   }  
}

int main(int argc, char *argv[])
{
 //Albero NON ordinato====================
  tree t1,t2,t3,t4,t;
  t1 = costruisci(Tdato(2), NULL, NULL);
  t2 = costruisci(Tdato(1), NULL, NULL);
  t3 = costruisci(Tdato(7), t1, t2);
  t1 = costruisci(Tdato(4), NULL, NULL);
  t2 = costruisci(Tdato(9), NULL, NULL);
  t4 = costruisci(Tdato(3), t1, t2);
  t = costruisci (Tdato(5), t3, t4);
  preordine(t); cout << endl;
  inordine(t); cout << endl;
  postordine(t); cout << endl;
  cout << "numero nodi=" << ContaNodi(t) << endl;
  cout << "numero foglie=" << ContaFoglie(t) << endl;
  cout << "altezza=" << Altezza(t) << endl;
  Stampa(t,0);
  cout << "cerca il numero 3:";
  if (Ricerca(t,Tdato(8))) { 
      cout << "TROVATO"<< endl;
  }else{
     cout << "NON TROVATO"<< endl; 
  }
  //Albero ordinato================================
  tree ord;
  int x;
  ord = NULL;
  do {
    cout << "insert valore (0 per finire)=";
    cin >> x; 
    if (x!=0) { ord = ins_ord(ord, x); } 
  }while(x!=0);
  Stampa(ord,0);
  inordine(ord); cout << endl;
  cout << "albero bilanciato?" << PerfBil(ord) << endl;

  system("PAUSE");	
  return 0;
}
