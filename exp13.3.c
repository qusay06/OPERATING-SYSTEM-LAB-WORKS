#include <stdio.h>

struct student {
    int regno;
    char name[20];
};

int main() {
    struct student s[3];
    int key, i;

    printf("Enter 3 Student Records (RegNo Name):\n");
    for (i = 0; i < 3; i++) {
        scanf("%d %s", &s[i].regno, s[i].name);
    }

    printf("Enter Register Number to Search: ");
    scanf("%d", &key);

    for (i = 0; i < 3; i++) {
        if (s[i].regno == key) {
            printf("\nRecord Found\n");
            printf("Reg No: %d\n", s[i].regno);
            printf("Name: %s\n", s[i].name);
            return 0;
        }
    }

    printf("Record Not Found\n");
    return 0;
}