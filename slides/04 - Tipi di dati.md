# Tipi di dati
In un linguaggio di programmazione un tipo di dato identifica l'insieme dei valori che possono essere assunti da una variabile e le operazioni che si possono svolgere su di essi. Sfruttando la *tipizzazione*, il compilatore può: *(a)* effettuare controlli sul tipo, e *(b)* gestire allocazione della memoria necessaria (diversa per ogni tipo)

Per gestire correttamente un qualunque dato in memoria sono necessarie due informazioni:
* l'indirizzo in cui il dato è memorizzato
* il tipo di dato rappresentato 

Il tipo di dato specifica:
* la modalità di rappresentazione della variabile in memoria
* la quantità di memoria occupata da quella variabile

![Variabili memoria](./images/variabile_memoria.avif)


## Dichiarazione di variabili

Con *dichiarazione di variabile* si intende il modo con cui in un file che segue la sintassi del linguaggio C viene richiesto di riservare memoria per contenere un certo dato e gli viene assegnato un nome simbolico (i.e., identificatore)

Nel linguaggio C è obbligatorio dichiarare l’utilizzo di una variabile, ovvero dichiarare il *nome* e il *tipo* della variabile.

```c++
<tipo variabile> <nome variabile> ;
```

Ad esempio:

```c++
// numeri interi
char c;
short s;
int i;
long l; 
long long ll;

// numeri interi senza segno
unsigned char c;
unsigned short s;
unsigned int i;
unsigned long l; 
unsigned long long ll;

// numeri in virgola mobile
float f;
double d;
```

## Definizione di variabili
Dopo la dichiarazione le variabili non hanno un valore predefinito. E' necessario eseguire un'operazione di *assegnamento* per definirne un valore. In questo modo la memoria allocata per la variabile viene anche riempita con un valore specifico.

Negli esempi sotto vengono utilizzate solo espressioni composte da *letterali numeriche* per definire i valori delle variabili:

```c++
// numeri interi
char c = 64;
short s = (short)1024;
int i = 1024;
long l = 1024L;
long long ll = 1024LL;

// numeri in virgola mobile
float f = 3.1415F;
double d = 3.1415;
```

## Letterali numeriche
Le sequenze che iniziano con un numero (non possono essere identificatori!) sono chiamate letterali numeriche. *Da non confondere con le variabili dichiarate costanti (const)*. Possono essere:
  * decimali: cominciano con una cifra da 1 a 9 e proseguono con altre cifre da 0 a 9
  * ottali: cominciano con 0 e proseguono con altre cifre da 0 a 7
  * esadecimali: cominciano con *0x* o *0X* e proseguono con altre cifre da 0 a 9 o con lettere (maiuscole o minuscole) da *A* a *F*

```c++
int n1 = 127  // 1 * 10^2 + 2 * 10^1 + 7 * 10^0
int n2 = 0177 // 1 * 8^2  + 7 * 8^1  + 7 * 8^0 
int n3 = 0x7f // 7 * 16^1 + 15 * 16^0
```

Ogni letterale può essere inoltre seguita un postfisso (L=long, U=unsigned, F=float)

![Letterali Numerici](./images/literals_interi.avif)


## Variabili costanti (di sola lettura)
È possibile specificare che la variabile in memoria potrà essere solo letta, ovvero che è una variabile read-only, tramite la parola riservata *const*. Questa variabile è identica alle altre (ha una locazione di memoria e un tipo), se non per il fatto che nessun comando successivo potrà modificarne il valore.

*Attenzione!* Nel caso di variabili *const* dobbiamo definirne il valore nel momento della dichiarazione

```c++
const <tipo> <nome-varibile> = <espressione> ;
const double pi_greco = 3.1415926535897932384;
```

Ad esempio:

```c++
/* compila */
int main() {
    const int a=2, b=3;
    printf("a=%d, b=%d\n", a, b);
    return 0;
}
```

