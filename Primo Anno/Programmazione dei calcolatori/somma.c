#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Si scriva un programma, chiamato somma, che legga gli argomenti dalla linea 
di comando e stampi la somma di quelli che rappresentano numeri. 
Ad esempio l’esecuzione di
$> ./somma 3.14 peppa pig 2 1.2 programma
deve stampare 6.34.
*/

float somma(int a, char *b[]){
    float somma = 0.0;
    int i;
    for ( i = 0; i < a; i++){
        char *fineptr;
        float num = strtof(b[i], &fineptr);
        
        if(*fineptr != '\0'){
            continue;
        }
        somma += num;
    }
    return somma;
}

int main(int a, char *b[]){
    
    float risultato = somma( a, b);
    printf("%.2f\n", risultato);
    return 0;
}