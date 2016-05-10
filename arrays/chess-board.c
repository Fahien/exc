#include <stdio.h>
#include <stdlib.h>

/*
 * Program that declares an 8x8 char array named chess_board
 */
int main (void)
{
    // Declare and initialize the chess board
    char chess_board[8][8] = {
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    // Print out the chess board
    for (unsigned i = 0; i < 8; ++i) {
        for (unsigned j = 0; j < 8; ++j) {
            printf("%c ", chess_board[i][j]);
        }
        printf("\b\n");
    }

    return EXIT_SUCCESS;
}
