#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int check(int a[], int n, int m, int d)
{
    int c = 1, last = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - last >= d)
        {
            c++;
            last = a[i];
        }
        if (c >= m) return 1;
    }
    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    int l = 1, r = a[n-1] - a[0], ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(a, n, m, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    printf("%d", ans);
    return 0;
}