#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: ./search-int-array n1 [n2 ... nN] key\n");
        return EXIT_FAILURE;
    }

    // Get the key
    int key = atoi(argv[argc - 1]);

    // Initialize the array
    unsigned int size = argc - 2;
    int a[size];
    for (unsigned int i = 0; i < size; ++i) {
        a[i] = atoi(argv[i + 1]);
    }

    // Call search function
    bool found = search(a, size, key);

    // Print out the result and exit
    printf("Key %s\n", found ? "found!" : "not found.");
    return EXIT_SUCCESS;
}
