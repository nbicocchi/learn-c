#include <stdio.h>

int calculateLength(char* ch) // Prende in input il puntatore al primo carattere della stringa
{
    int ctr = 0;

    while (*ch != '\0') // Cicla finchè non viene trovato il carattere terminatore '\0'
    {
        ctr++; // Incrementa il contatore per ogni carattere trovato
        ch++; // Muove il puntatore al successivo carattere della stringa
    }

    return ctr;
}
int main()
{
    char *str1 = "Programmazione di sistema";
    int l;

    l = calculateLength(str1);
    printf(" La lunghezza della stringa %s è pari a %d caratteri.\n", str1, l);
}
