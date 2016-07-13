#include "extension.h"
#include "capitalize.h"
#include <stdio.h>
#include <stdlib.h>

/// @brief Test program for get_extension function
int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (test_extension(argv[1], "txt")) {
        printf("%s is a text file\n", argv[1]);
    }
    else {
        // Print extension
        char extension[EXT_MAX] = {0};
        printf("Unknown extension %s\n", capitalize(get_extension(argv[1], extension)));
    }

    return EXIT_SUCCESS;
}
