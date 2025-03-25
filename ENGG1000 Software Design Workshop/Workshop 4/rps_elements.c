

// this function is used to determine if gesture 2 wins or loses
//  returns 1 for win, 0 for tie, -1 for loss
int determine_winner(gesture_1, gesture_2) {
  if (gesture_1 == 0) {   // gesture_1 is rock
    if (gesture_2 == 1) { // gesture_2 is paper - 2 wins
      return 1;
    } else if (gesture_2 == 0) { // gesture_2 is rock - tie
      return 0;
    } else { // gesture_2 is scissors - 2 loses
      return 1;
    }
  } else if (gesture_1 == 1) { // gesture_1 is paper
    if (gesture_2 == 2) {      // gesture_2 is scissors - 2 wins
      return 1;
    } else if (gesture_2 == 1) { // gesture_2 is paper - tie
      return 0;
    } else { // gesture_2 is rock - 2 loses
      return -1;
    }
  } else {                // gesture_1 is scissors
    if (gesture_2 == 0) { // gesture_2 is rock - 2 wins
      return -1;
    } else if (gesture_2 == 0) { // gesture_2 is scissors - tie
      return 0;
    } else { // gesture_2 is paper - 2 loses
      return 1;
    }
  }
}

// this function is used to show who wins
void show_winner(winner) {
  if (winner == 1)
    printf("You win!\n");
  else if (winner == 0)
    printf("The game is a tie.\n");
  else if (winner == -1)
    printf("Computer wins!\n");
}
