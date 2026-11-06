# File in C

## File binari e file di testo

Uno stesso dato può sempre essere memorizzato sia in file di testo che in file binari utilizzando un'opportuna rappresentazione. La scelta del tipo di rappresentazione dipende da considerazioni legate al tipo di utilizzo che viene fatto dei dati.

In un file di testo il contenuto si presenta come una stringa di caratteri mentre in un file binario si usa la codifica binaria. Ad esempio, per memorizzare un intero a 32 bit in un file binario sono sempre necessari 4 byte indipendentemente dal valore memorizzato. Al contrario, la memorizzazione in un file di testo richiede un numero di byte che dipende dal valore da memorizzare.

```text
Esempio: memorizzazione del numero decimale 214439

File di testo:
'2' '1' '4' '4' '3' '9'                         (6 byte)

File binario (dipende dalla endianness):
0x00 0x03 0x45 0xa7                             (4 byte)
```

```text
Esempio: memorizzazione del numero decimale 6

File di testo:
'6'                                             (1 byte)

File binario:
0x00 0x00 0x00 0x06                             (4 byte)
```

Un file di testo è un caso particolare di file binario che utilizza principalmente caratteri ASCII stampabili e caratteri di controllo (`\n`, `\t`, ecc.).

```c
/* Prints the ASCII codes from 0 to 127 */
#include <stdio.h>

int main(void) {
    int i;

    for (i = 0; i < 128; i++) {
        printf("[%3d] -> %c\n", i, i);
    }

    return 0;
}
```

Un file di testo può essere manipolato anche usando funzioni orientate ai file binari, poiché un file è sempre una sequenza di byte. Operare su file binari con funzioni orientate al testo è invece più difficile.

```bash
$ xxd /etc/passwd
$ xxd /bin/ls
```

## Differenze tra file di testo e file binari

### File di testo

* Contengono caratteri ASCII stampabili e caratteri di controllo
* Sono letti e scritti per caratteri o linee
* Le linee terminano normalmente con `\n`
* Sono facilmente visualizzabili con editor di testo
* Sono generalmente più portabili tra sistemi diversi
* Esempi:

  * sorgenti C
  * file JSON
  * file CSV
  * file di configurazione

### File binari

* Possono contenere qualsiasi valore di byte
* Vengono letti e scritti a blocchi
* Non sono leggibili direttamente con editor di testo
* Sono spesso più compatti ed efficienti
* Possono dipendere dall'architettura del sistema
* Esempi:

  * file eseguibili
  * immagini
  * audio/video
  * archivi compressi

## Portabilità dei file binari

I file binari possono dipendere da:

* endianness
* dimensione dei tipi primitivi
* padding delle struct
* architettura CPU
* compilatore

Per questo motivo i file di testo sono generalmente più interoperabili tra sistemi diversi.

---

# La libreria stdio e il tipo FILE

Le funzioni per la gestione dei file sono dichiarate nel file di intestazione:

```c
#include <stdio.h>
```

La libreria standard usa il tipo:

```c
FILE *
```

che rappresenta uno stream associato a un file.

Il programmatore normalmente non conosce il contenuto interno della struttura `FILE`, ma utilizza le funzioni della libreria standard.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;

    return EXIT_SUCCESS;
}
```

---

# FILE (user-space) e struct file (kernel-space)

È importante distinguere:

* `FILE *` → struttura della libreria C (user-space)
* `struct file` → struttura interna del kernel Linux (kernel-space)

```text
Applicazione C
    ↓
stdio (FILE *)
    ↓
system call
    ↓
kernel (struct file)
    ↓
filesystem/dispositivo
```

La libreria `stdio` introduce:

* buffering
* lettura/scrittura formattata
* funzioni ad alto livello

mentre il kernel espone primitive più semplici basate su file descriptor.

---

# FILE * vs file descriptor

## FILE *

Interfaccia ad alto livello della libreria standard:

```c
FILE *fp;
```

Funzioni tipiche:

```c
fopen()
fread()
fwrite()
fclose()
```

## File descriptor

Interfaccia a basso livello del kernel:

```c
int fd;
```

Funzioni POSIX:

```c
open()
read()
write()
close()
```

## Confronto

| FILE *         | File descriptor  |
| -------------- | ---------------- |
| Libreria stdio | Kernel           |
| Buffering stdio configurabile | Nessun buffer stdio; può esserci caching nel kernel |
| Alto livello   | Basso livello    |
| fopen()        | open()           |
| fread()        | read()           |
| fwrite()       | write()          |
| fclose()       | close()          |

---

# Apertura e chiusura di file

Per utilizzare un file è necessario:

1. aprirlo
2. utilizzarlo
3. chiuderlo

```c
FILE *fopen(const char *path, const char *mode);
int fclose(FILE *fp);
```

---

# fopen()

```c
FILE *fopen(const char *path, const char *mode);
```

## Modalità di apertura

| Mode | Significato                              |
| ---- | ---------------------------------------- |
| r    | sola lettura                             |
| r+   | lettura e scrittura (file deve esistere) |
| w    | scrittura, crea/tronca                   |
| w+   | lettura e scrittura, crea/tronca         |
| a    | append, crea se non esiste               |
| a+   | lettura e append, crea se non esiste     |

È possibile aggiungere `b` per indicare modalità binaria:

```text
rb
wb
ab+
```

Su Linux/Unix spesso non cambia nulla, mentre su Windows può essere importante.

## Modalità testo vs modalità binaria

Su Windows:

```text
'\n'  ↔  "\r\n"
```

In modalità testo il sistema può tradurre automaticamente i caratteri newline.

Per questo motivo:

* il numero di byte fisici può differire
* `ftell()` può non coincidere col numero reale di byte
* per file binari è corretto usare `"rb"` e `"wb"`

## Valore restituito

`fopen()` restituisce:

* puntatore valido a `FILE`
* `NULL` in caso di errore

Errori tipici:

* file inesistente
* permessi insufficienti
* percorso errato

---

# perror() ed errno

```c
#include <stdio.h>
#include <errno.h>

