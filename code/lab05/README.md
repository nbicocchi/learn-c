﻿## Esercizi C (File ed integrazione con la shell)

Si propone un gruppo di esercizi per imparare ad utilizzare l'accesso ai file e l'integrazione del C con la shell. In
particolare, viene proposta una serie di implementazioni semplificate di famosi comandi shell.

--- 

Esercizio 1. Implementare una versione semplificata del comando *echo*

```shell
$ echo [string ...]
```

dove:

* **[string ...]** rappresenta un gruppo di stringhe;
* il comando visualizza a monitor le stringhe passate come argomenti.

---

Esercizio 2. Implementare una versione semplificata del comando *touch*

```shell
$ touch filename
```

dove:

* **filename** rappresenta un nome di file da creare (vuoto).

---

Esercizio 3. Implementare una versione semplificata del comando *size*

```shell
$ size filename
```

dove:

* **filename** rappresenta un nome di file di cui mostrare la dimensione in byte.

---

Esercizio 4. Implementare una versione semplificata del comando *cmp*

```shell
$ cmp filename_1 filename_2
```

dove:

* **filename_1, filename_2** rappresentano due nomi di file da confrontare;
* il comando informa l'utente se i 2 file sono uguali o diversi. Se sono diversi, indica byte e linea del primo carattere diverso.

---

Esercizio 5. Implementare una versione semplificata del comando *cp*

```shell
$ cp filename_1 filename_2
```

dove:

* **filename_1 filename_2** rappresentano sorgente e destinazione della copia;
* il comando copia il contenuto di filename_1 all'interno di filename_2.

---

Esercizio 6. Implementare una versione semplificata del comando *cat*

```shell
$ cat [filename ...]
```

dove:

* **[filename ...]** rappresenta un gruppo di percorsi a file. In caso filename non venga indicato, il comando legge da stdin;
* il comando visualizza il contenuto dei file passati come parametro.

---

Esercizio 7. Implementare una versione semplificata del comando *head*

```shell
$ head n [filename]
```

dove:

* **filename** rappresenta un nome di file di cui mostrare le prime **n** linee. In caso filename non venga indicato, il comando legge da stdin.

---

Esercizio 8. Implementare una versione semplificata del comando *tail*

```shell
$ tail n [filename]
```

dove:

* **filename** rappresenta un nome di file di cui mostrare le ultime **n** linee. In caso filename non venga indicato, il comando legge da stdin.

---

Esercizio 9. Implementare una versione semplificata del comando *wc*

```shell
$ wc [filename]
```

dove:

* **filename** rappresenta un nome di file di cui mostrare su stdout sia il numero di bytes che di linee contenute. In caso filename non venga indicato, il comando legge da stdin.

---

Esercizio 10. Implementare una versione semplificata del comando *grep* (vedi funzione di libreria strstr())

```shell
$ grep string [filename]
```

dove:

* **filename** rappresenta un nome di file di cui mostrare tutte le linee che contengono string. In caso filename non venga indicato, il comando legge da stdin.

---

Esercizio 11. Implementare una versione semplificata del comando *diff*

```shell
$ diff filename_1 filename_2
```

dove:

* **filename_1, filename_2** rappresentano due nomi di file da confrontare; 
* Il comando confronta il contenuto dei 2 file riga per riga e mostra all'utente le eventuali differenze. In particolare, in caso 2 righe corrispondenti siano diverse (ad esempio, la terza riga di entrambi i file), il comando stampa le due versioni. Infine, in caso i due file abbiano un numero diverso di linee, vanno mostrate in output tutte le linee in più del file più lungo. Il comando esce con 0 se i file sono uguali, 1 se sono diversi, 2 in caso di problemi.

---

Esercizio 12. Implementare il comando *filestats* che fornisce statistiche di base sul contenuto di un file di testo (vedi funzione di libreria isspace())

```shell
$ filestats filename
```

dove:

* **filename** rappresenta il nome di un file di testo;
* Il comando legge il file e mostra all'utente le informazioni sul nome del file, numero di linee, parole, e caratteri contenuti.

Esempio di output:

```shell
File: /etc/passwd
Lines: 34
Words: 80
Characters: 1948
```

---

Esercizio 13. Implementare il comando *findword* che permette di cercare una parola all'interno di uno o più file di testo. (vedi funzione di libreria strstr())

```shell
$ findword word file1 [file2 ...]
```

dove:
* **word** rappresenta la parola da cercare;
* **file1, file2**, ... rappresentano uno o più nomi di file da analizzare;
* il comando cerca la parola specificata in ogni file e mostra all'utente il numero ed il contenuto della riga in cui la parola è stata trovata.

Esempio di output:

```shell
File: test1.txt
- Line 3: "La parola 'test' appare qui"
- Line 7: "Questo è un altro test"

File: test2.txt
- Line 1: "Test iniziale"
- Line 15: "Fine del test"

No occurrences found in: test3.txt
```

---

Esercizio 14. Implementare una versione semplificata del comando *tee*

```shell
$ tee <output_file>
```

dove:

* `<output_file>` rappresenta il percorso di un file di output;
* il comando legge da **stdin**, scrive il contenuto sia su **stdout** (schermo) che nel file specificato;
* il file di destinazione viene **sovrascritto** se esiste già (modalità "write").

Esempio d’uso:

```shell
$ echo "Hello, world!" | ./tee output.txt
Hello, world!
$ cat output.txt
Hello, world!
```

---

Esercizio 15. Implementare una versione semplificata del comando *uniq*

```shell
$ uniq [file]
```

dove:

* il comando legge da **stdin** oppure da file;
* stampa su **stdout** solo le righe che compaiono **almeno una volta** nell’input;
* l’ordine delle righe nell’output è lo stesso del primo incontro nell’input.

Esempio d’uso:

```shell
$ cat input.txt
apple
banana
apple
orange
banana
grape

$ cat input.txt | ./uniq
apple
banana
orange
grape
```
