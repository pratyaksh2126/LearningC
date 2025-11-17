#include <stdio.h>

int sum(int a, int b) { return a + b; }
int diff(int a, int b) { return a - b; }
int product(int a, int b) { return a * b; }
float divide(int a, int b) { return (float)a / b; }

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Sum = %d\n", sum(a, b));
    printf("Difference = %d\n", diff(a, b));
    printf("Product = %d\n", product(a, b));
    printf("Division = %.2f\n", divide(a, b));

    return 0;
}
