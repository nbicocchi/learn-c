#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

int tee_by_byte_blocks(FILE *source, FILE *target1, FILE *target2) {
  size_t nread, nwrite1, nwrite2;
  unsigned char buffer[BUFFER_SIZE];
  do {
    nread = fread(buffer, 1, sizeof(buffer), source);
    nwrite1 = nwrite2 = 0;
    if (nread) {
      nwrite1 = fwrite(buffer, 1, nread, target1);
      nwrite2 = fwrite(buffer, 1, nread, target2);
    }
  } while ((nread > 0) && (nread == nwrite1) && (nread == nwrite2));

  if ((nread != nwrite1) || (nread != nwrite2)) return FALSE;
  return TRUE;
}

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

  tee_by_byte_blocks(stdin, stdout, dst);

  fclose(dst);
  exit(EXIT_SUCCESS);
}
