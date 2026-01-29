#include <stdio.h>

int isPalindrome(int num) {
    int rev = 0, temp = num;

    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    return (rev == num);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPalindrome(n))
        printf("%d is a Palindrome\n", n);
    else
        printf("%d is NOT a Palindrome\n", n);

    return 0;
}
