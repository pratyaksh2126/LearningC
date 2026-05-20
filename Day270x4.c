#include <stdio.h>

int main() {
    int n, temp, rem, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp != 0) {
        rem = temp % 10;
        reverse = reverse * 10 + rem;
        temp = temp / 10;
    }

    if(n == reverse)
        printf("Palindrome Number");
    else
        printf("Not a Palindrome Number");

    return 0;
}