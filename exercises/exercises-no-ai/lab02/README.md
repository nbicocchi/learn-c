## Esercizi C (Array, stringhe, puntatori, funzioni)

I seguenti esercizi usano array e stringhe con memoria già disponibile, senza allocazione dinamica con malloc. Si assuma che i puntatori facciano riferimento ad aree di memoria valide e di dimensioni appropriate; i buffer destinazione devono includere lo spazio per l'eventuale terminatore nullo. Le stringhe di input sono terminate da '\0'.

---

Esercizio 1. Implementare una funzione *reversei* che inverte l’ordine di un array di interi rispettando il seguente prototipo:

```c
void reversei(int *dst, const int *src, unsigned size);
```

dove:

* **dst** è il puntatore all’array destinazione (invertito)
* **src** è il puntatore all’array sorgente
* **size** è la dimensione dell’array

---

Esercizio 2. Implementare una funzione *reverses* che inverte l’ordine dei caratteri di una stringa C rispettando il seguente prototipo:

```c
void reverses(char *dst, const char *src);
```   

dove:

* **dst** è il puntatore all’array destinazione (invertito)
* **src** è il puntatore all’array sorgente

---

Esercizio 3. Implementare una funzione *rotate* che trasforma una stringa di lettere minuscole dell'alfabeto inglese in un'altra della stessa lunghezza, spostando ogni lettera di *shift* posizioni in modo ciclico: la *a* segue la *z*. Assumere shift compreso tra 0 e 25.
Ad esempio: rotate(dst, "nicolaz", 2) -> "pkeqncb"

```c
void rotate(char *dst, const char *src, char shift);
```

dove:

* **dst** è il puntatore all’array destinazione (ruotato)
* **src** è il puntatore all’array sorgente
* **shift** il numero di caratteri con cui ruotare **src**

---

Esercizio 4. Implementare una funzione *findi* che individua la posizione di un valore all’interno di un array di
interi. La funzione rispetta il seguente prototipo:

```c
long findi(int value, const int *values, unsigned size);
```

dove:

* **value** è il valore da ricercare
* **values** è il puntatore all’array di input
* **size** è la dimensione dell’array
* **il valore di ritorno** indica la posizione all’interno dell’array, e ha valore speciale -1 se l’elemento non esiste

---

Esercizio 5. Implementare una funzione *capitalize* che, data una stringa C di input, ne genera un’altra in cui tutte le
lettere alfabetiche che seguono uno spazio siano maiuscole, mentre tutte le altre minuscole. Assumere che l’input possa
contenere lettere maiuscole, minuscole, altri simboli.

```c
void capitalize(char *dst, const char *src);
```

dove:

* **dst** è il puntatore all’array destinazione
* **src** è il puntatore all’array sorgente

---

Esercizio 6. Implementare una funzione *frequencies* che conti le occorrenze delle 26 lettere dell'alfabeto inglese in una stringa, senza distinguere maiuscole e minuscole e ignorando gli altri caratteri. La funzione inizializza e riempie il seguente array di frequenze:

```c
void frequencies(unsigned *freqs, const char *src);
```

dove:

