#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int can(int arr[], int n, int m, int d)
{
    int cnt = 1, last = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last >= d)
        {
            cnt++;
            last = arr[i];
        }
    }
    return cnt >= m;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int low = 1, high = arr[n-1] - arr[0], ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (can(arr, n, m, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    printf("%d", ans);
    return 0;
}