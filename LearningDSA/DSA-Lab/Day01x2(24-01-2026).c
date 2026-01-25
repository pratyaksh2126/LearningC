// Q2.Create an array 'a1' with 'n' elements. Insert an element in ith position of 'a1' and also delete an element from jth position of 'a1'.//

#include <stdio.h>

int main() {
    int a1[100], n, i, j, element;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    
    printf("Enter %d elements:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &a1[k]);
    }

    
    printf("Enter element to insert: ");
    scanf("%d", &element);

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &i);

    for (int k = n; k >= i; k--) {
        a1[k] = a1[k - 1];
    }
    a1[i - 1] = element;
    n++;

    printf("Array after insertion:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", a1[k]);
    }
    printf("\n");

    
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &j);

    for (int k = j - 1; k < n - 1; k++) {
        a1[k] = a1[k + 1];
    }
    n--;

    printf("Array after deletion:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", a1[k]);
    }

    return 0;
}