#include <stdio.h>

long long factorial(int n) {
    long long fact = 1;
    int i;

    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorial = %lld", factorial(n));

    return 0;
}