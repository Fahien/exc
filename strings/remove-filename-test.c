#include "remove-filename.h"
#include <stdio.h>
#include <stdlib.h>


/// @brief Test program for the remove_filename function
int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage %s url\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Remove file name
    remove_filename(argv[1]);
    printf("%s\n", argv[1]);
    return EXIT_SUCCESS;
}
