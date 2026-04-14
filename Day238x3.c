#include <stdio.h>

#define MAX 10

int orangesRotting(int grid[MAX][MAX], int m, int n){
    int vis[MAX][MAX]={0};
    int q[100][2], front=0,rear=0,fresh=0,time=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q[rear][0]=i; q[rear][1]=j; rear++;
                vis[i][j]=1;
            }
            else if(grid[i][j]==1) fresh++;
        }
    }

    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    while(front<rear && fresh>0){
        int size=rear-front;
        for(int k=0;k<size;k++){
            int x=q[front][0], y=q[front][1]; front++;
            for(int i=0;i<4;i++){
                int nx=x+d[i][0], ny=y+d[i][1];
                if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]==1&&vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    grid[nx][ny]=2;
                    q[rear][0]=nx; q[rear][1]=ny; rear++;
                    fresh--;
                }
            }
        }
        time++;
    }

    if(fresh>0) return -1;
    return time;
}

int main(){
    int m,n,grid[MAX][MAX];
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&grid[i][j]);
    printf("%d",orangesRotting(grid,m,n));
    return 0;
}