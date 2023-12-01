#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double dotProductSequential(double *vec1, double *vec2, int n)
{
    double result = 0.0;
    for (int i = 0; i < n; i++)
    {
        result += vec1[i] * vec2[i];
    }
    return result;
}

int main()
{
    int n = 1000000;
    double *vec1 = (double *)malloc(n * sizeof(double));
    double *vec2 = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
    {
        vec1[i] = (double)rand() / RAND_MAX;
        vec2[i] = (double)rand() / RAND_MAX;
    }

    double dotProductParallel = 0.0;
#pragma omp parallel for reduction(+ : dotProductParallel)
    for (int i = 0; i < n; i++)
    {
        dotProductParallel += vec1[i] * vec2[i];
    }

    printf("Producto punto (paralelo): %f\n", dotProductParallel);

    free(vec1);
    free(vec2);
    return 0;
}
