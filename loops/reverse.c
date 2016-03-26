#include <stdio.h>
#include <stdlib.h>

/*
 * Program that gets a number, then displays its digits reversed
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./reverse number\n");
        return EXIT_FAILURE;
    }

    // Convert input string to int
    int number = atoi(argv[1]);

    // Absolute value
    if (number < 0) number *= -1;

    // Print digits reversed one by one
    do {
        printf("%d", number % 10);
        number /= 10;
    } while (number != 0);

    printf("\n");
    return EXIT_SUCCESS;
}
