## Esercizi C (Puntatori)

Si propone un gruppo di esercizi per approfondire l'utilizzo dei riferimenti a locazioni di memoria (puntatori).

---

Esercizio 1. Scrivere un programma per mostrare la dichiarazione base di un puntatore.

![01.png](imgs/01.png)

---

Esercizio 2. Scrivere un programma per dimostrare come gestire i puntatori in un programma.

![02.png](imgs/02.png)

---

Esercizio 3. Scrivere un programma per dimostrare l'uso degli operatori `&(indirizzo di)` e `*(valore all'indirizzo)`.

![03.png](imgs/03.png)

---

Esercizio 4. Scrivere una funzione per sommare numeri utilizzando l'input da console ed il passaggio dei parametri per riferimento.

La funzione deve rispettare il seguente prototipo:

```c
long addTwoNumbers(long *n1, long *n2);
```

dove:

* **n1** e **n2** sono i puntatori agli addendi;
* la funzione ritorna il risultato della somma.

![04.png](imgs/04.png)

---

Esercizio 5. Scrivere una funzione per calcolare la lunghezza di una stringa usando il suo puntatore.

La funzione deve rispettare il seguente prototipo:

```c
int calculateLength(char* ch)
```

dove:

* **ch** è il puntatore al primo carattere della stringa;
* la funzione ritorna la lunghezza della stringa.

![05.png](imgs/05.png)

---

Esercizio 6. Scrivere un programma per dimostrare l'uso dei puntatori alle strutture.

![06.png](imgs/06.png)

---

Esercizio 7. Scrivere un programma per mostrare un puntatore a un array i cui contenuti sono puntatori a strutture.

![07.png](imgs/07.png)
