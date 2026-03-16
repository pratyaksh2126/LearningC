#include <stdio.h>
#define MAX 50

int arr[MAX];
int f=-1,r=-1,n=3,count=0;

int full(){ return count==n; }
int empty(){ return count==0; }

void insertFront(int x){
    if(full()) return;
    if(empty()) f=r=0;
    else f=(f-1+n)%n;
    arr[f]=x;
    count++;
}

void insertRear(int x){
    if(full()) return;
    if(empty()) f=r=0;
    else r=(r+1)%n;
    arr[r]=x;
    count++;
}

void deleteFront(){
    if(empty()) return;
    if(f==r) f=r=-1;
    else f=(f+1)%n;
    count--;
}

void deleteRear(){
    if(empty()) return;
    if(f==r) f=r=-1;
    else r=(r-1+n)%n;
    count--;
}

int main(){
    insertRear(10);
    insertRear(20);
    insertFront(5);
    printf("%d\n",arr[f]);
    printf("%d\n",arr[r]);
    return 0;
}