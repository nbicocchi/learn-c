#include <float.h>
#include <limits.h>
#include <stdio.h>

void stampa_array(const int *v, unsigned size) {
  unsigned i;

  for (i = 0; i < size; i++) {
    printf("%d\n", v[i]);
  }
}

int main(void) {
  int v[16];
  int *v2 = v;

  printf("%ld\n", sizeof(v));     /* 64 */
  printf("%ld\n", sizeof(v2));    /* 8 */
  printf("%p\n", &v[0]);          /* 0x7ffee0d7c8a0 */
  printf("%p\n", v);              /* 0x7ffee0d7c8a0 */
  printf("%p\n", &v2);            /* 0x7ffee0d7c898 */
}
