#include <stdio.h>
#include <stddef.h>
// Definizione di una struttura per memorizzare i dati di un dipendente
struct employee {
    char *empname;  // Nome dipendente (string pointer)
    int empid;      // ID dipendente (integer)
};

int main() {

    // Inizializzazione delle strutture con i valori
    static struct employee emp1 = {.empname="John", .empid=1001}, emp2 = {.empname="Alex", .empid=1002}, emp3 = {.empname="Taylor", .empid=1003};

    // Creazione di un array di puntatori a struct employee
    struct employee (*arr[]) = {&emp1, &emp2, &emp3};

    // Creazione di un puntatore ad un array di puntatori a struct employee
    struct employee (*(*pt)[3]) = &arr; // pt memorizza l'indirizzo dell'array di puntatori

    // Stampa il nome dell'employee usando il puntatore ad un array di puntatori a struct employee
    printf(" Employee Name : %s \n", (**(*pt + 1)).empname);

    printf("---------------- Spiegazione --------------------\n");
    printf("(**(*pt+1)).empname\n");
    printf("= (**(*&arr+1)).empname   come pt=&arr\n");
    printf("= (**(arr+1)).empname     dalla regola che *&pt = pt\n");
    printf("= (*arr[1]).empname       dalla regola che *(pt+i) = pt[i]\n");
    printf("= (*&emp2).empname        come arr[1] = &emp2\n");
    printf("= emp2.empname = Alex       dalla regola che *&pt = pt\n\n");

    // Stampa l'employee ID usando il puntatore ad un array di puntatori a struct employee
    printf(" Employee ID :  %d\n", (*(*pt + 1))->empid);

    printf("---------------- Spiegazione --------------------\n");
    printf("(*(*pt+1))-> empid\n");
    printf("= (**(*pt+1)).empid     dalla regola -> = (*).\n");
    printf("= emp2.empid = 1002\n");
    printf("\n\n");

    return 0;
}