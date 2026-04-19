#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);

    int edges[m][3];

    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);

    scanf("%d", &k);

    int d[101];
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[k] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (d[u] != INF && d[u] + w < d[v])
                d[v] = d[u] + w;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            printf("-1");
            return 0;
        }
        if (d[i] > ans) ans = d[i];
    }

    printf("%d", ans);
    return 0;
}