## Esercizi C (Allocazione dinamica della memoria)

Si propone un gruppo di esercizi per imparare ad utilizzare tecniche di allocazione dinamica della memoria.

I risultati allocati dinamicamente appartengono al chiamante, che deve liberarli con free, comprese le eventuali allocazioni interne. In caso di fallimento, liberare le allocazioni parziali prima di restituire NULL. Si assumono puntatori di input validi e dimensioni rappresentabili; per statistiche e matrici, usare dimensioni positive salvo diversa indicazione.

---

Esercizio 1. Implementare una funzione *reversei* che inverta l’ordine dei valori di un array di dati interi che
rispetti il seguente prototipo:

```c
int *reversei(const int *src, unsigned size);
```

dove:

* **src** è il puntatore all’array di input;
* **size** è la dimensione dell’array;
* la funzione ritorna il puntatore all’array invertito, allocato dalla funzione. Ha valore NULL in caso di errore di
  allocazione.

---

Esercizio 2. Implementare una funzione *reverses* che inverta l’ordine dei caratteri di una stringa che rispetti il
seguente prototipo:

```c
char *reverses(const char *src);
```

dove:

* **src** è il puntatore alla stringa in input.
* la funzione ritorna il puntatore all’array invertito, allocato dalla funzione. Ha valore NULL in caso di errore di
  allocazione.

---

Esercizio 3. Implementare una funzione *merge* che dati due array di valori interi *ordinati*, generi un terzo array che
contenga tutti i valori dei precedenti array in modo ordinato. Assumere che all’interno degli array ci possano essere
elementi duplicati. La funzione alloca dinamicamente la memoria necessaria a contenere i valori ordinati ma, al posto di ritornare al chiamante
il puntatore alla zona di memoria allocata (che sarebbe la cosa più ovvia e semplice) scrive l'indirizzo in cui 
trovare i valori all'interno della variabile dst (puntatore a puntatore). La funzione rispetti il seguente prototipo:

```c
void merge(int **dst, const int *a1, unsigned s1, const int *a2, unsigned s2);
```

dove:

* **dst** è l'indirizzo di una variabile puntatore del chiamante, nella quale scrivere l'indirizzo dell'array generato di s1 + s2 elementi. In caso di errore di allocazione, assegnare NULL a **\*dst**, non al parametro dst;
* **a1** è il puntatore al primo array di input;
* **s1** è la dimensione del primo array;
* **a2** è il puntatore al secondo array di input;
* **s2** è la dimensione del secondo array.

---

Esercizio 4. Implementare una funzione *array_stats* per l’individuazione del valore minimo, del valore massimo, della
media e della varianza dei valori di un array. La funzione deve rispettare il seguente prototipo:

```c
typedef struct array_info {
    int max;
    int min;
    float mean;
    float variance;
} array_info_t;

array_info_t *array_stats(const int *values, unsigned size);
```

dove:

* **values** è il puntatore all’array;
* **size** è la dimensione dell’array;
* la funzione ritorna un puntatore ad una struct array_info (allocata internamente alla funzione) che mantiene le statistiche.

---

Esercizio 5. Implementare una funzione *split* che separi una stringa in parole delimitate da spazi e restituisca un array di puntatori a stringhe, terminato da NULL: con N parole, list[N] == NULL. La funzione non deve modificare la stringa di input const; può lavorare su una copia modificabile. Implementare anche trim, che elimina gli spazi iniziali e finali modificando il buffer ricevuto senza allocare altra memoria. Si possono usare strcpy, strlen, strtok, memmove e memset; strdup è disponibile in ambiente POSIX, ma non appartiene a ISO C99. Le funzioni devono rispettare i seguenti prototipi:

```c
void trim(char *str);
char **split(const char *s);
```

dove:

* **s** è il puntatore alla stringa in input;
* la funzione ritorna il puntatore alla lista di stringhe, oppure NULL in caso di errori.

---

Esercizio 6. Implementare una funzione *matrix_transpose* che, data una matrice, ritorna la sua matrice trasposta (le righe diventano colonne e viceversa). La funzione deve rispettare il seguente prototipo:

```c
struct matrix {
    size_t rows, cols;
    double *data;
};

struct matrix *matrix_transpose(const struct matrix *m);
```

dove:

* **m** è il puntatore alla struttura che rappresenta la matrice originale;
* la funzione ritorna il puntatore alla matrice trasposta, allocata dinamicamente. Il puntatore vale NULL in
  caso di errori.

---

Esercizio 7. L'esercizio precedente ha la caratteristica di definire i dati della matrice *(data)* attraverso un array
monodimensionale. Questa soluzione semplifica nell'immediato l'allocazione della memoria ma previene la possibilità di accedere al campo *data* utilizzando la doppia parentesi quadra *data[][]*. Implementare una versione alternativa dell'esercizio precedente in cui *struct matrix* è definita come segue:

```c
struct matrix {
    size_t rows, cols;
    double **data;
};

struct matrix *matrix_transpose(const struct matrix *m);
```

---

