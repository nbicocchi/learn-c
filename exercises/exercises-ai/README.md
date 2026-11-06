# Esercizi con AI — Linguaggio C

Allenamento di comprensione, review e piccola riprogettazione del codice. Per ogni esercizio rispondere alla crocetta e alla domanda aperta prima di consultare la soluzione. I numeri di riga non fanno parte del codice.

Per generare altri esercizi usare [PROMPT.md](PROMPT.md). Gli esempi sono da analizzare su carta: alcuni contengono intenzionalmente difetti e non vanno eseguiti indiscriminatamente.

## Esercizio 1 — Calcolo di un punteggio

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma usa una macro per raddoppiare un punteggio prima di applicare un moltiplicatore. I valori sono piccoli e tutte le operazioni sono rappresentabili come int. Il programma è completo.

```text
 1  #include <stdio.h>
 2  #define DOUBLE(x) x + x
 3
 4  int main(void) {
 5      int base = 3;
 6      int score = 2 * DOUBLE(base);
 7      printf("%d\n", score);
 8      return 0;
 9  }
```

### 1. Scelta multipla

Quale valore viene stampato?

- **A.** 12
- **B.** 6
- **C.** 9
- **D.** Il programma non compila perché una macro non può contenere somme.

### 2. Riprogettazione

Si vuole sostituire DOUBLE con una funzione che calcoli il doppio del valore ricevuto e permetta anche chiamate come `DOUBLE(i++)`, incrementando i una sola volta. Fornisci la definizione della funzione e spiega brevemente perché soddisfa il requisito. Non occorre conservare il nome in maiuscolo.

<details>
<summary>Mostra la soluzione dell'esercizio 1</summary>

### 1. Scelta multipla: C

L'espansione produce `2 * base + base`: la moltiplicazione precede la somma, quindi il risultato è 9.

- **A errata:** presuppone parentesi che non sono presenti nell'espansione.
- **B errata:** ignora il secondo addendo della macro espansa.
- **D errata:** una macro può contenere operatori aritmetici.

### 2. Riprogettazione

Sostituire la direttiva della riga 2 con:

```c
int DOUBLE(int value) {
    return 2 * value;
}
```

L'argomento viene valutato una volta e il suo valore viene copiato nel parametro. Aggiungere soltanto parentesi alla macro risolverebbe la precedenza, non la duplicazione della valutazione; si assume che il doppio sia rappresentabile come int.

</details>

## Esercizio 2 — Selezione degli indici

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma somma gli indici da 0 a 4, escludendo l'indice 2. Il ciclo for gestisce l'aggiornamento del contatore; tutte le operazioni sono rappresentabili come int.

```text
 1  #include <stdio.h>
 2  int main(void) {
 3      int sum = 0;
 4      for (int i = 0; i < 5; i++) {
 5          if (i == 2) {
 6              continue;
 7          }
 8          sum += i;
 9      }
10      printf("%d\n", sum);
11      return 0;
12  }
```

### 1. Scelta multipla

Cosa stampa il programma?

- **A.** 8
- **B.** 10
- **C.** 1
- **D.** Non termina perché continue impedisce sempre l'incremento di i.

### 2. Domanda aperta

Un collega converte il for in `int i = 0; while (i < 5)`, lasciando identico il corpo e aggiungendo `i++` soltanto dopo `sum += i`. La conversione conserva il comportamento? Indica dove si manifesta l'eventuale differenza. Rispondi in 2–3 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 2</summary>

### 1. Scelta multipla: A

Vengono sommati 0, 1, 3 e 4. Nel for, continue passa all'aggiornamento e poi al controllo.

- **B errata:** include anche l'indice escluso.
- **C errata:** tratta continue come break.
- **D errata:** nel for l'aggiornamento viene comunque eseguito.

### 2. Domanda aperta

No: nel while proposto, quando i vale 2, continue salta l'incremento e torna direttamente alla condizione. Il contatore rimane 2 e il ciclo non termina; l'aggiornamento del for non era equivalente a un'istruzione in fondo al corpo in presenza di continue.

</details>

## Esercizio 3 — Controllo di un indice

**Tempo indicativo: 5–7 minuti.**

### Scenario

Una funzione decide se un indice è inferiore a un limite. Il dominio ammesso per index comprende anche valori negativi, mentre limit è unsigned int. Si assume che int e unsigned int abbiano entrambi 32 bit e che UINT_MAX sia 4294967295. Non viene effettuato alcun accesso a un array.

```text
 1  #include <stdio.h>
 2  int below(int index, unsigned int limit) {
 3      return index < limit;
 4  }
 5
 6  int main(void) {
 7      int index = -1;
 8      unsigned int limit = 3;
 9      printf("%d\n", below(index, limit));
10      return 0;
11  }
```

### 1. Scelta multipla

Che cosa viene stampato?

- **A.** -1
- **B.** 1, perché un numero negativo è sempre inferiore a uno positivo.
- **C.** Nessun valore garantito: il confronto causa overflow signed.
- **D.** 0, perché index viene convertito a unsigned int nel confronto.

### 2. Domanda aperta

