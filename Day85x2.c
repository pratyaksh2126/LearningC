#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, flag = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    // Remove newline if present
    if(str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    for(i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("String is a palindrome.\n");
    else
        printf("String is NOT a palindrome.\n");

    return 0;
}
