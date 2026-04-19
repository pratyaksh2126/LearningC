#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 101
#define INF 1000000000

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

void addEdge(int u, int v, int w) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v;
    n->w = w;
    n->next = adj[u];
    adj[u] = n;
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    scanf("%d", &k);

    int d[MAX], visited[MAX] = {0};

    for (int i = 1; i <= n; i++) d[i] = INF;
    d[k] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1, min = INF;
        for (int j = 1; j <= n; j++)
            if (!visited[j] && d[j] < min)
                min = d[j], u = j;

        if (u == -1) break;

        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v, w = temp->w;
            if (d[u] + w < d[v]) d[v] = d[u] + w;
            temp = temp->next;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            printf("-1");
            return 0;
        }
        if (d[i] > ans) ans = d[i];
    }

    printf("%d", ans);
    return 0;
}