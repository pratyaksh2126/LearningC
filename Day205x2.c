#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

bool isValid(char s[]) {
    for(int i = 0; s[i] != '\0'; i++) {

        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            push(s[i]);

        else {
            if(top == -1)
                return false;

            char x = pop();

            if((s[i]==')' && x!='(') ||
               (s[i]=='}' && x!='{') ||
               (s[i]==']' && x!='['))
                return false;
        }
    }

    return top == -1;
}

int main() {
    char s[10000];
    scanf("%s", s);

    if(isValid(s))
        printf("true");
    else
        printf("false");

    return 0;
}