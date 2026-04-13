#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int f(int n)
{
    return n;
}

int main(void)
{
    int i = 0;

    while (true) {
        i++;
        if (i == 9998) {
            continue;
        }
        printf("%d\n", i);

        if (i > 10000) {
            break;
        }
    }
}
