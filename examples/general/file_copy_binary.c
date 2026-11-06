#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

int copy_by_byte_blocks(FILE *source, FILE *target) {
    size_t nread, nwrite;
    unsigned char buffer[BUFFER_SIZE];
    do {
        nread = fread(buffer, 1, sizeof(buffer), source);
        nwrite = 0;
        if (nread > 0) {
            nwrite = fwrite(buffer, 1, nread, target);
        }
    } while ((nread > 0) && (nread == nwrite));

    if (ferror(source) || nread != nwrite) return FALSE;
    return TRUE;
}

int main(int argc, char *argv[]) {
    FILE *source, *target;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s source target\n", argv[0]);
        return EXIT_FAILURE;
    }

    source = fopen(argv[1], "rb");
    if (!source) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    target = fopen(argv[2], "wb");
    if (!target) {
        fclose(source);
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }

    if (!copy_by_byte_blocks(source, target)) {
        fprintf(stderr, "Copy failed\n");
        fclose(source);
        fclose(target);
        exit(EXIT_FAILURE);
    }

    int read_close = fclose(source);
    int write_close = fclose(target);
    if (read_close == EOF || write_close == EOF) {
        fprintf(stderr, "Close failed\n");
        return EXIT_FAILURE;
    }
    printf("[OK] %s -> %s\n", argv[1], argv[2]);
    exit(EXIT_SUCCESS);
}
