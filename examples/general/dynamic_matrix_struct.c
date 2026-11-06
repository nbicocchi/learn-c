#include <stdio.h>
#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    double **data;
};

struct matrix *allocate_matrix(size_t rows, size_t cols) {
    struct matrix *m;
    size_t i;

    m = malloc(sizeof(*m));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc((unsigned long) (rows) * sizeof(*(m->data)));
    if (m == NULL) return NULL;

    for (i = 0; i < rows; i++) {
        m->data[i] = malloc((unsigned long) (cols) * sizeof(**(m->data)));
        if (m->data[i] == NULL) return NULL;
    }

    return m;
}

void show_matrix(const struct matrix *m) {
    size_t i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%8.2lf", m->data[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(struct matrix *m) {
    size_t i;
    for (i = 0; i<m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

int main(void) {
    struct matrix *m;

    m = allocate_matrix(3, 2);
    if (m == NULL) {
        /* allocation error */
    }

    show_matrix(m);

    free_matrix(m);
}