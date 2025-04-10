# Le funzioni
Una funzione è una sequenza di istruzioni che vengono attivate a seguito di una apposita chiamata.

Vantaggi: 
  * favoriscono modularizzazione del codice
  * favoriscono il riuso del codice (librerie) 
  * favoriscono lo sviluppo incrementale (creazione di interfacce che disaccoppiano parti di software)
  * favoriscono la leggibilità del codice
    
Svantaggi:
  * Determinazione dell’indirizzo di rientro al codice chiamante 
  * Scambio di informazioni fra funzioni e codice chiamante (passaggio di parametri)

## Dichiarazione di funzioni
Serve per segnalare al compilatore l'esistenza di una determinata funzione (e come invocarla) ma non specifica le istruzioni che compongono la funzione. La dichiarazione specifica il *prototipo* della funzione:
* il tipo ritornato
* il nome della funzione
* l'elenco dei parametri (argomenti)

La *dichiarazione* di una funzione deve sempre precedere nel sorgente la prima invocazione della stessa. La *definizione*, invece, può essere presente in un qualunque punto del sorgente o in una libreria esterna.



```c
int secondi(int h, int m, int s);
/* in fase di dichiarazione è possibile omettere il nome dei parametri */
int secondi(int, int, int);
```

## Definizione di funzioni
Una definizione è costituita da due parti:
  
* la *dichiarazione della funzione*
* il *corpo della funzione*, racchiuso tra parentesi graffe e comprendente zero o più di queste componenti:
  * dichiarazioni e definizioni di variabili
  * istruzioni
  * istruzione return

```c
/* esempio di definizione */
int secondi(int h, int m, int s) {
    return (3600 * h + 60 * m + s);
}
```

## Invocazione di funzioni
L'*invocazione* di una funzione è l'operazione con la quale si richiama l'esecuzione della funzione. Per richiamare una funzione si deve utilizzare il nome della funzione seguita dagli argomenti racchiusi da parentesi tonde e separati da virgole. Un'invocazione di funzione trasferisce il controllo alla prima istruzione della funzione stessa.

Una funzione termina quando: (a) viene eseguita l'istruzione *return*, oppure (b) viene eseguita l'ultima istruzione.

```c
int secondi(int h, int m, int s) {
    return (3600 * h + 60 * m + s);
}

int main() {
    int h=1, m=1, s=1, totale_secondi;
    totale_secondi = secondi(h, m, s);
    printf("Totale secondi: %d\n", totale_secondi);
}
```

## Tipo void
L’uso del tipo *void* nelle funzioni identifica *tipi nulli*:
* se usato come tipo di ritorno, la funziona non restituisce alcun valore
* se usato come parametro di input, la funzione non accetta nessun parametro

```c
void say_hi(void) {
    printf("Hi!\n");
}

int main() {
    say_hi():
    return 0;
}
```

## Tempo di vita delle variabili locali
Le variabili che abbiamo utilizzato fin’ora sono *variabili locali*, visibili solo all’interno della funzione.

La gestione della memoria delle variabili locali è *automatica*:
  * Le variabili vengono allocate al momento dell’invocazione della funzione
  * Le variabili vengono de-allocate al momento del ritorno della funzione

Ad ogni invocazione, le variabili della funzione non dipendono dalle esecuzioni precedenti!


## Variabili globali
Il C supporta anche *variabili globali*, visibili sempre e da tutte le funzioni. *E' Preferibile limitare al massimo l'utilizzo di variabili globali (tutti possono scriverle!), oppure utilizzarle come costanti.*

```c
#include <stdio.h>

int a;
/* const int a; -> errore! */

void try_modification(void){
    a = 10;
}

int main(){
    a = 5;
    try_modification(); /* a = 10 */
    printf("a=%d\n", a);
}
```

## Variabili locali static
Una variabile locale è detta *static* se il suo tempo di vita corrisponde a quelllo del processo. E' possibile utilizzare variabili *static* per avere funzioni che mantengono uno stato fra diverse invocazioni.

```c
void counter() {
    static int count=0;
    
    count++;
    printf("count=%d\n", count);
}

int main(){
    counter(); /* count=1 */
    counter(); /* count=2 */
    
    return 0;
}
```

## Passaggio per valore (copia del valore)
Secondo la modalità del passaggio per valore *ogni funzione ha una propria zona di memoria per memorizzare i dati* (messa a disposizione solo al momento dell’effettivo utilizzo e rilasciata quando non è più necessaria).

Al momento dell’uso della funzione *i parametri sono copiati*, quindi non vi è un accesso diretto ai valori del chiamante.

```c
void scambia(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 2, b = 3;
    scambia(b, a);
    printf("a=%d b=%d\n", a, b);
}
```

![Passaggio di parametri per valore](./images/passaggio_valore.avif)


## Passaggio per riferimento (copia del riferimento)
Il passaggio per riferimento *implica il passaggio in copia di un puntatore alla variabile* e permette alla funzione chiamata di modificare il valore della variabile passata dal chiamante.


