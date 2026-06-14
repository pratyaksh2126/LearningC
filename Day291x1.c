#include <stdio.h>
#include <math.h>

int main() {
    int num, original, remainder, n = 0;
    int result = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;
    int temp = num;

    while (temp != 0) {
        temp /= 10;
        n++;
    }

    temp = num;

    while (temp != 0) {
        remainder = temp % 10;
        result += pow(remainder, n);
        temp /= 10;
    }

    if (result == original)
        printf("%d is an Armstrong Number", original);
    else
        printf("%d is not an Armstrong Number", original);

    return 0;
}