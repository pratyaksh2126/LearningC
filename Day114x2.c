#include <stdio.h>

int main() {
    FILE *fp;
    char filename[50], ch;
    int characters = 0, words = 0, lines = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        characters++;

        if (ch == ' ' || ch == '\t' || ch == '\n')
            words++;

        if (ch == '\n')
            lines++;
    }

    fclose(fp);

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
