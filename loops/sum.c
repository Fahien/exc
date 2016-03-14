#include <stdio.h>
#include <stdlib.h>

#define ARGC_MAX 100

/*
 * Sums a series of numbers
 */
int main (int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: ./sum n1 [n2 ...]\n");
		return EXIT_FAILURE;
	}

	if (argc > ARGC_MAX) {
		fprintf(stderr, "Too many arguments\n");
		return EXIT_FAILURE;
	}

	int sum = 0;
	int i = 1;
	while (i < argc) {
		sum += atoi(argv[i++]);
	}

	printf("The sum is: %d\n", sum);

	return EXIT_SUCCESS;
}
