// Gutierrez Grimaldo Alejandro

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int **formaI(int N, int NG);
void llenaI(int **ima, int N, int NG);
void calcularHisto(int **ima, int *histo, int N, int NG, int H);
double inicio(int N, int NG, int H);

int main(){
    double t[5][2];
    int nA[] = {2000, 3000, 4000, 5000, 8000};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 2; j++){
            t[i][j] = inicio(nA[i], 256, (j+1)*2);
        }
    }

    for(int i = 0; i < 5; i++){
        printf(" %d ", nA[i]);
        for(int j = 0; j < 2; j++){
            printf(" %.6f ", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int **formaI(int N, int NG){
    int **ima;
    int i;
    ima = (int**)calloc(N, sizeof(int*));
    for(i = 0; i < N; i++){
        ima[i] = (int*)calloc(N, sizeof(int));
    }
    return ima;
}

void llenaI(int **ima, int N, int NG){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            ima[i][j] = rand()%NG;
        }
    }
}

void calcularHisto(int **ima, int *histo, int N, int NG, int H){
    int i, j;
    int **histoP = (int**)calloc(H, sizeof(int*));

    for(i = 0; i < H; i++){
        histoP[i] = (int*)calloc(NG, sizeof(int));
    }

    #pragma omp parallel num_threads(H) private(j)
    {
        #pragma omp for
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                #pragma omp atomic
                histoP[omp_get_thread_num()][ima[i][j]]++;
            }
        }

        #pragma omp for
        for(i = 0; i < H; i++){
            #pragma omp critical
            {
                for(j = 0; j < NG; j++){
                    histo[j] += histoP[i][j];
                }
            }
        }
    }

    for(i = 0; i < H; i++){
        free(histoP[i]);
    }
    free(histoP);
}

double inicio(int N, int NG, int H){
    double inicio, fin;
    inicio = omp_get_wtime();
    int **ima, *histo, i;
    ima  = formaI(N, NG);
    llenaI(ima, N, NG);
    histo = (int*)calloc(NG, sizeof(int));
    calcularHisto(ima, histo, N, NG, H);
    fin = omp_get_wtime();
    free(histo);
    for(i = 0; i < N; i++){
        free(ima[i]);
    }
    free(ima);
    return fin - inicio;
}
