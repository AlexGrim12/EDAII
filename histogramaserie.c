#include <stdio.h>

#define MAX_INTENSITY 256

void calculateHistogram(int histogram[MAX_INTENSITY], int **image, int rows, int cols) {
    for (int i = 0; i < MAX_INTENSITY; i++) {
        histogram[i] = 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            histogram[image[i][j]]++;
        }
    }
}

int main() {
    int rows = 5, cols = 5;
    int **image = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        image[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            image[i][j] = i + j; 
        }
    }

    int histogram[MAX_INTENSITY];
    calculateHistogram(histogram, image, rows, cols);

    for (int i = 0; i < MAX_INTENSITY; i++) {
        if (histogram[i] > 0) {
            printf("Intensity %d: %d\n", i, histogram[i]);
        }
    }

    for (int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}