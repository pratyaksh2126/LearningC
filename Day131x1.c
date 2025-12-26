#include <stdio.h>

void add(int a, int b) {
    printf("Sum = %d\n", a + b);
}

void subtract(int a, int b) {
    printf("Difference = %d\n", a - b);
}

void multiply(int a, int b) {
    printf("Product = %d\n", a * b);
}

void divide(int a, int b) {
    if (b != 0)
        printf("Quotient = %.2f\n", (float)a / b);
    else
        printf("Division by zero not allowed\n");
}

int main() {
    int a, b, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: add(a, b); break;
        case 2: subtract(a, b); break;
        case 3: multiply(a, b); break;
        case 4: divide(a, b); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
