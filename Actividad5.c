#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    int tid, nth, i=0;
    #pragma omp parallel num_threads(2)
    for (int i = 0; i < 10; i++){    
        {
            for (int j = 0; j < 2; i++)
            {
                if (tid = 0)
                {
                    printf("Iterador: %d en el hilo %d\n", i, tid);
                }
                else
                {
                    printf("Iterador: %d en el hilo %d\n", i, tid);
                }
                
                
            }
        }
    }
    printf("Adios\n");
    return 0;
}
