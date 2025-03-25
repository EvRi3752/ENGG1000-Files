#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// ^ imports libraries to enable the user of functions such as printf, scanf, rand, and strand

// Defines the number of cards in the deck
// Defines a constant DECK_SIZE with the value 54, representing the total number of cards in the deck.
#define DECK_SIZE 54

// Define the colors and values of UNO cards
const char *colors[] = {"Red", "Green", "Blue", "Yellow"}; // defines an array of strings for the four colours in UNO
const char *values[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+2", "+4"}; //defines an array of integers representing the card values

// Structure to represent a card
typedef struct { 
    const char *color; //points to the string containing the colors
    const char *value; //points to the string containing the values
} Card;

// Function to initialize the deck
void initializeDeck(Card deck[]) {
    int index = 0; // Keeps track of the current position in the index array

    // Nested loop - Add number cards (0-9) and +2 cards for each color
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 12; j++) {
            deck[index].color = colors[i]; // Outer loop that iterates over four colours
            deck[index].value = values[j]; // Inner loop that iterates over the 12 values (0 - 9, +12)
            index++;
        }
    }

    // Adds +4 cards (no color, represented as "Wild") <- this runs AFTER the nested loop
    for (int i = 0; i < 4; i++) {
        deck[index].color = "Wild";
        deck[index].value = "+4";
        index++;
    }
}

// Function to shuffle the deck using the "Fisher-Yates algorithm" <- look more into this later
void shuffleDeck(Card deck[], int size) {
    srand(time(NULL)); // Seeds the random number generator with the current time to ensure different shuffles each time the program runs.
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Generate a random index between 0 and i
        // Swap deck[i] and deck[j] - card temp is a temporary variable used to swap different cards
        Card temp = deck[i]; // This loop iterates from the last card to the first 
        deck[i] = deck[j]; // For each card at index "I", a random index "J" is generated between 0 and 1 to which the card at index i is swapped with J
        deck[j] = temp; 
    }
}

// Function to display the first 10 cards of the deck
void displayFirst10Cards(Card deck[]) {
    printf("First 10 cards in the shuffled deck:\n"); // displays a header for the output
    for (int i = 0; i < 10; i++) {
        printf("Card %d: %s %s\n", i + 1, deck[i].color, deck[i].value);
    }
}

int main() {
    Card deck[DECK_SIZE]; // Declares an array of Card structures to represent the deck.

    // Initializes the deck
    initializeDeck(deck); // Calls the function to initialize the deck with cards.

    // Shuffles the deck
    shuffleDeck(deck, DECK_SIZE); // Calls the function to shuffle the deck.

    // Displays the first 10 cards of the shuffled deck
    displayFirst10Cards(deck); // Calls the function to display the first 10 cards of the shuffled deck.

    return 0;
}