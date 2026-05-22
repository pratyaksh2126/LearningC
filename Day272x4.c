#include <stdio.h>
#include <string.h>

int main() {
    char str[100], rev[100];
    int i, j = 0;

    printf("Enter a string: ");
    gets(str);

    for(i = strlen(str) - 1; i >= 0; i--) {
        rev[j] = str[i];
        j++;
    }

    rev[j] = '\0';

    printf("Reversed String = %s", rev);

    return 0;
}