#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int flights[m][3];
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &flights[i][0], &flights[i][1], &flights[i][2]);

    int src, dst, k;
    scanf("%d %d %d", &src, &dst, &k);

    int INF = 1000000000;
    int dp[k+2][n];

    for (int i = 0; i <= k+1; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = INF;

    dp[0][src] = 0;

    for (int i = 1; i <= k+1; i++) {
        for (int j = 0; j < n; j++)
            dp[i][j] = dp[i-1][j];

        for (int j = 0; j < m; j++) {
            int u = flights[j][0], v = flights[j][1], w = flights[j][2];
            if (dp[i-1][u] != INF && dp[i-1][u] + w < dp[i][v])
                dp[i][v] = dp[i-1][u] + w;
        }
    }

    int ans = dp[k+1][dst];

    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}