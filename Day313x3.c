#include <stdio.h>

int main() {
    char str[200];
    int i = 0;
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0') {

        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {

            char ch = str[i];

            if(ch >= 'A' && ch <= 'Z')
                ch += 32;

            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                vowels++;
            else
                consonants++;
        }

        else if(str[i] >= '0' && str[i] <= '9')
            digits++;

        else if(str[i] == ' ')
            spaces++;

        i++;
    }

    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    printf("Digits = %d\n", digits);
    printf("Spaces = %d\n", spaces);

    return 0;
}