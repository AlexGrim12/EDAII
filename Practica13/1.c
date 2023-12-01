// Gutierrez Grimaldo Alejandro

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 10
#define NG 10

int **formaI();
void llenarI(int **ima);
void calcularH(int **ima, int *histo);
void calcularHP(int **ima, int *histo);

int main()
{
    int **ima, *histo, *histoP;

    ima = formaI();
    llenarI(ima);

    histo = (int *)calloc(NG, sizeof(int));
    histoP = (int *)calloc(NG, sizeof(int));

    calcularH(ima, histo);
    calcularHP(ima, histoP);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", ima[i][j]);
        printf("\n");
    }

    printf("\nSecuencial");
    for (int i = 0; i < NG; i++)
        printf(" %d ", histo[i]);

    printf("\n\nParalelo");
    for (int i = 0; i < NG; i++)
        printf(" %d ", histoP[i]);

    printf("\n");
    free(histo);

    return 0;
}

int **formaI()
{
    int **ima;

    ima = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++)
        ima[i] = (int *)calloc(N, sizeof(int));

    return ima;
}

void llenarI(int **ima)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ima[i][j] = rand() % NG;
}

void calcularH(int **ima, int *histo)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            histo[ima[i][j]]++;
}

void calcularHP(int **ima, int *histo)
{
    int histoP[NG], i, j;

#pragma omp parallel private(j, histoP)
    {
        for (i = 0; i < NG; i++)
            histoP[i] = 0;

#pragma omp for
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                histoP[ima[i][j]]++;

#pragma omp critical
        {
            for (i = 0; i < NG; i++)
                histo[i] += histoP[i];
        }
    }
}