
#include <stdio.h>
#include <omp.h>

#define N 12
#define THREADS 4

int main() {
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int b[N] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int c[N];
    int i, tid;

    #pragma omp parallel num_threads(THREADS) private(i, tid)
    {
        tid = omp_get_thread_num();
        for (i = tid * (N/THREADS); i < (tid + 1) * (N/THREADS); i++) {
            c[i] = a[i] + b[i];
        }
    }

    printf("Array c:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
