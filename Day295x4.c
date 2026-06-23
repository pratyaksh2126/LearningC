#include <stdio.h>
#include <math.h>

int main() {
    int n, temp, remainder, digits = 0;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;

    while (temp != 0) {
        remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }

    if (sum == n)
        printf("%d is an Armstrong Number", n);
    else
        printf("%d is not an Armstrong Number", n);

    return 0;
}