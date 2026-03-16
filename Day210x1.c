#include <stdio.h>
#define MAX 100

int dq[MAX];
int front=-1,rear=-1,size=0,k;

int isFull(){ return size==k; }
int isEmpty(){ return size==0; }

int insertFront(int x){
    if(isFull()) return 0;
    if(isEmpty()) front=rear=0;
    else front=(front-1+k)%k;
    dq[front]=x;
    size++;
    return 1;
}

int insertLast(int x){
    if(isFull()) return 0;
    if(isEmpty()) front=rear=0;
    else rear=(rear+1)%k;
    dq[rear]=x;
    size++;
    return 1;
}

int deleteFront(){
    if(isEmpty()) return 0;
    if(front==rear) front=rear=-1;
    else front=(front+1)%k;
    size--;
    return 1;
}

int deleteLast(){
    if(isEmpty()) return 0;
    if(front==rear) front=rear=-1;
    else rear=(rear-1+k)%k;
    size--;
    return 1;
}

int getFront(){ if(isEmpty()) return -1; return dq[front]; }
int getRear(){ if(isEmpty()) return -1; return dq[rear]; }

int main(){
    k=3;
    insertLast(1);
    insertLast(2);
    insertFront(3);
    printf("%d\n",getRear());
    printf("%d\n",getFront());
    return 0;
}