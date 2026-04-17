#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int graph[MAX][MAX], indegree[MAX], queue[MAX];

int main() {
    int V, E, u, v;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        graph[v][u] = 1;
        indegree[u]++;
    }

    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < V; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if (count != V)
        printf("\n[]");

    return 0;
}