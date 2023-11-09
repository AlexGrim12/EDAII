#include <stdio.h>

int main()
{
    int v1=0, v2=0;
    printf("El valor de v1 y v2 antes de entrar a regio paralela es v1=%d v2=%d\n", v1, v2);

    #pragma omp parallel private(v2) num_threads(2)
    {
        int v3=3;
        v2 = 1;
        printf("El valor de v1 dentro RP es %d\n", v1);
        printf("El valor de v2 dentro RP es %d\n", v2);
        printf("El valor de v3 dentro RP es %d\n", v3);
        v1=8;
        v2=10;
        v3=11;
    }    
    printf("El valor de v1 fuera es %d\n", v1);
    printf("El valor de v2 fuera es %d\n", v2);
    return 0;
}

/*
1.-Cuales variables son compartidas y cuales privadas?
r = Las variables 2 y 3 son privadas, mientras que la variable 1 es modificable en cualquier parte porque es publica
2.-Las impresionde de las variables dentro y fuera de la region paralela son iguales o diferentes? porque?
r = Las privadas solamente cambian su valor dentro del hilo, pero fuera va a mantener su valor inicial
3.-Imprimir la v3 
r = Daria un error porque la variable no existe de manera publica
*/