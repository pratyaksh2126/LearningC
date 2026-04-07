#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void helper(struct TreeNode* root, struct TreeNode** prev) {
    if (!root) return;
    helper(root->right, prev);
    helper(root->left, prev);
    root->right = *prev;
    root->left = NULL;
    *prev = root;
}

void flatten(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    helper(root, &prev);
}