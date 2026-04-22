#include <stdio.h>

int parent[201];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py)
        parent[py] = px;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1)
                unite(i, j);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (parent[i] == i)
            count++;
    }

    printf("%d", count);

    return 0;
}