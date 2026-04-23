#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
} Node;

Node* dfs(Node* node, Node** visited) {
    if (visited[node->val])
        return visited[node->val];

    Node* clone = (Node*)malloc(sizeof(Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (Node**)malloc(node->numNeighbors * sizeof(Node*));

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++)
        clone->neighbors[i] = dfs(node->neighbors[i], visited);

    return clone;
}

Node* cloneGraph(Node* s, int n) {
    Node** visited = (Node**)calloc(n + 1, sizeof(Node*));
    return dfs(s, visited);
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