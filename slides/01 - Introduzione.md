# Introduzione

## Il linguaggio C
È un linguaggio di programmazione general-purpose progettato inizialmente da Dennis Ritchie dei Bell Laboratories e implementato nel 1972. Inventato per sopperire ai limiti del linguaggio B e BCPL.

Viene considerato un linguaggio di **basso livello**:
* Linguaggi di **alto livello**: gestione automatica della memoria, oggetti, stream, stringhe, collections...). Esempi: Python, Java, Javascript, C#, Dart, Kotlin
* Linguaggi di **basso livello**: gestione manuale della memoria e astrazioni semplici (tipi di dati, funzioni,
  strutture dati), parziale visibilità architetturale. Esempi: C, Rust
* Linguaggi di **bassissimo livello**: programmi scritti specificamente per un tipo di architettura hardware. Esempi: assembly, VHDL

I linguaggi sono creature vive e vengono migliorati periodicamente. La possibilità di utilizzare certe funzionalità del C dipende strettamente dal supporto del compilatore:

  * 1973: invenzione del linguaggio C da parte di Rennis Ritchie
  * 1983: National Standard Institute (ANSI) inizia la definizione di ANSI C o C standard
  * 1989: definizione dello standard [C89](https://en.wikipedia.org/wiki/ANSI_C#C89) 
  * 1999: definizione dello standard [C99](https://en.wikipedia.org/wiki/C99) 
  * 2011: definizione dello standard [C11](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
  * 2018: definizione dello standard [C17](https://en.wikipedia.org/wiki/C17_(C_standard_revision))



## Caratteristiche del C

E' la lingua franca per gli sviluppatori. Implementazioni di nuovi algoritmi, ad esempio, sono spesso divulgate inizialmente solo in C. E' anche il linguaggio in cui si descrive spesso il comportamento della macchina. **Evita superstizione!**

Il linguaggio è pensato per essere **efficiente**: lo sviluppatore ha il controllo completo su quello che succede. Tuttavia: commettere errori è facile e subdolo: il compilatore non rileva gli errori con la completezza delle alternative più recenti (Java o Python). Inoltre, gli errori possono produrre conseguenze gravi in termini di sicurezza e integrità del sistema non esistendo una virtual machine (*sandbox*).

* **Procedurale**: il programma è un insieme di *procedure* (funzioni). Non esiste supporto a strutture modulari più complesse come classi ed oggetti.
* **Compilato**: il codice sorgente deve essere trasformato in linguaggio macchina da un compilatore (e.g., gcc) *prima di essere eseguito*.
* **Tipizzato**: ogni variabile ha un tipo associato, lo sviluppatore deve sempre dichiarare il tipo prima di usare la variabile. E' però possibile utilizzare tipi alternativi per accedere al dato (i.e., lascamente tipizzato).




## Ambito di utilizzo del C

* Sistemi Operativi (e.g., kernel Windows/Linux/Mac/IoS/Android)
* Sistemi embedded (e.g., Arduino)
* Database (e.g., MySQL, MS SQL Server, and PostgreSQL)
* Linguaggi di programmazione (e.g., Python)
* Librerie e routine ad alte performance (e.g., numpy, webassembly)
* Motori grafici 3D (e.g., Unreal Engine C++)
* Software per telecomunicazioni (e.g., openWrt)
* Software di controllo per processi industriali (e.g., PLC)


## Ambienti di sviluppo
*Gli ambienti di sviluppo integrato – o IDE, Integrated Development Environment – sono strumenti fondamentali per il lavoro di un programmatore. Esistono una varietà di ambienti di sviluppo, dai più complessi ed articolati, fino a semplici editor di testo affiancati ad un compilatore.*

* CLion
* Visual Studio
* Eclipse
* Sublime text
* Vim


## Funzione *main()*
L'esecuzione di un programma C inizia sempre dalla prima istruzione della funzione *main*. La funzione *main* accetta argomenti (per ora ignorati) e ritorna un numero intero. Il programma termina quando la funzione *main* termina.

**Linea 3**: *int* tipo del valore di ritorno della funzione, *main* nome della funzione, *{* inizio del corpo della funzione. La funzione termina a linea 6 *}*.

**Linea 4**: *printf* invocazione della funzione di libreria printf(), che riceve come argomento la stringa costante *Hello, World!* terminata con carattere a capo *\\n*.

**Linea 5**: *return* istruzione che termina la funzione e ritorna *0* (successo in ambito Unix). 

```c++
#include <stdio.h>

int main() {
  printf("Hello, World!\n");
  return 0;
}
```

## Commenti

I commenti sono porzioni di testo che non vengono considerate dal compilatore (i.e., vengono eliminati dal preprocessore). Sono fondamentali per rendere leggibile il codice e promuovere la collaborazione fra più sviluppatori.

Come regola generale, è preferibile un commento descrittivo all'inizio di ogni funzione piuttosto che commenti brevi e sparsi.

```c++
/*
 * Questo è un commento multi-linea
 * che descrive la funzione sottostante
 */
int sum(int a, int b) {
    // Questo è un commento singola-linea
}
```

## Parole chiave
| **Parole chiave** | **Utilizzo** |
| ----------------- | ------------ |
| break case continue default do else for goto if return switch while | costrutti di controllo |
| char double enum float int long short signed struct union unsigned void | tipi di dato semplice |
| auto const extern register static volatile | modificatori di volatività e persistenza |
| sizeof | operatore che ritorna la dimensione di una varibile |
| typedef | definizione di tipi definiti dall'utente |


## Identificatori
In C un identificatore è un nome che si riferisce a funzioni, variabili, etc. definiti nel codice. 

* Non può essere una parola chive del linguaggio
* Non può cominciare con un numero
* Può contenere qualsiasi combinazione di:
  * lettere maiuscole e minuscole
  * numeri
  * il carattere underscore (_)

Esempi **validi**: prova1, prova_1, media_pesata, _tot

Esempi **invalidi**: 1_prova, totale_%, typedef


## Variabili
Una variabile è una porzione di memoria che contiene dei dati che possono essere modificati durante l'esecuzione. Ogni variabile deve essere **dichiarata**, ovvero:
* associata a un identificatore;
* associata a un tipo.

```c++
#include <stdio.h>

int main() {
    int a, b, somma;
    
    a = 10;
    b = 12;
    somma = a + b;
    printf("somma=%d\n", somma);
    return 0;
}
```

![Variabili](images/variabili.avif)

Utilizzare [PythonTutor](https://pythontutor.com/) oppure il debugger integrato per visualizzare lo stato delle variabili.

## Espressioni
*Un programma C e' una sequenza di espressioni. Le espressioni sono combinazioni di variabili, costanti, chiamate a funzione, e operatori*.

Non esiste in C una reale delimitazione fra espressioni logiche e aritmetiche in quanto *0* è considerato equivalente al valore logico *falso*, mentre *1* è considerato equivalente al valore logico *vero*.

Ad esempio:

```c++
45 * (a + b)
delta * sqrt(abs(x1 * x2))
sqrt(a * b - c) <= 10
(c1 || c2) && c3
max = a > b ? a : b
a % b
```
