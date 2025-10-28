#include <stdio.h>

int main() {
    float arr[5];
    int i;
    printf("Enter 5 values: ");
    for(i = 0; i < 5; i++)
        scanf("%f", &arr[i]);
    for(i = 0; i < 5; i++)
        if(arr[i] < 5)
            printf("arr[%d] = %.2f\n", i, arr[i]);
    return 0;
}
