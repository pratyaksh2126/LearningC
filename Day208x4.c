#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char prefix[100];
    int stack[100];
    int top=-1;

    printf("Enter prefix expression: ");
    scanf("%s",prefix);

    for(int i=strlen(prefix)-1;i>=0;i--){
        char c=prefix[i];

        if(isdigit(c))
            stack[++top]=c-'0';

        else{
            int a=stack[top--];
            int b=stack[top--];

            if(c=='+') stack[++top]=a+b;
            else if(c=='-') stack[++top]=a-b;
            else if(c=='*') stack[++top]=a*b;
            else if(c=='/') stack[++top]=a/b;
        }
    }

    printf("Result = %d\n",stack[top]);

    return 0;
}