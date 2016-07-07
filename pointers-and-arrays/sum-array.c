#include <stdio.h>
#include <stdlib.h>

int sum_array(const int *a, unsigned int n)
{
    const int *limit = a + n;
    int sum = *(a++);
    while (a < limit) {
        sum += *(a++);
    }
    return sum;
}

int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: ./sum-array n1 [n2 ... nN]\n");
        return EXIT_FAILURE;
    }

    // Initialize array
    unsigned int size = argc - 1;
    int a[size];
    for (unsigned int i = 0; i < size; ++i) {
        a[i] = atoi(argv[i + 1]);
    }

    // Call sum_array function
    int sum = sum_array(a, size);

    // Print out the result and exit
    printf("Sum: %d\n", sum);
    return EXIT_SUCCESS;
}
