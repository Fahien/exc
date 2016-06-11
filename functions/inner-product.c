#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_COUNT 8

/*
 * This function returns the inner product of two arrays of doubles
 * a[0] * b[0] + a[1] * b[1] + ... + a[n-1] * b[n-1]
 */
double innerProduct(double a[], double b[], unsigned int n)
{
    double ip = 0.0;
    for (unsigned int i = 0; i < n; ++i) {
        ip += a[i] * b[i];
    }
    return ip;
}

int main()
{
    // Create a and b
    double a[ELEMENT_COUNT];
    double b[ELEMENT_COUNT];

    for (int i = 0; i < ELEMENT_COUNT; ++i) {
        a[i] = b[i] = (double) i;
    }

    printf("innerProduct(a, b, %d) = %lf\n", ELEMENT_COUNT, innerProduct(a, b, ELEMENT_COUNT));
    return EXIT_SUCCESS;
}
