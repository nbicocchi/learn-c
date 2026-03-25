#include <stdio.h>
#include <math.h>

int main() {
    printf("Dimostrazione: float 32-bit non rappresenta tutti gli interi grandi\n\n");

    // Consideriamo numeri grandi consecutivi
    int i;
    for (i = 16777215; i <= 16777230; i++) {
        float f = (float) i; // conversione a float
        int back = (int) f;  // conversione float -> int

        printf("Intero originale: %d, Float -> Int: %d", i, back);
        if (back != i) {
            printf("  <-- non rappresentabile esattamente!");
        }
        printf("\n");
    }

    return 0;
}