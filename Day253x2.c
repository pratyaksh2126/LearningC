#include <stdio.h>

long long totalHours(int piles[], int n, int k) {
    long long h = 0;
    for(int i = 0; i < n; i++)
        h += (piles[i] + k - 1) / k;
    return h;
}

int main() {
    int n, h;
    scanf("%d", &n);
    int piles[n];
    for(int i = 0; i < n; i++) scanf("%d", &piles[i]);
    scanf("%d", &h);

    int l = 1, r = 0;
    for(int i = 0; i < n; i++)
        if(piles[i] > r) r = piles[i];

    while(l < r) {
        int mid = (l + r) / 2;
        if(totalHours(piles, n, mid) <= h)
            r = mid;
        else
            l = mid + 1;
    }

    printf("%d\n", l);
    return 0;
}