```c++
/* non compila */
int main(){
    const int a=2, b=3;
    a = 3; // errore! Stiamo modificando una costante!
    b = 2; // errore! Stiamo modificando una costante!
    printf("a=%d, b=%d\n", a, b);
    return 0;
}
```

## I tipi di dati interi
Esistono due tipi di numeri interi (a prescindere dalla dimensione)
* **signed**: con segno (il termine signed è implicito nei tipi)  
  * intervallo = [-2^(bit-1) : +2^(bit-1)-1] 
* **unsigned**: senza segno, ovvero solo numeri positivi 
  * intervallo = [0 : +2^(bit)-1]            
  
| **Nome**  | **Dimensione Tipica** | **Descrizione** |
| --------- | --------------------- | --------------- |
| [unsigned] char      | 1 byte | numero intero 8bit  |
| [unsigned] short     | 2 byte | numero intero 16bit |
| [unsigned] int       | 4 byte | numero intero 32bit |
| [unsigned] long      | 8 byte | numero intero 64bit |
| [unsigned] long long | 8 byte | numero intero 64bit |


I numeri positivi sono rappresentati alla stesso modo sia nei tipi signed che unsigned. I numeri negativi utilizzano la notazione in complemento a 2 (-N viene rappresentato come 2^bit – N)

![Complemento a 2](./images/rappresentazione_int.avif)

I limiti degli intervalli delle variabili intere sono disponibili nella forma di macro (*limits.h*)

  * CHAR_MIN, CHAR_MAX
  * SHRT_MIN, SHRT_MAX
  * INT_MIN, INT_MAX
  * LONG_MIN, LONG_MAX
  * LLONG_MIN, LLONG_MAX