Il contratto richiesto è ora «accettare soltanto gli indici nell'intervallo da zero incluso a limit escluso». Valuta la proposta `return (unsigned int)index < limit;`: basta a rispettarlo per **tutti** gli input ammessi? Fornisci un controesempio o una motivazione, in 2–3 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 3</summary>

### 1. Scelta multipla: D

Nel confronto il valore -1 viene convertito in UINT_MAX, che non è inferiore a 3. La conversione a unsigned segue regole definite.

- **A errata:** un confronto restituisce 0 oppure 1.
- **B errata:** ignora le conversioni aritmetiche tra signed e unsigned.
- **C errata:** non si tratta di overflow di un'operazione signed.

### 2. Domanda aperta

Non basta: con index uguale a -2 e limit uguale a UINT_MAX, il cast produce UINT_MAX - 1 e il controllo accetta un indice negativo. Serve controllare separatamente la non negatività, ad esempio `index >= 0 && (unsigned int)index < limit`.

</details>

## Esercizio 4 — Media delle misure

**Tempo indicativo: 5–7 minuti.**

### Scenario

Una funzione riceve la somma e il numero di misure e restituisce la media come double. count è sempre positivo e i valori sono piccoli. Il programma stampa una cifra dopo la virgola; la locale usa il punto decimale.

```text
 1  #include <stdio.h>
 2  double average(int sum, int count) {
 3      double result = sum / count;
 4      return result;
 5  }
 6
 7  int main(void) {
 8      printf("%.1f\n", average(5, 2));
 9      return 0;
10  }
```

### 1. Scelta multipla

Quale riga viene stampata?

- **A.** `2.5`
- **B.** `2.0`
- **C.** `3.0`
- **D.** `0.0`

### 2. Domanda aperta

Confronta le sostituzioni `(double)(sum / count)` e `(double)sum / count` alla riga 3: sono equivalenti per tutti gli input ammessi? Spiega in 2–3 frasi quando avviene la conversione e quale espressione soddisfa il requisito della media non intera.

<details>
<summary>Mostra la soluzione dell'esercizio 4</summary>

### 1. Scelta multipla: B

Gli operandi della divisione sono int: 5 / 2 produce 2, poi convertito a double.

- **A errata:** il tipo della variabile di destinazione non cambia retroattivamente la divisione.
- **C errata:** la divisione intera non arrotonda al più vicino.
- **D errata:** il quoziente intero è 2, non zero.

### 2. Domanda aperta

La prima forma converte un quoziente già troncato e per 5 e 2 resta 2.0. La seconda converte sum prima della divisione e provoca anche la conversione di count a double, ottenendo 2.5. Sono quindi diverse e la seconda rispetta il requisito, nei limiti della precisione del tipo.

</details>

## Esercizio 5 — Aggiornamento di un valore

**Tempo indicativo: 5–7 minuti.**

### Scenario

Una funzione riceve un puntatore a un intero modificabile. Il chiamante conserva il proprio puntatore e, dopo la chiamata, stampa il valore puntato. Non sono presenti accessi a memoria non valida durante l'esecuzione della funzione.

```text
 1  #include <stdio.h>
 2  void update(int *p) {
 3      int replacement = 8;
 4      p = &replacement;
 5  }
 6
 7  int main(void) {
 8      int value = 5;
 9      int *p = &value;
10      update(p);
11      printf("%d\n", *p);
12      return 0;
13  }
```

### 1. Scelta multipla

Cosa stampa il programma?

- **A.** 5
- **B.** 8
- **C.** Nessun valore garantito, perché il puntatore del chiamante punta a replacement dopo il ritorno.
- **D.** L'indirizzo di value, perché `%d` stampa automaticamente gli indirizzi.

### 2. Riprogettazione

Il contratto della funzione deve diventare «scrivere 8 nell'intero del chiamante», senza restituire né conservare puntatori a variabili locali. Sostituisci soltanto il corpo di update e motiva la differenza tra modificare il parametro e modificare l'oggetto puntato. Sono sufficienti una riga e 1–2 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 5</summary>

### 1. Scelta multipla: A

Il parametro p è una copia del puntatore del chiamante. Riassegnarlo non cambia né value né il puntatore in main.

- **B errata:** nessuna istruzione assegna 8 a value.
- **C errata:** il puntatore del chiamante non viene aggiornato all'indirizzo locale.
- **D errata:** `*p` è un intero, non un indirizzo.

### 2. Riprogettazione

Il corpo diventa:

```c
*p = 8;
```

La dereferenziazione modifica l'intero originale. Rimane il passaggio per valore del puntatore, ma non viene creata né esportata una nuova variabile locale.

</details>

## Esercizio 6 — Elaborazione di un vettore

**Tempo indicativo: 5–7 minuti.**

### Scenario

Una funzione deve raddoppiare gli elementi di un array. Si assume una piattaforma con sizeof(int) uguale a 4 e sizeof(int *) uguale a 8. Tutti gli elementi sono inizializzati e le operazioni non causano overflow.

```text
 1  #include <stdio.h>
 2  void scale(int values[]) {
 3      size_t count = sizeof(values) / sizeof(values[0]);
 4      for (size_t i = 0; i < count; i++) {
 5          values[i] *= 2;
 6      }
 7  }
 8  int main(void) {
 9      int values[] = {1, 2, 3, 4};
10      scale(values);
11      printf("%d %d\n", values[1], values[3]);
12      return 0;
13  }
```

