#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int total = 0;

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void solve(struct TreeNode* root, int isLeft) {
    if (!root) return;

    if (!root->left && !root->right && isLeft)
        total += root->val;

    solve(root->left, 1);
    solve(root->right, 0);
}

int main() {
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    solve(root, 0);
    printf("%d", total);
    return 0;
}