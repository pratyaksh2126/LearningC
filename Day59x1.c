#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), compare);

    if (n % 2 == 0)
        printf("Median: %.2f\n", (arr[n/2 - 1] + arr[n/2]) / 2.0);
    else
        printf("Median: %d\n", arr[n/2]);

    return 0;
}
