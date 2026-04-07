#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr) {
        if (curr->left) {
            struct TreeNode* pred = curr->left;
            while (pred->right)
                pred = pred->right;

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}