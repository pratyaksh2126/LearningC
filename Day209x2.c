#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int t1=-1, t2=-1;

void enqueue(int x){
    s1[++t1]=x;
}

int dequeue(){
    if(t2==-1){
        while(t1!=-1){
            s2[++t2]=s1[t1--];
        }
    }
    return s2[t2--];
}

int front(){
    if(t2==-1){
        while(t1!=-1){
            s2[++t2]=s1[t1--];
        }
    }
    return s2[t2];
}

int main(){
    enqueue(10);
    enqueue(20);
    printf("%d\n",front());
    printf("%d\n",dequeue());
    return 0;
}