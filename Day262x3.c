#include <stdio.h>
#include <string.h>

int main() {
    char str[100], rev[100];

    printf("Enter a string: ");
    scanf("%s", str);

    strcpy(rev, str);
    strrev(rev);

    if(strcmp(str, rev) == 0)
        printf("Palindrome String");
    else
        printf("Not a Palindrome String");

    return 0;
}