#include "space_station.h"

int main() {
    int num_stations = 5;
    struct SpaceStation **network = create_space_station_network(num_stations);
    if (network != NULL) {
        struct SpaceStation *station = find_space_station(network, num_stations, 3);
        if (station != NULL) {
            printf("Found Station ID: %d, Name: %s\n", station->station_id, station->name);
        } else {
            printf("Station not found.\n");
        }
        deallocate_space_station_network(network, num_stations);
    }
    return 0;
}