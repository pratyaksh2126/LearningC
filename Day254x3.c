#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int place(int a[], int n, int m, int gap)
{
    int count = 1, last = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] - last >= gap)
        {
            count++;
            last = a[i];
        }
    }
    return count >= m;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmpfunc);

    int left = 1, right = a[n-1] - a[0], ans = 0;

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (place(a, n, m, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    printf("%d", ans);
    return 0;
}