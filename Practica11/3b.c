#include <stdio.h>
#include <omp.h>
int main(int argc, char argv[])
{
    long long n = 100000000;
    double h;
    double x, pi, area = 0.0;
    int i, nth = 0;
    h = 1.0 / (double)n;
#pragma omp parallel private(x)
    {
#pragma omp for
        for (i = 0; i < n; i++)
        {
            x = (i + .5) * h;
            area = area + 4.0 / (1. + x * x);
        }
    }
    pi = area * h;
    printf("El valor de PI es %15.12f\n", pi);
    return 0;
} 
// La suma de los primeros 10 términos de la serie de pi con una precisión de 1 parte en 1000000000 es aproximadamente 0.322519943972
