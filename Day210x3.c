#include <stdio.h>

int dq[10];
int front=-1,rear=-1,cap=5,size=0;

void insertF(int x){
    if(size==cap) return;
    if(size==0) front=rear=0;
    else front=(front-1+cap)%cap;
    dq[front]=x;
    size++;
}

void insertR(int x){
    if(size==cap) return;
    if(size==0) front=rear=0;
    else rear=(rear+1)%cap;
    dq[rear]=x;
    size++;
}

void deleteF(){
    if(size==0) return;
    if(front==rear) front=rear=-1;
    else front=(front+1)%cap;
    size--;
}

void deleteR(){
    if(size==0) return;
    if(front==rear) front=rear=-1;
    else rear=(rear-1+cap)%cap;
    size--;
}

int main(){
    insertR(1);
    insertR(2);
    insertF(3);
    deleteR();
    printf("%d\n",dq[front]);
    return 0;
}