```c++
/* Minimum and maximum values a `signed short int' can hold.  */
#  define SHRT_MIN        (-32768)
#  define SHRT_MAX        32767
/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */
#  define USHRT_MAX        65535
/* Minimum and maximum values a `signed int' can hold.  */
#  define INT_MIN        (-INT_MAX - 1)
#  define INT_MAX        2147483647
/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */
#  define UINT_MAX        4294967295U
/* Minimum and maximum values a `signed long int' can hold.  */
#  if __WORDSIZE == 64
#   define LONG_MAX        9223372036854775807L
#  else
#   define LONG_MAX        2147483647L
#  endif
#  define LONG_MIN        (-LONG_MAX - 1L)
```
  
In alcuni contesti si può preferire utilizzare tipi non nativi (i.e., definiti nell'ambito di una libreria), ma che ci danno indicazioni precise sulle dimensioni a prescindere dall’architettura impiegata. L'utilizzo di questi tipi standard richiede dipendenze aggiuntive come ad esempio *stdint.h* della [GNU C Library](https://www.gnu.org/softwae/libc/manual/html_node/Integers.html)
  * **signed**: int8_t, int16_t, int32_t, int64_t
  * **unsigned**: uint8_t, uint16_t, uint32_t, uint64_t


## I tipi di dati in virgola mobile (IEEE 754)
I tipi *float* e *double* sono i cosiddetti numeri in virgola mobile che rappresentano l’insieme dei numeri reali: con essi possiamo rappresentare numeri molto piccoli o numeri molto grandi, positivi e negativi, con e senza decimali La differenza tra i due sta nel numero di bit riservati alla rappresentazione dei numeri, che si riflette sul range di numeri rappresentabili e sul numero di cifre dopo la virgola.


| **Nome** | **Dimensione Tipica** | **Descrizione** |
| -------- | -------------- | --------------- |
| float | 4 byte | numero in virgola mobile 32 bit |
| double | 8 byte | numero in virgola mobile 64 bit |
| long double | 16 byte | numero in virgola mobile 128 bit |

Lo standard **IEEE 754** è il formato più utilizzato per la rappresentazione dei numeri in virgola mobile nei computer. Esso definisce vari formati, tra cui il **formato a 32 bit (single precision)** e il **formato a 64 bit (double precision)**. Un numero in virgola mobile secondo IEEE 754 è rappresentato dalla seguente formula:

$$V = (-1)^S \times (1 + M) \times 2^{E}$$

Dove:
- **S** è il bit di **segno** (0 per positivo, 1 per negativo).
- **M** è la **mantissa** (o significando), che rappresenta la parte frazionaria del numero.
- **E** è l'**esponente**, che determina la scala del numero attraverso la base 2.

Lo standard prevede alcuni casi particolari:
- **Zero**: tutti i bit dell'esponente e della mantissa sono 0.
- **Numeri denormalizzati**: esponente a 0, ma la mantissa non è 0.
- **Infinito**: esponente tutto a 1 e mantissa a 0.
- **NaN (Not a Number)**: esponente tutto a 1 e mantissa diversa da 0.

![double](./images/rappresentazione_double_float.avif)


Per esempi concreti, vedi: https://www.h-schmidt.net/FloatConverter/IEEE754.html

| **Numero**    | **Esponente** | **Mantissa**       | **Errore**          |
|---------------|---------------|--------------------|---------------------|
| 1.0           | 0             | 1.0                | 0.0                 |
| 3.14159265359 | 1             | 1.5707963705062866 | 8.74225732421875E-8 |
| 4.0           | 2             | 1.0                | 0.0                 |
| 57.347        | 5             | 1.7920937538146973 | 1.220703125E-7      |
| 1000000       | 19            | 1.9073486328125    | 0.0                 |
| 1000000.1     | 19            | 1.907348871231079  | 0.025               |
| 123456789     | 26            | 1.8396495580673218 | 3.0                 |

I limiti degli intervalli delle variabili intere sono disponibili nella forma di macro (*float.h*)
  * FLT_MIN, FLT_MAX 
  * DBL_MIN, DBL_MAX
  * LDBL_MIN, LDBL_MAX
  
In ambito virgola mobile, non esistono tipi dalle dimensioni standard come nel caso dei numeri interi (e.g., int8_t, int16_t, int64_t)
  
## Operatore sizeof
L'operatore *sizeof* si applica ad un tipo, ad un nome di variabile o ad un'espressione. Restituisce la dimensione in byte dell'oggetto indicato. Il calcolo viene effettuato durante la fase di compilazione in base al tipo di dato che viene passato.

*sizeof* ritorna una variabile di tipo *unsigned long*

```c++
printf("char=%lu\n", sizeof(char));
printf("short=%lu\n", sizeof(short));
printf("int=%lu\n", sizeof(int));
printf("long=%lu\n", sizeof(long));
printf("longlong=%lu\n", sizeof(long long));
printf("float=%lu\n", sizeof(float));
printf("double=%lu\n", sizeof(double));
```

## Casting implicito

In C, il casting implicito (o type promotion) si verifica automaticamente quando un valore di un tipo di dati viene convertito in un altro tipo più "capiente" senza necessità di un cast esplicito da parte del programmatore. 

```c++
int main(void) {
    int  i = 17;

    /* ascii value is 99 */
    char c = 'c';

    float f = 3.14F;

    i = f + c;
    f = (i + c);

    printf("i=%d\n", i); /* i=102 */
    printf("f=%f\n", f); /* f=201.000000 */
}
```

```
Warning: Implicit conversion turns floating-point number into integer: 'float' to 'int'
Warning: Implicit conversion from 'int' to 'float' may lose precision
```

## Casting esplicito

Il casting esplicito in C consente di convertire manualmente un valore da un tipo di dato a un altro, utilizzando la sintassi (<tipo>) <espressione>. Questo avviene per evitare la perdita di precisione o overflow e garantire la correttezza delle operazioni aritmetiche.

```c++
int main(void) {
    int  i = 17;

    /* ascii value is 99 */
    char c = 'c';

    float f = 3.14F;

    i = (int)f + c;
    f = (float)(i + c);

    printf("i=%d\n", i); /* i=102 */
    printf("f=%f\n", f); /* f=201.000000 */
}
```

```c++
int main(void) {
    unsigned int u = UINT_MAX;
    float f = (float)u;
    double d = (double)u;

    printf("u=%u\n", u);  /* u=4294967295 */
    printf("f=%f\n", f);  /* f=4294967296.000000 */
    printf("d=%lf\n", d); /* d=4294967295.000000 */

    d = DBL_MAX;
    u = (unsigned int)d;
    printf("u=%u\n", u);  /* u=0 */
    printf("d=%lf\n", d); /* d=179769313486231570814527... */
}
```

## Puntatori
Un puntatore è una variabile che contiene un indirizzo di memoria. Dal momento che gli indirizzi di memoria sono interi positivi, in pratica un puntatore è un numero intero senza segno.

Come tutte le variabili, i puntatori sono caratterizzati da un proprio indirizzo e da una dimensione. I puntatori sulla stessa macchina sono tutti della stessa dimensione. 16, 32 o 64 bit a seconda del processore (o sistema operativo) su cui si lavora.

Un puntatore non contiene il valore di una variabile tradizionale, ma l'indirizzo di una locazione di memoria in cui sono immagazzinati un numero congruo di bit per essere interpretati come il tipo indicato. 
* L'operatore *&* (si legge *l'indirizzo di*) e consente di conoscere l'indirizzo di una variabile
* L'operatore * (si legge *il valore di*) permette di accedere e/o modificare il valore contenuto all'indirizzo di memoria specificato da un puntatore

```c++
int *p;
int num = 42;

