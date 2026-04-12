#include <stdio.h>

int main() {
    int choice;
    float temperature, result;

    printf("=== Temperature Converter ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    if (choice == 1) {
        result = (temperature * 9.0 / 5.0) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, result);
    } else if (choice == 2) {
        result = (temperature - 32) * 5.0 / 9.0;
        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, result);
    } else {
        printf("Invalid option.\n");
    }

    return 0;
} 