#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 100

void *allocations[MAX_ALLOCATIONS];
int allocationCount = 0;

void *gc_malloc(size_t size) {
    if (allocationCount >= MAX_ALLOCATIONS) {
        return NULL;
    }

    void *ptr = malloc(size);

    if (ptr != NULL) {
        allocations[allocationCount] = ptr;
        allocationCount++;
    }

    return ptr;
}

void gc_cleanup(void) {
    for (int i = 0; i < allocationCount; i++) {
        free(allocations[i]);
    }

    allocationCount = 0;
}

int main(void) {
    int *number = gc_malloc(sizeof(int));

    if (number == NULL) {
        printf("Allocation failed.\n");
        return 1;
    }

    *number = 42;

    printf("Number: %d\n", *number);

    gc_cleanup();

    return 0;
}