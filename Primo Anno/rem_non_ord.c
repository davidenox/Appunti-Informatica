/*Progettare una funzione che rimuove da una stringa a in input tutti i caratteri che non sono 
in ordine lessicografico con i precedenti a partire dal primo simbolo. Dopo l'operazione a
risulterà ordinata lessicograficamente.
Esempio: Sia a[] = "ddabeceffgfh", la funzione deve modificare a in modo che essa rappresenti la
stringa "ddeeffgh". La funzione dovrà avere il seguente prototipo:
void rimuovi_non_ordinati(char *a);
Dove a rappresenta la stringa in input.
Si calcoli il costo computazionale della funzione sia in termini di tempo che di memoria 
supplementare utilizzata.
Non possono essere utilizzate funzioni della libreria string tranne la funzione strlen()*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void rimuovi_non_ordinati(char *a) {
//   int i, j;
//   // Crea una lista vuota per memorizzare i caratteri di a in ordine lessicografico.
//   int len = strlen(a);
//   char *b = malloc(len + 1);
//   // Itera su ogni carattere c di a.
//   for (i = 0; a[i] != '\0'; i++) {
//     // Se c è in ordine lessicografico con l'ultimo carattere di b, aggiungilo a b.
//     if (i == 0 || a[i] >= b[i-1]) {
//       b[i] = a[i];
//     }
//   }
//   // Aggiungi il carattere di terminazione alla fine di b.
//   b[i] = '\0';
//   // Copia b in a.
//   for (i = 0; b[i] != '\0'; i++) {
//     a[i] = b[i];
//   }
//   // Libera la memoria allocata per b.
//   free(b);
// }

// int main () {
//     char a[] = "ddabeceffgfh";

//     rimuovi_non_ordinati(a);

//     printf("%s",a);

#include <stdio.h>
#include <string.h>

void rimuovi_non_ordinati(char *a) {
    if (a == NULL || strlen(a) <= 1) {
        // Gestione degli errori o stringhe vuote
        return;
    }

    int length = strlen(a);
    int writeIndex = 1;

    for (int i = 1; i < length; i++) {
        if (a[i] >= a[writeIndex - 1]) {
            a[writeIndex] = a[i];
            writeIndex++;
        }
    }

    a[writeIndex] = '\0';
}

int main() {
    char a[] = "ddabeceffgfh";
    printf("Stringa originale: %s\n", a);
    printf("%d\n",strlen(a));
    rimuovi_non_ordinati(a);

    printf("Stringa modificata: %s\n", a);
    printf("%d\n",strlen(a));
    return 0;
}

