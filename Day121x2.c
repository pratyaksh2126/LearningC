#include <stdio.h>
#include <string.h>

int isPalindrome(char str[])
{
    int i, len = strlen(str);
    for(i = 0; i < len/2; i++)
    {
        if(str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    gets(str);

    if(isPalindrome(str))
        printf("Palindrome String");
    else
        printf("Not a Palindrome String");

    return 0;
}
