#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define true 1
#define false 0
#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;

    printf("argc=%d\n", argc);

    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}