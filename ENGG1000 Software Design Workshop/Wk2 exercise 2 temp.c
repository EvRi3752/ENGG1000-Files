#include <stdio.h>

int main() {
    float temperature;
    char unit;

    // Program introduces itself and prompts the user for the temperature reading
    printf("Hi, I'm Temp, a simple temperature converter written in c, please enter the temperature you'd like to convert: ");
    scanf("%f", &temperature);

    // Prompts the user asking for which unit temp they're converting from
    printf("Enter the unit (C for Celsius, F for Fahrenheit): ");
    scanf(" %c", &unit); // The reason for why there is a space behind %c is to consume any leftover newline character

    // Performs the conversion based on the unit
    if (unit == 'C' || unit == 'c') {
        // Converts Celsius to Fahrenheit using an arithmetic formula 
        float fahrenheit = (temperature * 9 / 5) + 32;
        printf("%.2f°C is equal to %.2f°F\n", temperature, fahrenheit);
    } else if (unit == 'F' || unit == 'f') {
        // Converts Fahrenheit to Celsius using an arithmetic formula
        float celsius = (temperature - 32) * 5 / 9;
        printf("%.2f°F is equal to %.2f°C\n", temperature, celsius);
    } else {
        // Handles invalid unit inputs which prints an error message for the user
        printf("Invalid unit. Please enter 'C' for Celsius or 'F' for Fahrenheit.\n");
    }

    return 0;
}