#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define LINE_MAX 8192

int main(int argc, char *argv[]) {
    FILE *file1;
    FILE *file2;
    char buffer1[LINE_MAX];
    char buffer2[LINE_MAX];
    int line = 1;
    int diff_found = FALSE;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(2);
    }

    file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        perror("fopen()");
        exit(2);
    }

    file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        perror("fopen()");
        exit(2);
    }

    while (fgets(buffer1, LINE_MAX, file1) != NULL && fgets(buffer2, LINE_MAX, file2) != NULL) {
        if (strcmp(buffer1, buffer2) != 0) {
            printf("[%d] < %s", line, buffer1);
            printf("[%d] > %s", line, buffer2);
            diff_found = TRUE;
        }
        line++;
    }

    if (feof(file1) && !feof(file2)) {
        // file1 ended before file2
        while (fgets(buffer2, LINE_MAX, file2) != NULL) {
            printf("[%d] < %s", line, buffer2);
            line++;
        }
        diff_found = TRUE;
    }

    if (!feof(file1) && feof(file2)) {
        // file2 ended before file1
        while (fgets(buffer1, LINE_MAX, file1) != NULL) {
            printf("[%d] > %s", line, buffer1);
            line++;
        }
        diff_found = TRUE;
    }

    fclose(file1);
    fclose(file2);
    exit(diff_found);
}