/* p memorizza indirizzo di num */
p = &num
        
/* p viene utilizzato per modificare il valore di num */
*p = 3
```

![Puntatore](./images/puntatore.avif)

Un assegnamento come il seguente:

```c++
int num2 = *p;
```

Accede in lettura al valore memorizzato all'indirizzo puntato da *p* e lo assegna alla variabile *num2*. In pratica, dopo l'assegnamento effettuato precedentemente, alla variabile *num2* viene assegnato il valore 3.

Come ogni altra variabile, anche un puntatore, finché non viene inizializzato, contiene una sequenza di bit casuali che
difficilmente corrisponde a un indirizzo di memoria valido. *Tale situazione può essere causa di errori difficilmente identificabili*.

```c++
int main(){
    int *p;

    printf("%d\n", *p);
    
    /* male! scrive in un'area imprecisata della memoria del processo */ 
    *p = 5; 
    
    printf("%d\n", *p);
}
```

## Puntatore nullo
Il *puntatore nullo* vale zero e non è un puntatore valido; nelle funzioni che ritornano un puntatore è spesso ritornato come segnalazione di errore.
La macro *NULL* vale 0, e 0 è confrontabile con un puntatore.

```c++
char *p;
if (p != NULL) {
  /* istruzioni */
}
```

```c++
char *p;
if (p) {
  /* istruzioni */
}
```

## Array
Gli array permettono di memorizzare *in aree contigue di memoria* un numero fissato di elementi di tipo omogeneo.

E' possibile identificare univocamente tutti gli oggetti dell’array in modo sistematico tramite l’uso di indici numerici che, in un array di lunghezza N, vanno da 0 ad N-1.

A seconda del numero di dimensioni *(d)* dell'array, essi vengono chiamati vettori *(d=1)*, matrici *(d=2)*, o array multidimensionali *(d>2)*.

## Dichiarazione di un array

La sintassi per la dichiarazione di un array monodimensionale è la seguente:

```c++
nome-tipo identificatore [ cardinalità ] ;
```

* *nome-tipo* è un tipo di dato, sia semplice che derivato
* *identificatore* è il nome che identifica l'array
* *cardinalità* è una costante intera che indica da quanti elementi è costituito

Ad esempio:

```c++
double numbers[50];
unsigned long primes[1000];
```

## Definizione di un array
L'inizializzazione di un array può essere effettuata senza specificarne la dimensione, ma semplicemente elencandone gli elementi. Non viene specificata la cardinalità dell'array, ma si racchiude tra parentesi graffe una lista di elementi separati da virgola. Il compilatore dimensiona l'array sulla base del numero di valori utilizzati per l'inizializzazione.

```c++
int dxm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```

È possibile dichiarare un array di una determinata dimensione e inizializzarne esplicitamente solo i primi elementi, mentre i rimanenti elementi verranno inizializzati a 0
```c++
int n[10] = {1, 5, 3};
```

Un modo semplice per inizializzare a 0 tutti gli elementi di un array è:

```c++
int n[10] = {};
```


## Array in memoria
Il nome di un array è un *puntatore costante (non può essere modificato!)* il cui valore corrisponde all'indirizzo del primo elemento del'array

```c++
num == &num[0]
```

```c++
*num == num[0]
```

```c++
int main() {
    int n[16] = {};

    printf("%p\n", n);
    printf("%p\n", &n[0]);
    
    printf("%d\n", *n);
    printf("%d\n", n[0]);
}
```

In virtù del fatto che gli elementi di un array vengono sempre memorizzati in  aree contigue di memoria, l'indirizzo dell'elemento di indice *i* può essere ricavato con:

```c++  
addr = base + i * dim
```

Dove:
* *base* è l'indirizzo del primo elemento
* *dim* la dimensione di ciascun elemento

![Array](./images/puntatore_vettore.avif)
  


Nel caso si tenti di accedere ad un elemento di un array utilizzando un indice con valore al di fuori dell'intervallo
  ammesso, nel migliore dei casi il programma termina con un errore di *segmentation fault* (violazione di memoria),
  ovvero di accesso ad una area di memoria alla quale non è permesso accedere.

In altri casi l'accesso errato va a leggere/scrivere una porzione di memoria che appartiene al programma corrente,
  allocata nella memoria presente oltre la dimensione dell'array. Questa situazione è molto pericolosa per il funzionamento del programma, in quanto possono verificarsi comportamenti indesiderati, imprevedibili, e spesso difficili da diagnosticare.


## Uso di macro con array e cicli
In ogni punto del programma viene usata la macro MAX per fare riferimento alla dimensione dell'array. Il valore della macro MAX è definito in un unico punto e quindi esiste un unico punto di aggiornamento. Dopo la ricompilazione, il valore corretto viene utilizzato sia per dimensionare l'array e che per controllare il ciclo.

```c++
#define MAX 10
int vet[MAX];
for (i = 0; i < MAX; i++) {
    /* ... */
}
```

Una macro utile per essere utilizzata con gli array e che restituisce il numero di elementi:

```c++
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))
```
Ad esempio:

```c++
int v[10];
int dim = ARRAY_SIZE(v);
```

A *dim* viene  assegnato il valore 10. Si noti che il risultato non dipende dal tipo di dato.

## Array e puntatori
Nella maggior parte dei casi, puntatori ed array possono essere utilizzati in modo intercambiabile. Esistono però alcune eccezioni:

Operatore *sizeof*
  * *sizeof(array)* ritorna la quantità di memoria usata dall'array nel suo complesso
  * *sizeof(puntatore)* ritorna la quantità di memoria usata dal puntatore stesso (8 byte)

Operatore *&*
  * *&array* è un alias di &array[0] e ritorna l'indirizzo del primo elemento dell'array
  * *&pointer* ritorna l'indirizzo del puntatore stesso

```c++
void stampa_array(const int *v, unsigned size) {
    unsigned i;

    for (i = 0; i < size; i++) {
        printf("%d\n", v[i]);
    }
}

