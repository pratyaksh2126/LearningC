#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char postfix[100];
    int stack[100];
    int top=-1;

    printf("Enter postfix expression: ");
    scanf("%s",postfix);

    for(int i=0;i<strlen(postfix);i++){
        char c=postfix[i];

        if(isdigit(c))
            stack[++top]=c-'0';

        else{
            int a=stack[top--];
            int b=stack[top--];

            if(c=='+') stack[++top]=b+a;
            else if(c=='-') stack[++top]=b-a;
            else if(c=='*') stack[++top]=b*a;
            else if(c=='/') stack[++top]=b/a;
        }
    }

    printf("Result = %d\n",stack[top]);

    return 0;
}