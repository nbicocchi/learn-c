# Strutture di controllo
Il paradigma di programmazione strutturata consente di dirigere il flusso delle istruzioni a tempo di esecuzione, in base allo stato del programma.

Il programmatore può predisporre molteplici blocchi di istruzioni da eseguire alternativamente, o ripetutamente, in base al soddisfacimento di determinate condizioni.

A parte alcune minime differenze sintattiche, queste istruzioni sono simili a quelle che si possono trovare nella maggior parte dei linguaggi.

Costrutti **condizionali**:
  * **if** 
  * **switch-case**

Costrutti **iterativi**:
  * **while**
  * **do-while**
  * **for**


## Costrutto if

```c
if (espressione) {
    istruzione1;
}
```

```c
if (espressione) {
    istruzione1;
} else {
    istruzione2;
}
```

```c
if (espressione1) {
    istruzione1;
} else if (espressione2) {
    istruzione2;
} else {
    istruzione3;
}
```

* Operatori di confronto: < , > , == , != , >= , <=
* Operatori logici: AND (&&), OR (||), NOT (!)

Le condizioni valutate dal costrutto *if* sono valori *interi* interpretati come *valori di verità* (convenzionalmente, 0 == falso, 1 == vero). Il tipo *bool* è stato introdotto a partire dallo standard C99.

Alcuni esempi di seguito:

```c++
#include <stdio.h>
        
int main() {
    int a = 5;
    if (a < 0) {
        printf("a < 0\n");
    } else {
        printf("a >= 0\n");
    }
}
```

```c++
#include <stdio.h>

int main() {
    int a = 5;
    if (a < 0) {
        printf("a < 0");
    } else if (a < 10) {
        printf("0 <= a < 10");
    } else if (a < 20) {
        printf("10 <= a < 20");
    } else {
        printf("a >= 20");
    }
}
```

```c++
#include <stdio.h>

int main() {
    int a = 5, b = -2;
    if (a > 0) {
        if (b > 0) {
            printf("a>0, b>0\n");
        }
    }
}
```

```c++
#include <stdio.h>

int main() {
    int a = 5, b = -2;
    if ((a > 0) && (b > 0)) {
            printf("a>0, b>0\n");
        }
    }
}
```

## Operatore \?
L' operatore *?* (*ternary condition*) e' la forma piu' efficente per esprimere semplici costrutti if. 

```c++
espressione1 ? espressione2 : espressione3
```

che equivale a:

```c++
if (espressione1) {
  espressione2
} else { 
  espressione3
}
```

Ad esempio:

```c++
int max = (a > b) ? a : b;
```

equivale alla scrittura (assai più prolissa!) seguente:

```c++
int max;
if (a > b) {
    max = a;
} else {
    max = b;
}
```


## Costrutto switch-case
Lo switch case consente di implementare decisioni multiple e si basa sul confronto tra il risultato di un’espressione e un insieme di valori costanti. L'espressione deve essere di tipo *int* o *char*.

Il costrutto è composto da una espressione di controllo e da diversi blocchi di istruzione *case*, ognuno dei quali è associato a un particolare valore dell'espressione di controllo iniziale. Ogni blocco di istruzioni termine con l'istruzione *break*. L'ultimo blocco di istruzioni è detto *default* e' facoltativo e raggruppa tutti gli altri casi.

```c++
switch (espressione) { 
    case costante1: istruzioni1; break;
    case costante2: istruzioni2; break;
    case costante3: istruzioni3; break;
    .... 
    default: istruzioni; break; 
}
```

Alcuni esempi di seguito:

```c++
int a = 7;
switch(a) {
    case 0: printf("Eseguo il caso 0\n");
        break;
    case 3: printf("Eseguo il caso 3\n");
        break;
    case 7: printf("Eseguo il caso 7\n");
        break;
    default: printf("Caso default\n");
        break;
}
```

Eliminando le istruzioni *break* per separare i casi, cambia la semantica:
* se a == 0, vengono eseguiti i casi 0, 3, 7
* se a == 3, vengono eseguiti i casi 3, 7
* se a == 7, viene eseguito il caso 7

```c++
int a = 7;
switch (a) {
    case 0: printf("Eseguo il caso 0\n");
    case 3: printf("Eseguo il caso 3\n");
    case 7: printf("Eseguo il caso 7\n");
        break;
    default: printf("Caso default\n");
        break;
}
```

## Costrutto while
Il costrutto *while* è un costrutto condizionale dove un blocco di istruzioni viene eseguito fino a quando  l'espressione di controllo risulta vera.

*Ogni esecuzione del blocco di istruzioni è detta ciclo o iterazione*. In ogni ciclo sono eseguite le stesse istruzioni del blocco:

