#include <stdio.h>
int main(){
    #pragma omp parallel num_threads(2)
    {
    int i;
    printf("Hola Mundo");
    for(i=0;i<10;i++){
        printf("Iteracion: %d\n", i);
    }}
    printf("Adios\n");
}

// AGREGAR REGION PARALELA
/*
1.- Que diferencia hay en la salida del programa con respeco a la secuencia?
Lo imprime n veces dependiendo de los hilos que se manejen
2.- 
*/