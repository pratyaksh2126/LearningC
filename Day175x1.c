#include <stdio.h>

int main() {
    int a[50], b[50], c[100];
    int m, n, i = 0, j = 0, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &m);

    printf("Enter elements of first sorted array:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n);

    printf("Enter elements of second sorted array:\n");
    for (j = 0; j < n; j++) {
        scanf("%d", &b[j]);
    }

    i = j = 0;

    while (i < m && j < n) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < m)
        c[k++] = a[i++];

    while (j < n)
        c[k++] = b[j++];

    printf("Merged sorted array:\n");
    for (i = 0; i < m + n; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
