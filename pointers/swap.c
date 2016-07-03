#include <stdio.h>
#include <stdlib.h>


/// @brief The swap function exchanges the value of the variables i and j
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

/// @brief This program tests the swap function
int main (int argc, char **argv)
{
    // Check for command line arguments error
    if (argc != 3) {
        fprintf(stderr, "Usage: ./swap i j\n");
        return EXIT_FAILURE;
    }

    // Initialize variables
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);

    swap(&i, &j);

    // Print out i and j
    printf("%d %d\n", i, j);

    return EXIT_SUCCESS;
}
