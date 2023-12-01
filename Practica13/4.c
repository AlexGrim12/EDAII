// Gutierrez Grimaldo Alejandro

#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
#pragma omp parallel num_threads(4)
    {
#pragma omp sections
        {
#pragma omp section
            {
                printf("El hilo %d, esta en la seccion 1\n", omp_get_thread_num());
            }
#pragma omp section
            {
                printf("El hilo %d, esta en la seccion 2\n", omp_get_thread_num());
            }
#pragma omp section
            {
                printf("El hilo %d, esta en la seccion 3\n", omp_get_thread_num());
            }
#pragma omp section
            {
                printf("El hilo %d, esta en la seccion 4\n", omp_get_thread_num());
            }
        }
    }
    return 0;
}
// El hilo 1, esta en la seccion 1
// El hilo 0, esta en la seccion 2
// El hilo 2, esta en la seccion 3
// El hilo 3, esta en la seccion 4
// La asignación de hilos a secciones de código y el orden en que se ejecutan puede variar dependiendo de cómo el sistema operativo programe los hilos. Por lo tanto, es posible que no siempre veas la misma salida cada vez que se ejecute el programa.