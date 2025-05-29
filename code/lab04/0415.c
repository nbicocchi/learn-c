#include <stdio.h>
#include <stdlib.h>

int *filter_even(const int *arr, unsigned size, unsigned *out_size) {
    if (!arr || !out_size) return NULL;

    // Primo passaggio: conta gli elementi pari
    unsigned count = 0;
    for (unsigned i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) count++;
    }

    if (count == 0) {
        return NULL;
    }

    // Secondo passaggio: alloca e copia solo i pari
    int *result = malloc(count * sizeof(int));
    if (!result) {
        return NULL;
    }

    unsigned j = 0;
    for (unsigned i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            result[j++] = arr[i];
        }
    }

    *out_size = count;
    return result;
}

#define SIZE 9

int main(void) {
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned out_size = 0;

    int *even_array = filter_even(array, SIZE, &out_size);
    if (!even_array) {
      fprintf(stderr, "Failed to allocate memory for even array\n");
      exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Output: ");
    for (unsigned i = 0; i < out_size; ++i) {
        fprintf(stdout, "%d ", even_array[i]);
    }
    fprintf(stdout, "\n");
    free(even_array);
    exit(EXIT_SUCCESS);
}