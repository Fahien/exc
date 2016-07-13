#include "build-index-url.h"
#include <stdio.h>
#include <stdlib.h>

#define URL_MAX 64

int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s domain\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize variables
    char index_url[URL_MAX];
    build_index_url(argv[1], index_url);

    // Print result and exit
    printf("%s\n", index_url);
    return EXIT_SUCCESS;
}
