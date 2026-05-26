#include <stdio.h>

int main(void) {

    int number;

    while (1) {

        printf("Enter 0 to quit: ");
        scanf("%d", &number);

        if (number == 0) {
            break;
        }

        printf("You entered: %d\n", number);
    }

    return 0;
}