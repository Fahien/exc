#include <stdio.h>
#include <stdlib.h>

/*
 * Program that takes a first name and a last name and displays
 * the last name, a comma and the first initial, followed by a period.
 */
int main(int argc, char** argv)
{
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: ./name lastname firstname\n");
        return EXIT_FAILURE;
    }

    // Print out the formatted name and exit
    printf("%s, %c.\n", argv[2], argv[1][0]);
    return EXIT_SUCCESS;
}
