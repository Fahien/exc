#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: ./identity-matrix n\n");
        return EXIT_FAILURE;
    }

    // Get n
    int n = atoi(argv[1]);

    int matrix[n][n];
    int *p = matrix[0];
    int *limit = p + n * n;

    // Initialize the matrix
    int zeros_written = n;
    while (p < limit) {
        if (zeros_written == n) {
            *p = 1;
            zeros_written = 0;
        }
        else {
            *p = 0;
            ++zeros_written;
        }

        // Print
        printf("%d ", *p);
        ++p;
        if ((limit - p) % n == 0) {
            printf("\b\n");
        }
    }

    return EXIT_SUCCESS;
}
