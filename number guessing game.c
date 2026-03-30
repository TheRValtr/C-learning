#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess;
    int attempts = 0;
    int max_attempts = 5;

    // Seed random number generator
    srand(time(NULL));

    // Generate number between 1 and 100
    secret = rand() % 100 + 1;

    printf("=== Number Guessing Game ===\n");
    printf("Guess a number between 1 and 100\n");

    while (attempts < max_attempts) {
        printf("Attempt %d/%d: Enter your guess: ", attempts + 1, max_attempts);
        scanf("%d", &guess);

        attempts++;

        if (guess == secret) {
            printf("🎉 Correct! You guessed it in %d attempts.\n", attempts);
            return 0;
        } else if (guess > secret) {
            printf("Too high!\n");
        } else {
            printf("Too low!\n");
        }
    }

    printf("❌ You lost! The number was %d\n", secret);

    return 0;
}