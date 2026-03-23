#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr) {
        if (!curr->left) {
            printf("%d ", curr->val);
            curr = curr->right;
        } else {
            struct TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (!pred->right) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                printf("%d ", curr->val);
                curr = curr->right;
            }
        }
    }
}

int main() {
    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    inorder(root);
    return 0;
}