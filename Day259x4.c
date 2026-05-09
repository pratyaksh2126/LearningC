#include <stdio.h>

int main() {
    FILE *fp;
    char data[100];

    fp = fopen("sample.txt", "w");

    if(fp == NULL) {
        printf("File cannot be opened.\n");
        return 0;
    }

    printf("Enter text to write into file: ");
    scanf(" %[^\n]", data);

    fprintf(fp, "%s", data);

    fclose(fp);

    printf("Data written successfully.\n");

    return 0;
}