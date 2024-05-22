#include <stdio.h>

int main()
{
    int m = 300;     // Dichiara e inizializza una variabile intera m
    float fx = 300.60;  // Dichiara e inizializza una variabile float fx
    char cht = 'z';  // Dichiara e inizializza una variabile char cht

    int *pt1;     // Dichiara un puntatore a intero pt1
    float *pt2;   // Dichiara un puntatore a float pt2
    char *pt3;    // Dichiara un puntatore a char pt3

    pt1 = &m;     // Assegna l'indirizzo di m al puntatore pt1
    pt2 = &fx;    // Assegna l'indirizzo di fx al puntatore pt2
    pt3 = &cht;   // Assegna l'indirizzo di cht al puntatore pt3

    printf(" m = %d\n", m);       // Stampa il valore di m
    printf(" fx = %f\n", fx);     // Stampa il valore di fx
    printf(" cht = %c\n", cht);   // Stampa il valore di cht

    printf("\n Usando l'operatore & :\n");
    printf("-----------------------\n");
    printf(" indirizzo di m = %p\n", &m);   // Stampa l'indirizzo di m
    printf(" indirizzo di fx = %p\n", &fx); // Stampa l'indirizzo di fx
    printf(" indirizzo di cht = %p\n", &cht); // Stampa l'indirizzo di cht

    printf("\n Usando gli operatori & e * :\n");
    printf("-----------------------------\n");
    printf(" value at indirizzo di m = %d\n", *(&m));   // Stampa il valore all'indirizzo di m
    printf(" value at indirizzo di fx = %f\n", *(&fx)); // Stampa il valore all'indirizzo di fx
    printf(" value at indirizzo di cht = %c\n", *(&cht)); // Stampa il valore all'indirizzo di cht

    printf("\n Usando solo le variabili puntatore :\n");
    printf("----------------------------------\n");
    printf(" indirizzo di m = %p\n", pt1);  // Stampa l'indirizzo memorizzato in pt1
    printf(" indirizzo di fx = %p\n", pt2); // Stampa l'indirizzo memorizzato in pt2
    printf(" indirizzo di cht = %p\n", pt3); // Stampa l'indirizzo memorizzato in pt3

    printf("\n Usando solo gli operatori dei puntatori :\n");
    printf("----------------------------------\n");
    printf(" value at indirizzo di m = %d\n", *pt1); // Stampa il valore puntato da pt1
    printf(" value at indirizzo di fx= %f\n", *pt2); // Stampa il valore puntato da pt2
    printf(" value at indirizzo di cht= %c\n\n", *pt3); // Stampa il valore puntato da pt3
}