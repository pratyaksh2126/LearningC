#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct QNode {
    struct Node* treeNode;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QNode* temp = malloc(sizeof(struct QNode));
    temp->treeNode = node;
    temp->next = NULL;

    if (!q->rear) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (!q->front) return NULL;

    struct QNode* temp = q->front;
    struct Node* node = temp->treeNode;

    q->front = q->front->next;
    if (!q->front) q->rear = NULL;

    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

struct Node* build(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);

    int i = 1;

    while (i < n) {
        struct Node* cur = dequeue(q);

        if (i < n && arr[i] != -1) {
            cur->left = newNode(arr[i]);
            enqueue(q, cur->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = newNode(arr[i]);
            enqueue(q, cur->right);
        }
        i++;
    }
    return root;
}

void levelOrder(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int size = 0;
        struct QNode* temp = q->front;
        while (temp) {
            size++;
            temp = temp->next;
        }

        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue(q);
            printf("%d ", node->val);

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        printf("\n");
    }
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = build(arr, n);
    levelOrder(root);
}