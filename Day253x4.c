#include <stdio.h>

int possible(int piles[], int n, int h, int k) {
    long long time = 0;
    for(int i = 0; i < n; i++)
        time += (piles[i] + k - 1) / k;
    return time <= h;
}

int main() {
    int n, h;
    scanf("%d", &n);
    int piles[n];
    for(int i = 0; i < n; i++) scanf("%d", &piles[i]);
    scanf("%d", &h);

    int low = 1, high = 0;
    for(int i = 0; i < n; i++)
        if(piles[i] > high) high = piles[i];

    int res = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(piles, n, h, mid)) {
            res = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    printf("%d\n", res);
    return 0;
}