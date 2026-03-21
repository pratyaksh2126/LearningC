#include <stdio.h>

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    for (int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    int time = 0;

    while (1) {
        int temp[26];
        for (int i = 0; i < 26; i++)
            temp[i] = freq[i];

        int cycle = n + 1;
        int work = 0;

        while (cycle--) {
            int maxIdx = -1;
            for (int i = 0; i < 26; i++)
                if (temp[i] > 0 && (maxIdx == -1 || temp[i] > temp[maxIdx]))
                    maxIdx = i;

            if (maxIdx == -1)
                break;

            temp[maxIdx]--;
            freq[maxIdx]--;
            work++;
            time++;
        }

        int done = 1;
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0)
                done = 0;

        if (done)
            return time;

        time += (n + 1 - work);
    }
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