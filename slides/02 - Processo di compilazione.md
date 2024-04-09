# Processo di compilazione

## Compilazione
![Processo di compilazione](./images/compilazione.avif)

Parole chiave:
* **Codice sorgente**: file di testo che contiene il software scritto dallo sviluppatore
* **File oggetto**: file binario che contiene codice macchina corrispondente al programma C originale più informazioni simboliche
* **File eseguibile**: file binario che contiene il codice macchina pronto per l'esecuzione su una specifica architettura
* **Linker**: programma per unire più file oggetto con eventuali librerie esterne per ottenere il file eseguibile


Direttiva per eseguire solamente il preprocessore
```shell
$ gcc -E helloworld.c
```

Direttiva per disabilitare la fase di linking e produrre file oggetto (.o)
```shell
$ gcc -c helloworld.c
$ file helloworld.o
helloworld.o: Mach-O 64-bit object x86_64
```

Direttiva per compilazione completa
```shell
$ gcc helloworld.c -o helloworld
$ file helloworld
helloworld: Mach-O 64-bit executable x86_64
```

## Messaggi di errore
Gli *errori* causano il fallimento della compilazione del programma

I *warnings*, invece, sono segnalazioni di possibili problemi ma non causano il fallimento della fase di compilazione. In linea generale, è bene risolverli tutti prima di procedere con lo sviluppo.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Hello, World!\n");
  return 0
}
```

```
helloworld.c:6:1: error: expected ';' after return statement
helloworld.c:2:1: warning: Unused "#include <stdlib.h>"
```

## makefile
Per gestire la compilazione di un progetto C complesso si fa uso di tool ausiliari (e.g., make). Il comando make cerca all'intero della directory corrente un file di nome *makefile* o *Makefile*.

*make* evita di eseguire operazioni inutili: il codice viene compilato solo se vengono rilevate modifiche ai sorgenti.

```make
helloworld: helloworld.c
    gcc -Wall -o helloworld helloworld.c
```

*make* supporta l'utilizzo di variabili e simboli speciali:
* $(CC) : variabile che contiene il comando di compilazione (default: cc)
* $(CFLAGS): variabile che contiene le opzioni di invocazione del compilatore
* $@ : metacarattere che viene sostituito con il target (helloworld)
* $^ : metacarattere che viene sostituito con le dipendenze (helloworld.c)

```make
CC=gcc
CFLAGS=-Wall -g

clean:
    rm -rf helloworld

helloworld: helloworld.c
    $(CC) $(CFALGS) -o $@ $^
```

## CMake
Si tratta di un sistema automatico per generare il Makefile molto utile per aumentare la portabilità e la robustezza del processo di compilazione.

CLion utilizza un sistema chiamato CMake (https://cmake.org/). Il file che gestisce i processi di compilazione è chiamato *CmakeLists.txt*. 

Esempio di *CMakeLists.txt*:

```cmake
cmake_minimum_required(VERSION 3.15)
project(hello C)
set(CMAKE_C_FLAGS "-Wall -Wconversion -Wformat")
set(CMAKE_C_STANDARD 99)

add_executable(hello main.c)
target_link_libraries(hello m)
```

* **project(hello C)**: nome del progetto, linguaggio
* **set(CMAKE_C_FLAGS "-Wall -Wconversion -Wformat")**: opzioni di compilazione
* **set(CMAKE_C_STANDARD 99)**: standard C99
* **target_link_libraries(hello m)**: configura il linker per collegare libreria matematica (m)




## Preprocessore
Non è un comando o programma aggiuntivo, ma solo un termine con cui si definisce questa fase del processo di compilazione. La si può immaginare come una procedura di manipolazione di testo: l’input è codice sorgente l’output è codice sorgente.

Le direttive al preprocessore non esistono più nel codice sorgente che viene effettivamente compilato nè tantomento nel codice compilato. Si tratta di un meccanismo per manipolare il codice sorgente *prima della compilazione vera e propria*.

Per mostrare/salvare solo l’output del preprocessore si può usare:

```shell
$ gcc -E helloworld.c
```

Il simbolo *#* (diesis, cancelletto, o hash) precede tutte le operazioni che vengono gestite dal *preprocessore*:

```c
#include <stdio.h>

