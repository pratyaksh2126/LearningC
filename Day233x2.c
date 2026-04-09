#include <stdio.h>
#include <stdlib.h>

int pi;

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

int find(int in[], int s, int e, int x) {
    for (int i = s; i <= e; i++)
        if (in[i] == x) return i;
    return -1;
}

struct Node* build(int in[], int post[], int s, int e) {
    if (s > e) return NULL;

    struct Node* root = newNode(post[pi--]);

    if (s == e) return root;

    int idx = find(in, s, e, root->val);

    root->right = build(in, post, idx + 1, e);
    root->left = build(in, post, s, idx - 1);

    return root;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    pi = n - 1;
    struct Node* root = build(in, post, 0, n - 1);

    preorder(root);
    return 0;
}