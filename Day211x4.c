#include <stdio.h>

#define MAX 10000

int arr[MAX], size=0, k;

int kth(){
    int temp[MAX];
    for(int i=0;i<size;i++) temp[i]=arr[i];

    for(int i=0;i<k;i++){
        int max=i;
        for(int j=i+1;j<size;j++)
            if(temp[j]>temp[max]) max=j;

        int t=temp[i];temp[i]=temp[max];temp[max]=t;
    }
    return temp[k-1];
}

int main(){
    int n,q,x;
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++){scanf("%d",&x);arr[size++]=x;}
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        arr[size++]=x;
        if(size>=k) printf("%d\n",kth());
        else printf("-1\n");
    }
}