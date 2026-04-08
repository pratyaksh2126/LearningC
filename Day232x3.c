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

int identical(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;

    return (a->data == b->data) &&
           identical(a->left, b->left) &&
           identical(a->right, b->right);
}

int main() {
    struct Node* a = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);

    struct Node* b = newNode(1);
    b->left = newNode(2);
    b->right = newNode(3);

    printf("%d", identical(a, b));
    return 0;
}