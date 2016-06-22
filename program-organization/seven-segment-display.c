///
// This program displays a number using characters 
// to simulate the effect of a seven-segment display
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char* char_table[3][10] = {
    //  0       1       2       3       4       5       6       7       8       9
    { " _  ", "    ", " _  ", " _  ", "    ", " _  ", " _  ", " _  ", " _  ", " _  " },
    { "│ │ ", " │  ", " _│ ", " _│ ", "│_│ ", "│_  ", "│_  ", "  │ ", "│_│ ", "│_│ " },
    { "│_│ ", " │  ", "│_  ", " _│ ", "  │ ", " _│ ", "│_│ ", "  │ ", "│_│ ", " _│ " }
};

void print_char(char c, int i)
{
    // Do nothing if c is not a digit
    if (c < '0' || c > '9') return;
    printf("%s", char_table[i][c - '0']);
}

int main(int argc, char **argv)
{
    // Check for cli argument error
    if (argc < 2) {
        fprintf(stderr, "Usage: ./seven-segment-display number\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 3; ++i) {
    // For all characters in the string
    char c = 0;
        for (int j = 0; (c = argv[1][j]) != 0; ++j) {
            print_char(c, i);
        }
        printf("\n");
    }
    printf("\b");

    return EXIT_SUCCESS;
}
