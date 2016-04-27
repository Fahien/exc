#include <stdio.h>
#include <stdlib.h>

/*
 * Program that computes the factorial of a positive integer
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./factorial number\n");
        return EXIT_FAILURE;
    }

    // Get the number
    int num = atoi(argv[1]);

    // Initialize factorial
    long long unsigned factorial = 1;

    while (num > 1) {
        factorial *= num;
        --num;
    }

    // Print out the result and exit
    printf("%llu\n", factorial);
    return EXIT_SUCCESS;
}
