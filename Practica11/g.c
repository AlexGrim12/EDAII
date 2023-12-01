#include <stdio.h>
#include <omp.h>

int main()
{
    long long n_values[] = {10000, 100000, 1000000, 10000000};  // Puedes agregar más valores de n si lo deseas

    for (int j = 0; j < sizeof(n_values) / sizeof(n_values[0]); j++)
    {
        long long n = n_values[j];
        double h = 1.0 / (double)n;
        double x, pi = 0.0;

        double start = omp_get_wtime();

        for (int i = 0; i < n; i++)
        {
            x = (i + 0.5) * h;
            pi += 4.0 / (1.0 + x * x);
        }

        double end = omp_get_wtime();

        printf("Serie - N = %lld, PI = %15.12f, Tiempo = %15.12f segundos\n", n, h * pi, end - start);
    }

    return 0;
}
