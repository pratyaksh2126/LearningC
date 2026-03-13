#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, stack[1000], top=-1;
    char tokens[100][20];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%s",tokens[i]);

    for(int i=0;i<n;i++)
    {
        if(strcmp(tokens[i],"+")==0)
        {
            int b=stack[top--];
            int a=stack[top--];
            stack[++top]=a+b;
        }
        else if(strcmp(tokens[i],"-")==0)
        {
            int b=stack[top--];
            int a=stack[top--];
            stack[++top]=a-b;
        }
        else if(strcmp(tokens[i],"*")==0)
        {
            int b=stack[top--];
            int a=stack[top--];
            stack[++top]=a*b;
        }
        else if(strcmp(tokens[i],"/")==0)
        {
            int b=stack[top--];
            int a=stack[top--];
            stack[++top]=a/b;
        }
        else
            stack[++top]=atoi(tokens[i]);
    }

    printf("%d",stack[top]);
}