int main(void) {
    int v[16];
    int *v2 = v;

    printf("%ld\n", sizeof(v));     /* 64 */
    printf("%ld\n", sizeof(v2));    /* 8 */
    
    printf("%p\n", v);              /* 0x7ffee0d7c8a0 */
    printf("%p\n", &v);             /* 0x7ffee0d7c8a0 */
    printf("%p\n", &v[0]);          /* 0x7ffee0d7c8a0 */
    
    printf("%p\n", &v2);            /* 0x7ffee0d7c898 */
}
```

## Array di caratteri
I vettori di caratteri non differiscono dagli altri vettori. 

Esempi di dichiarazione:
* *vet* è un vettore di 4 caratteri non inizializzato
* *vet1* è un vettore di 4 caratteri inizializzato
* *vet2* è un vettore di 4 caratteri inizializzato (il primo è 'a', poi riempito di zeri)
* *vet3* è un vettore di 2 caratteri inizializzato (il primo è il valore numerico del carattere 0, il secondo è il valore numerico 0)

```c++
char vet[4];
char vet1[] = { 'a', 'b', 'c', '\n' };
char vet2[4] = { 'a' };
char vet3[] = { '0', 0 };
```

![](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/ASCII-Table-wide.svg/1600px-ASCII-Table-wide.svg.png?20221024154539)

Il seguente programma riproduce la tabella ASCII:

```c++
int main(void) {
  for (unsigned char c = 0; c < 128; c++) {
    printf("[%d] [%x] %c\n", c, c, c);
  }
}
```

## Le stringhe
Una stringa è rappresentata da una sequenza di 0 o più caratteri racchiusi fra doppi apici, per esempio:

```c++
char str[] = "Hello World!\n";
```

La memorizzazione di una stringa comprende i caratteri che effettivamente la compongono, più un carattere di terminazione che delimita l'ultimo carattere della stringa (delimitatore). Il carattere di terminazione è il byte di valore numerico 0 (zero). Esso non corrisponde ad un carattere ASCII stampabile.

La dimensione di una variabile stringa deve prevedere lo spazio sufficiente per includere anche il carattere zero di terminazione, oltre ai caratteri "effettivi" che compongono la stringa. La stringa vuota è rappresentata da "" (due doppi apici consecutivi), occupa 1 byte, che memorizza il carattere di terminazione.

```c++
#include <stdio.h>

