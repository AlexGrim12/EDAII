#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j, a;
    #pragma omp parallel num_threads(2)
    {
        printf("Hola Mundo\n");
        for ( i = 0; i < 10; i++)
        {
            printf("Iteracion: %d\n", i);
            for ( j = 0; j < 100; j++)
            {
                a=2;
            }
            
        }
        
    }
    printf("Adios\n");
    return 0;
}
