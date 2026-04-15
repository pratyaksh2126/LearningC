#include <stdio.h>

int V;
int adj[100][100];
int visited[100];

int dfs(int v, int parent) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int E;
    scanf("%d%d", &V, &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    int cycle = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cycle = 1;
                break;
            }
        }
    }

    printf(cycle ? "YES\n" : "NO\n");
    return 0;
}