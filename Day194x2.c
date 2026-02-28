#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxSum = arr[0];

    for (int i = 0; i < n; i++) {
        int currSum = 0;

        for (int j = 0; j < n; j++) {
            currSum += arr[(i + j) % n];

            if (currSum > maxSum)
                maxSum = currSum;
        }
    }

    printf("%d\n", maxSum);

    return 0;
}