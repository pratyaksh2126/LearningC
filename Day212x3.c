#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val, idx;
}Node;

void swap(Node *a, Node *b){
    Node t=*a; *a=*b; *b=t;
}

void heapifyUp(Node heap[], int i){
    while(i>0 && heap[(i-1)/2].val<heap[i].val){
        swap(&heap[i], &heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

void heapifyDown(Node heap[], int n, int i){
    int largest=i;
    int l=2*i+1, r=2*i+2;

    if(l<n && heap[l].val>heap[largest].val) largest=l;
    if(r<n && heap[r].val>heap[largest].val) largest=r;

    if(largest!=i){
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap,n,largest);
    }
}

int main(){
    int n,k;
    scanf("%d",&n);
    int *nums=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&nums[i]);
    scanf("%d",&k);

    Node *heap=malloc(n*sizeof(Node));
    int size=0;

    for(int i=0;i<n;i++){
        heap[size].val=nums[i];
        heap[size].idx=i;
        heapifyUp(heap,size);
        size++;

        while(size>0 && heap[0].idx<=i-k){
            heap[0]=heap[size-1];
            size--;
            heapifyDown(heap,size,0);
        }

        if(i>=k-1){
            printf("%d ",heap[0].val);
        }
    }

    free(nums);
    free(heap);
}