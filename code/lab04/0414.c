#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SpaceStation {
    char *name;
    int station_id;
};

struct SpaceStation **create_space_station_network(int num_stations) {
    struct SpaceStation **network = malloc(num_stations * sizeof(struct SpaceStation *));
    if (network == NULL) {
        return NULL;
    }
    for (int i = 0; i < num_stations; i++) {
        network[i] = malloc(sizeof(struct SpaceStation));
        if (network[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(network[j]->name);
                free(network[j]);
            }
            free(network);
            return NULL;
        }
        network[i]->name = malloc(50 * sizeof(char));
        if (network[i]->name == NULL) {
            for (int j = 0; j <= i; j++) {
                free(network[j]->name);
                free(network[j]);
            }
            free(network);
            return NULL;
        }
        snprintf(network[i]->name, 50, "SpaceStation %d", i + 1);
        network[i]->station_id = i + 1;
    }
    return network;
}

void deallocate_space_station_network(struct SpaceStation **network, int num_stations) {
    for (int i = 0; i < num_stations; i++) {
        free(network[i]->name);
        free(network[i]);
    }
    free(network);
}

struct SpaceStation *find_space_station(struct SpaceStation **network, int num_stations, int station_id) {
    for (int i = 0; i < num_stations; i++) {
        if (network[i]->station_id == station_id) {
            return network[i];
        }
    }
    return NULL;
}

struct SpaceStation *update_space_station(struct SpaceStation **network, int num_stations, int station_id, const char *new_name, int new_id) {
    for (int i = 0; i < num_stations; i++) {
        if (network[i]->station_id == station_id) {
            free(network[i]->name);
            network[i]->name = malloc((strlen(new_name) + 1) * sizeof(char));
            strcpy(network[i]->name, new_name);
            network[i]->station_id = new_id;
            return network[i];
        }
    }
    return NULL;
}

void show_space_station(struct SpaceStation *station) {
    if (station == NULL) {
        printf("[Station] empty\n");
        return;
    }
    printf("[Station] id: %d, name: %s\n", station->station_id, station->name);
}

void show_space_station_network(struct SpaceStation **network, int num_stations) {
    for (int i = 0; i < num_stations; i++) {
        show_space_station(network[i]);
    }
}

#define NUM_STATIONS 5
int main(void) {
    struct SpaceStation **network;
    struct SpaceStation *station;

    network = create_space_station_network(NUM_STATIONS);
    show_space_station_network(network, NUM_STATIONS);

    station = find_space_station(network, NUM_STATIONS, 3);
    show_space_station(station);

    station = find_space_station(network, NUM_STATIONS, 17);
    show_space_station(station);

    update_space_station(network, NUM_STATIONS, 5, "Ganimede", 55);
    show_space_station_network(network, NUM_STATIONS);

    deallocate_space_station_network(network, NUM_STATIONS);
}


