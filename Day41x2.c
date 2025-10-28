#include <stdio.h>
int main() {
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows=3, cols=3;
    printf("Boundary elements:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(i==0 || i==rows-1 || j==0 || j==cols-1)
                printf("%d ", matrix[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}
