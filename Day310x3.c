#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp[100];
    int i, j = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);

    for (i = len - 1; i >= 0; i--) {
        if (str[i] == ' ' || i == 0) {
            int k = (i == 0) ? i : i + 1;
            while (str[k] != ' ' && str[k] != '\0' && str[k] != '\n')
                temp[j++] = str[k++];
            temp[j++] = ' ';
        }
    }

    temp[j] = '\0';
    printf("Reversed Words: %s", temp);

    return 0;
}