#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define EPS (.00001)
/*
 * Program that uses Newton's method to compute the
 * square root of a positive floating-point number
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./newton-square-root number\n");
        return EXIT_FAILURE;
    }

    // Get x
    double x = atof(argv[1]);

    // Initial guess y
    double y = 1.0;

    double x_by_y = x / y;

    // Average of y and x/y
    double avg = (y + x_by_y) / 2;

    while (true) {
        /* Terminate when the absolute value of the difference between the old value
         * of y and the new value of y is less than the product of EPS and y */
        if (fabs(y - avg) < EPS * y) break;
        // Update y
        y = avg;
        // Update x / y
        x_by_y = x / y;
        // Update avg
        avg = (y + x_by_y) / 2;
    }

    // Print out the result and exit
    printf("%lf\n", avg);
    return EXIT_SUCCESS;
}
