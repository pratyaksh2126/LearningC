#include <stdio.h>
#include <string.h>

int main() {
    char src[100], dest[100];
    printf("Enter a string: ");
    scanf("%s", src);
    strcpy(dest, src);
    printf("Copied string: %s\n", dest);
    return 0;
}
