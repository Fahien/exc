#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// @brief Euclid's algorithm for computing the greatest common divisor
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

/// @params numerator and denominator are the numerator and denominator of a fraction
/// @params reduced_numerator and reduced_denominator are pointers to variables in which the function will 
/// store the numerator and denominator of the fraction once it has been reduced to the lowest terms
void reduce(int numerator, int denominator, int *reduced_numerator, int* reduced_denominator)
{
    // Compute the GCD
    int gcd = euclid_algorithm(numerator, denominator);
    // Reduce to lowest terms
    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
}

/// @brief This program gets a fraction, then reduces the fraction to lowest terms
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

    reduce(numerator, denominator, &numerator, &denominator);

    // Print out the new fraction
    printf("%d/%d\n", numerator, denominator);

    return EXIT_SUCCESS;
}
