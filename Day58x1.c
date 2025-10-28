#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

int main() {
    char str[100], *word_start = NULL, *temp = NULL;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (str[len-1] == '\n')
        str[len-1] = '\0';

    temp = str;
    while (*temp) {
        if (word_start == NULL && *temp != ' ')
            word_start = temp;
        if (word_start && (*(temp+1) == ' ' || *(temp+1) == '\0')) {
            reverse(word_start, temp);
            word_start = NULL;
        }
        temp++;
    }
    printf("Reversed words: %s\n", str);
    return 0;
}
