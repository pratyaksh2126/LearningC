#include <stdio.h>
#include <math.h>

int main() {
    int data[20], hamming[30];
    int i, j, k = 0, r = 0, m;

    printf("Enter number of data bits: ");
    scanf("%d", &m);

    printf("Enter data bits: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate number of parity bits
    while (pow(2, r) < (m + r + 1)) {
        r++;
    }

    int total = m + r;

    // Initialize hamming code with parity positions
    j = 0;
    for (i = 1; i <= total; i++) {
        if (i == pow(2, k)) {
            hamming[i] = 0;
            k++;
        } else {
            hamming[i] = data[j++];
        }
    }

    // Calculate parity bits
    for (i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;

        for (j = 1; j <= total; j++) {
            if (j & pos) {
                parity ^= hamming[j];
            }
        }
        hamming[pos] = parity;
    }

    printf("Hamming Code: ");
    for (i = 1; i <= total; i++) {
        printf("%d ", hamming[i]);
    }

    // Error detection
    int received[30];
    printf("\nEnter received code: ");
    for (i = 1; i <= total; i++) {
        scanf("%d", &received[i]);
    }

    int errorPos = 0;

    for (i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;

        for (j = 1; j <= total; j++) {
            if (j & pos) {
                parity ^= received[j];
            }
        }

        if (parity != 0) {
            errorPos += pos;
        }
    }

    if (errorPos == 0) {
        printf("No error detected\n");
    } else {
        printf("Error at position: %d\n", errorPos);
        received[errorPos] ^= 1;

        printf("Corrected Code: ");
        for (i = 1; i <= total; i++) {
            printf("%d ", received[i]);
        }
    }

    return 0;
}