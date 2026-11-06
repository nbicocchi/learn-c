#include "mymath.h"

unsigned int mypow(unsigned int base, unsigned int exp) {
    unsigned int result = 1;
    for (unsigned int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}