Esercizio 8. Implementare una funzione *matrix_swap_diagonals* che accetta come parametro un puntatore ad una matrice
quadrata e deve restituire un puntatore a una nuova matrice allocata dinamicamente che contenga la matrice ottenuta
scambiando la diagonale principale con l’antidiagonale, ovvero la diagonale che va dall’angolo in alto a destra
all’angolo in basso a sinistra. La funzione deve rispettare il seguente prototipo:

```c
struct matrix {
    size_t rows, cols;
    double *data;
};

struct matrix *matrix_swap_diagonals(const struct matrix *m);
```

dove:

* **m** è il puntatore alla struttura che rappresenta la matrice originale;
* la funzione ritorna il puntatore alla matrice con le diagonali invertite, allocata dinamicamente. Il puntatore
  vale NULL in caso di errori.

---

Esercizio 9. L'esercizio precedente ha la caratteristica di definire i dati della matrice *(data)* attraverso un array monodimensionale. Questa soluzione semplifica nell'immediato l'allocazione della memoria ma previene la possibilità di accedere al campo *data* utilizzando la notazione *data[][]*. Implementare una versione alternativa dell'esercizio precedente in cui *struct matrix* è definita come segue:

```c
struct matrix {
    size_t rows, cols;
    double **data;
};

struct matrix *matrix_swap_diagonals(const struct matrix *m);
```

---

Esercizio 10. Implementare una funzione *matrix_product* che accetta come parametri due puntatori a struttura matrice e restituisce un puntatore a una nuova matrice allocata dinamicamente che contiene il prodotto matriciale delle due passate come parametro. La funzione deve rispettare il seguente prototipo:

```c
struct matrix {
    size_t rows, cols;
    double *data;
};

struct matrix *matrix_product(const struct matrix *m1, const struct matrix *m2);
```

dove:

* **m1** è il puntatore alla struttura che rappresenta la prima matrice;
* **m2** è il puntatore alla struttura che rappresenta la seconda matrice;
* la funzione ritorna il puntatore alla matrice prodotto, allocata dinamicamente. Il puntatore vale NULL in caso
  di errori.

---

Esercizio 11. L'esercizio precedente ha la caratteristica di definire i dati della matrice *(data)* attraverso un array monodimensionale. Questa soluzione semplifica nell'immediato l'allocazione della memoria ma previene la possibilità di accedere al campo *data* utilizzando la notazione *data[][]*. Implementare una versione alternativa dell'esercizio precedente in cui *struct matrix* è definita come segue:

```c
struct matrix {
    size_t rows, cols;
    double **data;
};

struct matrix *matrix_product(const struct matrix *m1, const struct matrix *m2);
```

---

Esercizio 12. Implementare una funzione *matrix_compare* che accetta come parametri due puntatori a matrice e restituisce un numero intero da interpretare come un booleano. La funzione deve rispettare il seguente prototipo:

```c
struct matrix {
    size_t rows, cols;
    double **data;
};

int matrix_compare(const struct matrix *m1, const struct matrix *m2);
```

dove:

* **m1** è il puntatore alla struttura che rappresenta la prima matrice;
* **m2** è il puntatore alla struttura che rappresenta la seconda matrice;
* la funzione ritorna un numero intero (0 se le due matrici sono uguali, 1 se le due matrici sono diverse).

---

Esercizio 13. Implementare una funzione *invert_all* che accetta un array di puntatori terminato da NULL, ciascuno riferito a una stringa terminata da '\0', e inverte sia l'ordine delle stringhe sia quello dei caratteri di ogni stringa. La funzione deve rispettare il seguente prototipo:

```c
char **invert_all(char *strings[]);
```

dove:

* **strings** è il puntatore alla lista di stringhe (i.e., array di puntatori a carattere);
* la funzione ritorna una nuova lista di stringhe, allocata dinamicamente, in cui sia l'ordine delle stringhe che dei caratteri all'interno di ogni stringa è invertito.

---

Esercizio 14. Il Progetto Galactica è una collaborazione globale che mira a creare una rete interconnessa di stazioni spaziali per agevolare lo scambio di risorse, informazioni e conoscenze tra le colonie umane. Queste stazioni spaziali fungono da centri di ricerca, punti di transito e rifugi per gli esploratori spaziali. Data la seguente struttura, che rappresenta una singola stazione spaziale, è necessario implementare un gruppo di funzioni per gestire e monitorare una rete di stazioni. 

```c
struct SpaceStation {
    char *name;
    int station_id;
};
```

**(a)** Scrivere una funzione che allochi dinamicamente una rete di stazioni spaziali, dove ogni stazione spaziale ha un nome e un numero di stazione. La funzione deve restituire un puntatore a un array di puntatori a struct `SpaceStation`. Se l'allocazione fallisce, la funzione deve restituire `NULL`.

La funzione deve rispettare il seguente prototipo:

```c
struct SpaceStation **create_space_station_network(int num_stations);
```

dove:

* **num_stations** è il numero di stazioni da creare;

