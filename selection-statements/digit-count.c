#include <stdio.h>
#include <stdlib.h>

/*
 * Program that calculates how many digits a number contains
 */
int main (int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./digit-count <NUMBER>\n");
		return EXIT_FAILURE;
	}

	int number = atoi(argv[1]);

	if (number == 0) {
		printf("The number 0 has 1 digits\n");
		return EXIT_SUCCESS;
	}

	printf("The number %d has ", number);

	int digits = 0;
	while (number != 0) {
		number /= 10;
		++digits;
	}
	printf("%d digits\n", digits);

	return EXIT_SUCCESS;
}
