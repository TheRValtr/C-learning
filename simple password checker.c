#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50

int main(void) {
    char correctPassword[] = "secret123";
    char userPassword[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    fgets(userPassword, sizeof(userPassword), stdin);

    // Remove newline added by fgets
    userPassword[strcspn(userPassword, "\n")] = '\0';

    if (strcmp(userPassword, correctPassword) == 0) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}