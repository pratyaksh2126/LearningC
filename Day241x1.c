#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int graph[MAX][MAX], visited[MAX], stack[MAX];
int V, top = -1, hasCycle = 0;

void dfs(int v) {
    if (visited[v] == 1) {
        hasCycle = 1;
        return;
    }
    if (visited[v] == 2) return;

    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) dfs(i);
    }

    visited[v] = 2;
    stack[++top] = v;
}

int main() {
    int E, u, v;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        graph[v][u] = 1;
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++)
        if (!visited[i]) dfs(i);

    if (hasCycle) {
        printf("[]");
        return 0;
    }

    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}