#include "capitalize.h"
#include <stdio.h>
#include <stdlib.h>


/// @brief Test program for capitalize function
int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s s\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Print capitalized string
    printf("%s\n", capitalize(argv[1]));
    return EXIT_SUCCESS;
}
