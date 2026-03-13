#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, top=-1;
    int s[1000];
    char t[100][20];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%s",t[i]);

    for(int i=0;i<n;i++)
    {
        if(strcmp(t[i],"+")==0)
            s[top-1]+=s[top],top--;
        else if(strcmp(t[i],"-")==0)
            s[top-1]-=s[top],top--;
        else if(strcmp(t[i],"*")==0)
            s[top-1]*=s[top],top--;
        else if(strcmp(t[i],"/")==0)
            s[top-1]/=s[top],top--;
        else
            s[++top]=atoi(t[i]);
    }

    printf("%d",s[top]);
}