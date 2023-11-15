#include <stdio.h>
#include <omp.h>

int main() {

  // Declaramos los arreglos
  int a[12], b[12], c[12];

  // Inicializamos los arreglos
  for (int i = 0; i < 12; i++) {
    a[i] = i;
    b[i] = i * 2;
  }

  // Declaramos variables para almacenar el resultado
  int suma_a, suma_b, suma_c;

  // Inicializamos las variables
  suma_a = 0;
  suma_b = 0;

  // Ejecutamos la suma de forma paralela
  #pragma omp parallel for reduction(+:suma_a, suma_b)
  for (int i = 0; i < 12; i++) {
    if (i % 4 == 0) {
      suma_a += a[i];
    } else if (i % 4 == 1) {
      suma_b += a[i];
    } else if (i % 4 == 2) {
      suma_a += b[i];
    } else {
      suma_b += b[i];
    }
  }

  // Calculamos la suma final
  suma_c = suma_a + suma_b;

  // Imprimimos el resultado
  printf("La suma es: %d\n", suma_c);

  return 0;
}
