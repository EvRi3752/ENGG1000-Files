#include <stdio.h>

int main() {
    char name[50];
    int mood;

    // Program introduces itself and opens a prompt for the user to enter their name
    printf("Hello there my name is EMMA, a simple script written in c, Please enter your name: ");
    scanf("%s", name); // this line reads the input from the user, "&s" is a format specifier that tells the function scanf to expect an int as an output.

    // The program aptly named "EMMA" greets the user
    printf("Pleasure to meet you %s\n", name);

    // EMMA Asks the user how they are feeling
    printf("How are you today? Enter 1 if you are happy or 2 if you are sad: ");
    scanf("%d", &mood);

    // EMMA Responds based on the user's input
    if (mood == 1) {
        printf("I am happy that you are happy\n");
    } else if (mood == 2) {
        printf("I hope your day will get better\n");
    } else {
        printf("Invalid input. Please enter either 1 or 2.\n");
    }

    return 0;
}