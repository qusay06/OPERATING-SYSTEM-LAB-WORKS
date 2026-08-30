#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int allocation[10][10], max[10][10];
    int need[10][10];
    int available[10];
    int finish[10] = {0};
    int safeSeq[10];
    int count = 0;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    printf("Enter Number of Resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);

    // Calculate Need Matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j])
                        break;
                }
                if (j == m) {
                    for (k = 0; k < m; k++)
                        available[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("\nSystem is NOT in Safe State\n");
            return 0;
        }
    }

    printf("\nSystem is in Safe State\n");
    printf("Safe Sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}