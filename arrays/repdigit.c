#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Program that test input numbers for repeated digits
 */
int main (void)
{
    int number;

    // Declare
    int digits[10];
    int d;

    while (true)
    {
        // Set zeros
        for (unsigned i = 0; i < 10; ++i) {
            digits[i] = 0;
        }

        // Get a number
        scanf("%d", &number);

        // Exit clause
        if (number == 0) break;

        // Analyze the number
        while (number != 0) {
            // Get a digit
            d = number % 10;
            // Increment occurrencies
            ++digits[d];
            // Next
            number /= 10;
        }

        // Print out analysis
        printf("Digits:\t\t");
        for (unsigned i = 0; i < 10; ++i) {
            printf("%4d", i);
        }
        printf("\nOccurrencies:\t");
        for (unsigned i = 0; i < 10; ++i) {
            printf("%4d", digits[i]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
