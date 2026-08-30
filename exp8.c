#include <stdio.h>

int main() {
    int allocation[10][10], request[10][10];
    int available[10], work[10];
    int finish[10];
    int n, m, i, j, k, found;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    printf("Enter Number of Resource Types: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter Request Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("\nEnter Available Resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    for (i = 0; i < n; i++) {
        if (allocation[i][0] == 0 && allocation[i][1] == 0 && allocation[i][2] == 0)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    do {
        found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < m; j++) {
                    if (request[i][j] > work[j])
                        break;
                }
                if (j == m) {
                    for (k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
    } while (found);

    found = 0;
    printf("\nDeadlocked Processes:\n");
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            printf("P%d ", i);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No Deadlock Detected");
    }
    printf("\n");

    return 0;
}