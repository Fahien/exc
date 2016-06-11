#include <stdio.h>
#include <stdlib.h>

/*
 * This function evaluates a chess position. "Board" represents a 
 * configuration of pieces on a chessboard, where the letters K, Q,
 * R, B, N, P represent White pieces, and the letters k, q, r, b, n, 
 * p represent Black pieces.
 * This function sums the values of the White and pieces (Q = 9, 
 * R = 5, B = 3, N = 3, P = 1), sums the values of the Black pieces 
 * and returns the difference between the two numbers. This value
 * will be positive if White has an advantage in materials and
 * negative if Black has an advantage.
 */
int evaluate_position(char board[8][8])
{
    // Initialize variables
    int white_sum = 0;
    int black_sum = 0;

    // Iterate the chessboard
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            switch(board[i][j]) {
              case 'Q': white_sum += 9; break;
              case 'R': white_sum += 5; break;
              case 'B': case 'N': white_sum += 3; break;
              case 'P': white_sum += 1; break;
              case 'q': black_sum += 9; break;
              case 'r': black_sum += 5; break;
              case 'b': case 'n': black_sum += 3; break;
              case 'p': black_sum += 1; break;
              default: break;
            }
        }
    }

    // Return the difference
    return white_sum - black_sum;
}

int main (void)
{
    char chessboard[8][8] = {0};

    // Place kings
    chessboard[0][4] = 'K';
    chessboard[7][4] = 'k';

    // Place queens
    chessboard[0][5] = 'Q';
    chessboard[7][5] = 'q';

    // Check no advantage
    printf("evaluate_position(chessboard) should be zero: %d\n", evaluate_position(chessboard));

    // Place a white pedon
    chessboard[1][3] = 'P';

    // Check white advantage
    printf("evaluate_position(chessboard) should be positive: %d\n", evaluate_position(chessboard));

    // Place The Black Knight!
    chessboard[6][2] = 'n';

    // Check black advantage
    printf("evaluate_position(chessboard) should be negative: %d\n", evaluate_position(chessboard));

    return EXIT_SUCCESS;
}
