#include <stdio.h>

int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n-1);
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    for(int i=0; i<rows; i++) {
        for(int space=0; space < rows - i -1; space++)
            printf("  ");
        for(int j=0; j<=i; j++) {
            printf("%4d", nCr(i, j));
        }
        printf("\n");
    }
    return 0;
}
