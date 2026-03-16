#include <stdio.h>

// Definizione di una struttura per memorizzare i dati di un dipendente
struct empAddress {
    char *ename;        // Nome dipendente (string pointer)
    char stname[20];    // Indirizzo (array di caratteri)
    int pincode;        // Pincode (integer)
};
// Inizializzazione della struttura
struct empAddress employee = {"John Alter", "Court Street \n", 654134};
struct empAddress *pt = &employee;

int main() {
    printf(" %s from %s \n\n", pt->ename, (*pt).stname);
    return 0;
}