#include "space_station.h"

int main() {
    int num_stations = 5;
    struct SpaceStation **network = create_space_station_network(num_stations);
    if (network != NULL) {
        if (add_space_station(&network, &num_stations, "NewStation", 99) == 0) {
            for (int i = 0; i < num_stations; i++) {
                printf("Station ID: %d, Name: %s\n", network[i]->station_id, network[i]->name);
            }
        }
        deallocate_space_station_network(network, num_stations);
    }
    return 0;
}