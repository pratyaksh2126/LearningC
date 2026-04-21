#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 15

int n, cost[MAX][MAX];
int dp[1 << MAX][MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int mask, int pos) {
    if(mask == (1 << n) - 1) return cost[pos][0];

    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i))) {
            int val = cost[pos][i] + tsp(mask | (1 << i), i);
            ans = min(ans, val);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    memset(dp, -1, sizeof(dp));

    printf("%d\n", tsp(1, 0));
    return 0;
}