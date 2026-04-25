#include <stdio.h>

#define INF 1000000000

int minDistance(int dist[], int visited[], int n) {
    int min = INF, idx = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int graph[100][100], int n, int src, int dist[]) {
    int visited[100] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int n, m, threshold;
    scanf("%d %d", &n, &m);

    int graph[100][100] = {0};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    scanf("%d", &threshold);

    int city = -1, minCount = INF;

    for (int i = 0; i < n; i++) {
        int dist[100];
        dijkstra(graph, n, i, dist);

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[j] <= threshold)
                count++;
        }

        if (count <= minCount) {
            minCount = count;
            city = i;
        }
    }

    printf("%d\n", city);
    return 0;
}