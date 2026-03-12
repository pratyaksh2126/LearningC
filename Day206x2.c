#include <stdio.h>

#define MAX 100

typedef struct{
    int stack[MAX];
    int minStack[MAX];
    int top;
}MinStack;

void push(MinStack *s,int val){
    s->top++;
    s->stack[s->top]=val;

    if(s->top==0 || val<=s->minStack[s->top-1])
        s->minStack[s->top]=val;
    else
        s->minStack[s->top]=s->minStack[s->top-1];
}

void pop(MinStack *s){
    if(s->top>=0)
        s->top--;
}

int topElement(MinStack *s){
    return s->stack[s->top];
}

int getMin(MinStack *s){
    return s->minStack[s->top];
}

int main(){
    MinStack s;
    s.top=-1;

    push(&s,-2);
    push(&s,0);
    push(&s,-3);

    printf("%d\n",getMin(&s));
    pop(&s);
    printf("%d\n",topElement(&s));
    printf("%d\n",getMin(&s));
}