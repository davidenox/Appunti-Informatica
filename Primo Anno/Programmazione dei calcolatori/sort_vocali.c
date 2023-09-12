/*Si scriva una funzione C chiamata sort_by_vocals che prende in input una stringa a che 
rispetti le seguenti specifiche:
Prototipo: void sort_by_vocals( char *a );
Comportamento: dispone i caratteri di a in modo tale che le vocali precedano tutti gli altri
caratteri; tra la sequenza di vocali e la sequenza degli altri caratteri deve valere 
l'ordinamento lessicografico. Ad esempio se a è la stringa:
.pr0grAmMaz1onE-C*
dopo l'esecuzione di sort_by_vocals(a) a risulterà essere
AEao*-.01CMgmnprrz
Si calcoli il costo computazionale della funzione sia in termini di tempo che di memoria
supplementare utilizzata.
*/
#include <stdio.h>
#include <string.h>

void sort_by_vocals(char *a) {
    int len = strlen(a);
    char vowels[len + 1];
    char consonants[len + 1];
    int vowels_count = 0;
    int consonants_count = 0;

    for (int i = 0; i < len; i++) {
        char c = a[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // Check if the character is a vowel (case-insensitive)
            if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
                c == 'o' || c == 'O' || c == 'u' || c == 'U') {
                vowels[vowels_count++] = c;
            } else {
                consonants[consonants_count++] = c;
            }
        }
    }

    // Null-terminate the vowel and consonant arrays
    vowels[vowels_count] = '\0';
    consonants[consonants_count] = '\0';

    // Sort the vowel and consonant arrays lexicographically
    for (int i = 0; i < vowels_count - 1; i++) {
        for (int j = i + 1; j < vowels_count; j++) {
            if (vowels[i] > vowels[j]) {
                char temp = vowels[i];
                vowels[i] = vowels[j];
                vowels[j] = temp;
            }
        }
    }

    for (int i = 0; i < consonants_count - 1; i++) {
        for (int j = i + 1; j < consonants_count; j++) {
            if (consonants[i] > consonants[j]) {
                char temp = consonants[i];
                consonants[i] = consonants[j];
                consonants[j] = temp;
            }
        }
    }

    // Combine the sorted vowel and consonant arrays
    strcpy(a, vowels);
    strcat(a, consonants);
}

int main() {
    char a[] = ".pr0grAmMaz1onE-C*";
    sort_by_vocals(a);
    printf("%s\n", a);
    return 0;
}
