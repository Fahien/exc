#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int ret = 1;
    while (n > 0) {
        ret *= n;
        --n;
    }
    return ret;
}
/*
 * Program that approximates e by computing the value of
 * 1 + 1/1! + 1/2! + ... + 1/n!
 */
int main (int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./compute-e n\n");
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    double e = 1;

    for (int i = 1; i < n; i++) {
        e += 1.0/factorial(i);
    }

    printf("After %d computations e = %lf\n", n, e);

    return EXIT_SUCCESS;
}
