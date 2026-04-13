#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v;
    n->next = NULL;
    return n;
}

void addEdge(struct Node** adj, int u, int v) {
    struct Node* n = createNode(v);
    n->next = adj[u];
    adj[u] = n;

    n = createNode(u);
    n->next = adj[v];
    adj[v] = n;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int src;
    scanf("%d", &src);

    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        dist[i] = -1;

    int* q = (int*)malloc(n * sizeof(int));
    int f = 0, r = 0;

    dist[src] = 0;
    q[r++] = src;

    while (f < r) {
        int u = q[f++];

        struct Node* temp = adj[u];
        while (temp) {
            if (dist[temp->v] == -1) {
                dist[temp->v] = dist[u] + 1;
                q[r++] = temp->v;
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}