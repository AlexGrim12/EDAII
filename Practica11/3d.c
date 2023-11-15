#include <stdio.h>
#include <omp.h>

int main(int argc, char argv[])
{
  long long n = 1000000000;
  double h;
  double x, pi, area = 0.0;
  int i, nth = 0;
  h = 1.0 / (double)n;
#pragma omp parallel private(x)
  {
#pragma omp for
    for (i = 0; i < n; i++)
    {
// Sección crítica
#pragma omp critical
      {
        x = (i + .5) * h;
        area = area + 4.0 / (1. + x * x);
      }
    }
  }
  pi = area * h;
  printf("El valor de PI es %15.12f\n", pi);
  return 0;
}
// Sí, se obtuvo el resultado correcto. Esto se debe a que la sección crítica se utilizó para proteger el acceso a la variable area, lo que evitó que se modificara incorrectamente por múltiples hilos.

// La sección crítica es un bloque de código que sólo puede ser ejecutado por un hilo a la vez. Esto se hace para evitar que múltiples hilos accedan y modifiquen la misma variable al mismo tiempo, lo que podría causar problemas.