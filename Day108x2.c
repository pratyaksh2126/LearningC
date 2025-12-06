#include <stdio.h>

int main() {
    char str[100];
    int i = 0, length = 0;

    printf("Enter a string: ");
    gets(str);   // For simple college use (deprecated in modern C)

    while(str[i] != '\0') {
        length++;
        i++;
    }

    printf("Length of the string = %d", length);

    return 0;
}
