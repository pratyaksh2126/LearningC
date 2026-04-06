#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int v){
    struct TreeNode* n=malloc(sizeof(struct TreeNode));
    n->val=v; n->left=n->right=NULL;
    return n;
}

struct TreeNode* build(int a[],int n){
    if(n==0||a[0]==-1) return NULL;
    struct TreeNode** q=malloc(n*sizeof(struct TreeNode*));
    int f=0,r=0,i=1;
    struct TreeNode* root=newNode(a[0]);
    q[r++]=root;
    while(i<n){
        struct TreeNode* c=q[f++];
        if(a[i]!=-1){ c->left=newNode(a[i]); q[r++]=c->left; } i++;
        if(i<n && a[i]!=-1){ c->right=newNode(a[i]); q[r++]=c->right; } i++;
    }
    return root;
}

int main(){
    int n; scanf("%d",&n);
    int* a=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct TreeNode* root=build(a,n);
    if(!root){ printf("YES"); return 0; }

    struct TreeNode** q=malloc(2000*sizeof(struct TreeNode*));
    int f=0,r=0;
    q[r++]=root->left;
    q[r++]=root->right;

    while(f<r){
        struct TreeNode* x=q[f++];
        struct TreeNode* y=q[f++];
        if(!x && !y) continue;
        if(!x || !y || x->val!=y->val){ printf("NO"); return 0; }
        q[r++]=x->left; q[r++]=y->right;
        q[r++]=x->right; q[r++]=y->left;
    }
    printf("YES");
}