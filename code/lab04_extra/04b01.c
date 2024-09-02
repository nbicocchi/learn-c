#include <stdio.h>

int main(void)
{
    int m = 10, n, o;
    int *z = &m; // Dichiara un puntatore a intero z e gli assegna l'indirizzo di m

    // Stampa le informazioni di base su puntatori e variabili
    printf("\n\n Puntatore: mostra la dichiarazione di base del puntatore :\n");
    printf("-------------------------------------------------------\n");
    printf(" m=10, n e o sono due variabili integer e *z è un integer");
    printf("\n\n z memorizza l'indirizzo di m  = %p\n", z); // Stampa l'indirizzo memorizzato in z utilizzando %p
    printf("\n *z memorizza il valore di m = %d\n", *z); // Stampa il valore puntato da z utilizzando *z
    printf("\n &m memorizza l'indirizzo di m = %p\n", &m); // Stampa l'indirizzo di m usando &m
    printf("\n &n memorizza l'indirizzo di n = %p\n", &n); // Stampa l'indirizzo di n usando &n
    printf("\n &o memorizza l'indirizzo di o = %p\n", &o); // Stampa l'indirizzo di o usando &o
    printf("\n &z memorizza l'indirizzo di z = %p\n\n", &z); // Stampa l'indirizzo di z usando &z
}