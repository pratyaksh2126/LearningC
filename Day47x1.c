#include <stdio.h>
#define MAX 10
int stack[MAX], top = -1;

void push(int val) {
    if(top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for(int i=top; i>=0; i--) printf("%d\n", stack[i]);
}

int main() {
    push(10); push(20); push(30);
    display();
    pop();
    display();
    return 0;
}
