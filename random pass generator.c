#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

void generatePassword(char *password, int length) {
    char charset[] = 
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*";

    int charsetSize = sizeof(charset) - 1;

    for (int i = 0; i < length; i++) {
        int index = rand() % charsetSize;
        password[i] = charset[index];
    }

    password[length] = '\0';
}

int main(void) {
    char password[PASSWORD_LENGTH + 1];

    srand(time(NULL));

    generatePassword(password, PASSWORD_LENGTH);

    printf("Generated Password: %s\n", password);

    return 0;
}