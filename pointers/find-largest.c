#include <stdio.h>
#include <stdlib.h>

/// @brief When passed an array a of length n,
/// this function will return a pointer to the array's largest element
int *find_largest(int a[], unsigned int n)
{
    // Check for empty array
    if (n == 0) {
        fprintf(stderr, "Could not find the largest element of an array of length 0\n");
        exit(EXIT_FAILURE);
    }

    // Perform logic
    int *largest = a;
    for (unsigned int i = 1; i < n; ++i) {
        if (a[i] > *largest) {
            largest = a + i;
        }
    }

    return largest;
}


/// @brief Test program for the find_largest function
int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: ./find-largest n1 [n2 ... nN]\n");
        return EXIT_FAILURE;
    }

    // Initialize the array
    unsigned int size = argc - 1;
    int array[size];
    for (unsigned int i = 0; i < size; ++i) {
        array[i] = atoi(argv[i+1]);
    }

    // Call the find_largest function
    int *largest = find_largest(array, size);
    printf("The largest element is %d at address %p\n", *largest, (void *)largest);

    return EXIT_SUCCESS;
}
