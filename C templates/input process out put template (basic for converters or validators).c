#include <stdio.h>

int main(void) {
    double input;
    double result;

    printf("Enter value: ");
    scanf("%lf", &input);

    result = input * 2; // change logic depending on what's needed 

    printf("Result: %.2f\n", result);

    return 0;
}