**(b)** Scrivere una funzione che deallochi una rete di stazioni spaziali precedentemente allocata con `create_space_station_network`. La funzione riceve come parametri il puntatore alla rete e il numero totale di stazioni.

La funzione deve rispettare il seguente prototipo:

```c
void deallocate_space_station_network(struct SpaceStation **network, int num_stations);
```

dove:

* **network** è il puntatore alla rete;
* **num_stations** è il numero totale di stazioni;

**(c)** Scrivere una funzione che cerchi una stazione spaziale nella rete dato il suo ID. La funzione deve restituire un puntatore alla stazione spaziale se trovata, altrimenti NULL.


La funzione deve rispettare il seguente prototipo:

```c
struct SpaceStation *find_space_station(struct SpaceStation **network, int num_stations, int station_id);
```

dove:

* **network** è il puntatore alla rete;
* **num_stations** è il numero totale di stazioni;
* **station_id** è l'ID della stazione da cercare.


**(d)** Scrivere una funzione che aggiorni i dettagli (nome e ID) di una specifica stazione spaziale in una rete di stazioni spaziali.  La funzione deve restituire un puntatore alla stazione spaziale modificata, altrimenti NULL.

La funzione deve rispettare il seguente prototipo:

```c
struct SpaceStation *update_space_station(struct SpaceStation **network, int num_stations, int station_id, const char *new_name, int new_id);
```

dove:

* **network** è il puntatore alla rete;
* **num_stations** è il numero totale di stazioni;
* **station_id** è l'ID della stazione da aggiornare;
* **new_name** è il nuovo nome della stazione;
* **new_id** è il nuovo ID della stazione.

---

Esercizio 15. Implementare una funzione `filter_even` che, dato un array di interi, restituisce un nuovo array allocato dinamicamente contenente solo i valori pari, mantenendo l'ordine originale. Il numero di elementi del nuovo array viene scritto nella variabile indicata da out_size.

La funzione deve rispettare il seguente prototipo:

```c
int *filter_even(const int *arr, unsigned size, unsigned *out_size);
```

dove:

- **arr** è il puntatore all'array di input;
- **size** è il numero di elementi nell’array originale;
- **out_size** è un puntatore a unsigned dove salvare il numero di elementi dell'array restituito;
- Se non ci sono numeri pari o in caso di errore, la funzione restituisce NULL.

---

Esercizio 16. Implementare una funzione `matrix_diagonal_sum` che, data una matrice quadrata rappresentata tramite puntatori alle righe, calcoli separatamente la somma della diagonale principale e quella della diagonale secondaria. Restituire i due valori in una struttura allocata dinamicamente; per dimensioni dispari l'elemento centrale contribuisce a entrambe le somme.

La funzione deve rispettare il seguente prototipo:

```c
struct diag_sums {
    double main_diag;
    double sec_diag;
};

struct matrix {
    size_t rows, cols;
    double **data;
};

struct diag_sums *matrix_diagonal_sum(const struct matrix *m);
```

dove:

- **m** è il puntatore alla struttura che rappresenta la matrice;
- la funzione ritorna il puntatore alla struttura con i risultati, allocata dinamicamente. Il puntatore vale NULL in caso di errori.

---

Esercizio 30. *(Approfondimento, non richiesto all'esame)*. Implementare un gruppo di funzioni per gestire un array dinamico di elementi di tipo *double* simile ad una lista Java o Python (https://en.wikipedia.org/wiki/Dynamic_array). Le funzioni devono rispettare i seguenti prototipi:

```c
struct arraylist {
    /* number of actual elements contained */
    unsigned elements;
    
    /* size of the underlying array (l->data) */
    unsigned size;
    
    /* array containing the actual data */
    double *data;
};

/* Allocazione dinamica della lista */
struct arraylist *allocate_list();
void free_list(struct arraylist *l);

/* ritorna l'elemento di indice index, con index < l->elements */
double get(struct arraylist *l, unsigned index);

/* ritorna ed elimina l'elemento di indice index. in caso, riduce l'array l->data */
double delete(struct arraylist *l, unsigned index);

/* aggiunge alla lista (in fondo) un elemento di valore value */ 
void add(struct arraylist *l, double value);

/* modifica l'elemento di indice index con il valore value */
void set(struct arraylist *l, unsigned index, double value);

/* ritorna il numero di elementi memorizzati */
unsigned elements(struct arraylist *l);

/* ritorna la capacità dell'array sottostante, distinta dal numero di elementi */
unsigned size(struct arraylist *l);
```

---

Esercizio 31. *(Approfondimento, non richiesto all'esame)*. Implementare un gruppo di funzioni analoghe a quelle dell'esercizio precedente ma che utilizzino una lista concatenata (https://en.wikipedia.org/wiki/Linked_list) al posto di un array dinamico. Per rappresentare la lista, utilizzare le due strutture indicate di seguito.

```c
struct node {
    /* the actual data of the node */
    double data;

    /* pointer to the next node */
    struct node *next;
};

struct linkedlist {
    /* number of actual elements contained */
    unsigned elements;

    /* pointer to the head of the list */
    struct node *head;
};
```
