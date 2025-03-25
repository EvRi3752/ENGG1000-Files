#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

const char *gesture_names[] = {"Rock", "Paper", "Scissors", "Lizard", "Spock"}; 

int determine_winner(int player1, int player2){ 
    if (player1 == player2) {
        return 0; // Tie
    }
    else if ((player1 == 0 && player2 == 2) || // Rock beats Scissors
             (player1 == 1 && player2 == 0) || // Paper beats Rock
             (player1 == 2 && player2 == 1) || // Scissors beats paper
             (player1 == 0 && player2 == 3) || // Rock beats Lizard
             (player1 == 3 && player2 == 4) || // Lizard beats Spock
             (player1 == 4 && player2 == 2) || // Spock beats Scissors 
             (player1 == 2 && player2 == 3) || // Scissors beats Lizard
             (player1 == 3 && player2 == 1) || // Lizard beats paper
             (player1 == 1 && player2 == 4) || // Paper beats Spock
             (player1 == 4 && player2 == 0)) { // Spock beats rock
        return 1; // Player 1 wins
    } 
    else {
        return -1; // Player 2 wins
    }
}

void human_computer(){
    int computer; 
    int human;
    int winner;
    char play_again;
    int round = 1;
    const int max_rounds = 5;
    int player_score = 0, computer_score = 0;

    srand(time(NULL));

    do {
        player_score = 0;
        computer_score = 0;
        
        for (round = 1; round <= max_rounds; round++) {
            printf("\n--- Round %d of %d ---\n", round, max_rounds);
            printf("Score: You %d - %d Computer\n", player_score, computer_score);
            
            computer = rand() % 5; 
            printf("Please enter your gesture\n"); 
            printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors, 3 for Lizard, 4 for Spock: "); 
            scanf("%d", &human); 

            if (human < 0 || human > 4) { 
                printf("Invalid Input! Please enter either 0, 1, 2, 3, or 4.\n"); 
                round--; // Don't count this invalid attempt as a round
                continue; 
            }
            
            winner = determine_winner(human, computer); 
            printf("The computer chose %s and you chose %s.\n", gesture_names[computer], gesture_names[human]); 
            
            if (winner == 1) {
                printf("You win this round!\n");
                player_score++;
            }
            else if (winner == 0) {
                printf("This round is a tie.\n");
            }
            else if (winner == -1) {
                printf("Computer wins this round!\n");
                computer_score++;
            }
        }

        // Match results
        printf("\n=== Final Results ===\n");
        printf("You: %d points\nComputer: %d points\n", player_score, computer_score);
        if (player_score > computer_score) {
            printf("You win the match!\n");
        } else if (computer_score > player_score) {
            printf("Computer wins the match!\n");
        } else {
            printf("The match is a tie!\n");
        }

        printf("\nDo you want to play another match? (y/n): ");
        getchar(); // Clear the newline character left by scanf
        play_again = getchar();
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");
}

void computer_computer(){
    int computer1; 
    int computer2;
    int winner;
    char play_again;
    int round = 1;
    const int max_rounds = 5;
    int comp1_score = 0, comp2_score = 0;

    srand(time(NULL));

    do {
        comp1_score = 0;
        comp2_score = 0;
        
        for (round = 1; round <= max_rounds; round++) {
            printf("\n--- Round %d of %d ---\n", round, max_rounds);
            printf("Score: Computer1 %d - %d Computer2\n", comp1_score, comp2_score);
            
            computer1 = rand() % 5;
            computer2 = rand() % 5;

            winner = determine_winner(computer1, computer2); 
            printf("Computer1 chose %s and Computer2 chose %s.\n", 
                  gesture_names[computer1], gesture_names[computer2]); 
            
            if (winner == 1) {
                printf("Computer2 wins this round!\n");
                comp2_score++;
            }
            else if (winner == 0) {
                printf("This round is a tie.\n");
            }
            else if (winner == -1) {
                printf("Computer1 wins this round!\n");
                comp1_score++;
            }
        }

        // Match results
        printf("\n=== Final Results ===\n");
        printf("Computer1: %d points\nComputer2: %d points\n", comp1_score, comp2_score);
        if (comp1_score > comp2_score) {
            printf("Computer1 wins the match!\n");
        } else if (comp2_score > comp1_score) {
            printf("Computer2 wins the match!\n");
        } else {
            printf("The match is a tie!\n");
        }

        printf("\nDo you want to see another match? (y/n): ");
        getchar(); // Clear the newline character left by scanf
        play_again = getchar();
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for watching!\n");
}

void human_human(){ 
    int human1; 
    int human2;
    int winner;
    char play_again;
    int round = 1;
    const int max_rounds = 5;
    int player1_score = 0, player2_score = 0;

    srand(time(NULL));

    do {
        player1_score = 0;
        player2_score = 0;
        
        for (round = 1; round <= max_rounds; round++) {
            printf("\n--- Round %d of %d ---\n", round, max_rounds);
            printf("Score: Player1 %d - %d Player2\n", player1_score, player2_score);
            
            printf("Player 1, enter your gesture\n"); 
            printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors, 3 for Lizard, 4 for Spock: "); 
            scanf("%d", &human1); 

            if (human1 < 0 || human1 > 4) { 
                printf("Invalid Input! Please enter either 0, 1, 2, 3, or 4.\n"); 
                round--; // Don't count this invalid attempt as a round
                continue; 
            }
            
            printf("Player 2, enter your gesture\n"); 
            printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors, 3 for Lizard, 4 for Spock: "); 
            scanf("%d", &human2); 

            if (human2 < 0 || human2 > 4) { 
                printf("Invalid Input! Please enter either 0, 1, 2, 3, or 4.\n"); 
                round--; // Don't count this invalid attempt as a round
                continue; 
            }
            
            winner = determine_winner(human1, human2); 
            printf("Player1 chose %s and Player2 chose %s.\n", 
                  gesture_names[human1], gesture_names[human2]); 
            
            if (winner == 1) {
                printf("Player2 wins this round!\n");
                player2_score++;
            }
            else if (winner == 0) {
                printf("This round is a tie.\n");
            }
            else if (winner == -1) {
                printf("Player1 wins this round!\n");
                player1_score++;
            }
        }

        // Match results
        printf("\n=== Final Results ===\n");
        printf("Player1: %d points\nPlayer2: %d points\n", player1_score, player2_score);
        if (player1_score > player2_score) {
            printf("Player1 wins the match!\n");
        } else if (player2_score > player1_score) {
            printf("Player2 wins the match!\n");
        } else {
            printf("The match is a tie!\n");
        }

        printf("\nDo you want to play another match? (y/n): ");
        getchar(); // Clear the newline character left by scanf
        play_again = getchar();
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");
}

int main(){
    int selec;
    printf("Select Mode of Play\nPvC=1\nCvC=2\nPvP=3\n: ");
    scanf("%d", &selec); 
    if (selec == 1){ 
        human_computer();
    }
    else if (selec == 2){
        computer_computer();
    }
    else if (selec == 3){ 
        human_human();
    }
    else {
        printf("Invalid selection. Exiting.\n");
    }
    return 0; 
}