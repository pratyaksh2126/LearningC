#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    printf("Enter two strings: ");
    scanf("%s %s", str1, str2);
    strcat(str1, str2);
    printf("Concatenated: %s\n", str1);
    return 0;
}
