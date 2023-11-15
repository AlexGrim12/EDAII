#include <stdio.h>
int main(int argc, char *argv[])
{
    long long n = 100000000;
    double h;
    double x, pi, area = 0.0;
    int i;
    h = 1.0 / (double)n;
    for (i = 0; i < n; i++)
    {
        x = (i + .5) * h;
        area = area + 4.0 / (1. + x * x);
    }
    pi = area * h;
    printf("PI = %15.12f\n", pi);
    return 0;
}
