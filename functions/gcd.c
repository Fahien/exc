#include <stdio.h>
#include <stdlib.h>

#define MAX 4

/*
 * This function calculates the greatest common divisor of
 * the integers m and n using the Euclid's algorithm
 */
int gcd(int m, int n)
{
    int temp;
    while (n != 0) {

        temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

int main()
{
    printf("GCD between a couple of numbers.\n");

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            printf("gcd(%d, %d) = %d\n", i , j, gcd(i, j)); 
        }
    }

    return EXIT_SUCCESS;
}
