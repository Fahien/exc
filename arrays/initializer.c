#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Program that declares an array named weekend containing seven bool values 
 */
int main (void)
{
    // Declare and initialize the array
    bool weekend[] = {true, [6]=true};

    // Print out the array
    for (unsigned i = 0; i < sizeof(weekend)/sizeof(weekend[0]); i++) {
        printf("%s ", weekend[i] ? "true" : "false");
    }
    printf("\b\n");

    return EXIT_SUCCESS;
}
