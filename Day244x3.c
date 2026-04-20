#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = -1;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int src, dst, k;
    scanf("%d %d %d", &src, &dst, &k);

    int INF = 1000000000;
    int dist[n][k+2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k+1; j++)
            dist[i][j] = INF;

    dist[src][0] = 0;

    for (int s = 0; s <= k; s++) {
        for (int u = 0; u < n; u++) {
            if (dist[u][s] == INF) continue;

            for (int v = 0; v < n; v++) {
                if (adj[u][v] != -1) {
                    int w = adj[u][v];
                    if (dist[u][s] + w < dist[v][s+1])
                        dist[v][s+1] = dist[u][s] + w;
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= k+1; i++)
        if (dist[dst][i] < ans) ans = dist[dst][i];

    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}