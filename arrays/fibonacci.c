#include <stdio.h>
#include <stdlib.h>

/*
 * Program that declares an array named fib_numbers of length 40
 * and fills the array with the first 40 Fibonacci numbers
 */
int main (void)
{
    // Declare and initialize the array
    unsigned fib_numbers[40] = {0, 1};

    // Populate the array and print out the numbers
    printf("0 1 ");
    for (unsigned i = 2; i < 40; ++i)
    {
        fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
        printf("%d ", fib_numbers[i]);
    }
    printf("\b\n");

    return EXIT_SUCCESS;
}
