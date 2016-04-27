#include <stdio.h>
#include <stdlib.h>

/*
 * Program that sums a serie of double values
 */
int main (void)
{
    // Initialize variables
    double sum = 0.0;
    double num;
    
    // Read first double value
    int scanf_result = scanf("%lf", &num);

    while (scanf_result) {
        // Increment sum
        sum += num;
        // Load next double value
        scanf_result = scanf("%lf", &num);
    }

    // Print out result
    printf("Sum = %f\n", sum);

    return EXIT_SUCCESS;
}
