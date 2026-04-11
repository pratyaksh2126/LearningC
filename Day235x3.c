#include <stdio.h>
#include <stdlib.h>

int find(int parent[], int x)
{
    if(parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(int parent[], int x, int y)
{
    int px = find(parent, x);
    int py = find(parent, y);
    if(px != py)
        parent[py] = px;
}

int main()
{
    int n;
    scanf("%d", &n);

    int **a = malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
        a[i] = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int parent[200];
    for(int i = 0; i < n; i++)
        parent[i] = i;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j])
                unite(parent, i, j);

    int count = 0;
    for(int i = 0; i < n; i++)
        if(find(parent, i) == i)
            count++;

    printf("%d\n", count);
    return 0;
}