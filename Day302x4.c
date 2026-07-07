#include <stdio.h>

int main() {
    int a[3][3], b[3][3], sum[3][3];

    printf("Enter elements of First Matrix:\n");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);

    printf("Enter elements of Second Matrix:\n");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&b[i][j]);

    printf("\nSum Matrix:\n");

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            sum[i][j]=a[i][j]+b[i][j];
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}