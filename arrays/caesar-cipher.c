#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Program that encrypts a message using a Caesar cipher
 */
int main (int argc, char** argv)
{
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./caesar-cypher shift-amount\n");
        return EXIT_FAILURE;
    }

    // Get shift amount
    int shift = atoi(argv[1]);
    // Check shift amount
    if (shift < 1 || 25 < shift) {
        fprintf(stderr, "The shift amount must be comprised between 1 and 25\n");
        return EXIT_FAILURE;
    }

    // Loop variables
    char c;
    while (true) {
        // Get next char
        c = getchar();

        // Check for EOF
        if (c == EOF) break;

        // Cipher letter
        if ('A' <= c && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        else if ('a' <= c && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        }

        // Print out the char
        putchar(c);
    }

    return EXIT_SUCCESS;
}