int main() {
    char str1[] = "str1";
    char str2[128] = "str2";
    char str3[4] = "str3";

    // output: 5 128 4
    printf("%d %d %d\n", sizeof(str1), sizeof(str2), sizeof(str3));
    
    // output: str1 str2 str3randomstuff
    printf("%s %s %s\n", str1, str2, str3);

    /* replaces char '3' with standard termination (0) */
    str3[3] = 0;

    // output: str1 str2 str
    printf("%s %s %s\n", str1, str2, str3);
}
```

```c++
char c = 'a';  // carattere
char *s = "a"; // puntatore alla stringa costante "a"
char v[] = "a"; // array di 2 caratteri inizializzato a {'a', '\0'}

// Output: 1 8 2
printf("%d %d %d\n", sizeof(c), sizeof(s), sizeof(v));
```

Caratteri e stringhe sono diversi e non vanno confusi:
* un carattere è in realtà un numero intero (usato per rappresentare un carattere secondo il codice ASCII)
* una stringa è un array di caratteri che termina con un byte aggiuntivo di valore 0 (da non confondere con lo '0' carattere che ha invece valore 48). Detto in altro modo: una variabile di tipo stringa è un puntatore al primo carattere di un array di caratteri

```c++
// stampa carattere per carattere la stringa "Hello world"
// mostrando sia la rapppresentazione del carattere che il valore numerico
int main(void) {
  char str[] = "Hello World";
  for (int i = 0; i < strlen(str) + 1; i++) {
    printf("%c %d\n", str[i], str[i]);
  }
}
```

### printf()
In un programma C, *printf()* è una delle funzioni centrali per gestire l'output su console. *printf()* accetta una stringa che specifica il formato delle variabili e le variabili stesse (il numero degli specificatori deve corrispondere al numero delle variabili).

*printf()* con tipi interi con segno:

```c++
int main() {
    /* interi con segno */
    char c = 'a';
    int d = 1;
    long ld = 1;
    long long lld = 1;
    
    printf("%c\n", c);
    printf("%d\n", d);
    printf("%ld\n", ld);
    printf("%lld\n", lld);
}
```

*printf()* con tipi interi senza segno:

```c++
int main() {
    /* interi senza segno */
    unsigned char cu = 'a';
    unsigned int u = 1;
    unsigned long lu = 1;
    unsigned long long llu = 1;
    
    printf("%cu\n", cu);
    printf("%u\n", u);
    printf("%lu\n", lu);
    printf("%llu\n", llu);
}
```

*printf()* con tipi in virgola mobile:

```c++
int main() {
    /* virgola mobile */
    float f = 1.0;
    double lf = 1.0;
    long double llf = 1.0;
    
    printf("%f\n", f);
    printf("%lf\n", lf);
    printf("%Lf\n", llf);
}
```

### scanf()
In un programma C, *scanf()* è una delle funzioni centrali per gestire l'input da console. *scanf()* legge input formattato da tastiera.

```c++
#include <stdio.h>
int main() {
    char c;
    int d;
    float f;
    double lf;
    
    /* ogni variabile richiede uno specificatore di tipo */
    scanf("%c", &c);
    scanf("%d", &d);
    scanf("%f", &f);
    scanf("%lf", &lf);
}
```

## Array di puntatori (a carattere)
Gli elementi di un array possono essere di qualunque tipo, ad esempio char *\*settimana[]* è un array che memorizza 7 puntatori a carattere. Si tratta di un tipo in genere utilizzato per gestire gruppi di stringhe di caratteri.

```c
char *settimana[] = {
    "lunedì", 
    "martedì", 
    "mercoledì",
    "giovedì", 
    "venerdì",
    "sabato", 
    "domenica" 
};

