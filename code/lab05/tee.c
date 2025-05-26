#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *dst;
  char buffer[8192];

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <output_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  dst = fopen(argv[1], "w");
  if (!dst) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  while (fgets(buffer, sizeof(buffer), stdin)) {
    fputs(buffer, stdout);
    fputs(buffer, dst);
  }

  fclose(dst);
  exit(EXIT_SUCCESS);
}
