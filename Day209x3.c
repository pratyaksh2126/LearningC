#include <stdio.h>
#define MAX 50

int s1[MAX], s2[MAX];
int topA=-1, topB=-1;

void pushA(int x){
    s1[++topA]=x;
}

void transfer(){
    while(topA!=-1){
        s2[++topB]=s1[topA--];
    }
}

int removeQ(){
    if(topB==-1) transfer();
    return s2[topB--];
}

int peekQ(){
    if(topB==-1) transfer();
    return s2[topB];
}

int main(){
    pushA(5);
    pushA(15);
    pushA(25);
    printf("%d\n",peekQ());
    printf("%d\n",removeQ());
    return 0;
}