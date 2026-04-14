#include <stdio.h>

#define MAX 10

int orangesRotting(int grid[MAX][MAX], int m, int n){
    int q[100][3], front=0, rear=0;
    int fresh=0, ans=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q[rear][0]=i;
                q[rear][1]=j;
                q[rear][2]=0;
                rear++;
            }
            else if(grid[i][j]==1) fresh++;
        }
    }

    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    while(front<rear){
        int x=q[front][0], y=q[front][1], t=q[front][2];
        front++;
        if(t>ans) ans=t;

        for(int i=0;i<4;i++){
            int nx=x+d[i][0], ny=y+d[i][1];
            if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]==1){
                grid[nx][ny]=2;
                q[rear][0]=nx;
                q[rear][1]=ny;
                q[rear][2]=t+1;
                rear++;
                fresh--;
            }
        }
    }

    if(fresh>0) return -1;
    return ans;
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