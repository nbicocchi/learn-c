#include <stdio.h>
#include <stdlib.h>

#define LINE_BUFFER_SIZE 1024

void copy_by_char(FILE *source, FILE *target) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, target);
    }
}

int copy_by_line(FILE *source, FILE *target) {
    char buffer[LINE_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), source) != NULL) {
        if (fputs(buffer, target) == EOF) return 0;
    }
    return !ferror(source);
}

int main(int argc, char *argv[]) {
    FILE *source, *target;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s source target\n", argv[0]);
        return EXIT_FAILURE;
    }

    source = fopen(argv[1], "r");
    if (!source) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    target = fopen(argv[2], "w");
    if (!target) {
        fclose(source);
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }

    int copied = copy_by_line(source, target);
    int read_close = fclose(source);
    int write_close = fclose(target);
    if (!copied || read_close == EOF || write_close == EOF) {
        fprintf(stderr, "Copy failed\n");
        return EXIT_FAILURE;
    }
    printf("[OK] %s -> %s\n", argv[1], argv[2]);
    exit(EXIT_SUCCESS);
}
