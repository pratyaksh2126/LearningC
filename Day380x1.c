#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

    fp = fopen("data.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);

    fprintf(fp, "%s", text);

    fclose(fp);

    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nContent of file:\n");

    while (fgets(text, sizeof(text), fp) != NULL) {
        printf("%s", text);
    }

    fclose(fp);

    return 0;
}