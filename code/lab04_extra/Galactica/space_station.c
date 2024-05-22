#include "space_station.h"

// Space01
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

// Space02
void update_space_station(struct SpaceStation **network, int num_stations, int station_id, const char *new_name, int new_id) {
    for (int i = 0; i < num_stations; i++) {
        if (network[i]->station_id == station_id) {
            free(network[i]->name);
            network[i]->name = malloc((strlen(new_name) + 1) * sizeof(char));
            strcpy(network[i]->name, new_name);
            network[i]->station_id = new_id;
            return;
        }
    }
    printf("Station with ID %d not found.\n", station_id);
}

// Space03
void deallocate_space_station_network(struct SpaceStation **network, int num_stations) {
    for (int i = 0; i < num_stations; i++) {
        free(network[i]->name);
        free(network[i]);
    }
    free(network);
}

// Space04
int add_space_station(struct SpaceStation ***network, int *num_stations, const char *name, int station_id) {
    struct SpaceStation **new_network = realloc(*network, (*num_stations + 1) * sizeof(struct SpaceStation *));
    if (new_network == NULL) {
        return -1;
    }
    *network = new_network;
    (*network)[*num_stations] = malloc(sizeof(struct SpaceStation));
    if ((*network)[*num_stations] == NULL) {
        return -1;
    }
    (*network)[*num_stations]->name = malloc((strlen(name) + 1) * sizeof(char));
    if ((*network)[*num_stations]->name == NULL) {
        free((*network)[*num_stations]);
        return -1;
    }
    strcpy((*network)[*num_stations]->name, name);
    (*network)[*num_stations]->station_id = station_id;
    (*num_stations)++;
    return 0;
}

// Space05
struct SpaceStation *find_space_station(struct SpaceStation **network, int num_stations, int station_id) {
    for (int i = 0; i < num_stations; i++) {
        if (network[i]->station_id == station_id) {
            return network[i];
        }
    }
    return NULL;
}