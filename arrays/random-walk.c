#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_LIM 10

#define DIRECTION_COUNT 4
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

bool way_out(char board[BOARD_LIM][BOARD_LIM], int x, int y)
{
    bool up = false;
    bool right = false;
    bool down = false;
    bool left = false;
    // Test right
    if (x < BOARD_LIM - 1 && *(*(board + y) + x + 1) == '.') right = true;
    // Test up
    if (y > 0 && *(*(board + y - 1) + x) == '.') up = true;
    // Test down
    if (y < BOARD_LIM - 1 && *(*(board + y + 1) + x) == '.') down = true;
    // Test left
    if (x > 0 && *(*(board + y) + x - 1) == '.') left = true;
    // No way out
    return up || right || down || left;
}

/*
 * Program that generates a "random walk" across a 10x10 array.
 * The array contains characters (all '.' initially).
 * The program randomly walks from element to element, always going up,
 * down, left or right by one element. The element visited is labeled
 * with letters A through Z, in the order visited.
 */
int main (void)
{
    // Seed rand with current time
    srand((unsigned)time(NULL));

    // Current position
    int x = 0;
    int y = 0;

    // Declare the array
    char board[BOARD_LIM][BOARD_LIM];

    // Initialize with '.'
    for (int i = 0; i < BOARD_LIM; i++) {
        memset(*(board + i), '.', sizeof(*(board + i)));
    }

    // Print out the board
    for (int i = 0; i < BOARD_LIM; i++) {
        for (int j = 0; j < BOARD_LIM; j++) {
            printf("%c ", *(*(board + i) + j));
        }
        printf("\b\n");
    }

    // Direction - 0 UP - 1 RIGHT - 2 DOWN - 3 LEFT
    int direction;

    **board = 'A';
    // Loop the alphabet
    for (char c = 'B'; c <= 'Z';) {
        // Get a random direction
        direction = rand() % DIRECTION_COUNT;
        
        if (!way_out(board, x, y)) {
            fprintf(stderr, "No way out\n");
            break;
        }

        // Update coordinates
        switch (direction) {
            case UP:
                printf("Testing UP\n");
                if (y <= 0) {
                    printf("Skipping UP\n");
                    goto END_LOOP;
                }
                if (*(*(board + y - 1) + x) != '.') {
                    goto END_LOOP;
                }
                --y;
                break;
            case RIGHT:
                printf("Testing RIGHT\n");
                if (x >= BOARD_LIM - 1) {
                    printf("Skipping RIGHT\n");
                    goto END_LOOP;
                }
                if (*(*(board + y) + x + 1) != '.') {
                    goto END_LOOP;
                }
                ++x;
                break;
            case DOWN:
                printf("Testing DOWN\n");
                if (y >= BOARD_LIM - 1) {
                    printf("Skipping DOWN\n");
                    goto END_LOOP;
                }
                if (*(*(board + y + 1) + x) != '.') {
                    goto END_LOOP;
                }
                ++y;
                break;
            case LEFT:
                printf("Testing LEFT\n");
                if (x <= 0) {
                    printf("Skipping LEFT\n");
                    goto END_LOOP;
                }
                if (*(*(board + y) + x - 1) != '.') {
                    goto END_LOOP;
                }
                --x;
                break;
            default:
                fprintf(stderr, "Invalid direction %d\n", direction);
                return EXIT_FAILURE;
        }

        printf("Signing %d,%d with %c\n", x, y, c);
        // Sign the board
        *(*(board + y) + x) = c;
        // Increment character
        ++c;
END_LOOP:;
    }

    // Print out the board
    for (int i = 0; i < BOARD_LIM; i++) {
        for (int j = 0; j < BOARD_LIM; j++) {
            printf("%c ", *(*(board + i) + j));
        }
        printf("\b\n");
    }

    return EXIT_SUCCESS;
}
