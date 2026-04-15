#include <stdio.h>
#include <stdlib.h>

int find(int parent[], int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py)
        return;

    if (rank[px] < rank[py])
        parent[px] = py;
    else if (rank[px] > rank[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rank[px]++;
    }
}

int main() {
    int V, E;
    scanf("%d%d", &V, &E);

    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int cycle = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        if (find(parent, u) == find(parent, v))
            cycle = 1;
        else
            unionSet(parent, rank, u, v);
    }

    printf(cycle ? "YES\n" : "NO\n");
    return 0;
}