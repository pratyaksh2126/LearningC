#include <stdio.h>

int visited[201];

void dfs(int city, int n, int a[n][n]) {
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (a[city][i] == 1 && !visited[i])
            dfs(i, n, a);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, a);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}