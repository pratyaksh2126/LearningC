#include <stdio.h>
int main() {
    char str[100];
    int vowels=0, consonants=0, i=0;
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    while(str[i]!='\0') {
        char ch = str[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) {
            ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') vowels++;
            else consonants++;
        }
        i++;
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    return 0;
}
