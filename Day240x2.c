#include <stdio.h>
#include <stdlib.h>

struct Node{
    int v;
    struct Node* next;
};

void addEdge(struct Node** adj,int u,int v){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->v=v;
    temp->next=adj[u];
    adj[u]=temp;
}

int dfs(int v,struct Node** adj,int *vis,int *rec){
    vis[v]=1; rec[v]=1;
    struct Node* temp=adj[v];
    while(temp){
        int u=temp->v;
        if(!vis[u] && dfs(u,adj,vis,rec)) return 1;
        else if(rec[u]) return 1;
        temp=temp->next;
    }
    rec[v]=0;
    return 0;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    struct Node** adj=(struct Node**)calloc(n,sizeof(struct Node*));

    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        addEdge(adj,b,a);
    }

    int *vis=(int*)calloc(n,sizeof(int));
    int *rec=(int*)calloc(n,sizeof(int));

    for(int i=0;i<n;i++){
        if(!vis[i] && dfs(i,adj,vis,rec)){
            printf("false");
            return 0;
        }
    }
    printf("true");
}