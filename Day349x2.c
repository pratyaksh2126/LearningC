#include <stdio.h>
#include <string.h>

int main() {
    char input[200], output[100];
    int i, j = 0, count = 0;

    printf("Enter stuffed data: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];

        if (input[i] == '1') {
            count++;
            if (count == 5) {
                i++; // skip stuffed 0
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    output[j] = '\0';

    printf("Destuffed Data: %s\n", output);
    return 0;
}