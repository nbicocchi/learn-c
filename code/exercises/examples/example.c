#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int f(int n)
{
    return n;
}

int main(void) {
    char s1[] = "Hello World!";
    char *s2 = "Hello World!";

    s1[0] = 'a';    /* OK */
    s2[0] = 'a';    /* Errore a runtime */

    s2 = s1;        /* OK */
    s1 = s2;        /* Errore in compilazione */

    printf("%lu %lu\n", sizeof(s1), sizeof(s2));    /* Output: 13 8 */
}
