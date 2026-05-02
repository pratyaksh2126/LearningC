#include <stdio.h>
#include <stdlib.h>

#define MAX 20001

int BIT[MAX];

void update(int i) {
    while (i < MAX) {
        BIT[i]++;
        i += i & -i;
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= i & -i;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], res[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = n - 1; i >= 0; i--) {
        int val = arr[i] + 10001;
        res[i] = query(val - 1);
        update(val);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);

    return 0;
}