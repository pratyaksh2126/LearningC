#include <stdio.h>
int main() {
    int n, flag = 1;
    printf("Enter a number: "); scanf("%d", &n);
    if(n <= 1) flag = 0;
    for (int i = 2; i <= n/2 && flag; i++) {
        if (n % i == 0) flag = 0;
    }
    printf("%d is %s\n", n, (flag) ? "prime" : "not prime");
    return 0;
}
