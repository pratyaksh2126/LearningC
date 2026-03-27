#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    printf("%d\n", height(root));
    return 0;
}