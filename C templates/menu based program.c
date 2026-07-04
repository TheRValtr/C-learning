#include <stdio.h>

void printMenu(void) {
    printf("\n===== MENU =====\n");
    printf("1. Option One\n");
    printf("2. Option Two\n");
    printf("3. Option Three\n");
    printf("0. Exit\n");
}

void optionOne(void) {
    printf("Option One selected.\n");
}

void optionTwo(void) {
    printf("Option Two selected.\n");
}

void optionThree(void) {
    printf("Option Three selected.\n");
}

int main(void) {
    int choice;

    do {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                optionOne();
                break;
            case 2:
                optionTwo();
                break;
            case 3:
                optionThree();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 0);

    return 0;
}