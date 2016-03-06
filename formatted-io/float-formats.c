#include <stdio.h>
#include <stdlib.h>

/*
 * Write calls of printf that display a
 * float variable x in various formats
 */
int main (int argc, char** argv)
{
	if (argc != 2) {
		printf("Usage: ./float-formats <FLOAT NUMBER>\n");
		return EXIT_FAILURE;
	}

	float x;
	sscanf(argv[1], "%f", &x);

	// exponential notation
	// left justified in a fielf of size 8
	// one digit after the decimal point
	printf("%-8.1e\n", x);

	// exponential notation
	// right justified in a field of size 10
	// six digits after the decimal point
	printf("%10.6e\n", x);

	// fixed decimal notation
	// left justified in a fielf of size 8
	// three digits after the decimal point
	printf("%-8.3f\n", x);

	// fixed decimal notation
	// right justified in a fielf of size 6
	// no digits after the decimal point
	printf("%6.0f\n", x);

	return EXIT_SUCCESS;
}
