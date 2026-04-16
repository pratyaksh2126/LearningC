#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int **adj=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) adj[i]=(int*)calloc(n,sizeof(int));

    int *indegree=(int*)calloc(n,sizeof(int));

    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[b][a]=1;
        indegree[a]++;
    }

    int *queue=(int*)malloc(n*sizeof(int));
    int front=0,rear=0;

    for(int i=0;i<n;i++)
        if(indegree[i]==0) queue[rear++]=i;

    int count=0;

    while(front<rear){
        int v=queue[front++];
        count++;
        for(int i=0;i<n;i++){
            if(adj[v][i]){
                indegree[i]--;
                if(indegree[i]==0) queue[rear++]=i;
            }
        }
    }

    if(count==n) printf("true");
    else printf("false");
}