#include <stdio.h>

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return b != 0 ? a / b : 0; }

int main() {
    float num1, num2, result;
    char op;

    printf("Enter an expression (example: 5 + 3): ");
    scanf("%f %c %f", &num1, &op, &num2);

    switch (op) {
        case '+': result = add(num1, num2); break;
        case '-': result = subtract(num1, num2); break;
        case '*': result = multiply(num1, num2); break;
        case '/':
            if (num2 != 0)
                result = divide(num1, num2);
            else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }

    printf("Result: %.2f\n", result);
    return 0;
}
