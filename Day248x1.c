#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int timeCounter;

void dfs(int u, int parent, int visited[], int disc[], int low[], int ap[], int* adj[], int colSize[]) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int i = 0; i < colSize[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            children++;
            dfs(v, u, visited, disc, low, ap, adj, colSize);

            if (low[v] < low[u]) low[u] = low[v];

            if (parent != -1 && low[v] >= disc[u]) ap[u] = 1;
        }
        else if (v != parent) {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }

    if (parent == -1 && children > 1) ap[u] = 1;
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int colSize[V];
    for (int i = 0; i < V; i++) colSize[i] = 0;

    int u, v;
    int edges[E][2];

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        edges[i][0] = u;
        edges[i][1] = v;
        colSize[u]++;
        colSize[v]++;
    }

    int* adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(colSize[i] * sizeof(int));
        colSize[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        u = edges[i][0];
        v = edges[i][1];
        adj[u][colSize[u]++] = v;
        adj[v][colSize[v]++] = u;
    }

    int visited[V], disc[V], low[V], ap[V];
    for (int i = 0; i < V; i++) {
        visited[i] = disc[i] = low[i] = ap[i] = 0;
    }

    timeCounter = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, -1, visited, disc, low, ap, adj, colSize);
    }

    int res[V], count = 0;

    for (int i = 0; i < V; i++) {
        if (ap[i]) res[count++] = i;
    }

    if (count == 0) {
        printf("-1");
    } else {
        qsort(res, count, sizeof(int), cmp);
        for (int i = 0; i < count; i++) printf("%d ", res[i]);
    }

    return 0;
}