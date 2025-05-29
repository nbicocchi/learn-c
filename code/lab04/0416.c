#include <stdlib.h>
#include <stdio.h>

struct diag_sums {
    double main_diag;
    double sec_diag;
};

struct matrix {
    size_t rows, cols;
    double **data;
};

struct diag_sums *matrix_diagonal_sum(const struct matrix *m) {
    if (!m || m->rows != m->cols)
        return NULL;

    size_t n = m->rows;
    struct diag_sums *result = malloc(sizeof(struct diag_sums));
    if (!result) return NULL;

    result->main_diag = 0;
    result->sec_diag = 0;

    for (size_t i = 0; i < n; ++i) {
        result->main_diag += m->data[i][i];
        result->sec_diag += m->data[i][n - 1 - i];
    }

    return result;
}

struct matrix *allocate_matrix(size_t rows, size_t cols) {
    struct matrix *m;
    int i;

    m = malloc(sizeof(*m));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc((unsigned long) (rows) * sizeof(*m));
    if (m == NULL) return NULL;

    for (i = 0; i < rows; i++) {
        m->data[i] = malloc((unsigned long) (cols) * sizeof(**(m->data)));
        if (m->data[i] == NULL) return NULL;
    }

    return m;
}

void fill_matrix(struct matrix *m) {
    size_t i, j;
    double value = 0.0;

    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            m->data[i][j] = value++;
        }
    }
}

void free_matrix(struct matrix *m) {
    for (size_t i = 0; i < m->rows; ++i)
        free(m->data[i]);
    free(m->data);
    free(m);
}

int main(void) {
    struct matrix *m;

    m = allocate_matrix(3, 3);
    if (!m) {
      perror("allocate_matrix");
      exit(EXIT_FAILURE);
    }

    fill_matrix(m);

    struct diag_sums *sums = matrix_diagonal_sum(m);

    if (!sums) {
      perror("matrix_diagonal_sum");
      exit(EXIT_FAILURE);
    }

    printf("main diagonal: %f\n", sums->main_diag);
    printf("secondary diagonal: %f\n", sums->sec_diag);

    free(sums);
    free_matrix(m);
    exit(EXIT_SUCCESS);
}