FILE *fp;

fp = fopen("missing.txt", "r");

if (fp == NULL) {
    perror("fopen");
}
```

Possibile output:

```text
fopen: No such file or directory
```

`perror()` stampa:

* stringa passata come parametro
* descrizione dell'errore associato a `errno`

---

# fclose()

```c
int fclose(FILE *fp);
```

Chiude il file e libera le risorse associate.

Restituisce:

* `0` → successo
* `EOF` → errore

---

# fflush()

```c
int fflush(FILE *fp);
```

Trasferisce i dati nel buffer di output della libreria all'ambiente di esecuzione, tipicamente al kernel. Non garantisce la persistenza sul dispositivo fisico.

```c
printf("Hello");
fflush(stdout);
```

`fclose()` esegue automaticamente `fflush()`.

---

# Buffering

La libreria `stdio` usa buffering per ridurre il numero di system call.

## stdout

Normalmente:

* line-buffered su terminale
* fully-buffered su file

```c
printf("Hello");
sleep(5);
```

Potrebbe non apparire nulla fino al newline:

```c
printf("Hello\n");
```

oppure:

```c
fflush(stdout);
```

## stderr

Normalmente non bufferizzato.

---

# Esempio: apertura file

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fin;
    FILE *fout;

    fin = fopen("song.mp3", "rb");

    if (fin == NULL) {
        perror("song.mp3");
        exit(EXIT_FAILURE);
    }

    fout = fopen("copy.mp3", "wb");

    if (fout == NULL) {
        perror("copy.mp3");
        exit(EXIT_FAILURE);
    }
    
    // do stuff here

    fclose(fin);
    fclose(fout);

    exit(EXIT_SUCCESS);
}
```

---

# Lettura e scrittura binaria

```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *fp);

size_t fwrite(const void *ptr,
              size_t size,
              size_t nmemb,
              FILE *fp);
```

## Parametri

* `ptr` → buffer
* `size` → dimensione singolo elemento
* `nmemb` → numero elementi
* `fp` → file

## Valore restituito

Numero di elementi effettivamente letti/scritti.

---

# Copia di un file binario

```c
#include <stdio.h>

#define BUFFER_SIZE 4096

int copy_file(FILE *src, FILE *dst) {
    unsigned char buffer[BUFFER_SIZE];

    size_t nread;
    size_t nwrite;

    do {
        nread = fread(buffer, 1, BUFFER_SIZE, src);

        if (nread > 0) {
            nwrite = fwrite(buffer, 1, nread, dst);

            if (nwrite != nread) {
                return 0;
            }
        }

    } while (nread > 0);

    return !ferror(src);
}
```

---

# Lettura e scrittura di struct

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[32];
} Student;

int main(void) {
    FILE *fp;
    Student s = {1, "Alice"};

    fp = fopen("students.bin", "wb");
    if (fp == NULL) return 1;

    size_t written = fwrite(&s, sizeof(Student), 1, fp);
    int closed = fclose(fp);
    if (written != 1 || closed == EOF) return 1;

    return 0;
}
```

Vantaggi:

* compatto
* veloce

Svantaggi:

* poca portabilità
* dipendenza da padding e endianness

---

# Lettura e scrittura di testo

```c
int fgetc(FILE *stream);
int fputc(int c, FILE *stream);

char *fgets(char *str, int n, FILE *stream);
int fputs(const char *str, FILE *stream);
```

---

# Copia di un file di testo

## Per caratteri

```c
void copy_by_char(FILE *src, FILE *dst) {
    int ch;

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }
}
```

## Per linee

```c
#include <stdio.h>

#define LINE_MAX 1024

