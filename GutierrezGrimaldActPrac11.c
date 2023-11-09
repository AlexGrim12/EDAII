#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    #pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        #pragma omp for
        for (int i = 0; i < 8; i++)
        {
            printf("Iteracion %d del thread %d de %d threads\n", i, id, nthreads);
        }
    }
    return 0;
}
