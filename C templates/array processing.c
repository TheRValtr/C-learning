#include <stdio.h>

#define MAX_ITEMS 100

int main(void) {
    int values[MAX_ITEMS];
    int count;

    printf("How many items? ");
    scanf("%d", &count);

    if (count < 1 || count > MAX_ITEMS) {
        printf("Invalid count.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("\nValues entered:\n");

    for (int i = 0; i < count; i++) {
        printf("%d\n", values[i]);
    }

    return 0;
}