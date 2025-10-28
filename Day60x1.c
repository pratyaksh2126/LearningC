#include <stdio.h>

float add(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float mul(float a, float b) { return a * b; }
float divi(float a, float b) { return b == 0 ? 0 : a / b; }

int main() {
    char op;
    float a, b, result;
    printf("Enter expression (e.g. 3 + 4): ");
    scanf("%f %c %f", &a, &op, &b);

    switch(op) {
        case '+': result = add(a,b); break;
        case '-': result = sub(a,b); break;
        case '*': result = mul(a,b); break;
        case '/': 
            if (b == 0) {
                printf("Division by zero error\n");
                return 1;
            }
            result = divi(a,b); break;
        default: 
            printf("Invalid operator\n"); return 1;
    }
    printf("Result: %.2f\n", result);
    return 0;
}