### 1. Scelta multipla

Cosa stampa il programma nelle condizioni dichiarate?

- **A.** `2 4`
- **B.** `4 8`
- **C.** `4 4`
- **D.** Non compila: un parametro non può usare la notazione array.

### 2. Riprogettazione

Proponi un'interfaccia che permetta di raddoppiare array di qualsiasi lunghezza senza dedurla dalle dimensioni del puntatore. Indica firma, inizializzazione del ciclo e chiamata per l'array in main. Il corpo di aggiornamento può rimanere invariato. Sono sufficienti poche righe e una frase.

<details>
<summary>Mostra la soluzione dell'esercizio 6</summary>

### 1. Scelta multipla: C

Il parametro values è adattato a int *: il rapporto vale 8 / 4, cioè 2. Vengono raddoppiati soltanto i primi due elementi.

- **A errata:** il secondo elemento viene effettivamente modificato.
- **B errata:** presuppone che sizeof misuri l'array del chiamante.
- **D errata:** la notazione è ammessa, ma non trasmette la lunghezza dell'array.

### 2. Riprogettazione

Usare un parametro esplicito di lunghezza:

```c
void scale(int *values, size_t count) {
    for (size_t i = 0; i < count; i++) {
        values[i] *= 2;
    }
}
```

In main sostituire la chiamata con:

```c
scale(values, sizeof(values) / sizeof(values[0]));
```

Il rapporto è calcolato dove values è ancora un vero array. Il contratto richiede almeno count elementi accessibili; con count zero il ciclo non accede alla memoria.

</details>

## Esercizio 7 — Composizione di un messaggio

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma prepara il messaggio `ciao!` e vuole stamparlo come stringa C. Il buffer è locale e modificabile. Si valuta il rispetto dei limiti e della terminazione nulla, non il comportamento accidentale della memoria adiacente.

```text
 1  #include <stdio.h>
 2  int main(void) {
 3      char text[5] = "ciao";
 4      text[4] = '!';
 5      printf("%s\n", text);
 6      return 0;
 7  }
```

### 1. Scelta multipla

Quale affermazione è corretta?

- **A.** Viene sempre stampato `ciao!` e poi il programma termina correttamente.
- **B.** Non c'è un output garantito: printf riceve un array privo del terminatore nullo necessario a `%s`.
- **C.** La riga 4 è fuori dai limiti dell'array.
- **D.** Il compilatore aggiunge automaticamente un sesto elemento per il terminatore.

### 2. Domanda aperta

Qual è la capacità minima del buffer per rappresentare il risultato richiesto come stringa C? Indica la modifica minima alla dichiarazione che rende valido il programma dato, senza cambiare la stampa, e spiega quale elemento contiene il terminatore. Sono sufficienti una riga e 1–2 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 7</summary>

### 1. Scelta multipla: B

La riga 4 sostituisce l'unico terminatore dell'array con un punto esclamativo. `%s` richiede una stringa terminata e può leggere oltre il buffer: il comportamento è indefinito.

- **A errata:** un risultato osservato non è una garanzia del linguaggio.
- **C errata:** l'indice 4 è valido per un array di cinque elementi.
- **D errata:** la dimensione esplicita dell'array non viene aumentata automaticamente.

### 2. Domanda aperta

La capacità minima è 6: cinque caratteri visibili e il terminatore. Sostituire la riga 3 con:

```c
char text[6] = "ciao";
```

L'inizializzazione mette a zero anche l'elemento aggiuntivo: dopo la modifica di text[4], text[5] rimane nullo.

</details>

## Esercizio 8 — Copia di un record

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un record contiene un puntatore al nome e un punteggio. Due record sono ottenuti per assegnazione. Il nome è memorizzato in un array modificabile che rimane valido fino alla fine di main; non c'è memoria dinamica da liberare.

```text
 1  #include <stdio.h>
 2  struct record {
 3      char *name;
 4      int score;
 5  };
 6  int main(void) {
 7      char name[] = "Ada";
 8      struct record a = {name, 10};
 9      struct record b = a;
10      b.name[0] = 'E';
11      b.score = 20;
12      printf("%s %d\n", a.name, a.score);
13      return 0;
14  }
```

### 1. Scelta multipla

Quale riga viene stampata?

- **A.** `Ada 10`
- **B.** `Eda 20`
- **C.** `Ada 20`
- **D.** `Eda 10`

### 2. Domanda aperta

Se il requisito fosse «dopo la copia, modificare il nome di b non deve modificare quello di a», l'assegnazione della struttura sarebbe sufficiente? Spiega quali parti vengono copiate e proponi una rappresentazione minima per nomi lunghi al massimo 15 caratteri, senza allocazione dinamica. Rispondi in 2–3 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 8</summary>

### 1. Scelta multipla: D

L'assegnazione copia i campi: i due puntatori designano lo stesso array, mentre score è copiato come valore indipendente.

- **A errata:** ignora la modifica dell'array condiviso.
- **B errata:** il punteggio di a non viene aggiornato modificando quello di b.
- **C errata:** inverte i due effetti della copia.

### 2. Domanda aperta

