#include <stdio.h>

int main() {
    int n = 10, a = 0, b = 1, c, i;

    printf("%d %d ", a, b);

    for(i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    return 0;
}