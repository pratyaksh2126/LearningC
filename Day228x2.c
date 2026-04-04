#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = v; n->left = n->right = NULL;
    return n;
}

struct Node* build(int a[], int n) {
    if(n==0) return NULL;
    struct Node** q = malloc(n*sizeof(struct Node*));
    int f=0,r=0,i=1;
    struct Node* root=newNode(a[0]);
    q[r++]=root;
    while(i<n){
        struct Node* cur=q[f++];
        if(a[i]!=-1){cur->left=newNode(a[i]);q[r++]=cur->left;} i++;
        if(i<n && a[i]!=-1){cur->right=newNode(a[i]);q[r++]=cur->right;} i++;
    }
    return root;
}

void zigzag(struct Node* root){
    struct Node* q[2000];
    int f=0,r=0,rev=0;
    q[r++]=root;
    while(f<r){
        int size=r-f;
        int arr[2000];
        for(int i=0;i<size;i++){
            struct Node* cur=q[f++];
            arr[i]=cur->val;
            if(cur->left) q[r++]=cur->left;
            if(cur->right) q[r++]=cur->right;
        }
        if(rev){
            for(int i=size-1;i>=0;i--) printf("%d ",arr[i]);
        } else {
            for(int i=0;i<size;i++) printf("%d ",arr[i]);
        }
        rev=!rev;
    }
}

int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    struct Node* root=build(a,n);
    zigzag(root);
}