Non basta con il campo puntatore: viene copiato l'indirizzo, non l'array puntato. Un campo `char name[16]` incorporato nella struttura offre spazio per 15 caratteri e il terminatore; l'assegnazione copia anche l'array incorporato, rendendo indipendenti i nomi. L'inizializzazione dei record va adattata a questa rappresentazione.

</details>

## Esercizio 9 — Conteggio ricorsivo

**Tempo indicativo: 5–7 minuti.**

### Scenario

Una funzione conta ricorsivamente gli elementi positivi di un array. Il contratto richiede un array valido di almeno n elementi quando n è positivo; per n zero non deve accedere all'array. La profondità della ricorsione negli input considerati è piccola.

```text
 1  #include <stdio.h>
 2  #include <stddef.h>
 3  size_t positives(const int *v, size_t n) {
 4      if (n == 0) return 0;
 5      return (v[0] > 0) + positives(v + 1, n - 1);
 6  }
 7  int main(void) {
 8      int v[] = {2, -1, 0, 4};
 9      printf("%zu\n", positives(v, 4));
10      return 0;
11  }
```

### 1. Scelta multipla

Cosa stampa il programma?

- **A.** 2
- **B.** 3
- **C.** 4
- **D.** Non termina, perché il puntatore viene incrementato a ogni chiamata.

### 2. Domanda aperta

Il contratto consente la chiamata `positives(NULL, 0)`? Spiega se il codice accede al puntatore o ne esegue aritmetica in questo caso e perché la posizione del caso base conta. Rispondi in 2–3 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 9</summary>

### 1. Scelta multipla: A

Soltanto 2 e 4 sono strettamente positivi. Ogni confronto contribuisce 0 oppure 1.

- **B errata:** include lo zero tra i positivi.
- **C errata:** conta tutti gli elementi invece di quelli che soddisfano il confronto.
- **D errata:** n diminuisce fino al caso base.

### 2. Domanda aperta

Sì: il contratto non richiede elementi accessibili quando n è zero. Il return del caso base avviene prima di valutare v[0] o v + 1, quindi NULL non viene dereferenziato né usato nell'aritmetica dei puntatori. Spostare il controllo dopo tali operazioni perderebbe questa garanzia.

</details>

## Esercizio 10 — Creazione di una sequenza

**Tempo indicativo: 5–7 minuti.**

### Scenario

Una funzione crea un array dinamico contenente gli interi da 1 a n. Si assumono n positivo, dimensione dell'allocazione rappresentabile e n abbastanza piccolo per rappresentare ogni elemento come int. La memoria restituita appartiene al chiamante; NULL indica un fallimento.

```text
 1  #include <stdio.h>
 2  #include <stdlib.h>
 3  int *sequence(size_t n) {
 4      int *v = malloc(n * sizeof(*v));
 5      if (v == NULL) return NULL;
 6      for (size_t i = 0; i < n; i++) {
 7          v[i] = (int)i + 1;
 8      }
 9      return v;
10  }
11  int main(void) {
12      int *v = sequence(3);
13      if (v == NULL) return 1;
14      printf("%d\n", v[2]);
15      free(v);
16      return 0;
17  }
```

### 1. Scelta multipla

Assumendo che l'allocazione riesca, quale affermazione è corretta?

- **A.** Il blocco diventa invalido appena sequence termina.
- **B.** È necessario liberare separatamente ogni elemento int.
- **C.** Viene stampato 3 e il blocco viene liberato una sola volta dal chiamante.
- **D.** Il programma perde memoria perché sequence non chiama free prima di return.

### 2. Riprogettazione

Si vuole evitare qualsiasi allocazione nella funzione: il chiamante fornisce un buffer e la sua capacità, la funzione riceve anche n e restituisce 1 se lo riempie, 0 se la capacità è insufficiente, senza scrivere in quel caso. n resta positivo e limitato come sopra; il buffer ha capacity elementi validi e modificabili.

Proponi firma e corpo della nuova funzione, senza riscrivere main. Sono sufficienti poche righe e una breve motivazione.

<details>
<summary>Mostra la soluzione dell'esercizio 10</summary>

### 1. Scelta multipla: C

La durata del blocco dinamico non dipende dalla durata della variabile locale che ne contiene l'indirizzo. Il chiamante lo usa e poi lo libera.

- **A errata:** confonde la durata del puntatore locale con quella del blocco allocato.
- **B errata:** gli interi appartengono a un'unica allocazione.
- **D errata:** liberare prima del ritorno invaliderebbe il risultato; la responsabilità appartiene al chiamante.

### 2. Riprogettazione

```c
int sequence(int *v, size_t capacity, size_t n) {
    if (capacity < n) return 0;
    for (size_t i = 0; i < n; i++) {
        v[i] = (int)i + 1;
    }
    return 1;
}
```

Il controllo precede ogni scrittura. La funzione non acquisisce ownership del buffer e non deve chiamare free; il chiamante ne gestisce la durata.

</details>

## Esercizio 11 — Ampliamento di un buffer

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma allarga un buffer da due a quattro interi. Si considera specificamente il caso in cui malloc riesce ma realloc, chiamata con dimensione positiva, fallisce. In questo caso realloc restituisce NULL e lascia valido il vecchio blocco. Nessun'altra parte del programma conserva il suo indirizzo.

