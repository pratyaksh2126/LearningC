#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int totalSum = 0;
    int currMax = arr[0], maxSum = arr[0];
    int currMin = arr[0], minSum = arr[0];

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];

        if (i > 0) {
            currMax = max(currMax + arr[i], arr[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(currMin + arr[i], arr[i]);
            minSum = min(minSum, currMin);
        }
    }

    if (maxSum < 0)
        printf("%d\n", maxSum);
    else
        printf("%d\n", max(maxSum, totalSum - minSum));

    return 0;
}