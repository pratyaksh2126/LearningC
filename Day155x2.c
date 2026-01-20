#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str) - 1;   // ignore newline character

    printf("Reversed string: ");
    for(i = len; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
