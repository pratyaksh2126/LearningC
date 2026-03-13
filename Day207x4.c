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
        if(strcmp(tokens[i],"+")==0 || strcmp(tokens[i],"-")==0 || strcmp(tokens[i],"*")==0 || strcmp(tokens[i],"/")==0)
        {
            int y=stack[top--];
            int x=stack[top--];

            if(strcmp(tokens[i],"+")==0)
                stack[++top]=x+y;
            else if(strcmp(tokens[i],"-")==0)
                stack[++top]=x-y;
            else if(strcmp(tokens[i],"*")==0)
                stack[++top]=x*y;
            else
                stack[++top]=x/y;
        }
        else
        {
            stack[++top]=atoi(tokens[i]);
        }
    }

    printf("%d",stack[top]);
}