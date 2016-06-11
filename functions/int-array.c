#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ELEMENT_COUNT 8

int largestIn(int[], unsigned int);
int averageIn(int[], unsigned int);
int countPositiveIn(int [], unsigned int);

int main()
{
    int a[ELEMENT_COUNT];

    printf("Testing functions for an uninitialized array\n");
    printf("largestIn(a, %d) = %d\n", ELEMENT_COUNT, largestIn(a, ELEMENT_COUNT));
    printf("averageIn(a, %d) = %d\n", ELEMENT_COUNT, averageIn(a, ELEMENT_COUNT));
    printf("countPositiveIn(a, %d) = %d\n", ELEMENT_COUNT, countPositiveIn(a, ELEMENT_COUNT));

    for (int i = 0; i < ELEMENT_COUNT; ++i) {
        a[i] = -ELEMENT_COUNT / 2 + i;
    }

    printf("Testing functions for an initialized array\n");
    printf("largestIn(a, %d) = %d\n", ELEMENT_COUNT, largestIn(a, ELEMENT_COUNT));
    printf("averageIn(a, %d) = %d\n", ELEMENT_COUNT, averageIn(a, ELEMENT_COUNT));
    printf("countPositiveIn(a, %d) = %d\n", ELEMENT_COUNT, countPositiveIn(a, ELEMENT_COUNT));

    return EXIT_SUCCESS;
}

/*
 * Function that returns the largest element in an array of integers
 */
int largestIn(int a[], unsigned int n)
{
    int largest = INT_MIN;
    for (unsigned int i = 0; i < n; ++i) {
        if (a[i] > largest) largest = a[i];
    }
    return largest;
}

/*
 * Function that returns the average of all elements in an array of integers
 */
int averageIn(int a[], unsigned int n)
{
    int average = 0;
    for (unsigned int i = 0; i < n; ++i) {
        average += a[i];
    }
    if (n > 0) average /= (int) n;
    return average;
}

/*
 * Function that returns the number of positive elements in an array of integers
 */
int countPositiveIn(int a[], unsigned int n)
{
    int positives = 0;
    for (unsigned int i = 0; i < n; ++i) {
        if (a[i] > 0) ++positives;
    }
    return positives;
}
