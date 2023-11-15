#include <stdio.h>
#include <omp.h>

int main(int argc, char argv[])
{
  long long n = 1000000000;
  double h;
  double empezar, terminar;
  double x, pi, area = 0.0;
  int i, nth = 0;
  empezar = omp_get_wtime();
  h = 1.0 / (double)n;
  for (i = 0; i < n; i++)
  {
    x = (i + .5) * h;
    area = area + 4.0 / (1. + x * x);
  }
  pi = area * h;
  terminar = omp_get_wtime();
  printf("El valor de PI es %15.12f\n", pi);
  printf("El tiempo de ejecucion es %15.12f\n", terminar - empezar);
  return 0;
}
// Las implementaciones del punto D y E son equivalentes en términos de precisión. Sin embargo, la implementación del punto D es más eficiente en términos de tiempo de ejecución.

// La implementación del punto D utiliza un bucle for para calcular la suma de la serie de pi. Este bucle se puede paralelizar fácilmente utilizando OpenMP, lo que puede mejorar el rendimiento del programa.