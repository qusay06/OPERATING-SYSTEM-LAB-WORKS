#include <stdio.h>

int main() {
    int blockSize[20], processSize[20], allocation[20];
    int nb, np, i, j, bestIdx;

    printf("Enter Number of Blocks: ");
    scanf("%d", &nb);
    printf("Enter Number of Processes: ");
    scanf("%d", &np);

    printf("Enter Block Sizes:\n");
    for (i = 0; i < nb; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter Process Sizes:\n");
    for (i = 0; i < np; i++)
        scanf("%d", &processSize[i]);

    for (i = 0; i < np; i++)
        allocation[i] = -1;

    for (i = 0; i < np; i++) {
        bestIdx = -1;
        for (j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}