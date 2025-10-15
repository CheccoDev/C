/* Esempi con variabili di tipo int */
#include <stdio.h>
#include <stdlib.h>

int scriviFile(int v[], int dim, char* nomefile);
int leggiFile(int v[], int* dim, char* nomefile);
int scriviFile_v2(int v[], int dim, FILE* f);
int leggiFile_v2(int v[], int *dim, FILE* f);



int main(int argc, char *argv[])
{
	int vet[5] = {0,1,4,9,16};	
	// Opzione 1
	// apertura e chiusua file in funzione
	char nome_file_1[30] = "esempio3.txt";
	int vet_letto[5];
	int dim; 
	int i;
	int ret;
	ret = scriviFile(vet, 5, nome_file_1);
	if(ret==0){
		printf("errore scrittura file (1)\n");
	}
	ret = leggiFile(vet_letto, &dim, nome_file_1);
	if(ret==0){
		printf("errore lettura file (1)\n");
	}else{
		printf("Lettura 1\n");
		for(i=0 ;i<dim ; i++)
			printf("%d ", vet_letto[i]);
		printf("\n");
	}
	
	// Opzione 2
	// apertura e chiusua file FUORI funzione
	char nome_file_2[30] = "esempio3_2.txt";
	int vet2[5] = {10,20,30,40,50};
	int vet2_letto[5];
	FILE *ff;
	if( (ff=fopen(nome_file_2, "w"))==NULL){
		printf("errore scrittura file (2)\n");
	}else{
		scriviFile_v2(vet2, 5, ff);
		fclose(ff);
	}
	
	if( (ff=fopen(nome_file_2, "r"))==NULL){
		printf("errore lettura file (2)\n");
	}else{
		leggiFile_v2(vet2_letto, &dim, ff);
		fclose(ff);
		printf("Lettura 2\n");
		for(i=0 ;i<dim ; i++)
			printf("%d ", vet2_letto[i]);
		printf("\n");
	}
	
  	return 0;
}


int scriviFile(int v[], int dim, char* nomefile){
	FILE *f;
	int i;
	f = fopen(nomefile, "w");
	if(f==NULL){
		printf("Errore apertura file. Array w");
		return 0;
	}
	for(i=0 ; i<dim ; i++){
		fprintf(f, "%d\n", v[i]);	
	}
	fclose(f);
	return 1;
}
int leggiFile(int v[], int *dim, char* nomefile){
	FILE* f;
	f = fopen(nomefile, "r");
	if(f==NULL){
		printf("Errore apertura file. Array r");
		return 0;
	}
	(*dim)=0;
	// opzione 1 -- utilizzo feof
	while( !feof(f) ){
		fscanf(f, "%d", &v[(*dim)]);
		(*dim)++;	
	}
	fclose(f);	
	return 1;
}
int scriviFile_v2(int v[], int dim, FILE* f){
	int i;
	for(i=0 ; i<dim ; i++){
		fprintf(f, "%d\n", v[i]);	
	}
	return 1;
}
int leggiFile_v2(int v[], int* dim, FILE* f){
	(*dim)=0;
	// opzione 1 -- utilizzo feof
	while( !feof(f) ){
		fscanf(f, "%d", &v[(*dim)]);
		(*dim)++;	
	}
}




