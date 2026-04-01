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

struct Node* LCA(struct Node* root, int p, int q) {
    if (!root) return NULL;

    if (root->val == p || root->val == q)
        return root;

    struct Node* left = LCA(root->left, p, q);
    struct Node* right = LCA(root->right, p, q);

    if (left && right) return root;

    return left ? left : right;
}

int main() {
    struct Node* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);

    int p = 2, q = 4;

    struct Node* ans = LCA(root, p, q);
    if (ans) printf("%d\n", ans->val);

    return 0;
}