#include <stdio.h>

int main() {
    int num, rev = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    while (num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    printf("Reversed number: %d", rev);
    return 0;
}