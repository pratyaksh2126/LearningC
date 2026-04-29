#include <stdio.h>

int canEat(int piles[], int n, int h, int k) {
    long long hours = 0;
    for(int i = 0; i < n; i++)
        hours += (piles[i] + k - 1) / k;
    return hours <= h;
}

int minEatingSpeed(int piles[], int n, int h) {
    int l = 1, r = 0;
    for(int i = 0; i < n; i++)
        if(piles[i] > r) r = piles[i];

    int ans = r;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(canEat(piles, n, h, mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    int n, h;
    scanf("%d", &n);
    int piles[n];
    for(int i = 0; i < n; i++) scanf("%d", &piles[i]);
    scanf("%d", &h);
    printf("%d\n", minEatingSpeed(piles, n, h));
    return 0;
}