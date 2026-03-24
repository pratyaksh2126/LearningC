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

void preorder(struct Node* r) {
    if (!r) return;
    printf("%d ", r->val);
    preorder(r->left);
    preorder(r->right);
}

int main() {
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    struct Node* root = build(a,n,0);
    preorder(root);
    return 0;
}