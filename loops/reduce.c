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
 * Program that gets a fraction, then reduces the fraction to lowest terms
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./reduce n/m\n");
        return EXIT_FAILURE;
    }

    // Get numerator and denominator
    int numerator;
    int denominator;
    sscanf(argv[1], "%d/%d", &numerator, &denominator);

    // Compute the GCD
    int gcd = euclid_algorithm(numerator, denominator);

    // Reduce to lowest terms
    numerator /= gcd;
    denominator /= gcd;

    // Print out the new fraction
    printf("%d/%d\n", numerator, denominator);

    return EXIT_SUCCESS;
}
