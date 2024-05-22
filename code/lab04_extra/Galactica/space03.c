#include "space_station.h"

int main() {
    int num_stations = 5;
    struct SpaceStation **network = create_space_station_network(num_stations);
    if (network != NULL) {
        deallocate_space_station_network(network, num_stations);
    }
    return 0;
}