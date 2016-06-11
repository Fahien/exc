#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This function computes the value of the following polinomial
 * 3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6
 */
double evaluate_polynomial(double x)
{
    double value = -6.0;
    value += 7 * x;
    double x2 = x * x;
    value -= x2;
    double x3 = x2 * x;
    value -= 5 * x3;
    double x4 = x3 * x;
    value += 2 * x4;
    value += 3 * x4 * x;
    return value;
}

double evaluate_polynomial2(double x)
{
    return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
}

/*
 * This function measure the time of execution of a polynomial function
 */
float measure(double (* polynomial)(double x), double x)
{
    clock_t start = clock();
    for (int i = 0; i < 2048; ++i) {
        polynomial(x);
    }
    clock_t end = clock();
    return (float) end - start;
}

int main (int argc, char** argv)
{
    // Check command line argument
    if (argc < 2) {
        fprintf(stderr, "Usage: ./polynomial n\n");
        return EXIT_FAILURE;
    }

    // Get the x
    double x = atof(argv[1]);

    printf("Evaluate x = %lf\n", x);
    
    // Evaluate polynomial
    printf("polynomial(x) = %lf\n", evaluate_polynomial(x));
    // Evaluate polynomial 2
    printf("polynomial2(x) = %lf\n", evaluate_polynomial2(x));

    // Evaluate polynomial
    printf("polynomial time = %f\n", measure(evaluate_polynomial, x));
    // Evaluate polynomial 2
    printf("polynomial2 time = %f\n", measure(evaluate_polynomial2, x));

    return EXIT_SUCCESS;
}
