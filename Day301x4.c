#include <stdio.h>

int main() {
    int n, i, prime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1)
        prime = 0;

    for (i = 2; i <= n / 2 && prime; i++) {
        if (n % i == 0)
            prime = 0;
    }

    if (prime)
        printf("%d is Prime", n);
    else
        printf("%d is Not Prime", n);

    return 0;
}