```c++
while ( espressione di controllo ) { 
    // blocco di istruzioni 
} 
```

Ad esempio:

```c++
int i = 0;
while (i < 10) {
    printf("Il valore di i è %d\n", i);
    i = i + 1;
}
```

## Costrutto do-while
Il costrutto *do-while* è un costrutto post-condizionale dove prima sono eseguite le istruzioni che formano il blocco dell’iterazione e successivamente è verificata la la condizione. Se la condizione è vera allora si ripete il ciclo, altrimenti si passa all’istruzione successiva.

Il costrutto *do-while* può servire in tutti i casi in cui la prima iterazione deve essere eseguita a prescindere dal successo dell’istruzione di controllo.

```c++
do {
    // blocco di istruzioni
} while ( espressione di controllo );
```

Ad esempio:

```c++
int i = 0;
do {
    printf("Il valore di i è %d\n", i);
    i = i + 1;
} while (i < 10);
```

## Costrutto for
Il costrutto *for* è utilizzato per la ripetizione di istruzioni per un numero prestabilito di volte. Le variabili che controllano il flusso del ciclo *for* sono gestite all’interno della direttiva *for*:
* (1) assegnazione
* (2) controllo
* (3) modifica post-ciclo

```c++
for ([<espressione assegnazione>]; [<espressione controllo>];[<espressione post-ciclo>]) {
    // blocco di istruzioni
}
```

Ad esempio:

```c++
for (int i = 0; i < 10; i++) {
    printf("Il valore di i è %d\n", i);
}
```

* **i = 0**: assegnazione (eseguita una sola volta, come prima operazione)
* **i < 10**: condizione di controllo (verificata prima di ogni ciclo)
* **i++**: modifica post-ciclo (eseguita al termine di ogni ciclo)

## Istruzione break
L'istruzione *break* interrompe le iterazioni di costrutto iterativo (*for, while, do-while*). In genere è associata a una struttura condizionale *if* per associarla al verificarsi di un evento.

Ad esempio:

```c++
for (int i = 0; i < 5; i++) {
    if (i == 2) {
        break;
    }
    printf("%d ", i);
}

//Output: 0 1
```

## Istruzione continue
L'istruzione *continue* interrompe l'**iterazione corrente** tornando all'espressione di controllo per iniziare l'interazione successiva. **Il ciclo non viene interrotto**.

Ad esempio:

```c++
for (int i = 0; i < 5; i++) {
    if (i == 2) {
        continue;
    }
    printf("%d ", i);
}

//Output: 0 1 3 4
```

## Cicli infiniti
I costrutti iterativi possono essere utilizzati anche per creare *cicli infiniti*. Spesso i cicli infiniti sono interrotti attraverso un'istruzione dedicata (*break*) posizionata all'interno del blocco di istruzioni

```c++
for (;;) {
  /* istruzioni */
}
```

```c++
#define TRUE 1
while (TRUE) {
    /* istruzioni */
}
```

```c++
#define TRUE 1
do {
    /* istruzioni */
} while (TRUE);
```


## Errori comuni

### Assegnamento e verifica di uguaglianza
Confondere gli operatori di assegnamento (=) e di verifica di uguaglianza (==) può produrre innumerevoli errori. Considerata la facilità dell'errore (typo), fino a Python 3.8 l'assegnamento all'interno di una condizione *if* non era supportato. Ora è supportato attraverso un operatore dedicato (:=)

```c++
int main() {
    int a = 10;
    if (a == 1) { 
        // non viene eseguito
    }
}
```

```c++
int main(){
    int a = 10;
    if (a = 1) { 
        // viene eseguito
    }
}
```


### Overflow

```c++
// esempio di overflow 
// char[-128, 127]
// dovrebbe terminare non NON termina!
int main() {
  char a;
  for (a = 0; a < 200; a++) { }
  return 0;
}
```

### Underflow
```c++
// esempio di underflow 
// unsigned int[0, 4.294.967.295], int[-2.147.483.648, 2.147.483.647]
// non dovrebbe terminare MA termina!
int main() {
    int a;
    for (a = 9; a >= 0; a++) { }
    return 0;
}
```
## Istruzione goto
*goto* è un costrutto di *salto incondizionato* che rappresenta l'istruzione assembly *jump*. A volte si utilizza nella gestione degli errori, ma in generale è sconsigliato utilizzarlo se non si ha piena coscienza di ciò che si sta facendo

*Edsger W. Dijkstra - Go To statement considered harmful*

```c++
int main(){
    goto end;
    printf("Non eseguito\n");

end:
    printf("Fine\n");

    return 0;
}
```




