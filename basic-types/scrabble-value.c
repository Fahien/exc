#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * Program that computer the value of a word in the SCRABBLE Crossword Game 
 */
int main (int argc, char** argv)
{
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./scrabble-value word\n");
        return EXIT_FAILURE;
    }

    int value = 0;
    char symbol;
    for (size_t i = 0; i < strlen(argv[1]); i++) {
        // Get next character;
        symbol = toupper(argv[1][i]);

        // Find and sum value
        switch (symbol) {
            case 'A': case 'E': case 'I': case 'L': case 'N':
            case 'O': case 'R': case 'S': case 'T': case 'U':
                value += 1; break;
            case 'D': case 'G':
                value += 2; break;
            case 'B': case 'C': case 'M': case 'P':
                value += 3; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                value += 4; break;
            case 'K':
                value += 5; break;
            case 'J': case 'X':
                value += 8; break;
            case 'Q': case 'Z':
                value += 10; break;
            default: break;
        }
    }

    // Print the value and exit
    printf("%d\n", value);
    return EXIT_SUCCESS;
}
