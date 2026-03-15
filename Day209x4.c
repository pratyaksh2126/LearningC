#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int a=-1,b=-1;

void push(int x){
    s1[++a]=x;
}

int pop(){
    if(b==-1){
        while(a!=-1){
            s2[++b]=s1[a--];
        }
    }
    return s2[b--];
}

int peek(){
    if(b==-1){
        while(a!=-1){
            s2[++b]=s1[a--];
        }
    }
    return s2[b];
}

int main(){
    push(3);
    push(6);
    push(9);
    printf("%d\n",peek());
    printf("%d\n",pop());
    return 0;
}