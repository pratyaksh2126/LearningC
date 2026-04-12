#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if (!t1 && !t2)
        return 1;
    if (!t1 || !t2)
        return 0;
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}