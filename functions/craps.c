/**
 * This is a program that simulates the game of craps, which is played with two dice.
 * On the first roll, the player wins if the sum of the dice is 7 or 11. The player
 * loses if the sum is 2, 3, or 12. Any other roll is called the "point" and the game
 * continues. On each subsequent roll, the player wins if he or she rolls the point
 * again. The player loses by rolling 7. Any other roll is ignored and the game
 * continues. At the end of each game, the program will ask the user whether or not
 * to play again. When the user enters a response other than y or Y, the program will
 * display the number of wins and losses and then terminate.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * This function simulates a roll of two dishes
 */
int roll()
{
    int dice_one = rand() % 6 + 1;
    int dice_two = rand() % 6 + 1;
    return dice_one + dice_two;
}

int main ()
{
    // Initialize rand with time seed
    srand((unsigned)time(NULL));

    int turns = 0; // Turns played
    int point = 0; // The point

    // Game loop
    while (true) {
        
        // First turn
        if (turns == 0) {
            int roll_one = roll();
            printf("First roll: %d\n", roll_one);

            // Win on the first turn!
            if (roll_one == 7 || roll_one == 11) {
                printf("You win!\n");
                break; // Exit from game loop
            }

            // Lose on the first turn..
            if (roll_one == 2 || roll_one == 3 || roll_one == 12) {
                printf("You lose..\n");
                break; // Exit from game loop
            }

            // Roll one is just the "point"
            point = roll_one;
            printf("The point is %d\n", point);
        }
        // Normal turn
        else {
            int roll_normal = roll();
            printf("Roll number %d is %d\n", turns + 1, roll_normal);

            // Lose if it is 7
            if (roll_normal == 7) {
                printf("You lose..\n");
                break; // Exit from game loop
            }

            // Win if it's the point!
            if (roll_normal == point) {
                printf("You win!\n");
                break; // Exit from game loop
            }

            printf("Roll ignored\n");
        }

        turns++;

        printf("Would you play again? ");
        char response = 0;
        fgets(&response, sizeof(char) * 2, stdin);
        if (response == 'n' && response == 'N') break; // Exit from game loop

    } // End Game Loop

    printf("Turns played: %d\n", turns);
}
