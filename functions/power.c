#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This is an iterative function that computes the n-th power of a number x
 */
double iterative_pow(double x, int n)
{
    double result = 1.0;
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            result *= x;
        }
    }
    else {
        for (int i = 0; i > n; ++i) {
            result /= x;
        }
    }
    return result;
}

/*
 * This is a recursive function that computes the n-th power of a number x
 */
double recursive_pow(double x, int n)
{
    // Base case
    if (n == 0) return 1.0;
    // If n is even
    if (n % 2 == 0) {
        // Use the formula x^n = (x^n/2)^2
        // intermediate is x^n/2
        double intermediate = recursive_pow(x, n / 2);
        return intermediate * intermediate;
    }
    // If n is odd
    else {
        // Use the formula x^n = x * x^n-1
        return x * recursive_pow(x, n-1);
    }
}

/*
 * This function measure the time of execution of a polynomial function
 */
float measure(double (* power)(double x, int n), double x, int n)
{
    clock_t start = clock();
    for (int i = 0; i < 2048; ++i) {
        power(x, n);
    }
    clock_t end = clock();
    return (float) end - start;
}

int main (int argc, char** argv)
{
    // Check command line argument
    if (argc < 2) {
        fprintf(stderr, "Usage: ./power x n\n");
        return EXIT_FAILURE;
    }

    // Convert the first command line input to double
    double x = atof(argv[1]);
    // Convert the second command line input to int
    int n = atoi(argv[2]);

    // Evaluate polynomial
    printf("iterative_pow(%.4lf, %d) = %lf\n", x, n, iterative_pow(x, n));
    // Evaluate polynomial 2
    printf("recursive_pow(%.4lf, %d) = %lf\n", x, n, recursive_pow(x, n));

    // Evaluate polynomial
    printf("iterative_pow time = %.2f\n", measure(iterative_pow, x, n));
    // Evaluate polynomial 2
    printf("recursive_pow time = %.2f\n", measure(recursive_pow, x, n));

    return EXIT_SUCCESS;
}
