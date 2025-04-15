#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* allocazione della memoria */
  int *p = malloc(sizeof(*p));

  /* impiego dell'area allocata */
  *p = 57;

  /* deallocazione memoria */
  free(p);

  /* Errore! Dangling Reference
   * L'area di memoria puntata da p non e' piu' disponibile !!!! */
  *p = 20;

  /* Non accedo alla memoria puntata da p
   * Accedo a p e lo faccio puntare a NULL */
  p = NULL;
}