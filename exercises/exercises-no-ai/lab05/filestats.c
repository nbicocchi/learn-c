#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

void count_stats(FILE *file, int *lines, int *words, int *chars) {
    char buffer[BUFFER_SIZE];
    int in_word = 0;

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        (*lines)++;

        for (int i = 0; buffer[i] != '\0'; i++) {
            (*chars)++;

            if (isspace(buffer[i])) {
                in_word = FALSE;
            } else if (!in_word) {
                in_word = TRUE;
                (*words)++;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int lines = 0, words = 0, chars = 0;
    count_stats(file, &lines, &words, &chars);
    fclose(file);

    printf("File: %s\n", argv[1]);
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);

    exit(EXIT_SUCCESS);
}