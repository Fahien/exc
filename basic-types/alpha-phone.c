#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Program that translates an alphabetic phone number into numeric form
 */
int main (int argc, char** argv)
{
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./alpha-phone phone-number\n");
        return EXIT_FAILURE;
    }

    char symbol;
    for (size_t i = 0; i < strlen(argv[1]); i++) {
        // Get next character;
        symbol = argv[1][i];

        // Check for substitution
        if ('A' <= symbol && symbol <= 'C') {
            symbol = '2';
        }
        else if ('D' <= symbol && symbol <= 'F') {
            symbol = '3';
        }
        else if ('G' <= symbol && symbol <= 'I') {
            symbol = '4';
        }
        else if ('J' <= symbol && symbol <= 'L') {
            symbol = '5';
        }
        else if ('M' <= symbol && symbol <= 'O') {
            symbol = '6';
        }
        else if ('P' <= symbol && symbol <= 'S') {
            symbol = '7';
        }
        else if ('T' <= symbol && symbol <= 'V') {
            symbol = '8';
        }
        else if ('W' <= symbol && symbol <= 'Z') {
            symbol = '9';
        }

        // Print character
        putchar(symbol);
    }

    // Print endline and exit
    printf("\n");
    return EXIT_SUCCESS;
}
