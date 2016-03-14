#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX 100

/*
 * This program prints a table of squares
 */
int main (int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./squares number\n");
		return EXIT_FAILURE;
	}

	int num = atoi(argv[1]);

	// Check for bounding error
	if (num < 1) {
		fprintf(stderr, "The number should not be less than 1\n");
		return EXIT_FAILURE;
	}

	// Check for bounding error
	if (num > NUM_MAX) {
		fprintf(stderr, "The number should not be greater than %d\n", NUM_MAX);
		return EXIT_FAILURE;
	}

	for (int i = 1; i <= num; ++i) {
		printf("%6d%6d\n", i, i * i);
	}

	return EXIT_SUCCESS;
}
