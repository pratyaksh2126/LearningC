#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

typedef enum { NEED, HAS, COVERED } State;

int cameras;

State solve(struct TreeNode* root) {
    if (!root) return COVERED;

    State l = solve(root->left);
    State r = solve(root->right);

    if (l == NEED || r == NEED) {
        cameras++;
        return HAS;
    }

    if (l == HAS || r == HAS)
        return COVERED;

    return NEED;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (solve(root) == NEED)
        cameras++;
    return cameras;
}