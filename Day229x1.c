#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = val; t->left = t->right = NULL;
    return t;
}

Node* build(int a[], int n) {
    if (n==0 || a[0]==-1) return NULL;
    Node** q = malloc(n*sizeof(Node*));
    int f=0,r=0,i=1;
    Node* root = newNode(a[0]);
    q[r++]=root;
    while(i<n){
        Node* cur=q[f++];
        if(i<n && a[i]!=-1){cur->left=newNode(a[i]); q[r++]=cur->left;} i++;
        if(i<n && a[i]!=-1){cur->right=newNode(a[i]); q[r++]=cur->right;} i++;
    }
    return root;
}

void dfs(Node* root,int lvl,int* max){
    if(!root) return;
    if(lvl>*max){printf("%d ",root->data); *max=lvl;}
    dfs(root->right,lvl+1,max);
    dfs(root->left,lvl+1,max);
}

int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    Node* root=build(a,n);
    int max=-1;
    dfs(root,0,&max);
}