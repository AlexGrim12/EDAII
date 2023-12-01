#include <stdio.h>
#include <stdlib.h>

// Función para calcular el producto punto de dos vectores
double dotProductSequential(double *vec1, double *vec2, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

int main() {
    int n = 1000000; // Tamaño de los vectores
    double *vec1 = (double *)malloc(n * sizeof(double));
    double *vec2 = (double *)malloc(n * sizeof(double));

    // Inicialización de los vectores (puedes adaptar esto según tus necesidades)
    for (int i = 0; i < n; i++) {
        vec1[i] = (double)rand() / RAND_MAX;
        vec2[i] = (double)rand() / RAND_MAX;
    }

    // Versión secuencial
    double dotProductSequentialResult = dotProductSequential(vec1, vec2, n);

    printf("Producto punto (secuencial): %f\n", dotProductSequentialResult);

    free(vec1);
    free(vec2);
    return 0;
}
