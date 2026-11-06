#include <stdio.h>

struct dna_data {
  int process_algorithm;
  int bases[8192];
};

void process_dna_data(struct dna_data data) {
  printf("Processing sequence...\n");
  // do stuff
}

void process_dna_data_ptr(const struct dna_data *data) {
  printf("Processing sequence...\n");
  // do stuff
}

int main() {
  struct dna_data data = {
    .process_algorithm = 0,
    .bases = { 0 }
  };


  // 8192 x 4 + 4 bytes are copied
  process_dna_data(data);

  // 8 bytes are copied
  process_dna_data_ptr(&data);
}

