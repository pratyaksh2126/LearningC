#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    return (*(int *)x - *(int *)y);
}

int valid(int arr[], int n, int m, int dist)
{
    int placed = 1, prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - prev >= dist)
        {
            placed++;
            prev = arr[i];
        }
    }
    return placed >= m;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int low = 1, high = arr[n-1] - arr[0], res = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (valid(arr, n, m, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    printf("%d", res);
    return 0;
}