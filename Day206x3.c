#include <stdio.h>

#define MAX 100

int stack[MAX],minstack[MAX];
int top=-1,mintop=-1;

void push(int x){
    stack[++top]=x;

    if(mintop==-1 || x<=minstack[mintop])
        minstack[++mintop]=x;
}

void pop(){
    if(stack[top]==minstack[mintop])
        mintop--;
    top--;
}

int topElement(){
    return stack[top];
}

int getMin(){
    return minstack[mintop];
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