/**
    This program implements the game Rock Paper Scissors. 
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array to map gesture numbers to their names
const char *gesture_names[] = {"Rock", "Paper", "Scissors"};

// this function is used to determine if gesture 2 wins or loses
//  returns 1 for win, 0 for tie, -1 for loss
int determine_winner(int gesture_1, int gesture_2) {
    if (gesture_1 == 0) {               // gesture_1 is rock
        if (gesture_2 == 1) {           // gesture_2 is paper - 2 wins
            return 1;
        } else if (gesture_2 == 0) {    // gesture_2 is rock - tie
            return 0;
        } else {                        // gesture_2 is scissors - 2 loses
            return -1; 
        }
    } else if (gesture_1 == 1) {        // gesture_1 is paper
        if (gesture_2 == 2) {           // gesture_2 is scissors - 2 wins
            return 1;
        } else if (gesture_2 == 1) {    // gesture_2 is paper - tie
            return 0;
        } else {                        // gesture_2 is rock - 2 loses
            return -1; 
        }
    } else {                            // gesture_1 is scissors
        if (gesture_2 == 0) {           // gesture_2 is rock - 2 wins
            return 1;
        } else if (gesture_2 == 2) {    // gesture_2 is scissors - tie
            return 0;
        } else {                        // gesture_2 is paper - 2 loses
            return -1; 
        }
    }
}

// this is the function that gets executed when the program starts
int main() {
    int computer;
    int human;
    int winner;
    char play_again;

    // Seed the random number generator only once
    srand(time(NULL));

    do {
        // randomly pick computer gesture
        computer = rand() % 3; // Generates a random number between 0 and 2

        // ask human for their gesture
        printf("Please enter your gesture\n");
        printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors: ");
        scanf("%d", &human);

        // Validate user input
        if (human < 0 || human > 2) {
            printf("Invalid input! Please enter 0, 1, or 2.\n");
            continue; // Skip the rest of the loop and prompt again
        }

        // determine winner (calls determine_winner function described above)
        winner = determine_winner(computer, human);

        // show outcome of game
        printf("The computer chose %s and you chose %s.\n", gesture_names[computer], gesture_names[human]);
        if (winner == 1)
            printf("You win!\n");
        else if (winner == 0) {
            printf("The game is a tie.\n");
            }
        } else if (winner == -1)
            printf("Computer wins!\n");

    } while (1); // Infinite loop, exits only when the user chooses to quit

    printf("Thanks for playing!\n");

    return 0;
}