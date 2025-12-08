#include <stdio.h>

// Function declaration
int factorial(int n);

int main()
{
    int num, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    result = factorial(num);   // Function call

    printf("Factorial of %d is = %d", num, result);

    return 0;
}

// Function definition
int factorial(int n)
{
    int i, fact = 1;

    for(i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}
