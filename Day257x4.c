#include <stdio.h>

int main() {
    int n, flag = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    if (n <= 1)
        flag = 1;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("Prime Number");
    else
        printf("Not Prime");

    return 0;
}