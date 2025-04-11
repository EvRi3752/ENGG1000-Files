#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <assert.h>

const char *gesture_names[] = {"Rock", "Paper", "Scissors", "Lizard", "Spock", "Air", "Water", "Sponge", "Fire"}; // Rock=0, Paper=1, Scissors=2, Lizard=3, Spock=4, Air=5, Water=6, Sponge=7, Fire=8

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
             (player1 == 4 && player2 == 0) || // Spock beats Rock
             (player1 == 0 && player2 == 8) || // Rock beats fire
              (player1 == 0 && player2 == 7) || // Rock beats sponge 
              (player1 == 8 && player2 == 2) || // Fire beats scissors
              (player1 == 8 && player2 == 1) || // Fire beats paper
              (player1 == 8 && player2 == 7) || // Fire beats sponge
              (player1 == 2 && player2 == 5) || // Scissors beats Air
              (player1 == 2 && player2 == 7) || // Scissors beats Sponge
              (player1 == 7 && player2 == 1) || // Sponge beats paper
              (player1 == 7 && player2 == 5) || // Sponge beats air
              (player1 == 7 && player2 == 6) || // Sponge beats water 
              (player1 == 1 && player2 == 5) || // Paper beats air
               (player1 == 1 && player2 == 6) || // Paper beats water
               (player1 == 5 && player2 == 8) || // Air beats fire
               (player1 == 5 && player2 == 0) || // Air beats rock
               (player1 == 5 && player2 == 6) || // Air beats water
               (player1 == 6 && player2 == 0) || // Water beats rock
               (player1 == 6 && player2 == 8) || // Water beats fire 
               (player1 == 6 && player2 == 2) || // Water beats scissors
               (player1 == 3 && player2 == 5) ||  // Lizard beats Air
             (player1 == 3 && player2 == 6) ||  // Lizard beats Water
             (player1 == 3 && player2 == 7) ||  // Lizard beats Sponge
             (player1 == 3 && player2 == 8) ||  // Lizard beats Fire
             (player1 == 4 && player2 == 5) ||  // Spock beats Air
             (player1 == 4 && player2 == 6) ||  // Spock beats Water
             (player1 == 4 && player2 == 7) ||  // Spock beats Sponge
             (player1 == 4 && player2 == 8) || // Spock beats Fire
             (player1 == 5 && player2 == 3) ||  // Air beats Lizard
             (player1 == 5 && player2 == 4) ||  // Air beats Spock
             (player1 == 6 && player2 == 3) ||  // Water beats Lizard
             (player1 == 6 && player2 == 4) ||  // Water beats Spock
             (player1 == 7 && player2 == 3) ||  // Sponge beats Lizard
             (player1 == 7 && player2 == 4) ||  // Sponge beats Spock
             (player1 == 8 && player2 == 3) ||  // Fire beats Lizard
             (player1 == 8 && player2 == 4)) {  // Fire beats Spock) 
        return 1; // Player 1 wins
    } 
    else {
        return -1; // Player 2 wins
    }
}

