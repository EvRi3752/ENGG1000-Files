/**
    Test the functionality of determine_winner
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *gesture_names[] = {"Rock", "Paper", "Scissors"};

int determine_winner(int gesture_1, int gesture_2) {
    if (gesture_1 == 0) {               // gesture_1 is rock
        if (gesture_2 == 1) {           // gesture_2 is paper - 2 wins
            return -1;
        } else if (gesture_2 == 0) {    // gesture_2 is rock - tie
            return 0;
        } else {                        // gesture_2 is scissors - 2 loses
            return 1; 
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

void show_winner(int winner) {
    if (winner == 1)
        printf("You win!\n");
    else if (winner == 0)
        printf("The game is a tie.\n");
    else if (winner == -1)
        printf("Computer wins!\n");
}

void test_check_gesture(int gesture) {
    printf("gesture rock validity: ");
    if (determine_winner(gesture, gesture) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");
}

void test_check_gesture2(int gesture) {
    printf("gesture paper validity: ");
    if (determine_winner(gesture, gesture) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");
}

void test_check_gesture3(int gesture) {
    printf("gesture scissors validity: ");
    if (determine_winner(gesture, gesture) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");
}

int get_gesture() {
    int gesture;
    printf("Please enter your gesture\n");
    printf("Enter 0 for rock, 1 for paper, 2 for scissors: ");
    scanf("%d", &gesture);
    return gesture;
}

int get_random_gesture() {
    return rand() % 3;
}

void test_determine_winner(int gesture2) {
    printf("Tie Test: ");
    if (determine_winner(gesture2, gesture2) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Lose Test: ");
    if (determine_winner(1, gesture2) == -1)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Win Test: ");
    if (determine_winner(2, gesture2) == 1)
        printf("Passed\n");
    else
        printf("Failed\n");
}

void test_determine_winner2(int gesture1) {
    printf("Tie Test: ");
    if (determine_winner(gesture1, gesture1) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Lose Test: ");
    if (determine_winner(2, gesture1) == -1)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Win Test: ");
    if (determine_winner(0, gesture1) == 1)
        printf("Passed\n");
    else
        printf("Failed\n");
}

void test_determine_winner3(int gesture2) {
    printf("Tie Test: ");
    if (determine_winner(gesture2, gesture2) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Lose Test: ");
    if (determine_winner(0, gesture2) == -1)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Win Test: ");
    if (determine_winner(1, gesture2) == 1)
        printf("Passed\n");
    else
        printf("Failed\n");
}

void human_computer1() {
    int computer;
    int human;
    int winner;
    char play_again;

    srand(time(NULL));

    do {
        computer = rand() % 3;
        printf("Please enter your gesture\n");
        printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors: ");
        scanf("%d", &human);

        if (human < 0 || human > 2) {
            printf("Invalid input! Please enter 0, 1, or 2.\n");
            continue;
        }

        winner = determine_winner(computer, human);

        printf("The computer chose %s and you chose %s.\n", gesture_names[computer], gesture_names[human]);
        show_winner(winner);

        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');
}

void computer_computer() {
    int computer1;
    int computer2;
    int winner;

    srand(time(NULL));

    do {
        computer1 = rand() % 3;
        computer2 = rand() % 3;

        winner = determine_winner(computer1, computer2);

        printf("Computer1 chose %s and Computer2 chose %s.\n", gesture_names[computer1], gesture_names[computer2]);
        if (winner == 1)
            printf("Computer2 wins!\n");
        else if (winner == 0)
            printf("The game is a tie.\n");
        else
            printf("Computer1 wins!\n");

        printf("Run again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') break;
    } while (1);
}

void human_human() {
    int player1, player2;

    printf("Player 1, enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ");
    scanf("%d", &player1);

    printf("Player 2, enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ");
    scanf("%d", &player2);

    if (player1 < 0 || player1 > 2 || player2 < 0 || player2 > 2) {
        printf("Invalid input! Please enter 0, 1, or 2.\n");
        return;
    }

    int result = determine_winner(player1, player2);
    printf("Player 1 chose %s and Player 2 chose %s.\n", gesture_names[player1], gesture_names[player2]);
    
    if (result == 0) {
        printf("It's a tie!\n");
    } else if (result == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
}

int main() {
    srand(time(NULL));
    int selec;
    printf("Select Mode of Play\nPvC=1\nCvC=2\nPvP=3\n: ");
    scanf("%d", &selec); 
    if (selec == 0){ 
    printf("Testing when gesture 2 is rock\n");
    test_determine_winner(0);
    
    printf("Testing when gesture 1 is paper\n"); 
    test_determine_winner2(1);

    printf("Testing when gesture 2 is scissors\n");
    test_determine_winner3(2);

    printf("Testing validity of gesture rock\n");
    test_check_gesture(0);

    printf("Testing validity of gesture paper\n");
    test_check_gesture2(1);

    printf("Testing validity of gesture scissors\n");
    test_check_gesture3(2);
    }
    else if (selec == 1){
    printf("Playing player vs cpu\n"); 
    human_computer1();
    }
    else if (selec == 2){
    printf("Playing cpu vs cpu\n"); 
    computer_computer();
    }
    else if (selec == 3){
    printf("Playing player vs player\n"); 
    human_human();
    }
    else{
        printf("Invalid selection. Exiting.\n");
    }

    return 0;
}
