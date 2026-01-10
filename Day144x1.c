#include <stdio.h>

int isPalindrome(int num) {
    int rev = 0, temp = num;

    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if (rev == num)
        return 1;
    else
        return 0;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPalindrome(number))
        printf("%d is a Palindrome number.\n", number);
    else
        printf("%d is not a Palindrome number.\n", number);

    return 0;
}
