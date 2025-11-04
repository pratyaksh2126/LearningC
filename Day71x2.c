#include <stdio.h>

int main() {
    int n, i;
    float arr[100], sum = 0.0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        sum += arr[i];
    }

    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", sum / n);
    return 0;
}
