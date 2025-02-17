#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 1024

void search_word(const char *filename, const char *word) {
    FILE *file;
    char buffer[LINE_MAX];
    int line_number = 0;
    int found = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\nFile: %s\n", filename);

    while (fgets(buffer, LINE_MAX, file) != NULL) {
        line_number++;
        
        // Rimuovi il carattere newline se presente
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        
        if (strstr(buffer, word) != NULL) {
            printf("- Line %d: \"%s\"\n", line_number, buffer);
            found = 1;
        }
    }

    if (!found) {
        printf("No occurrences found in: %s\n", filename);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s word file1 [file2 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *word = argv[1];
    for (int i = 2; i < argc; i++) {
        search_word(argv[i], word);
    }

    exit(EXIT_SUCCESS);
}