```c
void scambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 2, b = 3;
    scambia(&b, &a);
    printf("a=%d b=%d\n", a, b);
}
```

![Passaggio di parametri per valore](./images/passaggio_riferimento.avif)


## Passaggio di puntatori const
Talvolta è necessario passare alla funzione variabili di grandi dimensioni (array, matrici). Per evitare la copia della variabile si usa un puntatore alla variabile. Tuttavia, questa possibilità si scontra con il fatto che, tramite il puntatore, la funzione può modificare i dati del chiamante. Questo può determinare che un errore di implementazione nella funzione propaghi esiti non voluti. 

Il problema è risolvibile attraverso *puntatori definiti costanti*

```c
void scambia(const int *a, const int *b) {
    int tmp = *a;
    *a = *b;        /* errore di compilazione */
    *b = tmp;       /* errore di compilazione */
}

int main() {
    int a = 2, b = 3;
    scambia(&b, &a);
    printf("a=%d b=%d\n", a, b);
}
```

## Passaggio di parametri al programma principale
E' possibile passare parametri *dalla shell* ad *un programma C* utilizzando parametri opzionali della funzione main():
* *argc* è un numero intero e rappresenta il numero dei parametri ricevuti (considerando anche il comando stesso)
* *argv* è un array di stringhe che rappresenta i parametri passati a linea di comando (*argv[0]* è il comando stesso)

```c
int main(void) {
    
}
```

```c
int main(int argc, char *argv[]) {
    
}
```

Ad esempio:

```c
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int a;
    double b;
    char c[128];

    if (argc != 4) {
        printf("usage: %s int double char[]\n", argv[0]);
        exit(1);
    }
    
    a = atoi(argv[1]);
    b = atof(argv[2]);
    strncpy(c, argv[3], sizeof(c));
    /* secure code, guarantees that the string is null-terminated */
    c[sizeof(c) - 1] = '\0';
    printf("%d %f %s\n", a, b, c);
}
```


## Ricorsione
Una funzione è definita in modo ricorsivo se è definita in termini di se stessa. Nella definizione ricorsiva di una funzione è possibile identificare *casi base* e *casi ricorsivi*:
* I *casi base* permettono di calcolare il valore della funzione, anche se solo nei casi più semplici
* I *casi ricorsivi* permettono di calcolare la funzione mediante altre valutazioni della funzione

```c
// caso base e casi ricorsivi per il calcolo del fattoriale

n! = 1 x 2 x ... x (n-2) x (n-1) x n

n! = 1            (if n == 0) // caso base
n! = n x (n-1)!   (if n > 0)  // caso ricorsivo
```

**Tuttavia, la ricorsione ha alcuni svantaggi:**

1. **Consumo di memoria** – Ogni chiamata ricorsiva aggiunge un nuovo frame allo stack, e se la profondità della ricorsione è troppo grande, si può esaurire lo spazio disponibile, causando un errore di "stack overflow".
2. **Prestazioni inferiori rispetto agli approcci iterativi** – Le chiamate di funzione hanno un overhead non trascurabile, e il costo di mantenere lo stack delle chiamate può rendere la ricorsione più lenta rispetto a un approccio iterativo equivalente.
3. **Rischio di ridondanza nei calcoli** – Senza ottimizzazioni come la **memoization** o la **ricorsione di coda**, la ricorsione può ricalcolare gli stessi valori più volte, riducendo l'efficienza (ad esempio, nel calcolo ingenuo dei numeri di Fibonacci).

In molti casi, un approccio iterativo può essere più efficiente, evitando il rischio di stack overflow e riducendo l'overhead delle chiamate di funzione. 


### Ricorsione (fattoriale)
```c
// implementazione fattoriale iterativa
int fatt(int n) {
    int fatt, i;
    for (i = 1, fatt = 1; i <= n; i++) {
        fatt = fatt * i;
    }
    return fatt;
}
```

```c
// implementazione fattoriale ricorsiva
int fattr(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fatt_r(n - 1);
}
```

### Ricorsione (fibonacci)

```c
#include <stdio.h>
#include <time.h>

// implementazione fibonacci iterativa
unsigned int fibonacci(unsigned int n) {
  int x = 0, y = 1, z = 0;
  for (int i = 0; i < n - 1; i++) {
    z = x + y;
    x = y;
    y = z;
  }
  return z;
}

// implementazione fibonacci ricorsiva
unsigned int fibonaccir(unsigned int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return (fibonaccir(n-1) + fibonaccir(n-2));
}

int main() {
  unsigned int n = 40;
  clock_t start;
  clock_t end;
  double duration;

  // iterative benchmark
  start = clock();
  printf("iterative benchmark: %ud\n", fibonacci(n));
  end = clock();

  duration = (double) (end - start) / CLOCKS_PER_SEC;
  printf("%.5lf seconds\n", duration);

  // recursive benchmark
  start = clock();
  printf("recursive benchmark: %ud\n", fibonaccir(n));
  end = clock();

  duration = (double) (end - start) / CLOCKS_PER_SEC;
  printf("%.3lf seconds\n", duration);
}
```