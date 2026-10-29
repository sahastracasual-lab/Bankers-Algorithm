
#include <stdio.h>

int main() {
    int n = 5, m = 4;
    int allocation[5][4] = {
        {0, 0, 1, 2},
        {1, 0, 0, 0},
        {1, 3, 5, 4},
        {0, 6, 3, 2},
        {0, 0, 1, 4}
    };

    int maximum[5][4] = {
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6},
        {0, 6, 5, 2},
        {0, 6, 5, 6}
    };

    int available[4] = {3, 14, 12, 12};
    int need[5][4];
    int finish[5] = {0};
    int safeSequence[5];
    int work[4];
    int i, j, count = 0, found;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    printf("Need Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for (j = 0; j < m; j++) {
        work[j] = available[j];
    }

    while (count < n) {
        found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int possible = 1;

                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if (possible) {
                    for (j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            break;
        }
    }

    if (count == n) {
        printf("\nSystem is in a SAFE state.\n");
        printf("Safe Sequence: ");

        for (i = 0; i < n; i++) {
            printf("P%d", safeSequence[i]);
            if (i < n - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("\nSystem is in an UNSAFE state.\n");
    }

    return 0;
}
