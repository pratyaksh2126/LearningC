#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

int cameras;

int dfs(struct TreeNode* root) {
    if (!root) return 1;

    int l = dfs(root->left);
    int r = dfs(root->right);

    if (l == -1 || r == -1) {
        cameras++;
        return 0;
    }

    if (l == 0 || r == 0)
        return 1;

    return -1;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == -1)
        cameras++;
    return cameras;
}