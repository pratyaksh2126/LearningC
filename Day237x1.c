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
}

void bfs(struct Node** adj, int n, int s) {
    int* visited = (int*)calloc(n, sizeof(int));
    int* q = (int*)malloc(n * sizeof(int));
    int f = 0, r = 0;

    visited[s] = 1;
    q[r++] = s;

    while (f < r) {
        int u = q[f++];
        printf("%d ", u);

        struct Node* temp = adj[u];
        while (temp) {
            if (!visited[temp->v]) {
                visited[temp->v] = 1;
                q[r++] = temp->v;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(q);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            addEdge(adj, i, v);
        }
    }

    int s;
    scanf("%d", &s);

    bfs(adj, n, s);

    return 0;
}