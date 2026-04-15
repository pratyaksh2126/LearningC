#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int parent, int visited[], int** adj, int size[]) {
    visited[v] = 1;
    for (int i = 0; i < size[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (dfs(u, v, visited, adj, size))
                return 1;
        } else if (u != parent) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d%d", &V, &E);

    int** adj = malloc(V * sizeof(int*));
    int* size = calloc(V, sizeof(int));
    int visited[V];

    for (int i = 0; i < V; i++) {
        adj[i] = malloc(2 * E * sizeof(int));
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int cycle = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, size)) {
                cycle = 1;
                break;
            }
        }
    }

    printf(cycle ? "YES\n" : "NO\n");
    return 0;
}