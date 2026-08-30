#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j;
    int fault = 0, count = 0;
    int found, pos, min;

    printf("Enter Number of Pages: ");
    scanf("%d", &n);
    printf("Enter Reference String:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter Number of Frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            if (i < f) {
                pos = i;
            } else {
                min = time[0];
                pos = 0;
                for (j = 0; j < f; j++) {
                    if (time[j] < min) {
                        min = time[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);
    return 0;
}