printf("%s\n", settimana[0]); /* Output: lunedi */
```

![Puntatore a puntatore a carattere](./images/puntatore_puntatore_char.avif)

Nell'esempio seguente un array di puntatori a carattere è utilizzato per costruire un indice per un gruppo di strighe memorizzate di un array di caratteri separato.

```c++
#include <stdio.h>
#include <string.h>

int main() {
  int n;
  printf("How many strings ? ");
  scanf("%d", &n);

  char *strings[n];
  char content[n][128];

  // fill char array with actual strings
  for (int i = 0; i < n; i++) {
    printf("Enter string %d: ", i + 1);
    scanf("%s", content[i]);
  }

  // build index with pointers
  for (int i = 0; i < n; i++) {
    strings[i] = content[i];
  }

  // print content
  for (int i = 0; i < n; i++) {
    printf("%s\n", content[i]);
  }

  // print content using the index
  for (int i = 0; i < n; i++) {
    printf("%s\n", strings[i]);
  }
}
```

## Funzioni di libreria

La [libreria standard del C](https://www.gnu.org/software/libc/) contiene un'ampia varietà di funzioni per manipolare tutti gli aspetti di un sistema operativo.

### Caratteri

```c++
#include <stdio.h>
#include <ctype.h>

int toupper(int ch);
int tolower(int ch);
int isupper(int ch);
int islower(int ch);
int isalpha(int ch);
int isdigit(int ch);
int isspace(int ch);
```

**toupper (Converte un carattere in maiuscolo, se possibile)**
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'a';
    char upper = toupper(ch);
    printf("toupper: %c -> %c\n", ch, upper);
    return 0;
}
```

**tolower (Converte un carattere in minuscolo, se possibile)**
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'A';
    char lower = tolower(ch);
    printf("tolower: %c -> %c\n", ch, lower);
    return 0;
}
```

**isupper (Verifica se un carattere è una lettera maiuscola)**
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'G';
    if (isupper(ch)) {
        printf("isupper: %c è una lettera maiuscola\n", ch);
    } else {
        printf("isupper: %c non è una lettera maiuscola\n", ch);
    }
    return 0;
}
```

