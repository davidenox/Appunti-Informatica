/*Si scriva una funzione che elimini da una stringa in input
tutti i caratteri non alfabetici. La funzione abbia il seg. prototipo; 
void remove_non_alpha( char *a); */
#include <stdio.h>
#include <string.h>

void remove_non_alpha( char *a ) {
  int i, j;
  for (i = 0; a[i] != '\0'; i++) {
    if (a[i] >= 'a' && a[i] <= 'z') {
      a[j++] = a[i];
    } 
    else if (a[i] >= 'A' && a[i] <= 'Z') {
      a[j++] = a[i];
    }
  }
  a[j] = '\0';
}

int main() {
  char a[] = "b7489qbc478qbt7q0b!£$(())";
  remove_non_alpha(a);
  printf("a = %s\n", a);
  return 0;
}