#include <stdio.h>
#include <stdlib.h>

#define N 50000

int maxH[N], minH[N], maxS=0, minS=0;

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

void maxUp(int i){while(i&&maxH[(i-1)/2]<maxH[i]){swap(&maxH[i],&maxH[(i-1)/2]);i=(i-1)/2;}}
void maxDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,largest=i;
        if(l<maxS && maxH[l]>maxH[largest]) largest=l;
        if(r<maxS && maxH[r]>maxH[largest]) largest=r;
        if(largest==i) break;
        swap(&maxH[i],&maxH[largest]); i=largest;
    }
}

void minUp(int i){while(i&&minH[(i-1)/2]>minH[i]){swap(&minH[i],&minH[(i-1)/2]);i=(i-1)/2;}}
void minDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;
        if(l<minS && minH[l]<minH[small]) small=l;
        if(r<minS && minH[r]<minH[small]) small=r;
        if(small==i) break;
        swap(&minH[i],&minH[small]); i=small;
    }
}

void add(int x){
    if(maxS==0||x<=maxH[0]){maxH[maxS++]=x;maxUp(maxS-1);}
    else{minH[minS++]=x;minUp(minS-1);}

    if(maxS>minS+1){
        int v=maxH[0]; maxH[0]=maxH[--maxS]; maxDown(0);
        minH[minS++]=v; minUp(minS-1);
    }else if(minS>maxS){
        int v=minH[0]; minH[0]=minH[--minS]; minDown(0);
        maxH[maxS++]=v; maxUp(maxS-1);
    }
}

double median(){
    if(maxS>minS) return maxH[0];
    return (maxH[0]+minH[0])/2.0;
}

int main(){
    int n,x; scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        add(x);
        printf("%.1f\n",median());
    }
}