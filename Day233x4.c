#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node *l, *r;
};

struct Node* newNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v;
    n->l = n->r = NULL;
    return n;
}

int f(int a[], int s, int e, int x) {
    while (s <= e) {
        if (a[s] == x) return s;
        s++;
    }
    return -1;
}

struct Node* b(int in[], int post[], int s, int e, int *pi) {
    if (s > e) return NULL;

    struct Node* n = newNode(post[(*pi)--]);

    if (s == e) return n;

    int i = f(in, s, e, n->v);

    n->r = b(in, post, i + 1, e, pi);
    n->l = b(in, post, s, i - 1, pi);

    return n;
}

void p(struct Node* r) {
    if (!r) return;
    printf("%d ", r->v);
    p(r->l);
    p(r->r);
}

int main() {
    int n;
    scanf("%d", &n);

    int in[n], post[n];

    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int pi = n - 1;

    struct Node* root = b(in, post, 0, n - 1, &pi);

    p(root);
    return 0;
}