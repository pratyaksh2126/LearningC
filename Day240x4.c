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

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    struct Node** adj=(struct Node**)calloc(n,sizeof(struct Node*));
    int *indegree=(int*)calloc(n,sizeof(int));

    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        addEdge(adj,b,a);
        indegree[a]++;
    }

    int *q=(int*)malloc(n*sizeof(int));
    int f=0,r=0;

    for(int i=0;i<n;i++)
        if(indegree[i]==0) q[r++]=i;

    int count=0;

    while(f<r){
        int v=q[f++];
        count++;
        struct Node* temp=adj[v];
        while(temp){
            indegree[temp->v]--;
            if(indegree[temp->v]==0)
                q[r++]=temp->v;
            temp=temp->next;
        }
    }

    if(count==n) printf("true");
    else printf("false");
}