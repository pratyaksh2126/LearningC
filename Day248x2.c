#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], disc[MAX], low[MAX], ap[MAX];
int timeCounter;

void dfs(int u, int parent, int V) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int v = 0; v < V; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                children++;
                dfs(v, u, V);

                if (low[v] < low[u]) low[u] = low[v];

                if (parent != -1 && low[v] >= disc[u]) ap[u] = 1;
            }
            else if (v != parent) {
                if (disc[v] < low[u]) low[u] = disc[v];
            }
        }
    }

    if (parent == -1 && children > 1) ap[u] = 1;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    timeCounter = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, -1, V);
    }

    int found = 0;

    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) printf("-1");

    return 0;
}