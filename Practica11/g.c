#include <stdio.h>
#include <omp.h>

int main(int argc, char argv[])
{
    long long n = 1000000000;
    double h;
    double empezar, terminar;
    double x, pi = 0.0;
    int i;

    empezar = omp_get_wtime();
    h = 1.0 / (double)n;

    #pragma omp parallel for private(x) reduction(+:pi)
    for (i = 0; i < n; i++)
    {
        x = (i + 0.5) * h;
        pi += 4.0 / (1.0 + x * x);
    }

    terminar = omp_get_wtime();

    printf("El valor de PI es %15.12f\n", h * pi);
    printf("El tiempo de ejecucion es %15.12f\n", terminar - empezar);

    return 0;
}
