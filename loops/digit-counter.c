#include <stdio.h>
#include <stdlib.h>

/*
 * Calculates the number of digits in an integer
 */
int main (int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./digit-counter number\n");
		return EXIT_FAILURE;
	}

	int number = atoi(argv[1]);
	int digits = 0;

	do {
		number /= 10;
		++digits;
	} while (number != 0);

	printf("The number has %d digit%s\n", digits, (digits != 1) ? "s" : "");

	return EXIT_SUCCESS;
}
