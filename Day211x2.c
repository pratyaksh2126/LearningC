#include <stdio.h>

#define MAX 10000

int arr[MAX], size=0, k;

void sort(){
    for(int i=0;i<size-1;i++)
        for(int j=0;j<size-i-1;j++)
            if(arr[j]<arr[j+1]){
                int t=arr[j];arr[j]=arr[j+1];arr[j+1]=t;
            }
}

int main(){
    int n,q,x;
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++){scanf("%d",&x);arr[size++]=x;}
    sort();
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        arr[size++]=x;
        sort();
        if(size>=k) printf("%d\n",arr[k-1]);
        else printf("-1\n");
    }
}