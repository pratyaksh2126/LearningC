#include <stdio.h>

int arr[50000], n=0;

void add(int x){
    arr[n++]=x;
}

void sort(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int t=arr[i]; arr[i]=arr[j]; arr[j]=t;
            }
        }
    }
}

double median(){
    sort();
    if(n%2) return arr[n/2];
    return (arr[n/2-1]+arr[n/2])/2.0;
}

int main(){
    int m,x; scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        add(x);
        printf("%.1f\n",median());
    }
}