void unit_tests(){
    printf("Running unit tests...\n");
    
    // Test all winning conditions 
    printf("Testing winning conditions...\n");
    assert(determine_winner(0, 2) == 1);   // Rock beats Scissors
    assert(determine_winner(1, 0) == 1);   // Paper beats Rock
    assert(determine_winner(2, 1) == 1);   // Scissors beats Paper
    assert(determine_winner(0, 3) == 1);   // Rock beats Lizard
    assert(determine_winner(3, 4) == 1);   // Lizard beats Spock
    assert(determine_winner(4, 2) == 1);   // Spock beats Scissors
    assert(determine_winner(2, 3) == 1);   // Scissors beats Lizard
    assert(determine_winner(3, 1) == 1);   // Lizard beats Paper
    assert(determine_winner(1, 4) == 1);   // Paper beats Spock
    assert(determine_winner(4, 0) == 1);   // Spock beats Rock
    assert(determine_winner(0, 8) == 1);   // Rock beats Fire
    assert(determine_winner(0, 7) == 1);   // Rock beats Sponge
    assert(determine_winner(8, 2) == 1);   // Fire beats Scissors
    assert(determine_winner(8, 1) == 1);   // Fire beats Paper
    assert(determine_winner(8, 7) == 1);   // Fire beats Sponge
    assert(determine_winner(2, 5) == 1);   // Scissors beats Air
    assert(determine_winner(2, 7) == 1);   // Scissors beats Sponge
    assert(determine_winner(7, 1) == 1);   // Sponge beats Paper
    assert(determine_winner(7, 5) == 1);   // Sponge beats Air
    assert(determine_winner(7, 6) == 1);   // Sponge beats Water
    assert(determine_winner(1, 5) == 1);   // Paper beats Air
    assert(determine_winner(1, 6) == 1);   // Paper beats Water
    assert(determine_winner(5, 8) == 1);   // Air beats Fire
    assert(determine_winner(5, 0) == 1);   // Air beats Rock
    assert(determine_winner(5, 6) == 1);   // Air beats Water
    assert(determine_winner(6, 0) == 1);   // Water beats Rock
    assert(determine_winner(6, 8) == 1);   // Water beats Fire
    assert(determine_winner(6, 2) == 1);   // Water beats Scissors
    assert(determine_winner(3, 5) == 1);   // Lizard beats Air
    assert(determine_winner(3, 6) == 1);   // Lizard beats Water
    assert(determine_winner(3, 7) == 1);   // Lizard beats Sponge
    assert(determine_winner(3, 8) == 1);   // Lizard beats Fire
    assert(determine_winner(4, 5) == 1);   // Spock beats Air
    assert(determine_winner(4, 6) == 1);   // Spock beats Water
    assert(determine_winner(4, 7) == 1);   // Spock beats Sponge
    assert(determine_winner(4, 8) == 1);   // Spock beats Fire
    assert(determine_winner(5, 3) == 1);   // Air beats Lizard
    assert(determine_winner(5, 4) == 1);   // Air beats Spock
    assert(determine_winner(6, 3) == 1);   // Water beats Lizard
    assert(determine_winner(6, 4) == 1);   // Water beats Spock
    assert(determine_winner(7, 3) == 1);   // Sponge beats Lizard
    assert(determine_winner(7, 4) == 1);   // Sponge beats Spock
    assert(determine_winner(8, 3) == 1);   // Fire beats Lizard
    assert(determine_winner(8, 4) == 1);   // Fire beats Spock

    // Test all ties
    printf("Testing tie conditions...\n");
    for (int i = 0; i < 9; i++) {
        assert(determine_winner(i, i) == 0);
    }
    
    // Test losing conditions (reverse of winning conditions)
    printf("Testing losing conditions...\n");
    assert(determine_winner(2, 0) == -1);  // Scissors loses to Rock
    assert(determine_winner(0, 1) == -1);  // Rock loses to Paper
    assert(determine_winner(1, 2) == -1);  // Paper loses to Scissors
    assert(determine_winner(3, 0) == -1);  // Lizard loses to Rock
    assert(determine_winner(4, 3) == -1);  // Spock loses to Lizard
    assert(determine_winner(8, 0) == -1);  // Fire loses to Rock
    assert(determine_winner(7, 0) == -1);  // Sponge loses to Rock
    assert(determine_winner(2, 8) == -1);  // Scissors loses to Fire
    assert(determine_winner(1, 8) == -1);  // Paper loses to Fire
    assert(determine_winner(7, 8) == -1);  // Sponge loses to Fire
    assert(determine_winner(5, 2) == -1);  // Air loses to Scissors
    assert(determine_winner(7, 2) == -1);  // Sponge loses to Scissors
    assert(determine_winner(1, 7) == -1);  // Paper loses to Sponge
    assert(determine_winner(5, 7) == -1);  // Air loses to Sponge
    assert(determine_winner(6, 7) == -1);  // Water loses to Sponge
    assert(determine_winner(5, 1) == -1);  // Air loses to Paper
    assert(determine_winner(6, 1) == -1);  // Water loses to Paper
    assert(determine_winner(8, 5) == -1);  // Fire loses to Air
    assert(determine_winner(0, 5) == -1);  // Rock loses to Air
    assert(determine_winner(6, 5) == -1);  // Water loses to Air
    assert(determine_winner(0, 6) == -1);  // Rock loses to Water
    assert(determine_winner(8, 6) == -1);  // Fire loses to Water
    assert(determine_winner(2, 6) == -1);  // Scissors loses to Water

    printf("All unit tests passed!\n");
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
            
            computer = rand() % 9; 
            printf("Please enter your gesture\n"); 
            printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors, 3 for Lizard, 4 for Spock, 5 for Air, 6 for Water, 7 for Sponge, 8 for Fire: "); 
            scanf("%d", &human); 

            if (human < 0 || human > 8) { 
                printf("Invalid Input! Please enter either 0, 1, 2, 3, 4, 5, 6, 7, or 8.\n"); 
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
            
            computer1 = rand() % 9;
            computer2 = rand() % 9;

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
            printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors, 3 for Lizard, 4 for Spock, 5 for Air, 6 for Water, 7 for Sponge, 8 for Fire: "); 
            scanf("%d", &human1); 

            if (human1 < 0 || human1 > 8) { 
                printf("Invalid Input! Please enter either 0, 1, 2, 3, 4, 5, 6, 7, or 8.\n"); 
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
    else if (selec ==4){
        unit_tests();
    }
    else {
        printf("Invalid selection. Exiting.\n");
    }
    return 0; 
}