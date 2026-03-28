#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Queue {
    struct TreeNode* arr[100];
    int front, rear;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[++q->front];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) return 0;
    struct Queue q;
    q.front = q.rear = -1;
    enqueue(&q, root);
    int sum = 0;

    while (!isEmpty(&q)) {
        struct TreeNode* temp = dequeue(&q);

        if (temp->left) {
            if (!temp->left->left && !temp->left->right)
                sum += temp->left->val;
            enqueue(&q, temp->left);
        }

        if (temp->right)
            enqueue(&q, temp->right);
    }
    return sum;
}

int main() {
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("%d", sumOfLeftLeaves(root));
    return 0;
}