/*Si scriva una funzione che prenda in input una stringa a ed un 
array binario b (di interi in { 0, 1}) della stessa lunghezza di
a ed elimini da a i caratteri nelle posizioni per cui b[i] vale 0. 
La funzione abbia il seguente prototipo:
void filtra( char *a, int *b );
*/
#include <stdio.h>
#include <string.h>

void filtra(char *a, int *b) {
    
    int len = strlen(a);
    printf("%d\n",len);
    
    int j = 0;
    for(int i=0 ; i < len; i++ ){
        if(b[i] == 1){
            a[j] = a[i];
            j++;
        }
    }
    a[j] = '\0';
}

int main(){
    char a[] = "algoritmo";
    int b[] = {0, 0, 0, 1, 0, 0, 1, 0, 1};
    filtra(a, b);
    printf("%s\n", a);

}