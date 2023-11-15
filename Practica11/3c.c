#include <stdio.h>
#include <omp.h>
int main(int argc, char argv[])
{
    long long n = 100;
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
// El valor de pi calculado con n = 100 es aproximadamente 2.970728791242. Este valor es aproximadamente 0.170863862358 menos que el valor exacto de pi, que es 3.141592653589793.