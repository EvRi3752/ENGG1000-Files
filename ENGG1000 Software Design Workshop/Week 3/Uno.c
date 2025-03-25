#include <stdio.h>
#include <stdbool.h>

// Function to check if a player has won the game
bool determine_winner(int player_card_count, int computer_card_count) {
    if (player_card_count == 0) {
        printf("Player wins the game!\n");
        return true;
    }
    if (computer_card_count == 0) {
        printf("Computer wins the game!\n");
        return true;
    }
    return false;
}

int main() {
    // Example usage of the determine_winner function
    int player_cards = 5;
    int computer_cards = 3;
    
    // Simulate the game loop (this would be expanded in further exercises)
    while (true) {
        printf("Player has %d cards. Computer has %d cards.\n", player_cards, computer_cards);
        
        // Simulate a turn where a player or computer plays a card
        player_cards--;  // Example of the player playing a card
        
        // Check for a winner
        if (determine_winner(player_cards, computer_cards)) {
            break;
        }
        
        computer_cards--;  // Example of the computer playing a card
        
        // Check again for a winner
        if (determine_winner(player_cards, computer_cards)) {
            break;
        }
    }
    
    return 0;
}
