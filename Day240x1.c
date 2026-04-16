#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int **adj, int *vis, int *rec, int n){
    vis[v]=1; rec[v]=1;
    for(int i=0;i<n;i++){
        if(adj[v][i]){
            if(!vis[i] && dfs(i,adj,vis,rec,n)) return 1;
            else if(rec[i]) return 1;
        }
    }
    rec[v]=0;
    return 0;
}

int canFinish(int n,int **pre,int m){
    int **adj=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) adj[i]=(int*)calloc(n,sizeof(int));

    for(int i=0;i<m;i++) adj[pre[i][1]][pre[i][0]]=1;

    int *vis=(int*)calloc(n,sizeof(int));
    int *rec=(int*)calloc(n,sizeof(int));

    for(int i=0;i<n;i++)
        if(!vis[i] && dfs(i,adj,vis,rec,n)) return 0;

    return 1;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int **pre=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        pre[i]=(int*)malloc(2*sizeof(int));
        scanf("%d%d",&pre[i][0],&pre[i][1]);
    }
    printf(canFinish(n,pre,m)?"true":"false");
}