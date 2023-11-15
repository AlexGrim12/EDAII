#include <stdio.h>
#include <omp.h>

int main(int argc, char argv[])
{
    long long n = 1000000000;
    double h;
    double empezar, terminar;
    double x, pi, area[omp_get_max_threads()];
    int i, nth = 0;
    empezar = omp_get_wtime();
    h = 1.0 / (double)n;
#pragma omp parallel for private(x)
    for (i = 0; i < n; i++)
    {
        x = (i + .5) * h;
        area[omp_get_thread_num()] = area[omp_get_thread_num()] + 4.0 / (1. + x * x);
    }
    pi = 0.0;
#pragma omp parallel for reduction(+ : pi)
    for (i = 0; i < omp_get_max_threads(); i++)
    {
        pi = pi + area[i];
    }
    terminar = omp_get_wtime();
    printf("El valor de PI es %15.12f\n", pi);
    printf("El tiempo de ejecucion es %15.12f\n", terminar - empezar);
    return 0;
}
