#include <stdio.h>

int main() {
    int num, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while(num != 0) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }

    printf("Reversed Number = %d", reverse);

    return 0;
}