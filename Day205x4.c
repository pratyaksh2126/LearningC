#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

int main() {
    char s[MAX], stack[MAX];
    int top = -1;

    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++) {

        switch(s[i]) {

            case '(':
            case '{':
            case '[':
                stack[++top] = s[i];
                break;

            case ')':
                if(top==-1 || stack[top--] != '(') {
                    printf("false");
                    return 0;
                }
                break;

            case '}':
                if(top==-1 || stack[top--] != '{') {
                    printf("false");
                    return 0;
                }
                break;

            case ']':
                if(top==-1 || stack[top--] != '[') {
                    printf("false");
                    return 0;
                }
                break;
        }
    }

    if(top == -1)
        printf("true");
    else
        printf("false");

    return 0;
}