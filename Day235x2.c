#include <stdio.h>
#include <stdlib.h>

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

    int vis[200] = {0}, count = 0;

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            int q[200], front = 0, rear = 0;
            q[rear++] = i;
            vis[i] = 1;

            while(front < rear)
            {
                int u = q[front++];
                for(int v = 0; v < n; v++)
                    if(a[u][v] && !vis[v])
                    {
                        vis[v] = 1;
                        q[rear++] = v;
                    }
            }
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}