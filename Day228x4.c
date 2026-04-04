#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *left,*right;
};

struct Node* newNode(int v){
    struct Node* n=malloc(sizeof(struct Node));
    n->val=v; n->left=n->right=NULL;
    return n;
}

struct Node* build(int a[],int n){
    if(n==0) return NULL;
    struct Node** q=malloc(n*sizeof(struct Node*));
    int f=0,r=0,i=1;
    struct Node* root=newNode(a[0]);
    q[r++]=root;
    while(i<n){
        struct Node* c=q[f++];
        if(a[i]!=-1){c->left=newNode(a[i]);q[r++]=c->left;} i++;
        if(i<n && a[i]!=-1){c->right=newNode(a[i]);q[r++]=c->right;} i++;
    }
    return root;
}

int res[2000][2000],col[2000];

void dfs(struct Node* root,int level){
    if(!root) return;
    if(level%2==0){
        res[level][col[level]++]=root->val;
    } else {
        for(int i=col[level];i>0;i--) res[level][i]=res[level][i-1];
        res[level][0]=root->val;
        col[level]++;
    }
    dfs(root->left,level+1);
    dfs(root->right,level+1);
}

void print(struct Node* root){
    dfs(root,0);
    for(int i=0;i<2000 && col[i];i++){
        for(int j=0;j<col[i];j++) printf("%d ",res[i][j]);
    }
}

int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    struct Node* root=build(a,n);
    print(root);
}