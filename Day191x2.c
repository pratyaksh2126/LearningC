#include <stdio.h>

void rotate(int nums[], int n, int k) {
    k = k % n;

    int temp[n];

    for (int i = 0; i < n; i++)
        temp[(i + k) % n] = nums[i];

    for (int i = 0; i < n; i++)
        nums[i] = temp[i];
}

int main() {
    int n, k;

    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    rotate(nums, n, k);

    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}