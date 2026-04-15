#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, E;
    scanf("%d%d", &V, &E);

    int** adj = malloc(V * sizeof(int*));
    int* size = calloc(V, sizeof(int));
    int visited[V], parent[V];

    for (int i = 0; i < V; i++) {
        adj[i] = malloc(2 * E * sizeof(int));
        visited[i] = 0;
        parent[i] = -1;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int queue[V], front, rear, cycle = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            front = rear = 0;
            queue[rear++] = i;
            visited[i] = 1;

            while (front < rear) {
                int node = queue[front++];

                for (int j = 0; j < size[node]; j++) {
                    int neigh = adj[node][j];

                    if (!visited[neigh]) {
                        visited[neigh] = 1;
                        parent[neigh] = node;
                        queue[rear++] = neigh;
                    } else if (parent[node] != neigh) {
                        cycle = 1;
                    }
                }
            }
        }
    }

    printf(cycle ? "YES\n" : "NO\n");
    return 0;
}