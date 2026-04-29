#include <stdio.h>

int main() {
    int n, h;
    scanf("%d", &n);
    int piles[n];
    for(int i = 0; i < n; i++) scanf("%d", &piles[i]);
    scanf("%d", &h);

    int max = 0;
    for(int i = 0; i < n; i++)
        if(piles[i] > max) max = piles[i];

    for(int k = 1; k <= max; k++) {
        long long hours = 0;
        for(int i = 0; i < n; i++)
            hours += (piles[i] + k - 1) / k;

        if(hours <= h) {
            printf("%d\n", k);
            break;
        }
    }
    return 0;
}