#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int a[n];
    for (int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &a[i]);
    }

    // Bubble sort (ascending)
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    printf("Sorted array (ascending):\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
