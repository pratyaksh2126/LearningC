#include <stdio.h>

int main() {
    int n, rev = 0, temp, rem;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while (temp != 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }

    if (rev == n)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}