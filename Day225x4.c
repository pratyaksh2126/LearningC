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

int findPath(struct Node* root, int path[], int *len, int k) {
    if (!root) return 0;

    path[(*len)++] = root->val;

    if (root->val == k) return 1;

    if (findPath(root->left, path, len, k) ||
        findPath(root->right, path, len, k))
        return 1;

    (*len)--;
    return 0;
}

int findLCA(struct Node* root, int n1, int n2) {
    int path1[100], path2[100];
    int len1 = 0, len2 = 0;

    findPath(root, path1, &len1, n1);
    findPath(root, path2, &len2, n2);

    int i;
    for (i = 0; i < len1 && i < len2; i++) {
        if (path1[i] != path2[i])
            break;
    }

    return path1[i - 1];
}

int main() {
    struct Node* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);

    printf("%d\n", findLCA(root, 2, 4));

    return 0;
}