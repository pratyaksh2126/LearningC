#include <stdio.h>

int main() {
    int n, temp, reverse = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp != 0) {
        remainder = temp % 10;
        reverse = reverse * 10 + remainder;
        temp = temp / 10;
    }

    if(n == reverse)
        printf("%d is Palindrome", n);
    else
        printf("%d is not Palindrome", n);

    return 0;
}