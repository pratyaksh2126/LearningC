#include <stdio.h>
#include <stdlib.h>

int* solve(int* t, int n) {
    int* ans = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) ans[i] = 0;

    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1;
        while (j < n && t[j] <= t[i]) {
            if (ans[j] == 0) {
                j = n;
                break;
            }
            j += ans[j];
        }
        if (j < n) ans[i] = j - i;
    }

    return ans;
}

int main() {
    int t[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(t)/sizeof(t[0]);
    int* res = solve(t, n);

    for (int i = 0; i < n; i++) printf("%d ", res[i]);

    free(res);
    return 0;
}