#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

int cameras;

int helper(struct TreeNode* root) {
    if (!root) return 2;

    int l = helper(root->left);
    int r = helper(root->right);

    if (l == 0 || r == 0) {
        cameras++;
        return 1;
    }

    if (l == 1 || r == 1)
        return 2;

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (helper(root) == 0)
        cameras++;
    return cameras;
}