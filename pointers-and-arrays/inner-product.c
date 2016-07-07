#include <stdio.h>
#include <stdlib.h>


/// @brief This function returns a[0] * b[0] + a[1] * b[1] + ... a[n-1] * b[n-1]
double inner_product(const double *a, const double *b, unsigned int size)
{
    // Check for size error
    if (size == 0) {
        fprintf(stderr, "Could not compute inner_product of empty vectors\n");
        exit(EXIT_FAILURE);
    }

    // Compute product
    const double *limit = a + size;
    double product = *a++ * *b++;
    while (a < limit) {
        product += *a++ * *b++;
    }

    return product;
}


void print_array(const double *a, unsigned int size)
{
    // Check for size error
    if (size == 0) {
        fprintf(stderr, "Could not print an empty vector\n");
        exit(EXIT_FAILURE);
    }

    // Compute product
    const double *limit = a + size;
    printf("[");
    while (a < limit) {
        printf("%lf, ", *a++);
    }
    printf("\b\b]\n");
}


int main(int argc, char** argv)
{
    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: ./inner-product a1 [a2 ... aN] b1 [b2 ... bN]\n");
        return EXIT_FAILURE;
    }

    // Get size
    unsigned int size = (argc - 1) / 2;

    // Create the arrays
    double a[size], b[size];
    for (unsigned int i = 0; i < size; ++i) {
        a[i] = atof(argv[i + 1]);
        b[i] = atof(argv[size + i + 1]);
    }

    print_array(a, size);
    print_array(b, size);

    double product = inner_product(a, b, size);
    printf("Inner product: %lf\n", product);
    return EXIT_SUCCESS;
}
