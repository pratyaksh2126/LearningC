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

void zigzag(struct Node* root){
    struct Node* dq[2000];
    int f=1000,r=1000,dir=1;
    dq[r++]=root;

    while(f<r){
        int size=r-f;
        while(size--){
            if(dir){
                struct Node* cur=dq[f++];
                printf("%d ",cur->val);
                if(cur->left) dq[r++]=cur->left;
                if(cur->right) dq[r++]=cur->right;
            } else {
                struct Node* cur=dq[--r];
                printf("%d ",cur->val);
                if(cur->right) dq[--f]=cur->right;
                if(cur->left) dq[--f]=cur->left;
            }
        }
        dir=!dir;
    }
}

int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    struct Node* root=build(a,n);
    zigzag(root);
}