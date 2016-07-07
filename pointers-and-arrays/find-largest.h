#include <stdio.h>
#include <stdlib.h>

/// @brief When passed an array a of length n,
/// this function will return a pointer to the array's largest element
int *find_largest(int *a, unsigned int n)
{
    // Check for empty array
    if (n == 0) {
        fprintf(stderr, "Could not find the largest element of an array of length 0\n");
        exit(EXIT_FAILURE);
    }

    // Perform logic
    const int *limit = a + n;
    int *largest = a++;
    while (a < limit) {
        if (*a > *largest) {
            largest = a;
        }
        a++;
    }

    return largest;
}
