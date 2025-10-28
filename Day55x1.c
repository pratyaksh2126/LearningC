#include <stdio.h>

int stringToInt(const char *str) {
    int result = 0, sign = 1, i = 0;
    if(str[0] == '-') {
        sign = -1;
        i = 1;
    }
    for(; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9')
            result = result * 10 + (str[i] - '0');
        else
            break; // Stop at non-digit
    }
    return sign * result;
}

int main() {
    char str[100];
    printf("Enter numeric string: ");
    scanf("%s", str);
    int val = stringToInt(str);
    printf("Converted integer: %d\n", val);
    return 0;
}
