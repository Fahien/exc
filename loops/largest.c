#include <stdio.h>
#include <stdlib.h>

/*
 * Program that finds the largest in a
 * series of numbers entered by the user.
 */
int main (void)
{
    // Default max
    float max = 0.0f;
    
    // Default number
    float number = 0.0f;
    
    do {
        // Get a number
        printf("Enter a number: ");
        scanf("%f", &number);

        // Update max
        if (number > max) max = number;
    } while (number > 0);

    // Print out the largest
    printf("The largest number entered was: %f\n", max);

    return EXIT_SUCCESS;
}
