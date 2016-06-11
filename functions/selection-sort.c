#include <stdio.h>
#include <stdlib.h>

/*
 * This function search an array of integers to find the largest element,
 * move it to the last position in the array and call itself recursively
 * to sort the first n-1 elements of the array
 */
void selectionSort(int a[], unsigned int size)
{
    if (size < 2) return;
    
    // Initialize variables
    int indexMax = 0;
    int elementMax = a[0];

    // Iterate the array to find the largest element
    for (int i = 1; i < size; ++i) {
        if (a[i] > elementMax) {
                indexMax = i;
                elementMax = a[i];
        }
    }

    // Move the largest element to the last position
    a[indexMax] = a[size - 1];
    a[size - 1] = elementMax;

    // Call itself to sort the first n-1 elements
    selectionSort(a, size - 1);
}

/*
 * This program takes a list of integers as command line arguments
 * and sort them by calling the function selectionSort.
 */
int main (int argc, char** argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: ./selection-sort n1 n2 ...\n");
        return EXIT_FAILURE;
    }

    // Declare the array
    int elements[argc - 1];

    // Populate the array
    for (int i = 1; i < argc; ++i) {
        elements[i - 1] = atoi(argv[i]);
        printf("%d ", elements[i - 1]);
    }
    printf("\b\n");

    // Sort the array
    selectionSort(elements, argc - 1);

    // Print out the sorted array
    for (int i = 0; i < argc - 1; ++i) {
        printf("%d ", elements[i]);
    }
    printf("\b\n");

    return EXIT_SUCCESS;
}
