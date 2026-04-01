#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct Node* LCA(struct Node* root, int p, int q) {
    if (!root) return NULL;

    if (p < root->val && q < root->val)
        return LCA(root->left, p, q);

    if (p > root->val && q > root->val)
        return LCA(root->right, p, q);

    return root;
}

int main() {
    int n, x, p, q;
    scanf("%d", &n);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &p, &q);

    struct Node* ans = LCA(root, p, q);
    if (ans) printf("%d\n", ans->val);

    return 0;
}