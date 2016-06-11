#include <stdio.h>
#include <stdlib.h>

/*
 * This function returns the k-th digit (from the right) in a positive integer, n
 */
int digit(int n, int k)
{
    for (int i = k; i > 1; --i) {
        n /= 10;
    }
    return n % 10;
}

int main()
{
    printf("digit(829, 1) = %d\n", digit(829, 1));
    printf("digit(829, 2) = %d\n", digit(829, 2));
    printf("digit(829, 3) = %d\n", digit(829, 3));
    printf("digit(829, 4) = %d\n", digit(829, 4));

    return EXIT_SUCCESS;
}