* **freqs** è il puntatore all’array delle frequenze (array di 26 elementi, uno per ogni lettera dell'alfabeto inglese)
* **src** è il puntatore all’array sorgente

---

Esercizio 7. Implementare una funzione *merge* che dati due array di interi ordinati in modo crescente, generi un
terzo array che contenga tutti i valori dei precedenti array in modo ordinato. Assumere che all’interno degli array ci
possano essere elementi duplicati. La funzione rispetta il seguente prototipo:

```c
void merge(int *dst, const int *a1, unsigned s1, const int *a2, unsigned s2);
```

dove:

* **dst** è il puntatore all’array destinazione
* **a1** è il puntatore al primo array di input
* **s1** è la dimensione del primo array
* **a2** è il puntatore al secondo array di input
* **s2** è la dimensione del secondo array

---

Esercizio 8. Implementare una funzione *fibonacci* per il calcolo della serie di Fibonacci, che calcola i primi
n valori della serie, a partire da 0 e 1, e li memorizza in un array. La funzione rispetta il seguente prototipo:

```c
void fibonacci(unsigned *dst, unsigned n);
```

dove:

* **dst** è il puntatore all’array destinazione
* **n** è il numero di valori della serie di Fibonacci da calcolare; i valori richiesti devono essere rappresentabili come unsigned

---

Esercizio 9. Implementare una funzione *trova_max* per individuare il valore massimo all’interno di un array di numeri
interi che rispetta il seguente prototipo:

```c
void trova_max(int *rmax, const int *values, unsigned size);
```

dove:

* **rmax** è il puntatore alla variabile che conterrà il valore massimo trovato;
* **values** è il puntatore all’array;
* **size** è la dimensione dell’array.

Si assuma che il puntatore all’array sia valido, che la dimensione indicata dalla variabile size sia sempre maggiore di
0 e consistente con i valori effettivamente presenti nell’array

---

Esercizio 10. Implementare una funzione *trova_minmax* simile a quella indicata nell’esercizio precedente, ma che
individui sia il valore minimo che quello massimo, con le stesse precondizioni sulla dimensione. La funzione deve rispettare il seguente prototipo:

```c
void trova_minmax(int *rmin, int *rmax, const int *values, unsigned size);
```

dove:

* **rmin** è il puntatore alla variabile che conterrà il valore minimo trovato;
* **rmax** è il puntatore alla variabile che conterrà il valore massimo trovato;
* **values** è il puntatore all’array;
* **size** è la dimensione dell’array.

---

Esercizio 11. Implementare una funzione *compute_mean_variance* per il calcolo della media aritmetica e della varianza di un insieme non vuoto di valori. Calcolare la varianza come media dei quadrati degli scarti dalla media, dividendo per size, non per size - 1. La funzione deve rispettare il seguente prototipo:

```c
void compute_mean_variance(float *rmean, float *rvariance, float *values, unsigned size);
```

dove:

* **rmean** è il puntatore alla variabile dove viene memorizzata la media;
* **rvariance** è il puntatore alla variabile dove viene memorizzata la varianza;
* **values** è il puntatore all’array;
* **size** è la dimensione dell’array.

---

Esercizio 12. Implementare una funzione *my_strcpy*, ispirata alla funzione *strcpy* dichiarata all'interno di string.h,
che copia il contenuto di una stringa all'interno di un'altra stringa. La funzione deve rispettare il seguente
prototipo:

```c
void my_strcpy(char *dst, const char *src);
```

dove:

* **dst** è il puntatore al vettore di caratteri verso cui effettuare la copia;
* **src** è il puntatore al vettore di caratteri da cui effettuare la copia.

---

Esercizio 13. Implementare una funzione *my_strcat*, ispirata alla funzione *strcat* dichiarata all'interno di string.h,
che concatena il contenuto di una stringa con quello di un'altra stringa. La funzione deve rispettare il seguente
prototipo:

```c
void my_strcat(char *dst, const char *src);
```

dove:

* **dst** è il puntatore al vettore di caratteri a cui concatenare;
* **src** è il puntatore al vettore di caratteri da concatenare a **dst**.

---

Esercizio 14. Implementare una funzione *my_strlen*, ispirata alla funzione *strlen* dichiarata all'interno di string.h,
che determina la lunghezza di una stringa zero-terminata. La funzione deve rispettare il seguente prototipo:

```c
unsigned my_strlen(const char *src);
```

dove:

* **src** è il puntatore al vettore di caratteri di cui si vuole calcolare la lunghezza;
* la funzione ritorna la lunghezza della stringa, escluso il carattere di terminazione.

---

Esercizio 15. Implementare una funzione *my_strcmp*, ispirata alla funzione *strcmp* dichiarata all'interno di string.h,
che confronta due stringhe. La funzione deve rispettare il seguente prototipo:

```c
int my_strcmp(const char *s1, const char *s2);
```

dove:

* **s1** è il puntatore al primo vettore di caratteri;
* **s2** è il puntatore al secondo vettore di caratteri;
* la funzione ritorna 0 se le stringhe sono uguali, 1 se sono diverse. A differenza di strcmp, questa versione non deve indicare l'ordinamento lessicografico.

---

Esercizio 16. Le funzioni memcpy e memmove, dichiarate in string.h, copiano byte da una sorgente a una destinazione. memcpy richiede che le aree non si sovrappongano; memmove gestisce anche aree sovrapposte. Non si tratta soltanto di una differenza di prestazioni. Ad esempio:

```c
int src[8] = {0,1,2,3,4,5,6,7};
memmove(src + 4, src + 2, 4 * sizeof(*src));
/* contenuto finale: 0 1 2 3 2 3 4 5 */
```

```c
int src[8] = {0,1,2,3,4,5,6,7};
memcpy(src + 4, src + 2, 4 * sizeof(*src));
/* comportamento indefinito: le aree si sovrappongono; nessun risultato garantito */
```

Implementare due funzioni *my_memmove* e *my_memcpy*, ispirate a memmove e memcpy, rispettando i seguenti prototipi:

```c
void *my_memcpy(void *dst, void *src, size_t size);
void *my_memmove(void *dst, void *src, size_t size);
```

dove:

* **dst** è il puntatore all'area (di memoria) destinazione;
* **src** è il puntatore all'area (di memoria) sorgente;
* **size** è il numero di byte da copiare;
* la funzione ritorna l'indirizzo dell'area destinazione.

---

Esercizio 17. Implementare un gruppo di funzioni *init, sort, search, show* per trattare vettori di interi. *init*
inizializza il vettore con numeri random compresi fra 0 e 100. *sort* ordina il vettore in modo crescente utilizzando
l'algoritmo Bubble Sort (https://en.wikipedia.org/wiki/Bubble_sort). *search* ritorna l'indice in cui il valore *value*
si trova, -1 in caso non sia presente nel vettore. *show* mostra il contenuto del vettore a video. Le funzioni devono
rispettare i seguenti prototipi:

```c
void init(int *v, unsigned size);
void sort(int *v, unsigned size);
int search(int *v, unsigned size, int value);
void show(int *v, unsigned size);
```

dove:

* **v** è il vettore;
* **size** è la dimensione del vettore;
* **value** è il valore da cercare.

---

Esercizio 18. *(Approfondimento, non richiesto all'esame)*. Implementare una funzione *merge_sort* che ordini un vettore
di interi in modo crescente utilizzando l'algoritmo Merge Sort (https://en.wikipedia.org/wiki/Merge_sort). La funzione
deve rispettare il seguente prototipo.

```c
void merge_sort(int arr[], int l, int r);
```

dove:

* **arr** è il vettore da ordinare;
* **l** è l'indice di sinistra del blocco da ordinare, tipicamente l = 0;
* **r** è l'indice dell'ultimo elemento del blocco da ordinare, tipicamente n - 1 per un vettore non vuoto di n elementi. sizeof(arr) misura byte soltanto dove arr è un vero array; nel parametro di funzione arr è invece un puntatore.
