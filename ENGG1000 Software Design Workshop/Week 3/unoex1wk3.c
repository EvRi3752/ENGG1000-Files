#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Defines the number of cards in the deck
#define DECK_SIZE 54

// Define the colors and values of UNO cards
const char *colors[] = {"Red", "Green", "Blue", "Yellow"};
const char *values[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+2", "+4"};

// Structure to represent a card
typedef struct {
    const char *color;
    const char *value;
} Card;

// Function to initialize the deck
void initializeDeck(Card deck[]) {
    int index = 0;

    // Add number cards (0-9) and +2 cards for each color
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 12; j++) {
            deck[index].color = colors[i];
            deck[index].value = values[j];
            index++;
        }
    }

    // Add +4 cards (no color, represented as "Wild")
    for (int i = 0; i < 4; i++) {
        deck[index].color = "Wild";
        deck[index].value = "+4";
        index++;
    }
}

// Function to shuffle the deck using the Fisher-Yates algorithm
void shuffleDeck(Card deck[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap deck[i] and deck[j]
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to display a hand of cards
void displayHand(Card hand[], int handSize, const char *playerName) {
    printf("%s's hand:\n", playerName);
    for (int i = 0; i < handSize; i++) {
        printf("%d: %s %s\n", i + 1, hand[i].color, hand[i].value);
    }
}

// Function to check if a card can be played on the top card
bool isValidMove(Card topCard, Card playerCard) {
    if (strcmp(playerCard.color, "Wild") == 0 || strcmp(playerCard.color, topCard.color) == 0 ||
        strcmp(playerCard.value, topCard.value) == 0) {
        return true;
    }
    return false;
}

// Function to draw a card from the deck
void drawCard(Card deck[], int *deckSize, Card hand[], int *handSize) {
    if (*deckSize > 0) {
        hand[*handSize] = deck[*deckSize - 1];
        (*handSize)++;
        (*deckSize)--;
    } else {
        printf("The deck is empty!\n");
    }
}

// Main game loop
void playGame(Card deck[], int deckSize) {
    Card playerHand[54], computerHand[54];
    int playerHandSize = 0, computerHandSize = 0;
    Card topCard;
    int currentPlayer = 0; // 0 for player, 1 for computer
    bool gameOver = false;

    // Deal initial cards (7 cards to each player)
    for (int i = 0; i < 7; i++) {
        drawCard(deck, &deckSize, playerHand, &playerHandSize);
        drawCard(deck, &deckSize, computerHand, &computerHandSize);
    }

    // Set the top card from the deck
    topCard = deck[deckSize - 1];
    deckSize--;

    printf("Top card: %s %s\n", topCard.color, topCard.value);

    while (!gameOver) {
        if (currentPlayer == 0) {
            // Player's turn
            printf("\nYour turn!\n");
            displayHand(playerHand, playerHandSize, "Player");

            int choice;
            printf("Enter the number of the card you want to play (or 0 to draw a card): ");
            scanf("%d", &choice);

            if (choice == 0) {
                // Draw a card
                drawCard(deck, &deckSize, playerHand, &playerHandSize);
                printf("You drew a card.\n");
            } else if (choice > 0 && choice <= playerHandSize) {
                // Check if the chosen card is valid
                Card chosenCard = playerHand[choice - 1];
                if (isValidMove(topCard, chosenCard)) {
                    // Play the card
                    topCard = chosenCard;
                    printf("You played: %s %s\n", topCard.color, topCard.value);

                    // Remove the card from the player's hand
                    for (int i = choice - 1; i < playerHandSize - 1; i++) {
                        playerHand[i] = playerHand[i + 1];
                    }
                    playerHandSize--;

                    // Check if the player has won
                    if (playerHandSize == 0) {
                        printf("You win!\n");
                        gameOver = true;
                        break;
                    }
                } else {
                    printf("Invalid move! The card must match the color or value of the top card.\n");
                }
            } else {
                printf("Invalid choice!\n");
            }
        } else {
            // Computer's turn
            printf("\nComputer's turn!\n");

            bool playedCard = false;
            for (int i = 0; i < computerHandSize; i++) {
                if (isValidMove(topCard, computerHand[i])) {
                    // Play the first valid card
                    topCard = computerHand[i];
                    printf("Computer played: %s %s\n", topCard.color, topCard.value);

                    // Remove the card from the computer's hand
                    for (int j = i; j < computerHandSize - 1; j++) {
                        computerHand[j] = computerHand[j + 1];
                    }
                    computerHandSize--;

                    // Check if the computer has won
                    if (computerHandSize == 0) {
                        printf("Computer wins!\n");
                        gameOver = true;
                        break;
                    }

                    playedCard = true;
                    break;
                }
            }

            if (!playedCard) {
                // Draw a card if no valid card is found
                drawCard(deck, &deckSize, computerHand, &computerHandSize);
                printf("Computer drew a card.\n");
            }
        }

        // Switch turns
        currentPlayer = 1 - currentPlayer;
    }
}

int main() {
    Card deck[DECK_SIZE];
    int deckSize = DECK_SIZE;

    // Initialize the deck
    initializeDeck(deck);

    // Shuffle the deck
    shuffleDeck(deck, deckSize);

    // Start the game
    playGame(deck, deckSize);

    return 0;
}