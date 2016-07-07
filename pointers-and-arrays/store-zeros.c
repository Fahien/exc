#include <stdio.h>
#include <stdlib.h>


void store_zeros(int *a, unsigned int size)
{
    int *limit = a + size;
    while (a < limit) {
        *a++ = 0;
    }
}


int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: ./store-zeros size\n");
        return EXIT_FAILURE;
    }

    // Get the size argument and check for errors
    int arg = atoi(argv[1]);
    if (arg == 0) {
        fprintf(stderr, "Could not initialize array with 0 elements\n");
        return EXIT_FAILURE;
    }
    else if (arg < 0) arg = -arg;

    unsigned int size = (unsigned int) arg;
    int a[size];

    // Fill with zeros
    store_zeros(a, size);

    printf("[");
    for (unsigned int i = 0; i < size; ++i) {
        printf("%d, ", a[i]);
    }
    printf("\b\b]\n");

    return EXIT_SUCCESS;
}
