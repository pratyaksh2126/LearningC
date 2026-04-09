#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

int map[6001];

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* build(int in[], int post[], int s, int e, int *pi) {
    if (s > e) return NULL;

    struct Node* root = newNode(post[*pi]);
    (*pi)--;

    if (s == e) return root;

    int idx = map[root->val + 3000];

    root->right = build(in, post, idx + 1, e, pi);
    root->left = build(in, post, s, idx - 1, pi);

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

    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        map[in[i] + 3000] = i;
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    int pi = n - 1;

    struct Node* root = build(in, post, 0, n - 1, &pi);

    preorder(root);
    return 0;
}