#include <stdio.h>
#include <limits.h>

#define MAX 101
#define INF 1000000000

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);

    int dist[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
    }

    scanf("%d", &k);

    int d[MAX], visited[MAX] = {0};

    for (int i = 1; i <= n; i++) d[i] = INF;
    d[k] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1, min = INF;
        for (int j = 1; j <= n; j++)
            if (!visited[j] && d[j] < min)
                min = d[j], u = j;

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++)
            if (dist[u][v] != INF && d[u] + dist[u][v] < d[v])
                d[v] = d[u] + dist[u][v];
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