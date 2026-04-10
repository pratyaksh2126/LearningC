#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

int dfs(struct TreeNode* root, int* cam) {
    if (!root) return 1;

    int l = dfs(root->left, cam);
    int r = dfs(root->right, cam);

    if (l == -1 || r == -1) {
        (*cam)++;
        return 0;
    }

    if (l == 0 || r == 0)
        return 1;

    return -1;
}

int minCameraCover(struct TreeNode* root) {
    int cam = 0;
    if (dfs(root, &cam) == -1)
        cam++;
    return cam;
}