#include <stdio.h>

#define MAX 10000

int heap[MAX], size=0, k;

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

void up(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<heap[i]){swap(&heap[p],&heap[i]);i=p;}
        else break;
    }
}

void down(int i){
    while(1){
        int l=2*i+1,r=2*i+2,largest=i;
        if(l<size && heap[l]>heap[largest]) largest=l;
        if(r<size && heap[r]>heap[largest]) largest=r;
        if(largest!=i){swap(&heap[i],&heap[largest]);i=largest;}
        else break;
    }
}

void insert(int x){
    heap[size++]=x;
    up(size-1);
}

int kth(){
    int temp[MAX], tsize=size;
    for(int i=0;i<size;i++) temp[i]=heap[i];

    for(int i=1;i<k;i++){
        temp[0]=temp[--tsize];
        int j=0;
        while(1){
            int l=2*j+1,r=2*j+2,largest=j;
            if(l<tsize && temp[l]>temp[largest]) largest=l;
            if(r<tsize && temp[r]>temp[largest]) largest=r;
            if(largest!=j){
                int t=temp[j];temp[j]=temp[largest];temp[largest]=t;
                j=largest;
            } else break;
        }
    }
    return temp[0];
}

int main(){
    int n,q,x;
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++){scanf("%d",&x);insert(x);}
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        insert(x);
        if(size>=k) printf("%d\n",kth());
        else printf("-1\n");
    }
}