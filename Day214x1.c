#include <stdio.h>
#include <stdlib.h>

int* solve(int* t, int n) {
    int* ans = (int*)malloc(n * sizeof(int));
    int* st = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) ans[i] = 0;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && t[i] > t[st[top]]) {
            int idx = st[top--];
            ans[idx] = i - idx;
        }
        st[++top] = i;
    }

    free(st);
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