```text
 1  #include <stdlib.h>
 2  int main(void) {
 3      int *v = malloc(2 * sizeof(*v));
 4      if (v == NULL) return 1;
 5      v[0] = 3;
 6      v[1] = 4;
 7      v = realloc(v, 4 * sizeof(*v));
 8      if (v == NULL) return 1;
 9      free(v);
10      return 0;
11  }
```

### 1. Scelta multipla

Che cosa accade nel caso di fallimento dichiarato?

- **A.** realloc libera automaticamente il blocco originale.
- **B.** v vale NULL e il blocco originale rimane allocato, ma non è più raggiungibile dal programma prima della terminazione.
- **C.** v conserva automaticamente il vecchio indirizzo.
- **D.** Il programma esegue necessariamente una doppia free.

### 2. Riprogettazione

Sostituisci le righe 7–8 affinché un fallimento non perda l'indirizzo del blocco e il programma termini dopo averlo liberato. In caso di successo, v deve riferirsi al blocco ridimensionato e il resto del programma deve rimanere valido. Sono sufficienti poche righe e una frase.

<details>
<summary>Mostra la soluzione dell'esercizio 11</summary>

### 1. Scelta multipla: B

L'assegnazione sostituisce l'unico puntatore al vecchio blocco con NULL. Il blocco non viene liberato da realloc in questo caso.

- **A errata:** contraddice il contratto di realloc con dimensione positiva.
- **C errata:** l'assegnazione sovrascrive v con il valore restituito.
- **D errata:** il ramo di fallimento termina prima della free e non ci sono due rilasci.

### 2. Riprogettazione

```c
int *tmp = realloc(v, 4 * sizeof(*v));
if (tmp == NULL) {
    free(v);
    return 1;
}
v = tmp;
```

Il puntatore temporaneo separa il risultato del tentativo dall'ownership del blocco originale. Dopo un successo si usa soltanto il nuovo puntatore, perché il blocco potrebbe essere stato spostato.

</details>

## Esercizio 12 — Elaborazione di una riga

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma memorizza una matrice come array di due righe, ciascuna composta da tre interi. Una funzione somma gli elementi della riga ricevuta. Le dimensioni sono quelle dichiarate e non si verificano overflow.

```text
 1  #include <stdio.h>
 2  int row_sum(const int row[3]) {
 3      int sum = 0;
 4      for (int i = 0; i < 3; i++) {
 5          sum += row[i];
 6      }
 7      return sum;
 8  }
 9  int main(void) {
10      int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
11      printf("%d\n", row_sum(m[1]));
12      return 0;
13  }
```

### 1. Scelta multipla

Quale valore viene stampato?

- **A.** 6
- **B.** 21
- **C.** 4
- **D.** 15

### 2. Domanda aperta

Per elaborare l'intera matrice, un collega propone `void process(int **m)` e sostiene di poterle passare direttamente l'array di main. La rappresentazione è compatibile? Spiega in 2–3 frasi il tipo ottenuto dalla conversione dell'array e la differenza rispetto a un array di puntatori.

<details>
<summary>Mostra la soluzione dell'esercizio 12</summary>

### 1. Scelta multipla: D

m[1] designa la seconda riga; la funzione somma 4, 5 e 6.

- **A errata:** è la somma della prima riga.
- **B errata:** è la somma di tutta la matrice.
- **C errata:** considera soltanto il primo elemento della riga ricevuta.

### 2. Domanda aperta

No: m viene convertito in un puntatore a una riga di tre int, cioè `int (*)[3]`, non in int **. La matrice contiene direttamente interi contigui, non puntatori a righe. Una firma coerente è `void process(int m[][3])`, eventualmente accompagnata dal numero di righe.

</details>

## Esercizio 13 — Apertura di un registro

**Tempo indicativo: 5–7 minuti.**

### Scenario

Il file `registro.txt` esiste già e contiene i quattro byte di `old\n`. Il programma seguente viene eseguito in un ambiente in cui newline corrisponde a un singolo byte. Tutte le operazioni di apertura, scrittura e chiusura riescono; il file non cambia per altre cause.

```text
 1  #include <stdio.h>
 2  int main(void) {
 3      FILE *fp = fopen("registro.txt", "w");
 4      if (fp == NULL) return 1;
 5      int written = fputs("new\n", fp);
 6      int closed = fclose(fp);
 7      if (written == EOF || closed == EOF) {
 8          return 1;
 9      }
10      return 0;
11  }
```

### 1. Scelta multipla

Qual è il contenuto finale del file?

- **A.** Soltanto `new\n`.
- **B.** `old\nnew\n`.
- **C.** Soltanto `old\n`.
- **D.** Un file vuoto, perché fclose annulla la scrittura.

### 2. Domanda aperta

Si propone di cambiare soltanto la modalità in `w+` per conservare lo storico e aggiungere la nuova riga. La proposta soddisfa il requisito? Indica quale modalità sarebbe adatta e se permetterebbe anche di creare un registro assente. Rispondi in 2–3 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 13</summary>

### 1. Scelta multipla: A

