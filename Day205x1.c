#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10000

bool isValid(char s[]) {
    char stack[MAX];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if(top == -1) return false;

            char x = stack[top--];

            if((s[i] == ')' && x != '(') ||
               (s[i] == '}' && x != '{') ||
               (s[i] == ']' && x != '['))
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