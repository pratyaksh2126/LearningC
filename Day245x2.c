#include <stdio.h>
#include <limits.h>

#define MAX 15

int n, cost[MAX][MAX];
int visited[MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int pos, int count) {
    if(count == n && cost[pos][0]) return cost[pos][0];

    int ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && cost[pos][i]) {
            visited[i] = 1;
            int val = cost[pos][i] + tsp(i, count + 1);
            ans = min(ans, val);
            visited[i] = 0;
        }
    }

    return ans;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for(int i = 0; i < n; i++) visited[i] = 0;

    visited[0] = 1;

    printf("%d\n", tsp(0, 1));
    return 0;
}