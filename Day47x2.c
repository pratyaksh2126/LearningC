#include <stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if(rear == MAX-1) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = val;
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front++]);
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for(int i=front; i<=rear; i++) printf("%d\n", queue[i]);
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}

