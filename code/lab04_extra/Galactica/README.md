# Missione Galactica
Benvenuti nel 3045, un'epoca in cui l'umanità ha esteso il proprio dominio nello spazio interstellare. Dopo decenni di esplorazione, scoperte e colonizzazione, le stazioni spaziali sono diventate i fulcri della nostra presenza oltre i confini terrestri.

### Il Progetto Galactica
Il Progetto Galactica è una collaborazione globale che mira a creare una rete interconnessa di stazioni spaziali per agevolare lo scambio di risorse, informazioni e conoscenze tra le colonie umane sparse per l'universo. Queste stazioni spaziali fungono da centri di ricerca, punti di transito e rifugi per gli esploratori spaziali.

### La sfida
Tuttavia, mantenere e gestire una rete così vasta e complessa non è un compito facile. È necessario un sistema efficiente per creare, aggiornare, gestire e monitorare le stazioni spaziali in tutto l'universo.

### Il tuo compito
Sei stato reclutato nel team di ingegneri spaziali del Progetto Galactica per sviluppare un sistema informatico che consenta di gestire le stazioni spaziali in modo efficiente. Il tuo compito è scrivere il codice necessario per creare, aggiornare, gestire e cercare stazioni spaziali nella rete Galactica.

### Indicazioni operative
- Per la risoluzione dei prossimi esercizi si consiglia di creare un file header `space_station.h` che contenga la definizione delle struct e delle funzioni necessarie.  
- L'implementazione delle funzioni si consiglia di realizzarla in un file `space_station.c` che sarà aggiornato di volta in volta ed incluso nella compilazione dei vari sorgenti.  
- Esempio di compilazione `gcc space01.c space_station.c -o space01`

---

**Esercizio Space01**. Scrivere una funzione che allochi dinamicamente una rete di stazioni spaziali, dove ogni stazione spaziale ha un nome e un numero di stazione. La funzione deve restituire un puntatore a un array di puntatori a struct `SpaceStation`. Se l'allocazione fallisce, la funzione deve restituire `NULL`.

La funzione deve rispettare il seguente prototipo:

```c
struct SpaceStation **create_space_station_network(int num_stations);
```

dove:

* **num_stations** è il numero di stazioni da creare;
* la funzione ritorna il puntatore a un array di puntatori a struct `SpaceStation`. Il puntatore vale NULL in caso di errori.

---

**Esercizio Space02**. Scrivere una funzione che aggiorni i dettagli (nome e ID) di una specifica stazione spaziale in una rete di stazioni spaziali. 

La funzione deve rispettare il seguente prototipo:

```c
void update_space_station(struct SpaceStation **network, int num_stations, int station_id, const char *new_name, int new_id);
```

dove:

* **network** è il puntatore alla rete;
* **num_stations** è il numero totale di stazioni;
* **station_id** è l'ID della stazione da aggiornare;
* **new_name** è il nuovo nome della stazione;
* **new_id** è il nuovo ID della stazione.

---

**Esercizio Space03**. Scrivere una funzione che deallochi una rete di stazioni spaziali precedentemente allocata con `create_space_station_network`. La funzione riceve come parametri il puntatore alla rete e il numero totale di stazioni.

La funzione deve rispettare il seguente prototipo:

```c
void deallocate_space_station_network(struct SpaceStation **network, int num_stations);
```

dove:

* **network** è il puntatore alla rete;
* **num_stations** è il numero totale di stazioni;

---

**Esercizio Space04**. Scrivere una funzione che aggiunga una nuova stazione spaziale alla rete. La funzione riceve come parametri un puntatore al puntatore alla rete, il numero attuale di stazioni e i dettagli della nuova stazione (nome e ID). La funzione deve aggiornare il puntatore alla rete per riflettere la nuova dimensione.

La funzione deve rispettare il seguente prototipo:

```c
int add_space_station(struct SpaceStation ***network, int *num_stations, const char *name, int station_id);
```

dove:

* **network** è il puntatore alla rete;
* **num_stations** è il numero totale di stazioni;
* **name** è il nome della stazione;
* **station_id** è l'ID della stazione;
* restituisce 0 se la stazione è stata aggiunta correttamente, -1 altrimenti.

---

**Esercizio Space05**. Scrivere una funzione che cerchi una stazione spaziale nella rete dato il suo ID. La funzione deve restituire un puntatore alla stazione spaziale se trovata, altrimenti deve restituire NULL.


La funzione deve rispettare il seguente prototipo:

```c
struct SpaceStation *find_space_station(struct SpaceStation **network, int num_stations, int station_id);
```

dove:

* **network** è il puntatore alla rete;
* **num_stations** è il numero totale di stazioni;
* **station_id** è l'ID della stazione da cercare.
