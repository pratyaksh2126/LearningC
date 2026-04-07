#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void preorder(struct TreeNode* root, struct TreeNode* arr[], int* size) {
    if (!root) return;
    arr[(*size)++] = root;
    preorder(root->left, arr, size);
    preorder(root->right, arr, size);
}

void flatten(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* arr[2000];
    int size = 0;

    preorder(root, arr, &size);

    for (int i = 0; i < size - 1; i++) {
        arr[i]->left = NULL;
        arr[i]->right = arr[i + 1];
    }

    if (size > 0) {
        arr[size - 1]->left = NULL;
        arr[size - 1]->right = NULL;
    }
}