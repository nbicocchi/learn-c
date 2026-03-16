#include <stdio.h>

long addTwoNumbers(long *n1, long *n2) {
    long sum;
    sum = *n1 + *n2; // Calcola la somma dereferenziando i puntatori n1 e n2
    return sum;
}

int main() {
    long fno, sno, sum;

    printf(" Inserisci il primo numero intero : ");
    scanf("%ld", &fno);
    printf(" Inserisci il secondo numero intero : ");
    scanf("%ld", &sno);

    sum = addTwoNumbers(&fno, &sno);

    printf(" La somma di %ld e %ld è pari a %ld\n", fno, sno, sum);
    return 0;
}
