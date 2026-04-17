#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX], queue[MAX];

void addEdge(int u, int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = adj[u];
    adj[u] = temp;
}

int main() {
    int V, E, u, v;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(v, u);
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

        struct Node* temp = adj[node];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0)
                queue[rear++] = temp->data;
            temp = temp->next;
        }
    }

    if (count != V)
        printf("\n[]");

    return 0;
}