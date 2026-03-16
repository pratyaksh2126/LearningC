#include <stdio.h>

int arr[100];
int front=-1,rear=-1,limit=4,c=0;

void pushFront(int x){
    if(c==limit) return;
    if(c==0) front=rear=0;
    else front=(front-1+limit)%limit;
    arr[front]=x;
    c++;
}

void pushRear(int x){
    if(c==limit) return;
    if(c==0) front=rear=0;
    else rear=(rear+1)%limit;
    arr[rear]=x;
    c++;
}

void popFront(){
    if(c==0) return;
    if(front==rear) front=rear=-1;
    else front=(front+1)%limit;
    c--;
}

void popRear(){
    if(c==0) return;
    if(front==rear) front=rear=-1;
    else rear=(rear-1+limit)%limit;
    c--;
}

int main(){
    pushRear(7);
    pushRear(8);
    pushFront(6);
    popFront();
    printf("%d\n",arr[rear]);
    return 0;
}