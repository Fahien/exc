#include <stdio.h>
#include <stdlib.h>


/// @brief This function searches the array a for its largest and second-largest element,
/// storing them in the variables pointed to by largest and second_largest, respectively.
void find_two_largest(int *a, unsigned int n, int *largest, int *second_largest)
{
    // Check arguments
    if (n < 2) {
        fprintf(stderr, "Could not find largest and second-largest in array of size less than 2");
        exit(EXIT_FAILURE);
    }

    *largest = (*a > *(a+1)) ? *a : *(a+1);
    *second_largest = (*a > *(a+1)) ? *(a+1) : *a;

    const int *limit = a + n;
    a += 2;
    while (a < limit) {
        if (*a > *largest) {
            *second_largest = *largest;
            *largest = *a;
        }
        else if (*a != *largest && *a > *second_largest) {
            *second_largest = *a;
        }
        ++a;
    }
}


int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: ./find-two-largest n1 n2 [n3 ... nN]\n");
        return EXIT_FAILURE;
    }

    // Initialize array
    unsigned size = (unsigned)(argc - 1);
    int a[size];
    for (unsigned int i = 0; i < size; ++i) {
        a[i] = atoi(argv[i + 1]);
    }

    // Find the largest and the second-largest
    int largest, second_largest;
    find_two_largest(a, size, &largest, &second_largest);
    printf("Largest: %d\nSecond-largest: %d\n", largest, second_largest);

    return EXIT_SUCCESS;
}
