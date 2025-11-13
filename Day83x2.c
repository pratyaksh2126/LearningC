#include <stdio.h>

int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int main() {
    int arr[5];
    printf("Enter 5 elements: ");
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    int total = sumArray(arr, 5);
    printf("Sum of array elements = %d\n", total);

    return 0;
}
