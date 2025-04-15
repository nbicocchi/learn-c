#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int *p;
  /* Dipendente dal tipo di dato */
  p = malloc(10 * sizeof(int));

  /* Indipendente dal tipo di dato, da preferire */
  p = malloc(10 * sizeof(*p));
}