#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *stack;
    int *minstack;
    int top;
    int size;
}MinStack;

MinStack* create(int n){
    MinStack* s=(MinStack*)malloc(sizeof(MinStack));
    s->stack=(int*)malloc(n*sizeof(int));
    s->minstack=(int*)malloc(n*sizeof(int));
    s->top=-1;
    s->size=n;
    return s;
}

void push(MinStack* s,int val){
    s->top++;
    s->stack[s->top]=val;

    if(s->top==0 || val<=s->minstack[s->top-1])
        s->minstack[s->top]=val;
    else
        s->minstack[s->top]=s->minstack[s->top-1];
}

void pop(MinStack* s){
    if(s->top>=0)
        s->top--;
}

int topElement(MinStack* s){
    return s->stack[s->top];
}

int getMin(MinStack* s){
    return s->minstack[s->top];
}

int main(){
    MinStack* s=create(100);

    push(s,-2);
    push(s,0);
    push(s,-3);

    printf("%d\n",getMin(s));

    pop(s);

    printf("%d\n",topElement(s));
    printf("%d\n",getMin(s));
}