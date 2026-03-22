#include <stdio.h>

int freq[101], total=0;

void add(int x){
    freq[x]++;
    total++;
}

double median(){
    int count=0;
    int m1=(total+1)/2, m2=(total%2?m1:m1+1);
    int a=0,b=0;

    for(int i=0;i<=100;i++){
        count+=freq[i];
        if(count>=m1 && a==0) a=i;
        if(count>=m2){ b=i; break; }
    }
    return (a+b)/2.0;
}

int main(){
    int n,x; scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        add(x);
        printf("%.1f\n",median());
    }
}