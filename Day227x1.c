#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* build(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[n];
    int f = 0, r = 0, i = 1;

    q[r++] = root;

    while (i < n) {
        struct Node* cur = q[f++];

        if (i < n && arr[i] != -1) {
            cur->left = newNode(arr[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = newNode(arr[i]);
            q[r++] = cur->right;
        }
        i++;
    }
    return root;
}

void levelOrder(struct Node* root) {
    if (!root) return;

    struct Node* q[2000];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r) {
        int size = r - f;

        for (int i = 0; i < size; i++) {
            struct Node* temp = q[f++];
            printf("%d ", temp->val);

            if (temp->left) q[r++] = temp->left;
            if (temp->right) q[r++] = temp->right;
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