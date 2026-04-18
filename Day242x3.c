#include <stdio.h>
#include <string.h>

#define MAX 26

int adj[MAX][MAX], vis[MAX], stack[MAX], top=-1, present[MAX];

void dfs(int u){
    vis[u]=1;
    for(int v=0;v<MAX;v++){
        if(adj[u][v] && !vis[v])
            dfs(v);
    }
    stack[++top]=u;
}

int main(){
    int n;
    scanf("%d",&n);
    char w[500][101];
    for(int i=0;i<n;i++) scanf("%s",w[i]);

    for(int i=0;i<n;i++)
        for(int j=0;w[i][j];j++)
            present[w[i][j]-'a']=1;

    for(int i=0;i<n-1;i++){
        int j=0;
        while(w[i][j] && w[i+1][j] && w[i][j]==w[i+1][j]) j++;
        if(w[i][j] && w[i+1][j])
            adj[w[i][j]-'a'][w[i+1][j]-'a']=1;
    }

    for(int i=0;i<MAX;i++)
        if(present[i] && !vis[i])
            dfs(i);

    while(top>=0)
        printf("%c",stack[top--]+'a');
}