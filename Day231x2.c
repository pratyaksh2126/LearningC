#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void flatten(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* stack[2000];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* curr = stack[top--];

        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;

        if (top >= 0)
            curr->right = stack[top];

        curr->left = NULL;
    }
}