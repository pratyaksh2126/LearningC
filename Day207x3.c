#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, a, b;
    int stack[1000];
    int top=-1;
    char token[100][20];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%s",token[i]);

    for(int i=0;i<n;i++)
    {
        if(strcmp(token[i],"+")==0)
        {
            b=stack[top--];
            a=stack[top--];
            stack[++top]=a+b;
        }
        else if(strcmp(token[i],"-")==0)
        {
            b=stack[top--];
            a=stack[top--];
            stack[++top]=a-b;
        }
        else if(strcmp(token[i],"*")==0)
        {
            b=stack[top--];
            a=stack[top--];
            stack[++top]=a*b;
        }
        else if(strcmp(token[i],"/")==0)
        {
            b=stack[top--];
            a=stack[top--];
            stack[++top]=a/b;
        }
        else
        {
            stack[++top]=atoi(token[i]);
        }
    }

    printf("%d",stack[top]);
}