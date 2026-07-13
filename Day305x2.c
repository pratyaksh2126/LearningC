#include <stdio.h>

int main() {
    int num, original, rem, sum = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    original = num;

    while(num > 0) {
        rem = num % 10;
        sum += rem * rem * rem;
        num /= 10;
    }

    if(sum == original)
        printf("Armstrong Number");
    else
        printf("Not an Armstrong Number");

    return 0;
}