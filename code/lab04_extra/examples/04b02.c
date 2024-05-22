#include <stdio.h>

int main()
{
    int* ab; // Dichiara un puntatatore ad intero ab
    int m;   // Diachiara una variabile di tipo integer m

    m = 29; // Assegna il valore 29 alla variabile m

    printf("\n\n Puntatore : come gestire i puntatori :\n");
    printf("------------------------------------------------------------\n");
    printf(" Indirizzo di m : %p\n", &m); // Stampa l'indirizzo della variabile m
    printf(" Valore di m : %d\n\n", m); // Stampa il valore della variabile m

    ab = &m; // Assegna l'indirizzo di m al puntatore ab

    printf(" Indirizzo del puntatore ab : %p\n", ab);      // Stampa l'indirizzo memorizzato nel puntatore ab
    printf(" Contenuto del puntatore ab : %d\n\n", *ab);   // Stampa il valore riferito da ab

    m = 34; // Assegna il valore 34 alla variabile m

    printf(" Indirizzo del puntatore ab : %p\n", ab);      // Stampa l'indirizzo memorizzato nel puntatore ab
    printf(" Contenuto del puntatore ab : %d\n\n", *ab);   // Stampa il valore riferito da ab

    *ab = 7; // Assegna il valore 7 alla variabile puntata da ab

    printf(" Indirizzo di m : %p\n", &m);               // Stampa l'indirizzo della variabile m
    // siccome ab contiene l'indirizzo di m
    // *ab ha cambiato il valore di m ed ora è diventato 7
    printf(" Valore di m : %d\n\n", m);                 // Stampa il valore della variabile m

    return 0;
}