int main(){
    printf("Hello, World!\n");
    return 0;
}
```

## Direttiva #include
Aggiunge codice sorgente presente in file esterni. Utilizzata di solito con file header con estensione .h

```c
#include <stdio.h>
#include "mymath.h"
```

Il preprocessore genera un file sorgente in cui la direttiva *#include <stdio.h>* è sostituita dal contenuto dell'intero file indicato (/usr/include, /usr/local/include)

```shell
$ cat /usr/include/stdio.h
```

Un utilizzo tipico della direttiva include consiste nell'utilizzare funzioni definite in file esterni. Ad esempio, all'interno del file mymath.h posizioniamo i prototipi delle funzioni:

```c
unsigned mypow(unsigned int base, unsigned int exp);
```

All'interno del file mymath.c posizioniamo le implementazioni delle funzioni e includiamo mymath.h in cui potremmo aver definito costanti utili:

```c
#include "mymath.h"

unsigned mypow(unsigned int base, unsigned int exp) {
    unsigned int result;
    for (result = 1; exp > 0; exp--) {
        result *= base;
    }
    return result;
}
```

All'interno del file main.c includiamo mymath.h ed utilizziamo le funzioni definite al suo interno:

```c
#include <stdio.h>
#include "mymath.h"

int main(){
    unsigned int base=3,exp=5;
    printf("%u^%u=%u\n", base, exp, mypow(base, exp));
    return 0;
}
```

Configuriamo CMake per costruire un unico file eseguibile (i.e., main) a partire da due file sorgenti (i.e., main.c mymath.c)

```cmake
cmake_minimum_required(VERSION 3.15)
project(mymath C)
set(CMAKE_C_STANDARD 99)

add_executable(main main.c mymath.c)
```

## Direttiva #define
La direttiva #define INPUT OUTPUT modifica il codice sorgente sostituendo tutte le occorrenze di INPUT con OUTPUT.

*Attenzione: #define non definisce variabili e/o funzioni globali!*

```c
#define INPUT OUTPUT
```

```c
#include <stdio.h>
#define MAX 10

int main() {
    printf("Il valore massimo è %d\n", MAX);
    return 0;
}
```

Il valore di sostituzione può anche essere parametrico. 

*Attenzione: N non è una funzione!*


```c
#define N(x) (10 * (x))
int main(){
    int a = N(5);
    return 0;
}
```

E' importante utilizzare in modo opportuno le parentesi per evitare problemi di priorità! Una definizione robusta si ottiene mettendo tra parentesi sia gli argomenti da sostituire che la macro stessa.

Definizione debole:

```c
#define SQUARE(a) a*a

SQUARE(3);  // Sostituito in 3*3 -> 9
SQUARE(1+2) // Sostituito in 1+2*1+2 -> Output:5
```

Definizione robusta:

```c
#define SQUARE(a) ((a)*(a))

SQUARE(3);  // Sostituito in (3)*(3) -> 9
SQUARE(1+2) // Sostituito in (1+2)*(1+2) -> 9
```

## Direttiva #undef
La direttiva #define non ha scope: legge i sorgenti e opera in modo sequenziale dall’inizio alla fine del file sorgente.

Per eliminare una definizione è necessario utilizzare la direttiva #undef in modo esplicito.

```c
int main(void) {
#define MAX 128
    printf("%d\n", MAX);
#undef MAX
    printf("%d\n", MAX);    /* Errore! MAX non è più definita */
}
```

## Direttiva #if
Il preprocessore non può valutare il contenuto di variabili o di codice a runtime. Le uniche *variabili* nel preprocessore sono quelle definite attraverso la direttiva #define. E' possibile abilitare o disabilitare porzioni di codice attraverso le direttive #if, #ifdef, #ifndef.

Esempio: utilizzando define possiamo definire l'architettura di riferimento.

```c
#define ARCH amd64

int main(void) {
#if (ARCH==amd64)
    printf("amd64\n");
#else
    printf("i386\n");
#endif
}
```

Esempio: message(S) stampa il messaggio solo se la MACRO DEBUG è definita.

```c
#define DEBUG

#ifdef DEBUG
#define message(S) printf(S)
#else
#define message(S)
#endif

int main(void) {
    message("Hello world!");
}
```

Esempio: per evitare errori dovuti ad inclusioni multiple dello stesso file header (.h) vengono utilizzate le *include guards*. Il file viene incluso solo se la direttiva *MYMATH_H* non è definita.

```c
/* mymath.h with include guards */
#ifndef MYMATH_H
#define MYMATH_H

unsigned mypow(unsigned, unsigned);

#endif // MYMATH_H
```
