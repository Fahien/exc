#include <stdio.h>
#include <stdlib.h>

/*
 * Program that finds the largest and smallest of four integers
 */
int main (int argc, char **argv)
{
	if (argc != 5) {
		fprintf(stderr, "Usage: ./max-min n1 n2 n3 n4\n");
		return EXIT_FAILURE;
	}

	int numbers[4];
	for (int i = 0; i < 4; i++) {
		numbers[i] = atoi(argv[i + 1]);
	}

	int min = numbers[0];
	int max = numbers[0];

	for (int i = 1; i < 4; i++) {
		if (numbers[i] < min) {
			min = numbers[i];
		}
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}

	printf("Largest: %d\nSmallest: %d\n", max, min);

	return EXIT_SUCCESS;
}
