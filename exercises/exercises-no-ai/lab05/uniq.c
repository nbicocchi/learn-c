#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_LINES 10000

void process_input(FILE *input) {
  char line[MAX_LINE_LEN];
  char *seen[MAX_LINES];
  int seen_count = 0;

  while (fgets(line, sizeof(line), input)) {
    int already_seen = 0;

    for (int i = 0; i < seen_count; i++) {
      if (strcmp(seen[i], line) == 0) {
        already_seen = 1;
        break;
      }
    }

    if (!already_seen) {
      printf("%s", line);
      if (seen_count < MAX_LINES) {
        seen[seen_count] = strdup(line);
        if (seen[seen_count] == NULL) {
          perror("strdup");
          exit(EXIT_FAILURE);
        }
        seen_count++;
      } else {
        fprintf(stderr, "Numero massimo di righe uniche superato (%d)\n", MAX_LINES);
        exit(EXIT_FAILURE);
      }
    }
  }

  // Libera la memoria
  for (int i = 0; i < seen_count; i++) {
    free(seen[i]);
  }
}

int main(int argc, char *argv[]) {
  FILE *input = stdin;

  // Gestione parametri
  if (argc > 2) {
    fprintf(stderr, "Uso: %s [file]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (argc == 2) {
    input = fopen(argv[1], "r");
    if (!input) {
      perror("fopen");
      exit(EXIT_FAILURE);
    }
  }

  process_input(input);

  // Chiusura file se necessario
  if (input != stdin) {
    fclose(input);
  }

  exit(EXIT_SUCCESS);
}
