#include <stdio.h>
#include <stdlib.h>

/*
 * Program that asks the user to enter a value for x and then displays
 * the value of the following polynomial: 3x⁵+ 2x⁴- 5x³- x²+ 7x - 6
 * Then uses the Horner's Rule: ((((3x + 2)x - 5)x - 1)x + 7)x - 6
 */
int main (void)
{
	printf("x? ");
	float x;
	int scanf_result = scanf("%f", &x);
	if (scanf_result == EOF) {
		perror("scanf");
		return EXIT_FAILURE;
	}

	float x2 = x * x;
	float x3 = x2 * x;
	float x4 = x3 * x;
	float x5 = x4 * x;

	float result = 3 * x5 + 2 * x4 - 5 * x3 - x2 + 7 * x - 6;
	printf("3x⁵+ 2x⁴- 5x³- x²+ 7x - 6 = %f\n", result);

	result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
	printf("((((3x + 2)x - 5)x - 1)x + 7)x - 6 = %f\n", result);
	
	return EXIT_SUCCESS;
}
