#include <stdio.h>
#include <stdlib.h>

/*
 * Program that gets a number, then prints all
 * even squares between 1 and that number
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./even-squares number\n");
        return EXIT_FAILURE;
    }

    // Convert input string to int
    int number = atoi(argv[1]);

    // Check input number
    if (number < 4) return EXIT_SUCCESS;

    // Print base
    printf("4\n");

    // Print even squares
    for (int i = 3, square = i*i; square <= number; ++i, square = i*i) {
        if (square % 2 == 0) printf("%d\n", square);
    }

    return EXIT_SUCCESS;
}
