#include <stdio.h>

/* compute length of string (like strlen) */
size_t str_len(const char *s) {
    const char *p = s;
    while (*p) ++p;
    return (size_t)(p - s);
}

/* copy src into dest (assumes dest has enough space) */
char *str_copy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++) != '\0') {}
    return dest;
}

/* compare two strings: 0 if equal, <0 if s1<s2, >0 if s1>s2 */
int str_cmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        ++s1; ++s2;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int main() {
    char s1[200], s2[200];
    printf("Enter first string: ");
    if (!fgets(s1, sizeof(s1), stdin)) return 1;
    printf("Enter second string: ");
    if (!fgets(s2, sizeof(s2), stdin)) return 1;

    // remove trailing newline from fgets
    size_t l1 = str_len(s1);
    if (l1 > 0 && s1[l1-1] == '\n') s1[l1-1] = '\0';
    size_t l2 = str_len(s2);
    if (l2 > 0 && s2[l2-1] == '\n') s2[l2-1] = '\0';

    printf("Length of first string: %zu\n", str_len(s1));
    printf("Length of second string: %zu\n", str_len(s2));

    char copy_of_s1[200];
    str_copy(copy_of_s1, s1);
    printf("Copied first string into another buffer: \"%s\"\n", copy_of_s1);

    int cmp = str_cmp(s1, s2);
    if (cmp == 0) printf("Strings are equal.\n");
    else if (cmp < 0) printf("First string is lexicographically smaller than second.\n");
    else printf("First string is lexicographically greater than second.\n");

    return 0;
}
