#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idx;
} Node;

int* solve(int* t, int n) {
    int* ans = (int*)malloc(n * sizeof(int));
    Node* st = (Node*)malloc(n * sizeof(Node));
    int top = -1;

    for (int i = 0; i < n; i++) ans[i] = 0;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && t[i] > t[st[top].idx]) {
            int id = st[top--].idx;
            ans[id] = i - id;
        }
        st[++top].idx = i;
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