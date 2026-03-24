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

void solve(struct Node* r, int res[], int* idx) {
    if (!r) return;
    res[(*idx)++] = r->val;
    solve(r->left, res, idx);
    solve(r->right, res, idx);
}

int main() {
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,n,0);

    int res[100], idx = 0;
    solve(root, res, &idx);

    for(int i=0;i<idx;i++) printf("%d ", res[i]);

    return 0;
}