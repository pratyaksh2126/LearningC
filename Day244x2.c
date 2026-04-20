#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n][n], cost[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = 1;
        cost[u][v] = w;
    }

    int src, dst, k;
    scanf("%d %d %d", &src, &dst, &k);

    int INF = 1000000000;
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;

    int q[10000][3];
    int front = 0, rear = 0;

    q[rear][0] = src;
    q[rear][1] = 0;
    q[rear][2] = 0;
    rear++;

    dist[src] = 0;

    while (front < rear) {
        int node = q[front][0];
        int stops = q[front][1];
        int costSoFar = q[front][2];
        front++;

        if (stops > k) continue;

        for (int v = 0; v < n; v++) {
            if (adj[node][v]) {
                int newCost = costSoFar + cost[node][v];
                if (newCost < dist[v] && stops <= k) {
                    dist[v] = newCost;
                    q[rear][0] = v;
                    q[rear][1] = stops + 1;
                    q[rear][2] = newCost;
                    rear++;
                }
            }
        }
    }

    if (dist[dst] == INF) printf("-1\n");
    else printf("%d\n", dist[dst]);

    return 0;
}