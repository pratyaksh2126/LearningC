#include <stdio.h>

#define MAX 10000

int heap[MAX], size = 0, k;

void swap(int *a, int *b){int t=*a;*a=*b;*b=t;}

void up(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]>heap[i]){swap(&heap[p],&heap[i]);i=p;}
        else break;
    }
}

void down(int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<size && heap[l]<heap[s]) s=l;
        if(r<size && heap[r]<heap[s]) s=r;
        if(s!=i){swap(&heap[i],&heap[s]);i=s;}
        else break;
    }
}

void insert(int x){
    heap[size++]=x;
    up(size-1);
    if(size>k){
        heap[0]=heap[size-1];
        size--;
        down(0);
    }
}

int main(){
    int n,q,x;
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++){scanf("%d",&x);insert(x);}
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        insert(x);
        printf("%d\n",heap[0]);
    }
}