#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

int main(){
    int player1, player2;
    bool g = true; 

    while(g=false){// Prompt Player 1 for their choice
    printf("Player 1, enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ");
    scanf("%d", &player1);

    // Prompt Player 2 for their choice
    printf("Player 2, enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ");
    scanf("%d", &player2);

    // Check for valid inputs
    if (player1 < 0 || player1 > 2 || player2 < 0 || player2 > 2) {
        printf("Invalid input! Please enter 0, 1, or 2.\n");
        return 1; // Exit the program with an error code
    }

    // Determine the winner or if it's a tie
    if (player1 == player2) {
        printf("It's a tie!\n");
        printf("Would you like to play again? 1 if yes, 2 if no: ");
        scanf("%d", &player1, &player2);
    }if (player1 < 1 && player2 < 1)
         g=false

    }else if ((player1 == 0 && player2 == 2) || // Rock beats Scissors
               (player1 == 1 && player2 == 0) || // Paper beats Rock
               (player1 == 2 && player2 == 1)) { // Scissors beats Paper
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}