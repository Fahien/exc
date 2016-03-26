#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Euclid's algorithm for computing the greatest common divisor
 */
int euclid_algorithm(int n, int m)
{
    while (true) {
        // If n is zero, m contains the GCD
        if (n == 0) return m;

        // Compute the remainder when m is divided by n
        int remainder = m % n;
        // Copy n into m
        m = n;
        // Copy the remainder into n
        n = remainder;
    }
}

/*
 * Program that get two integers, then displays their greatest common divisor
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: ./gcd n m\n");
        return EXIT_FAILURE;
    }

    // Convert input strings to ints
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    // Compute the GCD
    int gcd = euclid_algorithm(n, m);

    // Print out the GCD
    printf("%d\n", gcd);

    return EXIT_SUCCESS;
}
