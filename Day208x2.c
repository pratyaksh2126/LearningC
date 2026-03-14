#include <stdio.h>
#include <ctype.h>
#include <string.h>

int precedence(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int main(){
    char infix[100],stack[100],postfix[100];
    int top=-1,k=0;

    printf("Enter infix expression: ");
    scanf("%s",infix);

    for(int i=0;i<strlen(infix);i++){
        char c=infix[i];

        if(isalnum(c))
            postfix[k++]=c;

        else if(c=='(')
            stack[++top]=c;

        else if(c==')'){
            while(stack[top]!='(')
                postfix[k++]=stack[top--];
            top--;
        }

        else{
            while(top!=-1 && precedence(stack[top])>=precedence(c))
                postfix[k++]=stack[top--];
            stack[++top]=c;
        }
    }

    while(top!=-1)
        postfix[k++]=stack[top--];

    postfix[k]='\0';

    printf("Postfix = %s\n",postfix);

    return 0;
}