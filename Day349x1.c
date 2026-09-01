#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[200];
    int i, j = 0, count = 0;

    printf("Enter bit stream: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];

        if (input[i] == '1') {
            count++;
            if (count == 5) {
                output[j++] = '0'; // stuffing
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    output[j] = '\0';

    printf("Stuffed Data: %s\n", output);
    return 0;
}