La modalità w tronca il file all'apertura. Successivamente viene scritta e salvata la nuova riga.

- **B errata:** richiederebbe una modalità append.
- **C errata:** ignora sia il troncamento sia la nuova scrittura.
- **D errata:** fclose completa l'output pendente, non annulla le scritture.

### 2. Domanda aperta

No: anche w+ tronca il contenuto precedente, pur consentendo sia lettura sia scrittura. Per aggiungere le righe preservando lo storico è adatta la modalità a; crea il file se non esiste. a+ è un'alternativa se serve anche leggerlo, rispettando le regole degli stream di aggiornamento.

</details>

## Esercizio 14 — Conteggio dei byte letti

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma conta fino a tre risultati di lettura da un file binario. `dato.bin` contiene soltanto il byte ASCII di A. Si assumono unsigned char di 8 bit, int di 32 bit, EOF uguale a -1, apertura e chiusura riuscite e nessun errore di lettura. fgetc restituisce il byte come unsigned char convertito a int, oppure EOF a fine file.

```text
 1  #include <stdio.h>
 2  int main(void) {
 3      FILE *fp = fopen("dato.bin", "rb");
 4      if (fp == NULL) return 1;
 5      unsigned char ch;
 6      int count = 0;
 7      while (count < 3 && (ch = fgetc(fp)) != EOF) {
 8          count++;
 9      }
10      printf("%d\n", count);
11      fclose(fp);
12      return 0;
13  }
```

### 1. Scelta multipla

Quale conteggio viene stampato nelle condizioni dichiarate?

- **A.** 0
- **B.** 1
- **C.** 3
- **D.** Il programma non può terminare, nemmeno con il limite count < 3.

### 2. Domanda aperta

È possibile distinguere tutti i valori di byte da EOF dopo aver memorizzato il risultato di fgetc in unsigned char? Indica il tipo adatto per ch e spiega perché rimuovere soltanto il limite count < 3 non risolverebbe il problema. Rispondi in 2–3 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 14</summary>

### 1. Scelta multipla: C

EOF viene convertito in 255 nell'assegnazione a ch. Il valore promosso a int non è -1, quindi il ciclo conta anche i tentativi successivi alla fine del file, fino al limite di tre.

- **A errata:** la prima lettura produce il byte A e incrementa count.
- **B errata:** presuppone che EOF sia conservato nella variabile unsigned char.
- **D errata:** il limite count < 3 arresta comunque il ciclo.

### 2. Domanda aperta

No: il risultato va conservato in int, che può rappresentare sia tutti i byte sia EOF. Con unsigned char la conversione perde la distinzione tra EOF e il byte 255; togliendo il limite, i tentativi a fine file continuerebbero a essere interpretati come dati, fino a ulteriori problemi come l'overflow di count.

</details>

## Esercizio 15 — Scelta di una modalità

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma assegna un costo a una modalità di lavoro. I nomi delle modalità sono costanti di un'enumerazione. Il comportamento deve essere ricavato dal controllo di flusso effettivo, non dai nomi delle modalità.

```text
 1  #include <stdio.h>
 2  enum mode { BASIC, EXTENDED };
 3  int cost(enum mode mode) {
 4      int result = 0;
 5      switch (mode) {
 6          case BASIC: result += 2;
 7          case EXTENDED: result += 3; break;
 8          default: result = -1; break;
 9      }
10      return result;
11  }
12  int main(void) {
13      printf("%d\n", cost(BASIC));
14      return 0;
15  }
```

### 1. Scelta multipla

Quale valore viene stampato?

- **A.** 2
- **B.** 5
- **C.** 3
- **D.** -1

### 2. Domanda aperta

Un collega propone di inserire break dopo ogni case come regola automatica. È sempre una correzione valida? Spiega in riferimento alla funzione la differenza tra fall-through intenzionale e violazione di un contratto che richiedesse costo 2 per BASIC e 3 per EXTENDED. Rispondi in 2–3 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 15</summary>

### 1. Scelta multipla: B

Dopo il case BASIC non c'è break, quindi si aggiungono sia 2 sia 3 prima di uscire dallo switch.

- **A errata:** presuppone un break al termine del primo case.
- **C errata:** ignora l'incremento effettuato in BASIC.
- **D errata:** l'esecuzione non raggiunge default perché incontra il break del secondo case.

### 2. Domanda aperta

Non è una regola valida senza conoscere il contratto: il fall-through può essere intenzionale per sommare componenti di costo. Con il requisito esplicito 2 per BASIC e 3 per EXTENDED servirebbe invece interrompere BASIC dopo il primo incremento. La modifica cambia il comportamento, non soltanto lo stile.

</details>

## Esercizio 16 — Criterio di selezione

**Tempo indicativo: 5–7 minuti.**

### Scenario

Una funzione conta gli elementi di un array che soddisfano un predicato ricevuto come puntatore a funzione. Il predicato restituisce zero oppure un valore diverso da zero. Array e puntatore a funzione sono validi per tutta la chiamata.

