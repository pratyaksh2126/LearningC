#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[j] > arr[i]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
}

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    for (int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    sort(freq, 26);

    int maxFreq = freq[0];
    int idle = (maxFreq - 1) * n;

    for (int i = 1; i < 26 && idle > 0; i++) {
        idle -= (freq[i] < maxFreq - 1) ? freq[i] : maxFreq - 1;
    }

    if (idle < 0) idle = 0;

    return size + idle;
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