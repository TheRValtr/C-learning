#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count;

    printf("Cuantos numeros? ");
    scanf("%d", &count);

    int *numbers = malloc(count * sizeof(int));

    if (numbers == NULL) {
        printf("Mem allocation .\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);

    return 0;
}