```text
 1  #include <stdio.h>
 2  int positive(int value) {
 3      return value > 0;
 4  }
 5  size_t selected(const int *v, size_t n, int (*accept)(int)) {
 6      size_t count = 0;
 7      for (size_t i = 0; i < n; i++) {
 8          if (accept(v[i])) count++;
 9      }
10      return count;
11  }
12  int main(void) {
13      int v[] = {-2, 0, 3, 4};
14      printf("%zu\n", selected(v, 4, positive));
15      return 0;
16  }
```

### 1. Scelta multipla

Cosa stampa il programma?

- **A.** 4
- **B.** 3
- **C.** 0
- **D.** 2

### 2. Riprogettazione

Si vuole contare gli elementi strettamente maggiori di una soglia scelta dal chiamante, senza variabili globali. Estendi l'interfaccia del predicato e di selected affinché la soglia sia un parametro esplicito. Indica soltanto firme, espressione del predicato, chiamata al predicato e chiamata in main per soglia 3. Il resto del ciclo resta invariato.

<details>
<summary>Mostra la soluzione dell'esercizio 16</summary>

### 1. Scelta multipla: D

Il predicato accetta soltanto 3 e 4, quindi il conteggio è due.

- **A errata:** non tutti gli elementi soddisfano il predicato.
- **B errata:** lo zero non è strettamente positivo.
- **C errata:** un puntatore a funzione valido può essere invocato con la notazione mostrata.

### 2. Riprogettazione

Sostituire positive con:

```c
int above(int value, int threshold) {
    return value > threshold;
}
```

La firma di selected diventa:

```c
size_t selected(const int *v, size_t n,
                int (*accept)(int, int), int threshold)
```

Nella riga 8 usare `if (accept(v[i], threshold)) count++;`. In main:

```c
printf("%zu\n", selected(v, 4, above, 3));
```

La soglia è una dipendenza esplicita e può variare tra chiamate senza introdurre stato globale. Con questo input il nuovo conteggio è 1.

</details>

## Esercizio 17 — Argomenti del programma

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma stampa il numero di argomenti utente e poi ciascuno su una riga. Viene avviato dalla shell con il comando riportato nella domanda. La shell conserva tra virgolette i nomi contenenti spazi; argv[0] contiene `./elenco` e tutte le stampe riescono.

```text
 1  #include <stdio.h>
 2  int main(int argc, char *argv[]) {
 3      printf("utenti=%d\n", argc - 1);
 4      for (int i = 1; i < argc; i++) {
 5          printf("<%s>\n", argv[i]);
 6      }
 7      return 0;
 8  }
```

### 1. Scelta multipla

Qual è l'output di `./elenco "Anna Maria" Luca`?

- **A.** `utenti=2`, poi `<Anna Maria>` e `<Luca>` su righe distinte.
- **B.** `utenti=3`, poi `<Anna>`, `<Maria>` e `<Luca>`.
- **C.** `utenti=2`, poi `<./elenco>` e `<Anna Maria>`.
- **D.** `utenti=1`, poi `<Anna Maria Luca>`.

### 2. Domanda aperta

Un collega sostituisce `i < argc` con `i <= argc`, per «non perdere l'ultimo argomento». La modifica è corretta? Indica quale valore si incontra nell'iterazione aggiuntiva e se è un argomento valido per `%s`. Rispondi in 2–3 frasi, senza attribuire un output preciso a operazioni non valide.

<details>
<summary>Mostra la soluzione dell'esercizio 17</summary>

### 1. Scelta multipla: A

argc vale 3, incluso il nome del programma. Gli argomenti utente sono due e le virgolette vengono gestite dalla shell, non incluse nel nome ricevuto.

- **B errata:** lo spazio quotato non separa due argomenti.
- **C errata:** il ciclo parte da 1 e non stampa argv[0].
- **D errata:** Luca è passato come argomento distinto.

### 2. Domanda aperta

No: l'ultimo argomento valido è argv[argc - 1], già incluso. argv[argc] è il puntatore nullo che termina l'array, non una stringa valida da passare a `%s`; usarlo così causa comportamento indefinito. Non è garantito né un crash né la stampa di una particolare parola sostitutiva.

</details>

## Esercizio 18 — Aggiornamento di una maschera

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma mantiene tre opzioni nei bit meno significativi di un unsigned int. I bit sono numerati da zero partendo da destra. Tutti gli shift hanno ampiezza valida; le operazioni interessano soltanto i bit indicati.

```text
 1  #include <stdio.h>
 2  int main(void) {
 3      unsigned int flags = 5u;  /* bit bassi: 101 */
 4      flags |= (1u << 1);
 5      flags &= ~(1u << 0);
 6      int active = (flags & (1u << 2)) != 0;
 7      printf("%u %d\n", flags, active);
 8      return 0;
 9  }
```

### 1. Scelta multipla

Quale riga viene stampata?

- **A.** `7 1`
- **B.** `4 0`
- **C.** `6 1`
- **D.** `6 4`

### 2. Domanda aperta

Si propone di sostituire la riga 5 con `flags ^= (1u << 0)`, sostenendo che XOR cancella sempre il bit scelto. La sostituzione è equivalente per qualsiasi maschera? Fornisci un valore iniziale del bit che distingua le due operazioni e spiega perché l'input dell'esempio potrebbe non rilevare la differenza. Rispondi in 2–3 frasi.

<details>
<summary>Mostra la soluzione dell'esercizio 18</summary>

