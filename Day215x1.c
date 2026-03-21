#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    for (int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    int maxFreq = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > maxFreq)
            maxFreq = freq[i];

    int count = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] == maxFreq)
            count++;

    int res = (maxFreq - 1) * (n + 1) + count;
    return max(size, res);
}

int main() {
    int n, cooldown;
    scanf("%d", &n);

    char tasks[n];
    for (int i = 0; i < n; i++)
        scanf(" %c", &tasks[i]);

    scanf("%d", &cooldown);

    printf("%d\n", leastInterval(tasks, n, cooldown));
    return 0;
}