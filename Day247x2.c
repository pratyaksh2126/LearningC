#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
} Node;

Node* cloneGraph(Node* s, int n) {
    Node** visited = (Node**)calloc(n + 1, sizeof(Node*));
    Node** queue = (Node**)malloc((n + 1) * sizeof(Node*));
    int front = 0, rear = 0;

    Node* clone = (Node*)malloc(sizeof(Node));
    clone->val = s->val;
    clone->numNeighbors = s->numNeighbors;
    clone->neighbors = (Node**)malloc(s->numNeighbors * sizeof(Node*));

    visited[s->val] = clone;
    queue[rear++] = s;

    while (front < rear) {
        Node* curr = queue[front++];

        for (int i = 0; i < curr->numNeighbors; i++) {
            Node* neigh = curr->neighbors[i];

            if (!visited[neigh->val]) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->val = neigh->val;
                newNode->numNeighbors = neigh->numNeighbors;
                newNode->neighbors = (Node**)malloc(neigh->numNeighbors * sizeof(Node*));

                visited[neigh->val] = newNode;
                queue[rear++] = neigh;
            }

            visited[curr->val]->neighbors[i] = visited[neigh->val];
        }
    }

    return visited[s->val];
}

int main() {
    int n;
    scanf("%d", &n);

    Node** nodes = (Node**)malloc((n + 1) * sizeof(Node*));

    for (int i = 1; i <= n; i++) {
        nodes[i] = (Node*)malloc(sizeof(Node));
        nodes[i]->val = i;
        nodes[i]->neighbors = (Node**)malloc(n * sizeof(Node*));
    }

    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        nodes[i]->numNeighbors = k;
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            nodes[i]->neighbors[j] = nodes[x];
        }
    }

    Node* cloned = cloneGraph(nodes[1], n);
    printf("%d\n", cloned->val);

    return 0;
}