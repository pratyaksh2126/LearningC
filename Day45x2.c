#include <stdio.h>
#include <stdlib.h>
int main() {
    int *ptr, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }
    printf("Enter elements: ");
    for(int i=0; i<n; i++) scanf("%d", &ptr[i]);
    printf("Elements entered: ");
    for(int i=0; i<n; i++) printf("%d ", ptr[i]);
    free(ptr);
    return 0;
}
