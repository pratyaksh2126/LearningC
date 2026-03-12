#include <stdio.h>
#define MAX 100

int stack[MAX];
int minStack[MAX];
int top = -1;

void push(int val){
    top++;
    stack[top] = val;
    if(top==0 || val<=minStack[top-1])
        minStack[top] = val;
    else
        minStack[top] = minStack[top-1];
}

void pop(){
    if(top>=0) top--;
}

int topElement(){
    return stack[top];
}

int getMin(){
    return minStack[top];
}

int main(){
    push(-2);
    push(0);
    push(-3);

    printf("%d\n",getMin());
    pop();
    printf("%d\n",topElement());
    printf("%d\n",getMin());
}