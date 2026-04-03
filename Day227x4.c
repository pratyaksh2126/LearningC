#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = malloc(sizeof(struct Node));
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

void zigzag(struct Node* root) {
    if (!root) return;

    struct Node* q[2000];
    int f = 0, r = 0;
    int leftToRight = 1;

    q[r++] = root;

    while (f < r) {
        int size = r - f;
        int arr[2000];

        for (int i = 0; i < size; i++) {
            struct Node* node = q[f++];

            int index = leftToRight ? i : size - i - 1;
            arr[index] = node->val;

            if (node->left) q[r++] = node->left;
            if (node->right) q[r++] = node->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");

        leftToRight = !leftToRight;
    }
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = build(arr, n);
    zigzag(root);
}