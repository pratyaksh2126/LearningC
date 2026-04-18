#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

int queue[MAX], front, rear;

void enqueue(int x){ queue[++rear]=x; }
int dequeue(){ return queue[front++]; }
int empty(){ return front>rear; }

int main(){
    int n;
    scanf("%d",&n);
    char w[500][101];
    for(int i=0;i<n;i++) scanf("%s",w[i]);

    int indeg[MAX]={0}, present[MAX]={0};
    int *adj[MAX];
    int size[MAX]={0};

    for(int i=0;i<MAX;i++) adj[i]=(int*)malloc(MAX*sizeof(int));

    for(int i=0;i<n;i++)
        for(int j=0;w[i][j];j++)
            present[w[i][j]-'a']=1;

    for(int i=0;i<n-1;i++){
        int j=0;
        while(w[i][j] && w[i+1][j] && w[i][j]==w[i+1][j]) j++;
        if(w[i][j] && w[i+1][j]){
            int u=w[i][j]-'a', v=w[i+1][j]-'a';
            adj[u][size[u]++]=v;
            indeg[v]++;
        } else if(w[i][j] && !w[i+1][j]) return 0;
    }

    front=0; rear=-1;
    for(int i=0;i<MAX;i++) if(present[i] && indeg[i]==0) enqueue(i);

    char res[MAX]; int k=0;

    while(!empty()){
        int u=dequeue();
        res[k++]=u+'a';
        for(int i=0;i<size[u];i++){
            int v=adj[u][i];
            indeg[v]--;
            if(indeg[v]==0) enqueue(v);
        }
    }

    res[k]='\0';
    printf("%s",res);
}