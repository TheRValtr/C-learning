#include <stdio.h>

int sumArray(const int numbers[], int length) {
    int total = 0;

    for (int i = 0; i < length; i++) {
        total = total + numbers[i];
    }

    return total;
}

int main(void) {
    int numbers[] = {10, 20, 30, 40};

    int result = sumArray(numbers, 4);

    printf("Total: %d\n", result);

    return 0;
}