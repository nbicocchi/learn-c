#include <stdio.h>
#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    double **data;
    size_t (*get_rows)(const struct matrix *m);
    size_t (*get_cols)(const struct matrix *m);
};

size_t get_rows_impl(const struct matrix *m) {
    return m->rows;
}

size_t get_cols_impl(const struct matrix *m) {
    return m->cols;
}

struct matrix *allocate_matrix(size_t rows, size_t cols) {
    struct matrix *m;
    size_t i;

    m = malloc(sizeof(*m));
    m->rows = rows;
    m->cols = cols;
    /* function pointers initialized here */
    m->get_rows = get_rows_impl;
    m->get_cols = get_cols_impl;

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

    printf("Matrix 'm' has size [%d, %d]\n", m->get_rows(m), m->get_cols(m));

    show_matrix(m);

    free_matrix(m);
}