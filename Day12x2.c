#include <stdio.h>

int main() {
    int a, b, i, sum = 0;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    for(i = (a < b ? a : b); i <= (a > b ? a : b); i++)
        if(i % 2 != 0)
            sum += i;
    printf("Sum of odd numbers = %d\n", sum);
    return 0;
}
