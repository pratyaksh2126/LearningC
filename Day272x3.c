#include <stdio.h>
#include <math.h>

int main() {
    int n, temp, rem, result = 0, digits = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp != 0) {
        temp /= 10;
        digits++;
    }

    temp = n;

    while(temp != 0) {
        rem = temp % 10;
        result += pow(rem, digits);
        temp /= 10;
    }

    if(result == n)
        printf("Armstrong Number");
    else
        printf("Not an Armstrong Number");

    return 0;
}