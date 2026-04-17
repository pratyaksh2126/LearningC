#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX], stack[MAX];
int top = -1, V, hasCycle = 0;

void addEdge(int u, int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = adj[u];
    adj[u] = temp;
}

void dfs(int v) {
    if (visited[v] == 1) {
        hasCycle = 1;
        return;
    }
    if (visited[v] == 2) return;

    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        dfs(temp->data);
        temp = temp->next;
    }

    visited[v] = 2;
    stack[++top] = v;
}

int main() {
    int E, u, v;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(v, u);
    }

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