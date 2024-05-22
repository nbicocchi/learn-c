#include "space_station.h"

int main() {
    int num_stations = 5;
    struct SpaceStation **network = create_space_station_network(num_stations);
    if (network != NULL) {
        update_space_station(network, num_stations, 2, "NewName", 99);
        for (int i = 0; i < num_stations; i++) {
            printf("Station ID: %d, Name: %s\n", network[i]->station_id, network[i]->name);
            free(network[i]->name);
            free(network[i]);
        }
        free(network);
    }
    return 0;
}
