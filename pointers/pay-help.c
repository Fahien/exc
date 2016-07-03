#include <stdio.h>
#include <stdlib.h>

/// @brief This function determines the smallest number of
/// $20, $10, $5 and $1 bills necessary to pay the amount
/// @param dollars represents the amount
/// @param twenties points to a variable in which the 
/// function will store the number of $20 bills required.
/// @params tens, fives and ones are similar.
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;

    int mod20 = dollars % 20;
    *tens = mod20 / 10;

    int mod10 = mod20 % 10;
    *fives = mod10 / 5;

    *ones = mod10 % 5;
}

int main (int argc, char** argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: ./pay-help amount\n");
        return EXIT_FAILURE;
    }

    // Initialize variables
    int amount = atoi(argv[1]);
    int twenties, tens, fives, ones;

    pay_amount(amount, &twenties, &tens, &fives, &ones);

    printf("$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n",
        twenties, tens, fives, ones);

	return EXIT_SUCCESS;
}
