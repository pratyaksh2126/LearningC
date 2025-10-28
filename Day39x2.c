#include <stdio.h>
#define R1 2
#define C1 3
#define R2 3
#define C2 2

void multiplyMatrices(int a[R1][C1], int b[R2][C2], int result[R1][C2]) {
    for(int i=0; i<R1; i++) {
        for(int j=0; j<C2; j++) {
            result[i][j] = 0;
            for(int k=0; k<C1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[R1][C1] = {{1, 2, 3}, {4, 5, 6}};
    int b[R2][C2] = {{7, 8}, {9, 10}, {11, 12}};
    int result[R1][C2];

    multiplyMatrices(a, b, result);
    printf("Product matrix:\n");
    printMatrix(R1, C2, result);
    return 0;
}
