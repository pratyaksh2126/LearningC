#include <stdio.h>
int main() {
    int i, j, rows, columns, matrix[10][10], number;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &columns);
    printf("Enter matrix elements:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Enter scalar value: ");
    scanf("%d", &number);
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            matrix[i][j] *= number;
        }
    }
    printf("Result after scalar multiplication:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
