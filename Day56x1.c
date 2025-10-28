#include <stdio.h>

// Iterative factorial
int factorialIter(int n) {
    int fact = 1;
    for(int i=1; i<=n; i++) fact *= i;
    return fact;
}

// Recursive factorial
int factorialRec(int n) {
    if(n <= 1) return 1;
    return n * factorialRec(n-1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Iterative factorial of %d is %d\n", n, factorialIter(n));
    printf("Recursive factorial of %d is %d\n", n, factorialRec(n));
    return 0;
}
