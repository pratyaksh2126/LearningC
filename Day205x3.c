#include <stdio.h>
#include <string.h>

int main() {
    char s[10000];
    scanf("%s", s);

    int len;

    while(1) {
        len = strlen(s);

        for(int i = 0; i < len - 1; i++) {
            if((s[i]=='(' && s[i+1]==')') ||
               (s[i]=='{' && s[i+1]=='}') ||
               (s[i]=='[' && s[i+1]==']')) {

                for(int j = i; j < len-2; j++)
                    s[j] = s[j+2];

                s[len-2] = '\0';
                break;
            }
        }

        if(len == strlen(s))
            break;
    }

    if(strlen(s) == 0)
        printf("true");
    else
        printf("false");

    return 0;
}