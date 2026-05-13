#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main(void) {
    int i;
    char *nomi[] = {
        "Sara",
        "Sebastiano",
        "Paolo",
        "Agostino",
        "Elvira",
        NULL
};
    char **p;

    for (i = 0; i < 5; i++) {
        printf("[%d] %s\n", i, nomi[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("[%d] %s\n", i, *(nomi + i));
    }

    i = 0;
    for (p = nomi; *p; p++) {
        printf("[%d] %s\n", i++, *p);
    }
}