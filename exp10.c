#include <stdio.h>

int main() {
    int pageTable[20];
    int pageSize, numPages, logicalAddress;
    int pageNumber, offset, frameNumber, physicalAddress;
    int i;

    printf("Enter Page Size: ");
    scanf("%d", &pageSize);
    printf("Enter Number of Pages: ");
    scanf("%d", &numPages);

    printf("Enter Frame Numbers for Each Page:\n");
    for (i = 0; i < numPages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("Enter Logical Address: ");
    scanf("%d", &logicalAddress);

    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    if (pageNumber >= numPages) {
        printf("Invalid Logical Address\n");
        return 0;
    }

    frameNumber = pageTable[pageNumber];
    physicalAddress = (frameNumber * pageSize) + offset;

    printf("\nPage Number: %d", pageNumber);
    printf("\nOffset: %d", offset);
    printf("\nFrame Number: %d", frameNumber);
    printf("\nPhysical Address: %d\n", physicalAddress);

    return 0;
}