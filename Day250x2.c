#include <stdio.h>

int lowerBound(int arr[], int n, int target) {
    int left = 0, right = n - 1, ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, target;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &target);

    printf("%d", lowerBound(arr, n, target));

    return 0;
}