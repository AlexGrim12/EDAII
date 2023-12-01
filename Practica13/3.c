// Gutierrez Grimaldo Alejandro

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define nr 10
#define nc 10
#define NG 10

int **formaIma();
void llenaIma(int **ima);
void calcuHistoP(int **ima, int *histo);
int minHistoP(int *histo);

int main()
{
    int **ima, *histo, i, j, minVal;
    ima = formaIma();
    llenaIma(ima);
    histo = (int *)calloc(NG, sizeof(int));
    calcuHistoP(ima, histo);

    for (i = 0; i < nr; i++)
    {
        for (j = 0; j < nc; j++)
        {
            printf("%d ", ima[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < NG; i++)
    {
        printf("%d ", histo[i]);
    }

    minVal = minHistoP(histo);
    printf("\nEl valor minimo del histograma es: %d", minVal);

    free(histo);
    free(ima);

    return 0;
}

int **formaIma()
{
    int **ima, i;
    ima = (int **)calloc(nr, sizeof(int *));
    for (i = 0; i < nr; i++)
    {
        ima[i] = (int *)calloc(nc, sizeof(int));
    }
    return ima;
}

void llenaIma(int **ima)
{
    int i, j;
    for (i = 0; i < nr; i++)
    {
        for (j = 0; j < nc; j++)
        {
            ima[i][j] = rand() % NG;
        }
    }
}

void calcuHistoP(int **ima, int *histo)
{
    int i, j;
    int histoP[NG] = {0};

#pragma omp parallel private(i, j)
    {
        int localHistoP[NG] = {0};

#pragma omp for
        for (i = 0; i < nr; i++)
        {
            for (j = 0; j < nc; j++)
            {
                localHistoP[ima[i][j]]++;
            }
        }

#pragma omp critical
        {
            for (i = 0; i < NG; i++)
            {
                histo[i] += localHistoP[i];
            }
        }
    }
}

int minHistoP(int *histo)
{
    int minVal = NG;
    int i;

#pragma omp parallel for private(i) reduction(min : minVal)
    for (i = 0; i < NG; i++)
    {
        if (histo[i] > 0 && histo[i] < minVal)
        {
            minVal = histo[i];
        }
    }

    return minVal;
}
