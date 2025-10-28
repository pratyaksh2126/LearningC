#include <stdio.h>
#define MAX 5
int queue[MAX], front=-1, rear=-1;

void enqueue(int val) {
    if((front == 0 && rear == MAX-1) || (rear == (front-1)%(MAX-1))) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) front = rear = 0;
    else if(rear == MAX -1 && front != 0) rear = 0;
    else rear++;
    queue[rear] = val;
}

void dequeue() {
    if(front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    if(front == rear) front = rear = -1;
    else if(front == MAX -1) front = 0;
    else front++;
}

void display() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    int i = front;
    while(1) {
        printf("%d\n", queue[i]);
        if(i == rear) break;
        i = (i+1)%MAX;
    }
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
