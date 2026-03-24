#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* build(int a[], int n, int i) {
    if (i >= n || a[i] == -1) return NULL;
    struct Node* r = createNode(a[i]);
    r->left = build(a, n, 2*i+1);
    r->right = build(a, n, 2*i+2);
    return r;
}

int main() {
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,n,0);

    struct Node* cur = root;

    while (cur) {
        if (!cur->left) {
            printf("%d ", cur->val);
            cur = cur->right;
        } else {
            struct Node* pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;

            if (!pre->right) {
                printf("%d ", cur->val);
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = NULL;
                cur = cur->right;
            }
        }
    }

    return 0;
}