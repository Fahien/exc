#include <stdio.h>
#include <stdlib.h>

///
/// @brief The avg_sum function calculates the average and the sum of elements in an array
void avg_sum(int a[], unsigned int n, double *avg, double *sum)
{
    // Check for error
    if (n == 0) {
        fprintf(stderr, "Could not calculate avg and sum of an empty array\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the sum
    *sum = a[0];
    for (unsigned int i = 1; i < n; ++i) {
        *sum += a[i];
    }

    *avg = *sum / n;
}

///
/// @brief This program tests the avg_sum function
int main(int argc, char** argv)
{
    // Check for command line input error
    if (argc < 2) {
        fprintf(stderr, "Usage: ./max-min n1 [n2 ... nN]\n");
        return EXIT_FAILURE;
    }

    // Initialize the array of integers
    int a[argc - 1];
    for (int i = 0; i < argc - 1; ++i) {
        a[i] = atoi(argv[i + 1]);
    }

    // Find the average and the sum
    double avg, sum;
    avg_sum(a, argc - 1, &avg, &sum);

    // Print the average and the sum
    printf("Average: %lf\nSum: %lf\n", avg, sum);

    return EXIT_SUCCESS;
}