### 1. Scelta multipla: C

La prima operazione porta i bit bassi a 111, la seconda a 110, cioè 6. Il confronto con zero converte l'esito del test sul bit 2 in 1.

- **A errata:** ignora la cancellazione del bit 0.
- **B errata:** applica male la maschera e considera spento il bit 2.
- **D errata:** il confronto `!= 0` produce 0 oppure 1, non il valore della maschera.

### 2. Domanda aperta

No: se il bit scelto è già zero, AND con la maschera complementata lo lascia a zero, mentre XOR lo porta a uno. Ad esempio, per flags uguale a 4, dopo la riga 4 si ha 6: AND produce ancora 6, XOR produce 7. Nell'esempio originale il bit 0 era uno e entrambe le operazioni lo portano a zero.

</details>

## Esercizio 19 — Identificatori progressivi

**Tempo indicativo: 5–7 minuti.**

### Scenario

Una funzione produce identificatori crescenti a partire da 10. Il programma la chiama due volte in istruzioni separate, così l'ordine delle chiamate è determinato. Sono considerate soltanto queste due chiamate, senza problemi di overflow o concorrenza.

```text
 1  #include <stdio.h>
 2  int next_id(void) {
 3      static int value = 10;
 4      value++;
 5      return value;
 6  }
 7  int main(void) {
 8      int first = next_id();
 9      int second = next_id();
10      printf("%d %d\n", first, second);
11      return 0;
12  }
```

### 1. Scelta multipla

Cosa stampa il programma?

- **A.** `10 11`
- **B.** `11 12`
- **C.** `11 11`
- **D.** Non compila, perché static è ammesso soltanto fuori dalle funzioni.

### 2. Domanda aperta

Un collega afferma che value, essendo locale, viene reinizializzata a ogni chiamata e può essere letta direttamente da main. Valuta separatamente le due affermazioni, distinguendo durata e scope. Rispondi in 2–3 frasi e indica l'effetto di rimuovere static.

<details>
<summary>Mostra la soluzione dell'esercizio 19</summary>

### 1. Scelta multipla: B

La variabile static conserva il proprio valore: la prima chiamata restituisce 11, la seconda 12.

- **A errata:** l'incremento precede il return anche nella prima chiamata.
- **C errata:** presuppone una nuova inizializzazione a ogni chiamata.
- **D errata:** le variabili locali static sono ammesse.

### 2. Domanda aperta

Entrambe sono false: value ha durata statica ma scope locale alla funzione, quindi conserva il valore senza diventare direttamente visibile a main. Senza static sarebbe una variabile automatica inizializzata a 10 a ogni chiamata, producendo `11 11`. Durata e visibilità sono proprietà diverse.

</details>

## Esercizio 20 — Lettura di record binari

**Tempo indicativo: 5–7 minuti.**

### Scenario

Un programma legge al massimo quattro interi da un file prodotto sulla stessa implementazione C, che contiene esattamente due int completi con valori 7 e 9 e nessun byte ulteriore. Si assumono sizeof(int) uguale a 4, apertura e chiusura riuscite e nessun errore di lettura. fread restituisce il numero di elementi completi letti, non il numero di byte.

```text
 1  #include <stdio.h>
 2  int main(void) {
 3      FILE *fp = fopen("numeri.bin", "rb");
 4      if (fp == NULL) return 1;
 5      int values[4] = {0};
 6      size_t count = fread(values, sizeof(values[0]), 4, fp);
 7      printf("%zu %d\n", count, values[1]);
 8      fclose(fp);
 9      return 0;
10  }
```

### 1. Scelta multipla

Quale riga viene stampata?

- **A.** `8 9`
- **B.** `4 9`
- **C.** `2 0`
- **D.** `2 9`

### 2. Riprogettazione

Definisci una funzione `read_sum(FILE *fp, int *out)` che legga fino a quattro int e, in assenza di errori, scriva in out la somma dei soli elementi completi letti e restituisca 1. Se ferror segnala un errore, restituisca 0 senza modificare out. fp e out sono validi; la funzione non deve chiudere lo stream e la somma è rappresentabile come int. Un file vuoto è valido e deve produrre somma zero.

Fornisci il corpo della funzione e una breve motivazione. Per questo contratto eventuali byte finali che non completano un int non contribuiscono alla somma.

<details>
<summary>Mostra la soluzione dell'esercizio 20</summary>

### 1. Scelta multipla: D

Vengono letti due elementi completi, per un totale di otto byte. Il secondo elemento letto vale 9.

- **A errata:** confonde elementi e byte.
- **B errata:** confonde la capacità del buffer con il numero effettivamente letto.
- **C errata:** il secondo elemento è stato effettivamente letto dal file e vale 9.

### 2. Riprogettazione

```c
int read_sum(FILE *fp, int *out) {
    int values[4];
    size_t count = fread(values, sizeof(values[0]), 4, fp);
    if (ferror(fp)) return 0;
    int sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += values[i];
    }
    *out = sum;
    return 1;
}
```

Si usano soltanto gli elementi completi effettivamente letti. Il risultato viene scritto dopo il controllo dell'errore, preservando out nel ramo di fallimento e lasciando al chiamante la gestione dello stream.

</details>
