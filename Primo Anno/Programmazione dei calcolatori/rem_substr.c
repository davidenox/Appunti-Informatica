/*Date due stringhe a e b, progettare una funzione che rimuove b da a nel caso in cui 
b sia sottostringa di a. La funzione deve restituire 0 se b non è sottostringa di a, 
1 altrimenti. Infine, la quantità di memoria supplementare utilizzata dalla funzione 
(ovvero quella allocata all’interno della funzione) deve essere costante.*/
#include <stdio.h>
#include <string.h>

int remove_substring(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_b > len_a) {
        return 0;
    }

    int i, j;
    for (i = 0; i <= len_a - len_b; i++) {
        for (j = 0; j < len_b; j++) {
            if (a[i + j] != b[j]) {
                break;
            }
        }
        if (j == len_b) {
            // La sottostringa b è stata trovata in a
            int k;
            for (k = i; k < len_a - len_b; k++) {
                a[k] = a[k + len_b];
            }
            a[k] = '\0';
            return 1;
        }
    }

    return 0; // b non è una sottostringa di a
}

int main() {
    char a[] = "programmazione";
    char *b = "gramma";

    int result = remove_substring(a, b);

    if (result) {
        printf("%s\n", &a);
    } else {
        printf("sottostringa non trovata\n");
    }

    return 0;
}
