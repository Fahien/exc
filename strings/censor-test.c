#include "censor.h"
#include <stdio.h>
#include <stdlib.h>


/// @brief Test program for censor function
int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s string token\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Censor token in string
    printf("%s\n", censor(argv[1], argv[2]));
    return EXIT_SUCCESS;
}
