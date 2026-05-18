#include <stdio.h>

int main(void) {

    for (int row = 1; row <= 3; row++) {

        for (int col = 1; col <= 5; col++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}