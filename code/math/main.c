#include <stdio.h>
#include "mymath.h"

int main() {
    unsigned int base = 3, exp = 5;
    unsigned int result = mypow(base, exp);
    printf("%u^%u = %u\n", base, exp, result);
    return 0;
}