#include <stdio.h>

int arr[50000], n=0;

void add(int x){
    int i=n-1;
    while(i>=0 && arr[i]>x){
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=x;
    n++;
}

double median(){
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