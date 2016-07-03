#include <stdio.h>
#include <stdlib.h>

///
/// @brief The max_min function finds the largest and the smallest elements in an array
void max_min(int a[], unsigned int n, int *max, int *min)
{
    // Check for error
    if (n == 0) {
        fprintf(stderr, "Could not find min and max of an empty array\n");
        exit(EXIT_FAILURE);
    }

    // Initialize min and max
    *max = *min = a[0];

    // Find min and max
    for (unsigned int i = 1; i < n; ++i) {
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
}

///
/// @brief This program tests the max_min function
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

    // Find the max and the min
    int max, min;
    max_min(a, argc - 1, &max, &min);

    // Print the max and the min
    printf("Largest: %d\nSmallest: %d\n", max, min);

    return EXIT_SUCCESS;
}
