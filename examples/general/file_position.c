#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(FILE *source) {
    char buffer[10];

    size_t nread = fread(buffer, 1, sizeof(buffer), source);
    fprintf(stdout, "%.*s\n", (int)nread, buffer);
    fprintf(stdout, "ftell(): %ld\n", ftell(source));
}

int main(int argc, char *argv[]) {
    FILE *source;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }
    source = fopen(argv[1], "rb");
    if (!source) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    fseek(source, 0L, SEEK_SET);
    read(source);

    fseek(source, 1L, SEEK_SET);
    read(source);

    fseek(source, 1L, SEEK_CUR);
    read(source);

    fseek(source, -20L, SEEK_END);
    read(source);

    rewind(source);
    read(source);

    fclose(source);
    exit(EXIT_SUCCESS);
}
