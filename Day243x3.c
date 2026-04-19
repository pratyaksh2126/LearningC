#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 101
#define INF 1000000000

typedef struct {
    int v, dist;
} Node;

typedef struct {
    Node arr[10000];
    int size;
} Heap;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void push(Heap *h, int v, int d) {
    int i = h->size++;
    h->arr[i].v = v;
    h->arr[i].dist = d;

    while (i && h->arr[(i-1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

Node pop(Heap *h) {
    Node root = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, s = i;

        if (l < h->size && h->arr[l].dist < h->arr[s].dist) s = l;
        if (r < h->size && h->arr[r].dist < h->arr[s].dist) s = r;

        if (s != i) {
            swap(&h->arr[i], &h->arr[s]);
            i = s;
        } else break;
    }

    return root;
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    scanf("%d", &k);

    int d[MAX];
    for (int i = 1; i <= n; i++) d[i] = INF;

    Heap h;
    h.size = 0;

    d[k] = 0;
    push(&h, k, 0);

    while (h.size) {
        Node cur = pop(&h);
        int u = cur.v;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && d[u] + graph[u][v] < d[v]) {
                d[v] = d[u] + graph[u][v];
                push(&h, v, d[v]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            printf("-1");
            return 0;
        }
        if (d[i] > ans) ans = d[i];
    }

    printf("%d", ans);
    return 0;
}