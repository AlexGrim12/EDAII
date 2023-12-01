#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int findMinSequential(int *arr, int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n = 1000000;
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    // Versión paralela con OpenMP (reducción)
    int minParallel = INT_MAX;
    #pragma omp parallel for reduction(min : minParallel)
    for (int i = 0; i < n; i++) {
        if (arr[i] < minParallel) {
            minParallel = arr[i];
        }
    }

    printf("El minimo encontrado (paralelo) es: %d\n", minParallel);

    free(arr);
    return 0;
}