**islower (Verifica se un carattere è una lettera minuscola)**
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'g';
    if (islower(ch)) {
        printf("islower: %c è una lettera minuscola\n", ch);
    } else {
        printf("islower: %c non è una lettera minuscola\n", ch);
    }
    return 0;
}
```

**isalpha (Verifica se un carattere è una lettera dell'alfabeto)**
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'X';
    if (isalpha(ch)) {
        printf("isalpha: %c è una lettera dell'alfabeto\n", ch);
    } else {
        printf("isalpha: %c non è una lettera dell'alfabeto\n", ch);
    }
    return 0;
}
```

**isdigit (Verifica se un carattere è una cifra numerica)**
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = '5';
    if (isdigit(ch)) {
        printf("isdigit: %c è una cifra numerica\n", ch);
    } else {
        printf("isdigit: %c non è una cifra numerica\n", ch);
    }
    return 0;
}
```

**isspace (Verifica se un carattere è uno spazio o un carattere di spaziatura)**
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = ' ';
    if (isspace(ch)) {
        printf("isspace: Il carattere è uno spazio o un carattere di spaziatura\n");
    } else {
        printf("isspace: Il carattere non è uno spazio o un carattere di spaziatura\n");
    }
    return 0;
}
```

### Stringhe

```c++
#include <stdlib.h>
#include <string.h>

int atoi(const char *str);
long atol(const char *str);
double atof(const char *str);

int strcmp(const char *s1, const char *s2);
int strcasecmp(const char *s1, const char *s2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
char *strdup(const char *s1);
size_t strlen(const char *str);
```
**atoi (Converte una stringa in un intero)**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "123";
    int num = atoi(str);
    printf("atoi: %d\n", num);
    return 0;
}
```

**atol (Converte una stringa in un long)**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "123456789";
    long num = atol(str);
    printf("atol: %ld\n", num);
    return 0;
}
```

**atof (Converte una stringa in un double)**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "3.14159";
    double num = atof(str);
    printf("atof: %f\n", num);
    return 0;
}
```

**strcmp (Confronta due stringhe, case-sensitive)**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "apple";
    char str2[] = "banana";
    int result = strcmp(str1, str2);
    printf("strcmp: %d\n", result);
    return 0;
}
```

**strcasecmp (Confronta due stringhe, case-insensitive)**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "hello";
    int result = strcasecmp(str1, str2);
    printf("strcasecmp: %d\n", result);
    return 0;
}
```

**strcpy (Copia una stringa in un'altra)**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, world!";
    char dest[50];  
    strcpy(dest, src);
    printf("strcpy: %s\n", dest);
    return 0;
}
```

**strcat (Concatena due stringhe)**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello, ";
    char str2[] = "world!";
    strcat(str1, str2);
    printf("strcat: %s\n", str1);
    return 0;
}
```

**strdup (Duplica una stringa, allocando memoria dinamicamente)**
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[] = "Memory duplication";
    char *copy = strdup(str);
    printf("strdup: %s\n", copy);
    free(copy);  // Importante liberare la memoria allocata
    return 0;
}
```

**strlen (Restituisce la lunghezza di una stringa)**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Measure this!";
    size_t length = strlen(str);
    printf("strlen: %zu\n", length);
    return 0;
}
```

### Matematica

```c++
#include <math.h>

/* funzioni trigonometriche */
double sin(double x)
double cos(double x)
double tan(double x)

/* funzioni esponenziali */
double log(double x)
double sqrt(double x)
double pow(double base, double power)

/* funzioni arrotondamento */
double trunc(double x)
double ceil(double x)
double floor(double x)
double round(double x)
```

### Numeri casuali
* *srand()* inizializza il seme (seed) per la generazione
* *rand()* ritorna un numero intero pseudo casuale compreso fra 0 e RAND_MAX

```c++
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   int i;
   
   srand((unsigned) time(NULL));
   for(i = 0; i < 5; i++) {
      printf("%d\n", rand() % 50);              /* int numbers [0, 49] */
      printf("%lf\n", rand()/(double)RAND_MAX); /* double numbers [0, 1]
   }
}
```