#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* build(int a[], int n, int i) {
    if (i >= n || a[i] == -1) return NULL;
    struct Node* r = createNode(a[i]);
    r->left = build(a, n, 2*i+1);
    r->right = build(a, n, 2*i+2);
    return r;
}

int main() {
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,n,0);

    struct Node* stack[100];
    int top = -1;

    if (root) stack[++top] = root;

    while (top != -1) {
        struct Node* cur = stack[top--];
        printf("%d ", cur->val);
        if (cur->right) stack[++top] = cur->right;
        if (cur->left) stack[++top] = cur->left;
    }

    return 0;
}