void copy_by_line(FILE *src, FILE *dst) {
    char buffer[LINE_MAX];

    while (fgets(buffer, LINE_MAX, src) != NULL) {
        fputs(buffer, dst);
    }
}
```

---

# feof()

```c
int feof(FILE *stream);
```

Restituisce valore diverso da zero se è stato raggiunto EOF.

## Attenzione

`feof()` verifica l'indicatore di fine file, impostato quando una lettura incontra la fine del file. Non predice la lettura successiva e non distingue da solo tutti gli errori: per quelli si usa ferror().

## Pattern scorretto

```c
while (!feof(fp)) {
    ch = fgetc(fp);
}
```

## Pattern corretto

```c
while ((ch = fgetc(fp)) != EOF) {
    ...
}
```

---

# Posizione corrente nel file

Ogni stream mantiene una posizione corrente.

Un file aperto più volte può avere più offset indipendenti.

```c
int fseek(FILE *stream, long offset, int whence);

long ftell(FILE *stream);

void rewind(FILE *stream);
```

---

# fseek()

```c
fseek(fp, 0L, SEEK_SET);
```

## whence

| Costante | Significato        |
| -------- | ------------------ |
| SEEK_SET | inizio file        |
| SEEK_CUR | posizione corrente |
| SEEK_END | fine file          |

---

# ftell()

```c
long pos = ftell(fp);
```

Restituisce l'offset corrente.

---

# rewind()

```c
rewind(fp);
```

Equivalente a:

```c
fseek(fp, 0L, SEEK_SET);
```

Quanto al posizionamento; rewind azzera anche l'indicatore di errore dello stream, mentre fseek non lo fa.

---

# Esempio: dimensione file

```c
FILE *fp;

fp = fopen("/etc/passwd", "r");

fseek(fp, 0L, SEEK_END);

long size = ftell(fp);

fclose(fp);
```

---

# Esempio: lettura al contrario

Il seguente esempio legge i byte in ordine inverso, non i caratteri Unicode. Richiede un file regolare posizionabile, aperto in modalità binaria, e il controllo degli esiti di fseek e ftell in codice di produzione.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;

    long i;
    long size;

    fp = fopen("test.txt", "rb");

    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);

    size = ftell(fp);

    for (i = 1; i <= size; i++) {
        fseek(fp, -i, SEEK_END);
        putchar(fgetc(fp));
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
```

---

# Flussi standard

La libreria standard definisce:

| Stream | Significato     |
| ------ | --------------- |
| stdin  | input standard  |
| stdout | output standard |
| stderr | output errori   |

Sono aperti automaticamente dal sistema.

---

# Redirezione shell

```bash
./program < input.txt
./program > output.txt
./program >> output.txt
./program 2> errors.txt
```

---

# Lettura e scrittura formattata

```c
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);

int scanf(const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
```

---

# sprintf() e snprintf()

```c
char buffer[10];

sprintf(buffer, "Hello World!");
```

Pericoloso: possibile overflow.

Versione sicura:

```c
snprintf(buffer, sizeof(buffer),
         "Hello World!");
```

In codice moderno `snprintf()` è generalmente preferibile.

---

# scanf() vs fgets()

## scanf("%s")

```c
char str[32];

scanf("%s", str);
```

Problemi:

* interrompe sugli spazi
* possibile overflow

## fgets()

```c
char str[32];

fgets(str, sizeof(str), stdin);
```

Più sicura.

---

# Argomenti a linea di comando

```c
int main(int argc, char *argv[])
```

## Parametri

* `argc` → numero argomenti
* `argv` → array di stringhe

---

# Esempio

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;

    printf("argc=%d\n", argc);

    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}
```

Esecuzione:

```bash
./example a b c
```

Output:

```text
argc=4
argv[0] = ./example
argv[1] = a
argv[2] = b
argv[3] = c
```

---

# Esempio realistico: copia file

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *src;
    FILE *dst;

    int ch;

    if (argc != 3) {
        fprintf(stderr,
                "Usage: %s source target\n",
                argv[0]);

        exit(EXIT_FAILURE);
    }

    src = fopen(argv[1], "rb");

    if (src == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    dst = fopen(argv[2], "wb");

    if (dst == NULL) {
        perror(argv[2]);
        fclose(src);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(src)) != EOF) {
        if (fputc(ch, dst) == EOF) {
            fclose(src);
            fclose(dst);
            return EXIT_FAILURE;
        }
    }

    int failed = ferror(src);
    int src_close = fclose(src);
    int dst_close = fclose(dst);
    if (failed || src_close == EOF || dst_close == EOF) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
```

---

# Condivisione offset dopo fork()

Nei sistemi Unix:

```c
fork();
```

Padre e figlio hanno tabelle dei descrittori distinte, ma i descrittori ereditati fanno riferimento alla stessa open file description nel kernel e ne condividono l'offset. Gli eventuali buffer stdio, invece, vengono copiati nello spazio utente.

Questo comportamento è molto importante nella programmazione concorrente e nei sistemi operativi.
