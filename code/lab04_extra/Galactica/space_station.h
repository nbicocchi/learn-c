#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SpaceStation {
    char *name;
    int station_id;
};

// Space01
struct SpaceStation **create_space_station_network(int num_stations);
// Space02
void update_space_station(struct SpaceStation **network, int num_stations, int station_id, const char *new_name, int new_id);
// Space03
void deallocate_space_station_network(struct SpaceStation **network, int num_stations);
// Space04
int add_space_station(struct SpaceStation ***network, int *num_stations, const char *name, int station_id);
// Space05
struct SpaceStation *find_space_station(struct SpaceStation **network, int num_stations, int station_id);