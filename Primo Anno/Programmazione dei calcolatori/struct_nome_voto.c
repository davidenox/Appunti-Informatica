/*
Creare una semplice struct alunno che contiene il nome, il cognome e il voto. 
Dopo inserire da 1 a 20 alunni al massimo e permettere di effettuare una ricerca 
per cognome dell’alunno. 
Se ci sono più alunni con lo stesso cognome visualizzarli entrambi.
*/
#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct {
	char cognome[30];
	char nome[20];
	int voto;
}alunno;

int main() {
  	alunno a[MAX];
  	int n,i,j,trovato;
  	char cerca[20];
  
  	do{
  	printf("Inserisci il numero di alunni:");
	scanf("%d", &n);	 
	} while (n<1 || n>MAX);
	
	for(i=0; i<n; i++){
		printf("Inserisci il cognome dell'alunno:");
		scanf("%s", a[i].cognome);
		printf("Inserisci il nome dell'alunno:");
		scanf("%s", a[i].nome);
		printf("Inserisci il voto:");
		scanf("%d", &a[i].voto);
	}
	
	printf("\nInserisci il cognome dell'alunno da cercare: ");
	scanf("%s", cerca);
	
	trovato=0;
	for(j=0;j<n;j++){
		if(strcmp(a[j].cognome, cerca)==0) {
			printf("\nAlunno trovato in posizione %d.\n%s\t%d\n",j+1,a[j].nome, a[j].voto);
			trovato=1;
		}	
	}
	
	if (!trovato) 
		printf("\nAlunno non trovato.\n");

  return 0;
}