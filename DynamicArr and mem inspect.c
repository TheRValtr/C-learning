#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = malloc(5 * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("Value: %d | Address: %p\n", arr[i], &arr[i]);
    }

    free(arr);

    return 0;
}